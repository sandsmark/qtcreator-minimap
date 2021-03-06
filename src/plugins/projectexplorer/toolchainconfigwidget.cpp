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

#include "toolchainconfigwidget.h"
#include "toolchain.h"

#include <utils/qtcassert.h>
#include <utils/pathchooser.h>

#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>

namespace ProjectExplorer {
namespace Internal {

// --------------------------------------------------------------------------
// ToolChainConfigWidgetPrivate
// --------------------------------------------------------------------------

class ToolChainConfigWidgetPrivate
{
public:
    ToolChainConfigWidgetPrivate(ToolChain *tc) :
        m_toolChain(tc), m_debuggerPathChooser(0), m_errorLabel(0)
    {
        Q_ASSERT(tc);
    }

    ToolChain *m_toolChain;
    Utils::PathChooser *m_debuggerPathChooser;
    QLabel *m_errorLabel;
};

} // namespace Internal

// --------------------------------------------------------------------------
// ToolChainConfigWidget
// --------------------------------------------------------------------------

ToolChainConfigWidget::ToolChainConfigWidget(ToolChain *tc) :
    m_d(new Internal::ToolChainConfigWidgetPrivate(tc))
{
}

void ToolChainConfigWidget::setDisplayName(const QString &name)
{
    m_d->m_toolChain->setDisplayName(name);
}

ToolChain *ToolChainConfigWidget::toolChain() const
{
    return m_d->m_toolChain;
}

void ToolChainConfigWidget::emitDirty()
{
    emit dirty(toolChain());
}

void ToolChainConfigWidget::addDebuggerCommandControls(QFormLayout *lt,
                                                       const QStringList &versionArguments)
{
    ensureDebuggerPathChooser(versionArguments);
    lt->addRow(tr("&Debugger:"), m_d->m_debuggerPathChooser);
}

void ToolChainConfigWidget::addDebuggerCommandControls(QGridLayout *lt,
                                                       int row, int column,
                                                       const QStringList &versionArguments)
{
    ensureDebuggerPathChooser(versionArguments);
    QLabel *label = new QLabel(tr("&Debugger:"));
    label->setBuddy(m_d->m_debuggerPathChooser);
    lt->addWidget(label, row, column);
    lt->addWidget(m_d->m_debuggerPathChooser, row, column + 1);
}

void ToolChainConfigWidget::ensureDebuggerPathChooser(const QStringList &versionArguments)
{
    if (m_d->m_debuggerPathChooser)
        return;
    m_d->m_debuggerPathChooser = new Utils::PathChooser;
    m_d->m_debuggerPathChooser->setExpectedKind(Utils::PathChooser::ExistingCommand);
    if (!versionArguments.isEmpty())
        m_d->m_debuggerPathChooser->setCommandVersionArguments(versionArguments);
    connect(m_d->m_debuggerPathChooser, SIGNAL(changed(QString)), this, SLOT(emitDirty()));
}

void ToolChainConfigWidget::addDebuggerAutoDetection(QObject *receiver, const char *autoDetectSlot)
{
    QTC_ASSERT(m_d->m_debuggerPathChooser, return; )
    m_d->m_debuggerPathChooser->addButton(tr("Autodetect"), receiver, autoDetectSlot);
}

QString ToolChainConfigWidget::debuggerCommand() const
{
    QTC_ASSERT(m_d->m_debuggerPathChooser, return QString(); )
    return m_d->m_debuggerPathChooser->path();
}

void ToolChainConfigWidget::setDebuggerCommand(const QString &d)
{
    QTC_ASSERT(m_d->m_debuggerPathChooser, return; )
    m_d->m_debuggerPathChooser->setPath(d);
}

void ToolChainConfigWidget::addErrorLabel(QFormLayout *lt)
{
    if (!m_d->m_errorLabel) {
        m_d->m_errorLabel = new QLabel;
        m_d->m_errorLabel->setVisible(false);
    }
    lt->addRow(m_d->m_errorLabel);
}

void ToolChainConfigWidget::addErrorLabel(QGridLayout *lt, int row, int column, int colSpan)
{
    if (!m_d->m_errorLabel) {
        m_d->m_errorLabel = new QLabel;
        m_d->m_errorLabel->setVisible(false);
    }
    lt->addWidget(m_d->m_errorLabel, row, column, 1, colSpan);
}

void ToolChainConfigWidget::setErrorMessage(const QString &m)
{
    QTC_ASSERT(m_d->m_errorLabel, return; )
    if (m.isEmpty()) {
        clearErrorMessage();
    } else {
        m_d->m_errorLabel->setText(m);
        m_d->m_errorLabel->setStyleSheet(QLatin1String("background-color: \"red\""));
        m_d->m_errorLabel->setVisible(true);
    }
}

void ToolChainConfigWidget::clearErrorMessage()
{
    QTC_ASSERT(m_d->m_errorLabel, return; )
    m_d->m_errorLabel->clear();
    m_d->m_errorLabel->setStyleSheet(QString());
    m_d->m_errorLabel->setVisible(false);
}

} // namespace ProjectExplorer
