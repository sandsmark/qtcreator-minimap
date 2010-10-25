/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** Commercial Usage
**
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://qt.nokia.com/contact.
**
**************************************************************************/

#include "qdeclarativeviewobserver.h"
#include "qdeclarativeviewobserver_p.h"
#include "qdeclarativeobserverservice.h"
#include "selectiontool.h"
#include "zoomtool.h"
#include "colorpickertool.h"
#include "layeritem.h"
#include "boundingrecthighlighter.h"
#include "subcomponenteditortool.h"
#include "qmltoolbar.h"

#include "qt_private/qdeclarativedebughelper_p.h"

#include <QDeclarativeItem>
#include <QDeclarativeEngine>
#include <QDeclarativeContext>
#include <QDeclarativeExpression>
#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsObject>
#include <QApplication>
#include <QAbstractAnimation>

namespace QmlJSDebugger {

const int SceneChangeUpdateInterval = 5000;

QDeclarativeViewObserverPrivate::QDeclarativeViewObserverPrivate(QDeclarativeViewObserver *q) :
    q(q),
    designModeBehavior(false),
    executionPaused(false),
    slowdownFactor(1.0f),
    toolbar(0)
{
}

QDeclarativeViewObserverPrivate::~QDeclarativeViewObserverPrivate()
{
}

QDeclarativeViewObserver::QDeclarativeViewObserver(QDeclarativeView *view, QObject *parent) :
    QObject(parent), data(new QDeclarativeViewObserverPrivate(this))
{
    data->view = view;
    data->manipulatorLayer = new LayerItem(view->scene());
    data->selectionTool = new SelectionTool(this);
    data->zoomTool = new ZoomTool(this);
    data->colorPickerTool = new ColorPickerTool(this);
    data->boundingRectHighlighter = new BoundingRectHighlighter(this);
    data->subcomponentEditorTool = new SubcomponentEditorTool(this);
    data->currentTool = data->selectionTool;

    data->view->setMouseTracking(true);
    data->view->viewport()->installEventFilter(this);

    data->debugService = QDeclarativeObserverService::instance();
    connect(data->debugService, SIGNAL(designModeBehaviorChanged(bool)), SLOT(setDesignModeBehavior(bool)));
    connect(data->debugService, SIGNAL(reloadRequested()), SLOT(_q_reloadView()));
    connect(data->debugService,
            SIGNAL(currentObjectsChanged(QList<QObject*>)),
            SLOT(_q_onCurrentObjectsChanged(QList<QObject*>)));
    connect(data->debugService, SIGNAL(animationSpeedChangeRequested(qreal)), SLOT(changeAnimationSpeed(qreal)));
    connect(data->debugService, SIGNAL(colorPickerToolRequested()), SLOT(_q_changeToColorPickerTool()));
    connect(data->debugService, SIGNAL(selectMarqueeToolRequested()), SLOT(_q_changeToMarqueeSelectTool()));
    connect(data->debugService, SIGNAL(selectToolRequested()), SLOT(_q_changeToSingleSelectTool()));
    connect(data->debugService, SIGNAL(zoomToolRequested()), SLOT(_q_changeToZoomTool()));
    connect(data->debugService,
            SIGNAL(objectCreationRequested(QString,QObject*,QStringList,QString)),
            SLOT(_q_createQmlObject(QString,QObject*,QStringList,QString)));
    connect(data->debugService,
            SIGNAL(objectReparentRequested(QObject *, QObject *)),
            SLOT(_q_reparentQmlObject(QObject *, QObject *)));
    connect(data->debugService, SIGNAL(contextPathIndexChanged(int)), SLOT(_q_changeContextPathIndex(int)));
    connect(data->debugService, SIGNAL(clearComponentCacheRequested()), SLOT(_q_clearComponentCache()));
    connect(data->view, SIGNAL(statusChanged(QDeclarativeView::Status)), SLOT(_q_onStatusChanged(QDeclarativeView::Status)));

    connect(data->colorPickerTool, SIGNAL(selectedColorChanged(QColor)), SIGNAL(selectedColorChanged(QColor)));
    connect(data->colorPickerTool, SIGNAL(selectedColorChanged(QColor)),
            data->debugService, SLOT(selectedColorChanged(QColor)));

    connect(data->subcomponentEditorTool, SIGNAL(cleared()), SIGNAL(inspectorContextCleared()));
    connect(data->subcomponentEditorTool, SIGNAL(contextPushed(QString)), SIGNAL(inspectorContextPushed(QString)));
    connect(data->subcomponentEditorTool, SIGNAL(contextPopped()), SIGNAL(inspectorContextPopped()));
    connect(data->subcomponentEditorTool, SIGNAL(contextPathChanged(QStringList)), data->debugService, SLOT(contextPathUpdated(QStringList)));

    data->createToolbar();

    data->_q_changeToSingleSelectTool();
}

QDeclarativeViewObserver::~QDeclarativeViewObserver()
{
}

void QDeclarativeViewObserver::setObserverContext(int contextIndex)
{
    if (data->subcomponentEditorTool->contextIndex() != contextIndex) {
        QGraphicsObject *object = data->subcomponentEditorTool->setContext(contextIndex);
        if (object)
            data->debugService->setCurrentObjects(QList<QObject*>() << object);
    }
}

void QDeclarativeViewObserverPrivate::_q_reloadView()
{
    subcomponentEditorTool->clear();
    clearHighlight();
    emit q->reloadRequested();
}

void QDeclarativeViewObserverPrivate::clearEditorItems()
{
    clearHighlight();
    setSelectedItems(QList<QGraphicsItem*>());
}

bool QDeclarativeViewObserver::eventFilter(QObject *obj, QEvent *event)
 {
     switch (event->type()) {
     case QEvent::Leave: {
         if (leaveEvent(event))
             return true;
         break;
     }
     case QEvent::MouseButtonPress: {
         if (mousePressEvent(static_cast<QMouseEvent*>(event)))
            return true;
         break;
     }
     case QEvent::MouseMove: {
         if (mouseMoveEvent(static_cast<QMouseEvent*>(event)))
             return true;
         break;
     }
     case QEvent::MouseButtonRelease: {
         if (mouseReleaseEvent(static_cast<QMouseEvent*>(event)))
             return true;
         break;
     }
     case QEvent::KeyPress: {
         if (keyPressEvent(static_cast<QKeyEvent*>(event)))
             return true;
         break;
     }
     case QEvent::KeyRelease: {
         if (keyReleaseEvent(static_cast<QKeyEvent*>(event)))
             return true;
         break;
     }
     case QEvent::MouseButtonDblClick: {
         if (mouseDoubleClickEvent(static_cast<QMouseEvent*>(event)))
             return true;
         break;
     }
     case QEvent::Wheel: {
         if (wheelEvent(static_cast<QWheelEvent*>(event)))
             return true;
         break;
     }
     default: {
         break;
     }
     } //switch

     // standard event processing
     return QObject::eventFilter(obj, event);
}

bool QDeclarativeViewObserver::leaveEvent(QEvent * /*event*/)
{
    if (!data->designModeBehavior)
        return false;
    data->clearHighlight();
    return true;
}

bool QDeclarativeViewObserver::mousePressEvent(QMouseEvent *event)
{
    if (!data->designModeBehavior)
        return false;
    data->cursorPos = event->pos();
    data->currentTool->mousePressEvent(event);
    return true;
}

bool QDeclarativeViewObserver::mouseMoveEvent(QMouseEvent *event)
{
    if (!data->designModeBehavior) {
        data->clearEditorItems();
        return false;
    }
    data->cursorPos = event->pos();

    QList<QGraphicsItem*> selItems = data->selectableItems(event->pos());
    if (!selItems.isEmpty()) {
        declarativeView()->setToolTip(AbstractFormEditorTool::titleForItem(selItems.first()));
    } else {
        declarativeView()->setToolTip(QString());
    }
    if (event->buttons()) {
        data->subcomponentEditorTool->mouseMoveEvent(event);
        data->currentTool->mouseMoveEvent(event);
    } else {
        data->subcomponentEditorTool->hoverMoveEvent(event);
        data->currentTool->hoverMoveEvent(event);
    }
    return true;
}

bool QDeclarativeViewObserver::mouseReleaseEvent(QMouseEvent *event)
{
    if (!data->designModeBehavior)
        return false;
    data->subcomponentEditorTool->mouseReleaseEvent(event);

    data->cursorPos = event->pos();
    data->currentTool->mouseReleaseEvent(event);

    data->debugService->setCurrentObjects(AbstractFormEditorTool::toObjectList(selectedItems()));
    return true;
}

bool QDeclarativeViewObserver::keyPressEvent(QKeyEvent *event)
{
    if (!data->designModeBehavior) {
        return false;
    }
    data->currentTool->keyPressEvent(event);
    return true;
}

bool QDeclarativeViewObserver::keyReleaseEvent(QKeyEvent *event)
{
    if (!data->designModeBehavior) {
        return false;
    }

    switch(event->key()) {
    case Qt::Key_V:
        data->_q_changeToSingleSelectTool();
        break;
// disabled because multiselection does not do anything useful without design mode
//    case Qt::Key_M:
//        data->_q_changeToMarqueeSelectTool();
//        break;
    case Qt::Key_I:
        data->_q_changeToColorPickerTool();
        break;
    case Qt::Key_Z:
        data->_q_changeToZoomTool();
        break;
    case Qt::Key_Enter:
    case Qt::Key_Return:
        if (!data->selectedItems().isEmpty())
            data->subcomponentEditorTool->setCurrentItem(data->selectedItems().first());
        break;
    case Qt::Key_Space:
        if (data->executionPaused) {
            continueExecution(data->slowdownFactor);
        } else {
            pauseExecution();
        }
        break;
    default:
        break;
    }

    data->currentTool->keyReleaseEvent(event);
    return true;
}

void QDeclarativeViewObserverPrivate::_q_createQmlObject(const QString &qml, QObject *parent, const QStringList &importList, const QString &filename)
{
    if (!parent)
        return;

    QString imports;
    foreach(const QString &s, importList) {
        imports += s + "\n";
    }

    QDeclarativeContext *parentContext = view->engine()->contextForObject(parent);
    QDeclarativeComponent component(view->engine(), q);
    QByteArray constructedQml = QString(imports + qml).toLatin1();

    component.setData(constructedQml, filename);
    QObject *newObject = component.create(parentContext);
    if (newObject) {
        newObject->setParent(parent);
        QDeclarativeItem *parentItem = qobject_cast<QDeclarativeItem*>(parent);
        QDeclarativeItem *newItem    = qobject_cast<QDeclarativeItem*>(newObject);
        if (parentItem && newItem) {
            newItem->setParentItem(parentItem);
        }
    }
}

void QDeclarativeViewObserverPrivate::_q_reparentQmlObject(QObject *object, QObject *newParent)
{
    if (!newParent)
        return;

    object->setParent(newParent);
    QDeclarativeItem *newParentItem = qobject_cast<QDeclarativeItem*>(newParent);
    QDeclarativeItem *item    = qobject_cast<QDeclarativeItem*>(object);
    if (newParentItem && item) {
        item->setParentItem(newParentItem);
    }
}

void QDeclarativeViewObserverPrivate::_q_clearComponentCache()
{
    view->engine()->clearComponentCache();
}

QGraphicsItem *QDeclarativeViewObserverPrivate::currentRootItem() const
{
    return subcomponentEditorTool->currentRootItem();
}

bool QDeclarativeViewObserver::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (!data->designModeBehavior)
        return false;

    if (data->currentToolMode != Constants::SelectionToolMode
            && data->currentToolMode != Constants::MarqueeSelectionToolMode)
        return true;

    QGraphicsItem *itemToEnter = 0;
    QList<QGraphicsItem*> itemList = data->view->items(event->pos());
    data->filterForSelection(itemList);

    if (data->selectedItems().isEmpty() && !itemList.isEmpty()) {
        itemToEnter = itemList.first();
    } else if (!data->selectedItems().isEmpty() && !itemList.isEmpty()) {
        itemToEnter = itemList.first();
    }

    if (itemToEnter)
        itemToEnter = data->subcomponentEditorTool->firstChildOfContext(itemToEnter);

    data->subcomponentEditorTool->setCurrentItem(itemToEnter);
    data->subcomponentEditorTool->mouseDoubleClickEvent(event);

    if ((event->buttons() & Qt::LeftButton) && itemToEnter) {
        QGraphicsObject *objectToEnter = itemToEnter->toGraphicsObject();
        if (objectToEnter)
            data->debugService->setCurrentObjects(QList<QObject*>() << objectToEnter);
    }

    return true;
}

bool QDeclarativeViewObserver::wheelEvent(QWheelEvent *event)
{
    if (!data->designModeBehavior)
        return false;
    data->currentTool->wheelEvent(event);
    return true;
}

void QDeclarativeViewObserverPrivate::enterContext(QGraphicsItem *itemToEnter)
{
    QGraphicsItem *itemUnderCurrentContext = itemToEnter;
    if (itemUnderCurrentContext)
        itemUnderCurrentContext = subcomponentEditorTool->firstChildOfContext(itemToEnter);

    if (itemUnderCurrentContext)
        subcomponentEditorTool->setCurrentItem(itemToEnter);
}

void QDeclarativeViewObserver::setDesignModeBehavior(bool value)
{
    emit designModeBehaviorChanged(value);

    data->toolbar->setDesignModeBehavior(value);
    data->debugService->setDesignModeBehavior(value);

    data->designModeBehavior = value;
    if (data->subcomponentEditorTool) {
        data->subcomponentEditorTool->clear();
        data->clearHighlight();
        data->setSelectedItems(QList<QGraphicsItem*>());

        if (data->view->rootObject())
            data->subcomponentEditorTool->pushContext(data->view->rootObject());
    }

    if (!data->designModeBehavior)
        data->clearEditorItems();
}

bool QDeclarativeViewObserver::designModeBehavior()
{
    return data->designModeBehavior;
}

void QDeclarativeViewObserverPrivate::changeTool(Constants::DesignTool tool, Constants::ToolFlags /*flags*/)
{
    switch(tool) {
    case Constants::SelectionToolMode:
        _q_changeToSingleSelectTool();
        break;
    case Constants::NoTool:
    default:
        currentTool = 0;
        break;
    }
}

void QDeclarativeViewObserverPrivate::setSelectedItemsForTools(QList<QGraphicsItem *> items)
{
    currentSelection.clear();
    foreach(QGraphicsItem *item, items) {
        if (item) {
            QGraphicsObject *obj = item->toGraphicsObject();
            if (obj)
                currentSelection << obj;
        }
    }
    currentTool->updateSelectedItems();
}

void QDeclarativeViewObserverPrivate::setSelectedItems(QList<QGraphicsItem *> items)
{
    setSelectedItemsForTools(items);
    debugService->setCurrentObjects(AbstractFormEditorTool::toObjectList(items));
}

QList<QGraphicsItem *> QDeclarativeViewObserverPrivate::selectedItems()
{
    QList<QGraphicsItem *> selection;
    foreach(const QWeakPointer<QGraphicsObject> &selectedObject, currentSelection) {
        if (selectedObject.isNull()) {
            currentSelection.removeOne(selectedObject);
        } else {
            selection << selectedObject.data();
        }
    }

    return selection;
}

void QDeclarativeViewObserver::setSelectedItems(QList<QGraphicsItem *> items)
{
    data->setSelectedItems(items);
}

QList<QGraphicsItem *> QDeclarativeViewObserver::selectedItems()
{
    return data->selectedItems();
}

QDeclarativeView *QDeclarativeViewObserver::declarativeView()
{
    return data->view;
}

void QDeclarativeViewObserverPrivate::clearHighlight()
{
    boundingRectHighlighter->clear();
}

void QDeclarativeViewObserverPrivate::highlight(QGraphicsObject * item, ContextFlags flags)
{
    highlight(QList<QGraphicsObject*>() << item, flags);
}

void QDeclarativeViewObserverPrivate::highlight(QList<QGraphicsObject *> items, ContextFlags flags)
{
    if (items.isEmpty())
        return;

    QList<QGraphicsObject*> objectList;
    foreach(QGraphicsItem *item, items) {
        QGraphicsItem *child = item;
        if (flags & ContextSensitive)
            child = subcomponentEditorTool->firstChildOfContext(item);

        if (child) {
            QGraphicsObject *childObject = child->toGraphicsObject();
            if (childObject)
                objectList << childObject;
        }
    }

    boundingRectHighlighter->highlight(objectList);
}

bool QDeclarativeViewObserverPrivate::mouseInsideContextItem() const
{
    return subcomponentEditorTool->containsCursor(cursorPos.toPoint());
}

QList<QGraphicsItem*> QDeclarativeViewObserverPrivate::selectableItems(const QPointF &scenePos) const
{
    QList<QGraphicsItem*> itemlist = view->scene()->items(scenePos);
    return filterForCurrentContext(itemlist);
}

QList<QGraphicsItem*> QDeclarativeViewObserverPrivate::selectableItems(const QPoint &pos) const
{
    QList<QGraphicsItem*> itemlist = view->items(pos);
    return filterForCurrentContext(itemlist);
}

QList<QGraphicsItem*> QDeclarativeViewObserverPrivate::selectableItems(const QRectF &sceneRect, Qt::ItemSelectionMode selectionMode) const
{
    QList<QGraphicsItem*> itemlist = view->scene()->items(sceneRect, selectionMode);

    return filterForCurrentContext(itemlist);
}

void QDeclarativeViewObserverPrivate::_q_changeToSingleSelectTool()
{
    currentToolMode = Constants::SelectionToolMode;
    selectionTool->setRubberbandSelectionMode(false);

    changeToSelectTool();

    emit q->selectToolActivated();
    debugService->setCurrentTool(Constants::SelectionToolMode);
}

void QDeclarativeViewObserverPrivate::changeToSelectTool()
{
    if (currentTool == selectionTool)
        return;

    currentTool->clear();
    currentTool = selectionTool;
    currentTool->clear();
    currentTool->updateSelectedItems();
}

void QDeclarativeViewObserverPrivate::_q_changeToMarqueeSelectTool()
{
    changeToSelectTool();
    currentToolMode = Constants::MarqueeSelectionToolMode;
    selectionTool->setRubberbandSelectionMode(true);

    emit q->marqueeSelectToolActivated();
    debugService->setCurrentTool(Constants::MarqueeSelectionToolMode);
}

void QDeclarativeViewObserverPrivate::_q_changeToZoomTool()
{
    currentToolMode = Constants::ZoomMode;
    currentTool->clear();
    currentTool = zoomTool;
    currentTool->clear();

    emit q->zoomToolActivated();
    debugService->setCurrentTool(Constants::ZoomMode);
}

void QDeclarativeViewObserverPrivate::_q_changeToColorPickerTool()
{
    if (currentTool == colorPickerTool)
        return;

    currentToolMode = Constants::ColorPickerMode;
    currentTool->clear();
    currentTool = colorPickerTool;
    currentTool->clear();

    emit q->colorPickerActivated();
    debugService->setCurrentTool(Constants::ColorPickerMode);
}

void QDeclarativeViewObserverPrivate::_q_changeContextPathIndex(int index)
{
    subcomponentEditorTool->setContext(index);
}

void QDeclarativeViewObserver::changeAnimationSpeed(qreal slowdownFactor)
{
    data->slowdownFactor = slowdownFactor;

    if (data->slowdownFactor != 0) {
        continueExecution(data->slowdownFactor);
    } else {
        pauseExecution();
    }
}

void QDeclarativeViewObserver::continueExecution(qreal slowdownFactor)
{
    Q_ASSERT(slowdownFactor > 0);

    data->slowdownFactor = slowdownFactor;
    static const qreal animSpeedSnapDelta = 0.01f;

    qreal slowDownFactor = data->slowdownFactor;
    if (qAbs(1.0f - slowDownFactor) < animSpeedSnapDelta) {
        slowDownFactor = 1.0f;
    }

    QDeclarativeDebugHelper::setAnimationSlowDownFactor(slowDownFactor);
    data->executionPaused = false;

    emit executionStarted(data->slowdownFactor);
    data->debugService->setAnimationSpeed(data->slowdownFactor);
}

void QDeclarativeViewObserver::pauseExecution()
{
    QDeclarativeDebugHelper::setAnimationSlowDownFactor(0.0f);
    data->executionPaused = true;

    emit executionPaused();
    data->debugService->setAnimationSpeed(0);
}

void QDeclarativeViewObserverPrivate::_q_applyChangesFromClient()
{

}


QList<QGraphicsItem*> QDeclarativeViewObserverPrivate::filterForSelection(QList<QGraphicsItem*> &itemlist) const
{
    foreach(QGraphicsItem *item, itemlist) {
        if (isEditorItem(item) || !subcomponentEditorTool->isChildOfContext(item))
            itemlist.removeOne(item);
    }

    return itemlist;
}

QList<QGraphicsItem*> QDeclarativeViewObserverPrivate::filterForCurrentContext(QList<QGraphicsItem*> &itemlist) const
{
    foreach(QGraphicsItem *item, itemlist) {

        if (isEditorItem(item) || !subcomponentEditorTool->isDirectChildOfContext(item)) {

            // if we're a child, but not directly, replace with the parent that is directly in context.
            if (QGraphicsItem *contextParent = subcomponentEditorTool->firstChildOfContext(item)) {
                if (contextParent != item) {
                    if (itemlist.contains(contextParent)) {
                        itemlist.removeOne(item);
                    } else {
                        itemlist.replace(itemlist.indexOf(item), contextParent);
                    }
                }
            } else {
                itemlist.removeOne(item);
            }
        }
    }

    return itemlist;
}

bool QDeclarativeViewObserverPrivate::isEditorItem(QGraphicsItem *item) const
{
    return (item->type() == Constants::EditorItemType
         || item->type() == Constants::ResizeHandleItemType
         || item->data(Constants::EditorItemDataKey).toBool());
}

void QDeclarativeViewObserverPrivate::_q_onStatusChanged(QDeclarativeView::Status status)
{
    if (status == QDeclarativeView::Ready) {
        if (view->rootObject()) {
            if (subcomponentEditorTool->contextIndex() != -1)
                subcomponentEditorTool->clear();
            subcomponentEditorTool->pushContext(view->rootObject());
            emit q->executionStarted(1.0f);

        }
        debugService->reloaded();
    }
}

void QDeclarativeViewObserverPrivate::_q_onCurrentObjectsChanged(QList<QObject*> objects)
{
    QList<QGraphicsItem*> items;
    QList<QGraphicsObject*> gfxObjects;
    foreach(QObject *obj, objects) {
        QDeclarativeItem* declarativeItem = qobject_cast<QDeclarativeItem*>(obj);
        if (declarativeItem) {
            items << declarativeItem;
            QGraphicsObject *gfxObj = declarativeItem->toGraphicsObject();
            if (gfxObj)
                gfxObjects << gfxObj;
        }
    }
    if (designModeBehavior) {
        setSelectedItemsForTools(items);
        clearHighlight();
        highlight(gfxObjects, QDeclarativeViewObserverPrivate::IgnoreContext);
    }
}

QString QDeclarativeViewObserver::idStringForObject(QObject *obj)
{
    return QDeclarativeObserverService::instance()->idStringForObject(obj);
}

// adjusts bounding boxes on edges of screen to be visible
QRectF QDeclarativeViewObserver::adjustToScreenBoundaries(const QRectF &boundingRectInSceneSpace)
{
    int marginFromEdge = 1;
    QRectF boundingRect(boundingRectInSceneSpace);
    if (qAbs(boundingRect.left()) - 1 < 2) {
        boundingRect.setLeft(marginFromEdge);
    }

    QRect rect = data->view->rect();
    if (boundingRect.right() >= rect.right() ) {
        boundingRect.setRight(rect.right() - marginFromEdge);
    }

    if (qAbs(boundingRect.top()) - 1 < 2) {
        boundingRect.setTop(marginFromEdge);
    }

    if (boundingRect.bottom() >= rect.bottom() ) {
        boundingRect.setBottom(rect.bottom() - marginFromEdge);
    }

    return boundingRect;
}

QToolBar *QDeclarativeViewObserver::toolbar() const
{
    return data->toolbar;
}

void QDeclarativeViewObserverPrivate::createToolbar()
{
    toolbar = new QmlToolbar(q->declarativeView());
    QObject::connect(q, SIGNAL(selectedColorChanged(QColor)), toolbar, SLOT(setColorBoxColor(QColor)));

    QObject::connect(q, SIGNAL(designModeBehaviorChanged(bool)), toolbar, SLOT(setDesignModeBehavior(bool)));

    QObject::connect(toolbar, SIGNAL(designModeBehaviorChanged(bool)), q, SLOT(setDesignModeBehavior(bool)));
    QObject::connect(toolbar, SIGNAL(animationSpeedChanged(qreal)), q, SLOT(changeAnimationSpeed(qreal)));
    QObject::connect(toolbar, SIGNAL(colorPickerSelected()), q, SLOT(_q_changeToColorPickerTool()));
    QObject::connect(toolbar, SIGNAL(zoomToolSelected()), q, SLOT(_q_changeToZoomTool()));
    QObject::connect(toolbar, SIGNAL(selectToolSelected()), q, SLOT(_q_changeToSingleSelectTool()));
    QObject::connect(toolbar, SIGNAL(marqueeSelectToolSelected()), q, SLOT(_q_changeToMarqueeSelectTool()));

    QObject::connect(toolbar, SIGNAL(applyChangesFromQmlFileSelected()), q, SLOT(_q_applyChangesFromClient()));

    QObject::connect(q, SIGNAL(executionStarted(qreal)), toolbar, SLOT(setAnimationSpeed(qreal)));
    QObject::connect(q, SIGNAL(executionPaused()), toolbar, SLOT(setAnimationSpeed()));

    QObject::connect(q, SIGNAL(selectToolActivated()), toolbar, SLOT(activateSelectTool()));

    // disabled features
    //connect(d->m_toolbar, SIGNAL(applyChangesToQmlFileSelected()), SLOT(applyChangesToClient()));
    //connect(q, SIGNAL(resizeToolActivated()), d->m_toolbar, SLOT(activateSelectTool()));
    //connect(q, SIGNAL(moveToolActivated()),   d->m_toolbar, SLOT(activateSelectTool()));

    QObject::connect(q, SIGNAL(colorPickerActivated()), toolbar, SLOT(activateColorPicker()));
    QObject::connect(q, SIGNAL(zoomToolActivated()), toolbar, SLOT(activateZoom()));
    QObject::connect(q, SIGNAL(marqueeSelectToolActivated()), toolbar, SLOT(activateMarqueeSelectTool()));
}


} //namespace QmlJSDebugger

#include <moc_qdeclarativeviewobserver.cpp>