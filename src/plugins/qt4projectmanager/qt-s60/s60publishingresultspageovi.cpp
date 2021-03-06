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
#include "s60publishingresultspageovi.h"
#include "s60publisherovi.h"
#include "ui_s60publishingresultspageovi.h"

#include <QtGui/QDesktopServices>
#include <QtGui/QAbstractButton>
#include <QtCore/QProcess>

namespace Qt4ProjectManager {
namespace Internal {

S60PublishingResultsPageOvi::S60PublishingResultsPageOvi(S60PublisherOvi *publisher, QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::S60PublishingResultsPageOvi),
  m_publisher(publisher)
{
    ui->setupUi(this);
    connect(m_publisher, SIGNAL(progressReport(QString,QColor)), SLOT(updateResultsPage(QString,QColor)));
}

S60PublishingResultsPageOvi::~S60PublishingResultsPageOvi()
{
    delete ui;
}

void S60PublishingResultsPageOvi::initializePage()
{
    wizard()->setButtonText(QWizard::FinishButton, tr("Open Containing Folder"));
    connect(m_publisher, SIGNAL(succeeded()), SIGNAL(completeChanged()));
    connect(wizard()->button(QWizard::FinishButton), SIGNAL(clicked()), SLOT(openFileLocation()));
    m_publisher->buildSis();
}

bool S60PublishingResultsPageOvi::isComplete() const
{
    return m_publisher->hasSucceeded();
}

void S60PublishingResultsPageOvi::updateResultsPage(const QString& status, QColor c)
{
    QTextCursor cur(ui->resultsTextBrowser->document());
    QTextCharFormat tcf = cur.charFormat();
    tcf.setForeground(c);
    cur.movePosition(QTextCursor::End);
    cur.insertText(status, tcf);
}

void S60PublishingResultsPageOvi::openFileLocation()
{
#ifdef Q_OS_WIN
    QProcess::startDetached("explorer /select,"+ m_publisher->createdSisFilePath());
#else
    QDesktopServices::openUrl(QUrl("file:///" + m_publisher->createdSisFileContainingFolder()));
#endif
}

} // namespace Internal
} // namespace Qt4ProjectManager
