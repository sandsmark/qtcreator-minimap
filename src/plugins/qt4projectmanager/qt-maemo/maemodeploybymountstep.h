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

#ifndef MAEMODEPLOYBYMOUNTSTEP_H
#define MAEMODEPLOYBYMOUNTSTEP_H

#include "abstractmaemodeploystep.h"

#include "maemodeployable.h"
#include "maemomountspecification.h"

namespace Qt4ProjectManager {
namespace Internal {
class AbstractMaemoPackageInstaller;
class MaemoDeploymentMounter;
class MaemoRemoteCopyFacility;

class AbstractMaemoDeployByMountStep : public AbstractMaemoDeployStep
{
    Q_OBJECT
public:

private slots:
    void handleMounted();
    void handleUnmounted();
    void handleMountError(const QString &errorMsg);
    void handleMountDebugOutput(const QString &output);
    void handleInstallationFinished(const QString &errorMsg);

protected:
    AbstractMaemoDeployByMountStep(ProjectExplorer::BuildStepList *bc,
        const QString &id);
    AbstractMaemoDeployByMountStep(ProjectExplorer::BuildStepList *bc,
        AbstractMaemoDeployByMountStep *other);

    QString deployMountPoint() const;

private:
    enum ExtendedState { Inactive, Mounting, Installing, Unmounting };

    virtual void startInternal();
    virtual void stopInternal();

    virtual QList<MaemoMountSpecification> mountSpecifications() const=0;
    virtual void deploy()=0;
    virtual void cancelInstallation()=0;
    virtual void handleInstallationSuccess()=0;

    void ctor();
    void mount();
    void unmount();
    void setFinished();

    MaemoDeploymentMounter *m_mounter;
    ExtendedState m_extendedState;
};


class MaemoMountAndInstallDeployStep : public AbstractMaemoDeployByMountStep
{
    Q_OBJECT
public:
    MaemoMountAndInstallDeployStep(ProjectExplorer::BuildStepList *bc);
    MaemoMountAndInstallDeployStep(ProjectExplorer::BuildStepList *bc,
        MaemoMountAndInstallDeployStep *other);

    static const QString Id;
    static const QString DisplayName;
private:
    virtual bool isDeploymentPossibleInternal(QString &whynot) const;
    virtual bool isDeploymentNeeded(const QString &hostName) const;

    virtual QList<MaemoMountSpecification> mountSpecifications() const;
    virtual void deploy();
    virtual void cancelInstallation();
    virtual void handleInstallationSuccess();

    void ctor();

    AbstractMaemoPackageInstaller *m_installer;
};


class MaemoMountAndCopyDeployStep : public AbstractMaemoDeployByMountStep
{
    Q_OBJECT
public:
    MaemoMountAndCopyDeployStep(ProjectExplorer::BuildStepList *bc);
    MaemoMountAndCopyDeployStep(ProjectExplorer::BuildStepList *bc,
        MaemoMountAndCopyDeployStep *other);

    static const QString Id;
    static const QString DisplayName;
private:
    virtual bool isDeploymentPossibleInternal(QString &whynot) const;
    virtual bool isDeploymentNeeded(const QString &hostName) const;

    virtual QList<MaemoMountSpecification> mountSpecifications() const;
    virtual void deploy();
    virtual void cancelInstallation();
    virtual void handleInstallationSuccess();

    void ctor();
    Q_SLOT void handleFileCopied(const MaemoDeployable &deployable);

    MaemoRemoteCopyFacility *m_copyFacility;
    mutable QList<MaemoDeployable> m_filesToCopy;
};

} // namespace Internal
} // namespace Qt4ProjectManager

#endif // MAEMODEPLOYBYMOUNTSTEP_H
