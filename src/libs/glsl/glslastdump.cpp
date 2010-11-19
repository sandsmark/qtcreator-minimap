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

#include "glslastdump.h"
#include <QtCore/QTextStream>

#ifdef Q_CC_GNU
#  include <cxxabi.h>
#endif

using namespace GLSL;

ASTDump::ASTDump(QTextStream &out)
    : out(out), _depth(0)
{
}

void ASTDump::operator()(AST *ast)
{
    _depth = 0;
    accept(ast);
}

bool ASTDump::preVisit(AST *ast)
{
    const char *id = typeid(*ast).name();
#ifdef Q_CC_GNU
    id = abi::__cxa_demangle(id, 0, 0, 0);
#endif
    out << QByteArray(_depth, ' ') << id << endl;
    ++_depth;
    return true;
}

void ASTDump::postVisit(AST *)
{
    --_depth;
}