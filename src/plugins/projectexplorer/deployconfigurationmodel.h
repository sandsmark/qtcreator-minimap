/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2011 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef PROJECTEXPLORER_DEPLOYCONFIGURATIONMODEL_H
#define PROJECTEXPLORER_DEPLOYCONFIGURATIONMODEL_H

#include <QtCore/QAbstractItemModel>

namespace ProjectExplorer {

class Target;
class DeployConfiguration;

/*! A model to represent the run configurations of a target.
    To be used in for the drop down of comboboxes
    Does automatically adjust itself to added and removed RunConfigurations
*/
class DeployConfigurationModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit DeployConfigurationModel(Target *target, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    DeployConfiguration *deployConfigurationAt(int i);
    DeployConfiguration *deployConfigurationFor(const QModelIndex &idx);
    QModelIndex indexFor(DeployConfiguration *rc);
private slots:
    void addedDeployConfiguration(ProjectExplorer::DeployConfiguration*);
    void removedDeployConfiguration(ProjectExplorer::DeployConfiguration*);
    void displayNameChanged();
private:
    Target *m_target;
    QList<DeployConfiguration *> m_deployConfigurations;
};

} // namespace ProjectExplorer

#endif // PROJECTEXPLORER_DEPLOYCONFIGURATIONMODEL_H
