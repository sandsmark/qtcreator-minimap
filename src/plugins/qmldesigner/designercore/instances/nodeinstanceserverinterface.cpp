/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** No Commercial Usage
**
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
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
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**************************************************************************/

#include "nodeinstanceserverinterface.h"
#include <qmetatype.h>

#include "propertyabstractcontainer.h"
#include "propertyvaluecontainer.h"
#include "propertybindingcontainer.h"
#include "instancecontainer.h"
#include "createinstancescommand.h"
#include "createscenecommand.h"
#include "changevaluescommand.h"
#include "changebindingscommand.h"
#include "changefileurlcommand.h"
#include "removeinstancescommand.h"
#include "clearscenecommand.h"
#include "removepropertiescommand.h"
#include "reparentinstancescommand.h"
#include "changeidscommand.h"
#include "changestatecommand.h"
#include "completecomponentcommand.h"
#include "addimportcontainer.h"

#include "informationchangedcommand.h"
#include "pixmapchangedcommand.h"
#include "valueschangedcommand.h"
#include "addimportcommand.h"
#include "childrenchangedcommand.h"
#include "imagecontainer.h"
#include "statepreviewimagechangedcommand.h"
#include "componentcompletedcommand.h"
#include "synchronizecommand.h"


namespace QmlDesigner {

static bool isRegistered=false;

NodeInstanceServerInterface::NodeInstanceServerInterface(QObject *parent) :
    QObject(parent)
{
    registerCommands();
}

void NodeInstanceServerInterface::registerCommands()
{
    if (isRegistered)
        return;

    isRegistered = true;

    qRegisterMetaType<CreateInstancesCommand>("CreateInstancesCommand");
    qRegisterMetaTypeStreamOperators<CreateInstancesCommand>("CreateInstancesCommand");

    qRegisterMetaType<ClearSceneCommand>("ClearSceneCommand");
    qRegisterMetaTypeStreamOperators<ClearSceneCommand>("ClearSceneCommand");

    qRegisterMetaType<CreateSceneCommand>("CreateSceneCommand");
    qRegisterMetaTypeStreamOperators<CreateSceneCommand>("CreateSceneCommand");

    qRegisterMetaType<ChangeBindingsCommand>("ChangeBindingsCommand");
    qRegisterMetaTypeStreamOperators<ChangeBindingsCommand>("ChangeBindingsCommand");

    qRegisterMetaType<ChangeValuesCommand>("ChangeValuesCommand");
    qRegisterMetaTypeStreamOperators<ChangeValuesCommand>("ChangeValuesCommand");

    qRegisterMetaType<ChangeFileUrlCommand>("ChangeFileUrlCommand");
    qRegisterMetaTypeStreamOperators<ChangeFileUrlCommand>("ChangeFileUrlCommand");

    qRegisterMetaType<ChangeStateCommand>("ChangeStateCommand");
    qRegisterMetaTypeStreamOperators<PropertyAbstractContainer>("ChangeStateCommand");

    qRegisterMetaType<RemoveInstancesCommand>("RemoveInstancesCommand");
    qRegisterMetaTypeStreamOperators<RemoveInstancesCommand>("RemoveInstancesCommand");

    qRegisterMetaType<RemovePropertiesCommand>("RemovePropertiesCommand");
    qRegisterMetaTypeStreamOperators<RemovePropertiesCommand>("RemovePropertiesCommand");

    qRegisterMetaType<ReparentInstancesCommand>("ReparentInstancesCommand");
    qRegisterMetaTypeStreamOperators<ReparentInstancesCommand>("ReparentInstancesCommand");

    qRegisterMetaType<ChangeIdsCommand>("ChangeIdsCommand");
    qRegisterMetaTypeStreamOperators<ChangeIdsCommand>("ChangeIdsCommand");

    qRegisterMetaType<ChangeStateCommand>("ChangeStateCommand");
    qRegisterMetaTypeStreamOperators<ChangeStateCommand>("ChangeStateCommand");

    qRegisterMetaType<InformationChangedCommand>("InformationChangedCommand");
    qRegisterMetaTypeStreamOperators<InformationChangedCommand>("InformationChangedCommand");

    qRegisterMetaType<ValuesChangedCommand>("ValuesChangedCommand");
    qRegisterMetaTypeStreamOperators<ValuesChangedCommand>("ValuesChangedCommand");

    qRegisterMetaType<PixmapChangedCommand>("PixmapChangedCommand");
    qRegisterMetaTypeStreamOperators<PixmapChangedCommand>("PixmapChangedCommand");

    qRegisterMetaType<InformationContainer>("InformationContainer");
    qRegisterMetaTypeStreamOperators<InformationContainer>("InformationContainer");

    qRegisterMetaType<PropertyValueContainer>("PropertyValueContainer");
    qRegisterMetaTypeStreamOperators<PropertyValueContainer>("PropertyValueContainer");

    qRegisterMetaType<PropertyBindingContainer>("PropertyBindingContainer");
    qRegisterMetaTypeStreamOperators<PropertyBindingContainer>("PropertyBindingContainer");

    qRegisterMetaType<PropertyAbstractContainer>("PropertyAbstractContainer");
    qRegisterMetaTypeStreamOperators<PropertyAbstractContainer>("PropertyAbstractContainer");

    qRegisterMetaType<InstanceContainer>("InstanceContainer");
    qRegisterMetaTypeStreamOperators<InstanceContainer>("InstanceContainer");

    qRegisterMetaType<IdContainer>("IdContainer");
    qRegisterMetaTypeStreamOperators<IdContainer>("IdContainer");

    qRegisterMetaType<AddImportCommand>("AddImportCommand");
    qRegisterMetaTypeStreamOperators<AddImportCommand>("AddImportCommand");

    qRegisterMetaType<ChildrenChangedCommand>("ChildrenChangedCommand");
    qRegisterMetaTypeStreamOperators<ChildrenChangedCommand>("ChildrenChangedCommand");

    qRegisterMetaType<ImageContainer>("ImageContainer");
    qRegisterMetaTypeStreamOperators<ImageContainer>("ImageContainer");

    qRegisterMetaType<StatePreviewImageChangedCommand>("StatePreviewImageChangedCommand");
    qRegisterMetaTypeStreamOperators<StatePreviewImageChangedCommand>("StatePreviewImageChangedCommand");

    qRegisterMetaType<CompleteComponentCommand>("CompleteComponentCommand");
    qRegisterMetaTypeStreamOperators<CompleteComponentCommand>("CompleteComponentCommand");

    qRegisterMetaType<ComponentCompletedCommand>("ComponentCompletedCommand");
    qRegisterMetaTypeStreamOperators<ComponentCompletedCommand>("ComponentCompletedCommand");

    qRegisterMetaType<AddImportContainer>("AddImportContainer");
    qRegisterMetaTypeStreamOperators<AddImportContainer>("AddImportContainer");

    qRegisterMetaType<SynchronizeCommand>("SynchronizeCommand");
    qRegisterMetaTypeStreamOperators<SynchronizeCommand>("SynchronizeCommand");
}

}
