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

#include "breakpoint.h"

#include <QtCore/QByteArray>
#include <QtCore/QDebug>

namespace Debugger {
namespace Internal {

//////////////////////////////////////////////////////////////////
//
// BreakpointParameters
//
//////////////////////////////////////////////////////////////////

/*!
    \class Debugger::Internal::BreakpointParameters

    Data type holding the parameters of a breakpoint.
*/

BreakpointParameters::BreakpointParameters(BreakpointType t)
  : type(t), enabled(true), pathUsage(BreakpointPathUsageEngineDefault),
    ignoreCount(0), lineNumber(0), address(0), size(0),
    bitpos(0), bitsize(0), threadSpec(-1),
    tracepoint(false)
{}

bool BreakpointParameters::equals(const BreakpointParameters &rhs) const
{
    return type == rhs.type
        && enabled == rhs.enabled
        && pathUsage == rhs.pathUsage
        && fileName == rhs.fileName
        && conditionsMatch(rhs.condition)
        && ignoreCount == rhs.ignoreCount
        && lineNumber == rhs.lineNumber
        && address == rhs.address
        && threadSpec == rhs.threadSpec
        && functionName == rhs.functionName
        && tracepoint == rhs.tracepoint
        && module == rhs.module
        && command == rhs.command;
}

bool BreakpointParameters::conditionsMatch(const QByteArray &other) const
{
    // Some versions of gdb "beautify" the passed condition.
    QByteArray s1 = condition;
    s1.replace(' ', "");
    QByteArray s2 = other;
    s2.replace(' ', "");
    return s1 == s2;
}

QString BreakpointParameters::toString() const
{
    QString result;
    QTextStream ts(&result);
    ts << " FileName: " << fileName;
    ts << " Condition: " << condition;
    ts << " IgnoreCount: " << ignoreCount;
    ts << " LineNumber: " << lineNumber;
    ts << " Address: " << address;
    ts << " FunctionName: " << functionName;
    ts << " PathUsage: " << pathUsage;
    ts << " Tracepoint: " << tracepoint;
    ts << " Module: " << module;
    ts << " Command: " << command;
    return result;
}

//////////////////////////////////////////////////////////////////
//
// BreakpointResponse
//
//////////////////////////////////////////////////////////////////

/*!
    \class Debugger::Internal::BreakpointResponse

    This is what debuggers produce in response to the attempt to
    insert a breakpoint. The data might differ from the requested bits.
*/

BreakpointResponse::BreakpointResponse()
    : number(0), pending(true), multiple(false), correctedLineNumber(0)
{}

QString BreakpointResponse::toString() const
{
    QString result;
    QTextStream ts(&result);
    ts << " Number: " << number;
    ts << " Pending: " << pending;
    ts << " FullName: " << fullName;
    ts << " Multiple: " << multiple;
    ts << " Extra: " << extra;
    ts << " CorrectedLineNumber: " << correctedLineNumber;
    return result + BreakpointParameters::toString();
}

void BreakpointResponse::fromParameters(const BreakpointParameters &p)
{
    BreakpointParameters::operator=(p);
    number = 0;
    fullName.clear();
    multiple = false;
    extra.clear();
    correctedLineNumber = 0;
}

} // namespace Internal
} // namespace Debugger
