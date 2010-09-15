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

#ifndef QDECLARATIVEVIEWOBSERVER_H
#define QDECLARATIVEVIEWOBSERVER_H

#include "qmljsdebugger_global.h"
#include "qmlviewerconstants.h"
#include <qdeclarativeview.h>
#include <QWeakPointer>

QT_FORWARD_DECLARE_CLASS(QDeclarativeItem);
QT_FORWARD_DECLARE_CLASS(QMouseEvent);
QT_FORWARD_DECLARE_CLASS(QToolBar);

namespace QmlViewer {

class CrumblePath;
class QDeclarativeViewObserverPrivate;

class QMLJSDEBUGGER_EXPORT QDeclarativeViewObserver : public QObject
{
    Q_OBJECT
public:

    explicit QDeclarativeViewObserver(QDeclarativeView *view, QObject *parent = 0);
    ~QDeclarativeViewObserver();

    void setSelectedItems(QList<QGraphicsItem *> items);
    QList<QGraphicsItem *> selectedItems();

    QDeclarativeView *declarativeView();

    QToolBar *toolbar() const;
    static QString idStringForObject(QObject *obj);
    QRectF adjustToScreenBoundaries(const QRectF &boundingRectInSceneSpace);
    void setDebugMode(bool isDebugMode);

public Q_SLOTS:
    void setDesignModeBehavior(bool value);
    bool designModeBehavior();

    void changeAnimationSpeed(qreal slowdownFactor);
    void continueExecution(qreal slowdownFactor = 1.0f);
    void pauseExecution();

    void setInspectorContext(int contextIndex);

Q_SIGNALS:
    void designModeBehaviorChanged(bool inDesignMode);
    void reloadRequested();
    void marqueeSelectToolActivated();
    void selectToolActivated();
    void zoomToolActivated();
    void colorPickerActivated();
    void selectedColorChanged(const QColor &color);

    void executionStarted(qreal slowdownFactor);
    void executionPaused();

    void inspectorContextCleared();
    void inspectorContextPushed(const QString &contextTitle);
    void inspectorContextPopped();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

    bool leaveEvent(QEvent *);
    bool mousePressEvent(QMouseEvent *event);
    bool mouseMoveEvent(QMouseEvent *event);
    bool mouseReleaseEvent(QMouseEvent *event);
    bool keyPressEvent(QKeyEvent *event);
    bool keyReleaseEvent(QKeyEvent *keyEvent);
    bool mouseDoubleClickEvent(QMouseEvent *event);
    bool wheelEvent(QWheelEvent *event);

    void setSelectedItemsForTools(QList<QGraphicsItem *> items);

private:
    Q_DISABLE_COPY(QDeclarativeViewObserver)
    Q_PRIVATE_SLOT(d_func(), void _q_reloadView())
    Q_PRIVATE_SLOT(d_func(), void _q_onStatusChanged(QDeclarativeView::Status))
    Q_PRIVATE_SLOT(d_func(), void _q_onCurrentObjectsChanged(QList<QObject*>))
    Q_PRIVATE_SLOT(d_func(), void _q_applyChangesFromClient())
    Q_PRIVATE_SLOT(d_func(), void _q_createQmlObject(const QString &, QObject *, const QStringList &, const QString &))
    Q_PRIVATE_SLOT(d_func(), void _q_reparentQmlObject(QObject *, QObject *))
    Q_PRIVATE_SLOT(d_func(), void _q_changeToSingleSelectTool())
    Q_PRIVATE_SLOT(d_func(), void _q_changeToMarqueeSelectTool())
    Q_PRIVATE_SLOT(d_func(), void _q_changeToZoomTool())
    Q_PRIVATE_SLOT(d_func(), void _q_changeToColorPickerTool())
    Q_PRIVATE_SLOT(d_func(), void _q_changeContextPathIndex(int index))
    Q_PRIVATE_SLOT(d_func(), void _q_clearComponentCache());

    inline QDeclarativeViewObserverPrivate *d_func() { return data.data(); }
    QScopedPointer<QDeclarativeViewObserverPrivate> data;
    friend class QDeclarativeViewObserverPrivate;
    friend class AbstractFormEditorTool;

};

} //namespace QmlViewer

#endif // QDECLARATIVEVIEWOBSERVER_H