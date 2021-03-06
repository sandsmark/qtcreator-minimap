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

#include "s60emulatorrunconfiguration.h"

#include "qt4project.h"
#include "qt4target.h"
#include "s60manager.h"
#include "qt4symbiantarget.h"
#include "qt4projectmanagerconstants.h"
#include "qtoutputformatter.h"

#include <utils/qtcassert.h>
#include <utils/detailswidget.h>

#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QFormLayout>

using namespace ProjectExplorer;
using namespace Qt4ProjectManager;
using namespace Qt4ProjectManager::Internal;

namespace {
const char * const S60_EMULATOR_RC_ID("Qt4ProjectManager.S60EmulatorRunConfiguration");
const char * const S60_EMULATOR_RC_PREFIX("Qt4ProjectManager.S60EmulatorRunConfiguration.");

const char * const PRO_FILE_KEY("Qt4ProjectManager.S60EmulatorRunConfiguration.ProFile");

QString pathFromId(const QString &id)
{
    if (!id.startsWith(QLatin1String(S60_EMULATOR_RC_PREFIX)))
        return QString();
    return id.mid(QString::fromLatin1(S60_EMULATOR_RC_PREFIX).size());
}

QString pathToId(const QString &path)
{
    return QString::fromLatin1(S60_EMULATOR_RC_PREFIX) + path;
}

}

// ======== S60EmulatorRunConfiguration

S60EmulatorRunConfiguration::S60EmulatorRunConfiguration(Qt4BaseTarget *parent, const QString &proFilePath) :
    RunConfiguration(parent, QLatin1String(S60_EMULATOR_RC_ID)),
    m_proFilePath(proFilePath),
    m_validParse(parent->qt4Project()->validParse(proFilePath))
{
    ctor();
}

S60EmulatorRunConfiguration::S60EmulatorRunConfiguration(Qt4BaseTarget *parent, S60EmulatorRunConfiguration *source) :
    RunConfiguration(parent, source),
    m_proFilePath(source->m_proFilePath),
    m_validParse(source->m_validParse)
{
    ctor();
}

void S60EmulatorRunConfiguration::ctor()
{
    if (!m_proFilePath.isEmpty())
        //: S60 emulator run configuration default display name, %1 is base pro-File name
        setDefaultDisplayName(tr("%1 in Symbian Emulator").arg(QFileInfo(m_proFilePath).completeBaseName()));
    else
        //: S60 emulator run configuration default display name (no pro-file name)
        setDefaultDisplayName(tr("Run on Symbian Emulator"));
    Qt4Project *pro = qt4Target()->qt4Project();
    connect(pro, SIGNAL(proFileUpdated(Qt4ProjectManager::Internal::Qt4ProFileNode*,bool)),
            this, SLOT(proFileUpdate(Qt4ProjectManager::Internal::Qt4ProFileNode*,bool)));
    connect(pro, SIGNAL(proFileInvalidated(Qt4ProjectManager::Internal::Qt4ProFileNode *)),
            this, SLOT(proFileInvalidated(Qt4ProjectManager::Internal::Qt4ProFileNode *)));
}


S60EmulatorRunConfiguration::~S60EmulatorRunConfiguration()
{
}

void S60EmulatorRunConfiguration::handleParserState(bool success)
{
    bool enabled = isEnabled();
    m_validParse = success;
    if (enabled != isEnabled()) {
        emit isEnabledChanged(!enabled);
    }
}

void S60EmulatorRunConfiguration::proFileInvalidated(Qt4ProjectManager::Internal::Qt4ProFileNode *pro)
{
    if (m_proFilePath != pro->path())
        return;
    handleParserState(false);
}

void S60EmulatorRunConfiguration::proFileUpdate(Qt4ProjectManager::Internal::Qt4ProFileNode *pro, bool success)
{
    if (m_proFilePath != pro->path())
        return;
    handleParserState(success);
    emit targetInformationChanged();
}

Qt4SymbianTarget *S60EmulatorRunConfiguration::qt4Target() const
{
    return static_cast<Qt4SymbianTarget *>(target());
}

bool S60EmulatorRunConfiguration::isEnabled(ProjectExplorer::BuildConfiguration *configuration) const
{
    if (!m_validParse)
        return false;
    Q_ASSERT(configuration->target() == target());
    Q_ASSERT(target()->id() == Constants::S60_EMULATOR_TARGET_ID);

    const Qt4BuildConfiguration *qt4bc = qobject_cast<const Qt4BuildConfiguration *>(configuration);
    return qt4bc && qt4bc->toolChain();
}

QWidget *S60EmulatorRunConfiguration::createConfigurationWidget()
{
    return new S60EmulatorRunConfigurationWidget(this);
}

ProjectExplorer::OutputFormatter *S60EmulatorRunConfiguration::createOutputFormatter() const
{
    return new QtOutputFormatter(qt4Target()->qt4Project());
}

QVariantMap S60EmulatorRunConfiguration::toMap() const
{
    QVariantMap map(ProjectExplorer::RunConfiguration::toMap());
    const QDir projectDir = QDir(target()->project()->projectDirectory());
    map.insert(QLatin1String(PRO_FILE_KEY), projectDir.relativeFilePath(m_proFilePath));
    return map;
}

bool S60EmulatorRunConfiguration::fromMap(const QVariantMap &map)
{
    const QDir projectDir = QDir(target()->project()->projectDirectory());
    m_proFilePath = projectDir.filePath(map.value(QLatin1String(PRO_FILE_KEY)).toString());

    if (m_proFilePath.isEmpty())
        return false;

    m_validParse = qt4Target()->qt4Project()->validParse(m_proFilePath);

    //: S60 emulator run configuration default display name, %1 is base pro-File name
    setDefaultDisplayName(tr("%1 in Symbian Emulator").arg(QFileInfo(m_proFilePath).completeBaseName()));

    return RunConfiguration::fromMap(map);
}

QString S60EmulatorRunConfiguration::executable() const
{
    Qt4BuildConfiguration *qt4bc = qt4Target()->activeBuildConfiguration();
    QtVersion *qtVersion = qt4bc->qtVersion();
    QString baseDir = qtVersion->systemRoot();
    QString qmakeBuildConfig = "urel";
    if (qt4bc->qmakeBuildConfiguration() & QtVersion::DebugBuild)
        qmakeBuildConfig = "udeb";
    baseDir += "/epoc32/release/winscw/" + qmakeBuildConfig;

    TargetInformation ti = qt4Target()->qt4Project()->rootProjectNode()->targetInformation(m_proFilePath);
    if (!ti.valid)
        return QString();
    QString executable = QDir::toNativeSeparators(QDir::cleanPath(baseDir + QLatin1Char('/') + ti.target));
    executable += QLatin1String(".exe");

    return executable;
}

QString S60EmulatorRunConfiguration::proFilePath() const
{
    return m_proFilePath;
}

// ======== S60EmulatorRunConfigurationWidget

S60EmulatorRunConfigurationWidget::S60EmulatorRunConfigurationWidget(S60EmulatorRunConfiguration *runConfiguration,
                                                                     QWidget *parent)
    : QWidget(parent),
    m_runConfiguration(runConfiguration),
    m_detailsWidget(new Utils::DetailsWidget),
    m_executableLabel(new QLabel(m_runConfiguration->executable()))
{
    m_detailsWidget->setState(Utils::DetailsWidget::NoSummary);
    QVBoxLayout *mainBoxLayout = new QVBoxLayout();
    mainBoxLayout->setMargin(0);
    setLayout(mainBoxLayout);
    mainBoxLayout->addWidget(m_detailsWidget);
    QWidget *detailsContainer = new QWidget;
    m_detailsWidget->setWidget(detailsContainer);

    QFormLayout *detailsFormLayout = new QFormLayout();
    detailsFormLayout->setMargin(0);
    detailsContainer->setLayout(detailsFormLayout);

    detailsFormLayout->addRow(tr("Executable:"), m_executableLabel);

    connect(m_runConfiguration, SIGNAL(targetInformationChanged()),
            this, SLOT(updateTargetInformation()));

    connect(m_runConfiguration, SIGNAL(isEnabledChanged(bool)),
            this, SLOT(runConfigurationEnabledChange(bool)));

    setEnabled(m_runConfiguration->isEnabled());
}

void S60EmulatorRunConfigurationWidget::updateTargetInformation()
{
    m_executableLabel->setText(m_runConfiguration->executable());
}

void S60EmulatorRunConfigurationWidget::runConfigurationEnabledChange(bool enabled)
{
    setEnabled(enabled);
}

// ======== S60EmulatorRunConfigurationFactory

S60EmulatorRunConfigurationFactory::S60EmulatorRunConfigurationFactory(QObject *parent)
    : IRunConfigurationFactory(parent)
{
}

S60EmulatorRunConfigurationFactory::~S60EmulatorRunConfigurationFactory()
{
}

bool S60EmulatorRunConfigurationFactory::canCreate(Target *parent, const QString &id) const
{
    Qt4SymbianTarget *t = qobject_cast<Qt4SymbianTarget *>(parent);
    if (!t ||
        t->id() != QLatin1String(Constants::S60_EMULATOR_TARGET_ID))
        return false;
    return t->qt4Project()->hasApplicationProFile(pathFromId(id));
}

RunConfiguration *S60EmulatorRunConfigurationFactory::create(Target *parent, const QString &id)
{
    if (!canCreate(parent, id))
        return 0;
    Qt4SymbianTarget *t = static_cast<Qt4SymbianTarget *>(parent);
    return new S60EmulatorRunConfiguration(t, pathFromId(id));
}

bool S60EmulatorRunConfigurationFactory::canRestore(Target *parent, const QVariantMap &map) const
{
    Qt4SymbianTarget *t = qobject_cast<Qt4SymbianTarget *>(parent);
    if (!t ||
        t->id() != QLatin1String(Constants::S60_EMULATOR_TARGET_ID))
        return false;
    QString id(ProjectExplorer::idFromMap(map));
    return id == QLatin1String(S60_EMULATOR_RC_ID);
}

RunConfiguration *S60EmulatorRunConfigurationFactory::restore(Target *parent, const QVariantMap &map)
{
    if (!canRestore(parent, map))
        return 0;
    Qt4SymbianTarget *t = static_cast<Qt4SymbianTarget *>(parent);
    S60EmulatorRunConfiguration *rc = new S60EmulatorRunConfiguration(t, QString());
    if (rc->fromMap(map))
        return rc;
    delete rc;
    return 0;
}

bool S60EmulatorRunConfigurationFactory::canClone(Target *parent, RunConfiguration *source) const
{
    return canCreate(parent, source->id());
}

RunConfiguration *S60EmulatorRunConfigurationFactory::clone(Target *parent, RunConfiguration *source)
{
    if (!canClone(parent, source))
        return 0;
    Qt4SymbianTarget *t = static_cast<Qt4SymbianTarget *>(parent);
    return new S60EmulatorRunConfiguration(t, QString());
}

QStringList S60EmulatorRunConfigurationFactory::availableCreationIds(Target *parent) const
{
    Qt4SymbianTarget *t = qobject_cast<Qt4SymbianTarget *>(parent);
    if (!t ||
        t->id() != QLatin1String(Constants::S60_EMULATOR_TARGET_ID))
        return QStringList();

    return t->qt4Project()->applicationProFilePathes(QLatin1String(S60_EMULATOR_RC_PREFIX));
}

QString S60EmulatorRunConfigurationFactory::displayNameForId(const QString &id) const
{
    if (!pathFromId(id).isEmpty())
        return tr("%1 in Symbian Emulator").arg(QFileInfo(pathFromId(id)).completeBaseName());
    return QString();
}

// ======== S60EmulatorRunControl

S60EmulatorRunControl::S60EmulatorRunControl(S60EmulatorRunConfiguration *runConfiguration, QString mode)
    : RunControl(runConfiguration, mode)
{
    // FIXME: This should be configurable!
    Utils::Environment env = runConfiguration->qt4Target()->activeBuildConfiguration()->environment();
    m_applicationLauncher.setEnvironment(env);

    m_executable = runConfiguration->executable();
    connect(&m_applicationLauncher, SIGNAL(applicationError(QString)),
            this, SLOT(slotError(QString)));
    connect(&m_applicationLauncher, SIGNAL(appendMessage(QString, ProjectExplorer::OutputFormat)),
            this, SLOT(slotAppendMessage(QString, ProjectExplorer::OutputFormat)));
    connect(&m_applicationLauncher, SIGNAL(processExited(int)),
            this, SLOT(processExited(int)));
    connect(&m_applicationLauncher, SIGNAL(bringToForegroundRequested(qint64)),
            this, SLOT(bringApplicationToForeground(qint64)));
}

void S60EmulatorRunControl::start()
{
    m_applicationLauncher.start(ApplicationLauncher::Gui, m_executable, QString());
    emit started();

    QString msg = tr("Starting %1...").arg(QDir::toNativeSeparators(m_executable));
    appendMessage(msg, NormalMessageFormat);
}

RunControl::StopResult S60EmulatorRunControl::stop()
{
    m_applicationLauncher.stop();
    return StoppedSynchronously;
}

bool S60EmulatorRunControl::isRunning() const
{
    return m_applicationLauncher.isRunning();
}

void S60EmulatorRunControl::slotError(const QString & err)
{
    appendMessage(err, ErrorMessageFormat);
    emit finished();
}

void S60EmulatorRunControl::slotAppendMessage(const QString &line, OutputFormat format)
{
    static QString prefix = tr("[Qt Message]");
    static int prefixLength = prefix.length();
    int index = line.indexOf(prefix);
    if (index != -1)
        appendMessage(line.mid(index + prefixLength + 1), format);
}

void S60EmulatorRunControl::processExited(int exitCode)
{
    QString msg = tr("%1 exited with code %2");
    appendMessage(msg, exitCode ? ErrorMessageFormat : NormalMessageFormat);
    emit finished();
}
