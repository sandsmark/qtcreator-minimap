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

#include "cmakeeditor.h"

#include "cmakehighlighter.h"
#include "cmakeeditorfactory.h"
#include "cmakeprojectconstants.h"

#include <texteditor/fontsettings.h>
#include <texteditor/texteditoractionhandler.h>
#include <texteditor/texteditorconstants.h>
#include <texteditor/texteditorsettings.h>

#include <QtCore/QFileInfo>

using namespace CMakeProjectManager;
using namespace CMakeProjectManager::Internal;

//
// ProFileEditorEditable
//

CMakeEditor::CMakeEditor(CMakeEditorWidget *editor)
  : BaseTextEditor(editor),
    m_context(CMakeProjectManager::Constants::C_CMAKEEDITOR,
              TextEditor::Constants::C_TEXTEDITOR)
{ }

Core::Context CMakeEditor::context() const
{
    return m_context;
}

Core::IEditor *CMakeEditor::duplicate(QWidget *parent)
{
    CMakeEditorWidget *w = qobject_cast<CMakeEditorWidget*>(widget());
    CMakeEditorWidget *ret = new CMakeEditorWidget(parent, w->factory(), w->actionHandler());
    ret->duplicateFrom(w);
    TextEditor::TextEditorSettings::instance()->initializeEditor(ret);
    return ret->editor();
}

QString CMakeEditor::id() const
{
    return QLatin1String(CMakeProjectManager::Constants::CMAKE_EDITOR_ID);
}

//
// CMakeEditor
//

CMakeEditorWidget::CMakeEditorWidget(QWidget *parent, CMakeEditorFactory *factory, TextEditor::TextEditorActionHandler *ah)
    : BaseTextEditorWidget(parent), m_factory(factory), m_ah(ah)
{
    CMakeDocument *doc = new CMakeDocument();
    doc->setMimeType(QLatin1String(CMakeProjectManager::Constants::CMAKEMIMETYPE));
    setBaseTextDocument(doc);

    ah->setupActions(this);

    baseTextDocument()->setSyntaxHighlighter(new CMakeHighlighter);
}

CMakeEditorWidget::~CMakeEditorWidget()
{
}

TextEditor::BaseTextEditor *CMakeEditorWidget::createEditor()
{
    return new CMakeEditor(this);
}

void CMakeEditorWidget::setFontSettings(const TextEditor::FontSettings &fs)
{
    TextEditor::BaseTextEditorWidget::setFontSettings(fs);
    CMakeHighlighter *highlighter = qobject_cast<CMakeHighlighter*>(baseTextDocument()->syntaxHighlighter());
    if (!highlighter)
        return;

    static QVector<QString> categories;
    if (categories.isEmpty()) {
        categories << QLatin1String(TextEditor::Constants::C_LABEL)  // variables
                << QLatin1String(TextEditor::Constants::C_LINK)   // functions
                << QLatin1String(TextEditor::Constants::C_COMMENT)
                << QLatin1String(TextEditor::Constants::C_STRING)
                << QLatin1String(TextEditor::Constants::C_VISUAL_WHITESPACE);
    }

    const QVector<QTextCharFormat> formats = fs.toTextCharFormats(categories);
    highlighter->setFormats(formats.constBegin(), formats.constEnd());
    highlighter->rehighlight();
}

//
// ProFileDocument
//

CMakeDocument::CMakeDocument()
    : TextEditor::BaseTextDocument()
{
}

QString CMakeDocument::defaultPath() const
{
    QFileInfo fi(fileName());
    return fi.absolutePath();
}

QString CMakeDocument::suggestedFileName() const
{
    QFileInfo fi(fileName());
    return fi.fileName();
}
