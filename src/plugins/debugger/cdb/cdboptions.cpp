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

#include "cdboptions.h"

#include <QtCore/QSettings>

static const char settingsGroupC[] = "CDB2";
static const char symbolPathsKeyC[] = "SymbolPaths";
static const char sourcePathsKeyC[] = "SourcePaths";
static const char breakEventKeyC[] = "BreakEvent";
static const char additionalArgumentsKeyC[] = "AdditionalArguments";

namespace Debugger {
namespace Internal {

CdbOptions::CdbOptions()
{
}

QString CdbOptions::settingsGroup()
{
    return QLatin1String(settingsGroupC);
}

void CdbOptions::clear()
{
    symbolPaths.clear();
    sourcePaths.clear();
}

QStringList CdbOptions::oldEngineSymbolPaths(const QSettings *s)
{
    return s->value(QLatin1String("CDB/SymbolPaths")).toStringList();
}

void CdbOptions::fromSettings(QSettings *s)
{
    clear();
    const QString keyRoot = QLatin1String(settingsGroupC) + QLatin1Char('/');
    additionalArguments = s->value(keyRoot + QLatin1String(additionalArgumentsKeyC), QString()).toString();
    symbolPaths = s->value(keyRoot + QLatin1String(symbolPathsKeyC), QStringList()).toStringList();
    sourcePaths = s->value(keyRoot + QLatin1String(sourcePathsKeyC), QStringList()).toStringList();
    breakEvents = s->value(keyRoot + QLatin1String(breakEventKeyC), QStringList()).toStringList();
}

void CdbOptions::toSettings(QSettings *s) const
{
    s->beginGroup(QLatin1String(settingsGroupC));
    s->setValue(QLatin1String(symbolPathsKeyC), symbolPaths);
    s->setValue(QLatin1String(sourcePathsKeyC), sourcePaths);
    s->setValue(QLatin1String(breakEventKeyC), breakEvents);
    s->setValue(QLatin1String(additionalArgumentsKeyC), additionalArguments);
    s->endGroup();
}

bool CdbOptions::equals(const CdbOptions &rhs) const
{
    return additionalArguments == rhs.additionalArguments
            && symbolPaths == rhs.symbolPaths
            && sourcePaths == rhs.sourcePaths
            && breakEvents == rhs.breakEvents;
}

} // namespace Internal
} // namespace Debugger
