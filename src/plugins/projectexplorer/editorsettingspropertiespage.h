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

#ifndef EDITORSETTINGSPROPERTIESPAGE_H
#define EDITORSETTINGSPROPERTIESPAGE_H

#include "iprojectproperties.h"
#include "ui_editorsettingspropertiespage.h"

namespace ProjectExplorer {

class EditorConfiguration;

namespace Internal {

const char * const EDITORSETTINGS_PANEL_ID("ProjectExplorer.EditorSettingsPanel");

class EditorSettingsPanelFactory : public IProjectPanelFactory
{
public:
    QString id() const;
    QString displayName() const;
    IPropertiesPanel *createPanel(Project *project);
    bool supports(Project *project);
};

class EditorSettingsWidget;

class EditorSettingsPanel : public IPropertiesPanel
{
public:
    EditorSettingsPanel(Project *project);
    ~EditorSettingsPanel();
    QString displayName() const;
    QWidget *widget() const;
    QIcon icon() const;

private:
    EditorSettingsWidget *m_widget;
    const QIcon m_icon;
};

class EditorSettingsWidget : public QWidget
{
    Q_OBJECT
public:
    EditorSettingsWidget(Project *project);

private slots:
    void setGlobalSettingsEnabled(bool enabled);
    void restoreDefaultValues();

private:
    void settingsToUi(const EditorConfiguration *config);

    Ui::EditorSettingsPropertiesPage m_ui;
    Project *m_project;
};

} // namespace Internal
} // namespace ProjectExplorer

#endif // EDITORSETTINGSPROPERTIESPAGE_H
