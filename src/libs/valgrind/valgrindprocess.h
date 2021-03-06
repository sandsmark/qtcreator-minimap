/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2011 Nokia Corporation and/or its subsidiary(-ies).
**
** Author: Milian Wolff, KDAB (milian.wolff@kdab.com)
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

#ifndef VALGRIND_RUNNER_P_H
#define VALGRIND_RUNNER_P_H

#include <utils/qtcprocess.h>

namespace Valgrind {
namespace Internal {

/**
 * Abstract process that can be subclassed to supply local and remote valgrind runs
 */
class ValgrindProcess : public QObject
{
    Q_OBJECT
public:
    explicit ValgrindProcess(QObject *parent = 0);
    virtual ~ValgrindProcess();

    virtual bool isRunning() const = 0;

    virtual void run(const QString &valgrindExecutable, const QStringList &valgrindArguments,
                     const QString &debuggeeExecutable, const QString &debuggeeArguments) = 0;
    virtual void close() = 0;

    virtual QString errorString() const = 0;
    virtual QProcess::ProcessError error() const = 0;

    virtual void setProcessChannelMode(QProcess::ProcessChannelMode mode) = 0;
    virtual void setWorkingDirectory(const QString &path) = 0;
    virtual void setEnvironment(const Utils::Environment &environment) = 0;

signals:
    void started();
    void finished(int, QProcess::ExitStatus);
    void error(QProcess::ProcessError);
    void standardOutputReceived(const QByteArray &);
    void standardErrorReceived(const QByteArray &);
};

/**
 * Run valgrind on the local machine
 */
class LocalValgrindProcess : public ValgrindProcess
{
    Q_OBJECT

public:
    explicit LocalValgrindProcess(QObject *parent = 0);
    virtual ~LocalValgrindProcess();

    virtual bool isRunning() const;

    virtual void run(const QString &valgrindExecutable, const QStringList &valgrindArguments,
                     const QString &debuggeeExecutable, const QString &debuggeeArguments);
    virtual void close();

    virtual QString errorString() const;
    QProcess::ProcessError error() const;

    virtual void setProcessChannelMode(QProcess::ProcessChannelMode mode);
    virtual void setWorkingDirectory(const QString &path);
    virtual void setEnvironment(const Utils::Environment &environment);

    Q_PID pid() const;

private slots:
    void readyReadStandardError();
    void readyReadStandardOutput();

private:
    Utils::QtcProcess m_process;
};

// remote support will be supplied later

}
}

#endif // VALGRIND_RUNNER_P_H
