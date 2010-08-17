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

#ifndef S60DEPLOYCONFIGURATIONWIDGET_H
#define S60DEPLOYCONFIGURATIONWIDGET_H

#include <QtGui/QWidget>
#include <QtCore/QPointer>

#include <projectexplorer/deployconfiguration.h>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QComboBox;
class QToolButton;
class QCheckBox;
QT_END_NAMESPACE

namespace Utils {
    class DetailsWidget;
}

namespace trk {
    class Launcher;
}

namespace SymbianUtils {
class SymbianDevice;
}

namespace Qt4ProjectManager {
namespace Internal {

class S60DeployConfiguration;

/* Configuration widget for S60 devices on serial ports that are
 * provided by the SerialDeviceLister class. Has an info/test
 * button connecting to the device and showing info. */
class S60DeployConfigurationWidget : public ProjectExplorer::DeployConfigurationWidget
{
    Q_OBJECT
public:
    explicit S60DeployConfigurationWidget(QWidget *parent = 0);
    ~S60DeployConfigurationWidget();

    void init(ProjectExplorer::DeployConfiguration *dc);

private slots:
    void updateTargetInformation();
    void updateInstallationDrives();
    void updateSerialDevices();
    void setInstallationDrive(int index);
    void setSerialPort(int index);
    void updateDeviceInfo();
    void clearDeviceInfo();
    void slotLauncherStateChanged(int);
    void slotWaitingForTrkClosed();
    void silentInstallChanged(int);

private:
    inline SymbianUtils::SymbianDevice device(int i) const;
    inline SymbianUtils::SymbianDevice currentDevice() const;

    void setDeviceInfoLabel(const QString &message, bool isError = false);

    S60DeployConfiguration *m_deployConfiguration;
    Utils::DetailsWidget *m_detailsWidget;
    QComboBox *m_serialPortsCombo;
    QLabel *m_sisFileLabel;
    QToolButton *m_deviceInfoButton;
    QLabel *m_deviceInfoDescriptionLabel;
    QLabel *m_deviceInfoLabel;
    QPointer<trk::Launcher> m_infoLauncher;
    QComboBox *m_installationDriveCombo;
    QCheckBox *m_silentInstallCheckBox;
};

} // namespace Internal
} // namespace Qt4ProjectManager

#endif // S60DEPLOYCONFIGURATIONWIDGET_H