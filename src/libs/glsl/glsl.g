---------------------------------------------------------------------------
--
-- This file is part of Qt Creator
--
-- Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
--
-- Contact: Nokia Corporation (qt-info@nokia.com)
--
-- Commercial Usage
--
-- Licensees holding valid Qt Commercial licenses may use this file in
-- accordance with the Qt Commercial License Agreement provided with the
-- Software or, alternatively, in accordance with the terms contained in
-- a written agreement between you and Nokia.
--
-- GNU Lesser General Public License Usage
--
-- Alternatively, this file may be used under the terms of the GNU Lesser
-- General Public License version 2.1 as published by the Free Software
-- Foundation and appearing in the file LICENSE.LGPL included in the
-- packaging of this file.  Please review the following information to
-- ensure the GNU Lesser General Public License version 2.1 requirements
-- will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
--
-- If you are unsure which license is appropriate for your use, please
-- contact the sales department at http://qt.nokia.com/contact.
---------------------------------------------------------------------------

--
-- todo:
--    spelling of XOR_OP and CARET

%decl glslparser.h
%impl glslparser.cpp
%parser GLSLParserTable
%token_prefix T_

%token ADD_ASSIGN "+="
%token AMPERSAND "&"
%token AND_ASSIGN "&="
%token AND_OP "&&"
%token ATTRIBUTE "attribute"
%token BANG "!"
%token BOOL "bool"
%token BREAK "break"
%token BVEC2 "bvec2"
%token BVEC3 "bvec3"
%token BVEC4 "bvec4"
%token CARET "^"
%token CASE "case"
%token CENTROID "centroid"
%token COLON ":"
%token COMMA ","
%token CONST "const"
%token CONTINUE "continue"
%token DASH "-"
%token DEC_OP "--"
%token DEFAULT "default"
%token DISCARD "discard"
%token DIV_ASSIGN "/="
%token DMAT2 "dmat2"
%token DMAT2X2 "dmat2x2"
%token DMAT2X3 "dmat2x3"
%token DMAT2X4 "dmat2x4"
%token DMAT3 "dmat3"
%token DMAT3X2 "dmat3x2"
%token DMAT3X3 "dmat3x3"
%token DMAT3X4 "dmat3x4"
%token DMAT4 "dmat4"
%token DMAT4X2 "dmat4x2"
%token DMAT4X3 "dmat4x3"
%token DMAT4X4 "dmat4x4"
%token DO "do"
%token DOT "."
%token DOUBLE "double"
%token DVEC2 "dvec2"
%token DVEC3 "dvec3"
%token DVEC4 "dvec4"
%token ELSE "else"
%token EQUAL "="
%token EQ_OP "=="
%token FLAT "flat"
%token FLOAT "float"
%token FOR "for"
%token GE_OP ">="
%token HIGHP "highp"
%token IDENTIFIER "identifier"
%token IF "if"
%token IN "in"
%token INC_OP "++"
%token INOUT "inout"
%token INT "int"
%token INVARIANT "invariant"
%token ISAMPLER1D "isampler1D"
%token ISAMPLER1DARRAY "isampler1DArray"
%token ISAMPLER2D "isampler2D"
%token ISAMPLER2DARRAY "isampler2DArray"
%token ISAMPLER2DMS "isampler2DMS"
%token ISAMPLER2DMSARRAY "isampler2DMSArray"
%token ISAMPLER2DRECT "isampler2DRect"
%token ISAMPLER3D "isampler3D"
%token ISAMPLERBUFFER "isamplerBuffer"
%token ISAMPLERCUBE "isamplerCube"
%token ISAMPLERCUBEARRAY "isamplerCubeArray"
%token IVEC2 "ivec2"
%token IVEC3 "ivec3"
%token IVEC4 "ivec4"
%token LAYOUT "layout"
%token LEFT_ANGLE "<"
%token LEFT_ASSIGN "<<="
%token LEFT_BRACE "{"
%token LEFT_BRACKET "["
%token LEFT_OP "<<"
%token LEFT_PAREN "("
%token LE_OP "<="
%token LOWP "lowp"
%token MAT2 "mat2"
%token MAT2X2 "mat2x2"
%token MAT2X3 "mat2x3"
%token MAT2X4 "mat2x4"
%token MAT3 "mat3"
%token MAT3X2 "mat3x2"
%token MAT3X3 "mat3x3"
%token MAT3X4 "mat3x4"
%token MAT4 "mat4"
%token MAT4X2 "mat4x2"
%token MAT4X3 "mat4x3"
%token MAT4X4 "mat4x4"
%token MEDIUMP "mediump"
%token MOD_ASSIGN "%="
%token MUL_ASSIGN "*="
%token NE_OP "!="
%token NOPERSPECTIVE "noperspective"
%token NUMBER "number constant"
%token OR_ASSIGN "|="
%token OR_OP "||"
%token OUT "out"
%token PATCH "patch"
%token PERCENT "%"
%token PLUS "plus"
%token PRECISION "precision"
%token QUESTION "?"
%token RETURN "return"
%token RIGHT_ANGLE ">"
%token RIGHT_ASSIGN ">>="
%token RIGHT_BRACE "}"
%token RIGHT_BRACKET "]"
%token RIGHT_OP ">>"
%token RIGHT_PAREN ")"
%token SAMPLE "sample"
%token SAMPLER1D "sampler1D"
%token SAMPLER1DARRAY "sampler1DArray"
%token SAMPLER1DARRAYSHADOW "sampler1DArrayShadow"
%token SAMPLER1DSHADOW "sampler1DShadow"
%token SAMPLER2D "sampler2D"
%token SAMPLER2DARRAY "sampler2DArray"
%token SAMPLER2DARRAYSHADOW "sampler2DArrayShadow"
%token SAMPLER2DMS "sampler2DMS"
%token SAMPLER2DMSARRAY "sampler2DMSArray"
%token SAMPLER2DRECT "sampler2DRect"
%token SAMPLER2DRECTSHADOW "sampler2DRectShadow"
%token SAMPLER2DSHADOW "sampler2DShadow"
%token SAMPLER3D "sampler3D"
%token SAMPLERBUFFER "samplerBuffer"
%token SAMPLERCUBE "samplerCube"
%token SAMPLERCUBEARRAY "samplerCubeArray"
%token SAMPLERCUBEARRAYSHADOW "samplerCubeArrayShadow"
%token SAMPLERCUBESHADOW "samplerCubeShadow"
%token SEMICOLON ";"
%token SLASH "/"
%token SMOOTH "smooth"
%token STAR "*"
%token STRUCT "struct"
%token SUBROUTINE "subroutine"
%token SUB_ASSIGN "-="
%token SWITCH "switch"
%token TILDE "~"
%token TYPE_NAME "type_name"
%token UINT "uint"
%token UNIFORM "uniform"
%token USAMPLER1D "usampler1D"
%token USAMPLER1DARRAY "usampler1DArray"
%token USAMPLER2D "usampler2D"
%token USAMPLER2DARRAY "usampler2DArray"
%token USAMPLER2DMS "usampler2DMS"
%token USAMPLER2DMSARRAY "usampler2DMSarray"
%token USAMPLER2DRECT "usampler2DRect"
%token USAMPLER3D "usampler3D"
%token USAMPLERBUFFER "usamplerBuffer"
%token USAMPLERCUBE "usamplerCube"
%token USAMPLERCUBEARRAY "usamplerCubeArray"
%token UVEC2 "uvec2"
%token UVEC3 "uvec3"
%token UVEC4 "uvec4"
%token VARYING "varying"
%token VEC2 "vec2"
%token VEC3 "vec3"
%token VEC4 "vec4"
%token VERTICAL_BAR "|"
%token VOID "void"
%token WHILE "while"
%token XOR_ASSIGN "^="
%token XOR_OP "^"
%token TRUE "true"
%token FALSE "false"
%token PREPROC "preprocessor directive"
%token COMMENT "comment"
%token ERROR "error"

%start translation_unit

/:
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

#include "$header"
#include "glsllexer.h"
#include "glslast.h"
#include <vector>
#include <stack>

namespace GLSL {

class GLSL_EXPORT Parser: public $table
{
public:
    union Value {
        void *ptr;
        const std::string *string;
        AST *ast;
        List<AST *> *ast_list;
        Declaration *declaration;
        List<Declaration *> *declaration_list;
        TranslationUnit *translation_unit;
    };

    Parser(Engine *engine, const char *source, unsigned size, int variant);
    ~Parser();

    TranslationUnit *parse();

private:
    // 1-based
    Value &sym(int n) { return _symStack[_tos + n - 1]; }
    AST *&ast(int n) { return _symStack[_tos + n - 1].ast; }
    const std::string *&string(int n) { return _symStack[_tos + n - 1].string; }

    inline int consumeToken() { return _index++; }
    inline const Token &tokenAt(int index) const { return _tokens.at(index); }
    inline int tokenKind(int index) const { return _tokens.at(index).kind; }
    void reduce(int ruleno);

private:
    Engine *_engine;
    int _tos;
    int _index;
    std::vector<int> _stateStack;
    std::vector<int> _locationStack;
    std::vector<Value> _symStack;
    std::vector<Token> _tokens;
};

} // end of namespace GLSL
:/

/.
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

#include "glslparser.h"
#include "glslengine.h"
#include <iostream>
#include <cstdio>
#include <cassert>

using namespace GLSL;

Parser::Parser(Engine *engine, const char *source, unsigned size, int variant)
    : _engine(engine), _tos(-1), _index(0)
{
    _tokens.reserve(1024);

    _stateStack.resize(128);
    _locationStack.resize(128);
    _symStack.resize(128);

    _tokens.push_back(Token()); // invalid token

    std::stack<int> parenStack;
    std::stack<int> bracketStack;
    std::stack<int> braceStack;

    Lexer lexer(engine, source, size);
    lexer.setVariant(variant);
    Token tk;
    do {
        lexer.yylex(&tk);

        switch (tk.kind) {
        case T_LEFT_PAREN:
            parenStack.push(_tokens.size());
            break;
        case T_LEFT_BRACKET:
            bracketStack.push(_tokens.size());
            break;
        case T_LEFT_BRACE:
            braceStack.push(_tokens.size());
            break;

        case T_RIGHT_PAREN:
            if (! parenStack.empty()) {
                _tokens[parenStack.top()].matchingBrace = _tokens.size();
                parenStack.pop();
            }
            break;
        case T_RIGHT_BRACKET:
            if (! bracketStack.empty()) {
                _tokens[bracketStack.top()].matchingBrace = _tokens.size();
                bracketStack.pop();
            }
            break;
        case T_RIGHT_BRACE:
            if (! braceStack.empty()) {
                _tokens[braceStack.top()].matchingBrace = _tokens.size();
                braceStack.pop();
            }
            break;
        default:
            break;
        }

        _tokens.push_back(tk);
    } while (tk.isNot(EOF_SYMBOL));

    _index = 1;
}

Parser::~Parser()
{
}

TranslationUnit *Parser::parse()
{
    int action = 0;
    int yytoken = -1;
    int yyloc = -1;
    void *yyval = 0; // value of the current token.

    _tos = -1;

    do {
        if (yytoken == -1 && -TERMINAL_COUNT != action_index[action]) {
            yyloc = consumeToken();
            yytoken = tokenKind(yyloc);
            if (yytoken == T_IDENTIFIER && t_action(action, T_TYPE_NAME) != 0) {
                const Token &la = tokenAt(_index);

                if (la.is(T_IDENTIFIER)) {
                    yytoken = T_TYPE_NAME;
                } else if (la.is(T_LEFT_BRACKET) && la.matchingBrace != 0 &&
                           tokenAt(la.matchingBrace + 1).is(T_IDENTIFIER)) {
                    yytoken = T_TYPE_NAME;
                }
            }
            yyval = _tokens.at(yyloc).ptr;
        }

        if (unsigned(++_tos) == _stateStack.size()) {
            _stateStack.resize(_tos * 2);
            _locationStack.resize(_tos * 2);
            _symStack.resize(_tos * 2);
        }

        _stateStack[_tos] = action;
        action = t_action(action, yytoken);
        if (action > 0) {
            if (action == ACCEPT_STATE) {
                --_tos;
                return _symStack[0].translation_unit;
            }
            _symStack[_tos].ptr = yyval;
            _locationStack[_tos] = yyloc;
            yytoken = -1;
        } else if (action < 0) {
            const int ruleno = -action - 1;
            const int N = rhs[ruleno];
            _tos -= N;
            reduce(ruleno);
            action = nt_action(_stateStack[_tos], lhs[ruleno] - TERMINAL_COUNT);
        }
    } while (action);

    fprintf(stderr, "unexpected token `%s' at line %d\n", yytoken != -1 ? spell[yytoken] : "",
        _tokens[yyloc].line + 1);

    return 0;
}
./



/.
void Parser::reduce(int ruleno)
{
switch(ruleno) {
./



variable_identifier ::= IDENTIFIER ;
/.
case $rule_number: {
    ast(1) = new IdentifierExpression(sym(1).string);
}   break;
./

primary_expression ::= NUMBER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

primary_expression ::= TRUE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

primary_expression ::= FALSE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

primary_expression ::= variable_identifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

primary_expression ::= LEFT_PAREN expression RIGHT_PAREN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

postfix_expression ::= primary_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

postfix_expression ::= postfix_expression LEFT_BRACKET integer_expression RIGHT_BRACKET ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

postfix_expression ::= function_call ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

postfix_expression ::= postfix_expression DOT IDENTIFIER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

postfix_expression ::= postfix_expression INC_OP ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

postfix_expression ::= postfix_expression DEC_OP ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

integer_expression ::= expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_call ::= function_call_or_method ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_call_or_method ::= function_call_generic ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_call_or_method ::= postfix_expression DOT function_call_generic ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_call_generic ::= function_call_header_with_parameters RIGHT_PAREN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_call_generic ::= function_call_header_no_parameters RIGHT_PAREN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_call_header_no_parameters ::= function_call_header VOID ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_call_header_no_parameters ::= function_call_header ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_call_header_with_parameters ::= function_call_header assignment_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_call_header_with_parameters ::= function_call_header_with_parameters COMMA assignment_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_call_header ::= function_identifier LEFT_PAREN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_identifier ::= type_specifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_identifier ::= IDENTIFIER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

unary_expression ::= postfix_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

unary_expression ::= INC_OP unary_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

unary_expression ::= DEC_OP unary_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

unary_expression ::= unary_operator unary_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

unary_operator ::= PLUS ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

unary_operator ::= DASH ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

unary_operator ::= BANG ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

unary_operator ::= TILDE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

multiplicative_expression ::= unary_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

multiplicative_expression ::= multiplicative_expression STAR unary_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

multiplicative_expression ::= multiplicative_expression SLASH unary_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

multiplicative_expression ::= multiplicative_expression PERCENT unary_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

additive_expression ::= multiplicative_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

additive_expression ::= additive_expression PLUS multiplicative_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

additive_expression ::= additive_expression DASH multiplicative_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

shift_expression ::= additive_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

shift_expression ::= shift_expression LEFT_OP additive_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

shift_expression ::= shift_expression RIGHT_OP additive_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

relational_expression ::= shift_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

relational_expression ::= relational_expression LEFT_ANGLE shift_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

relational_expression ::= relational_expression RIGHT_ANGLE shift_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

relational_expression ::= relational_expression LE_OP shift_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

relational_expression ::= relational_expression GE_OP shift_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

equality_expression ::= relational_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

equality_expression ::= equality_expression EQ_OP relational_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

equality_expression ::= equality_expression NE_OP relational_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

and_expression ::= equality_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

and_expression ::= and_expression AMPERSAND equality_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

exclusive_or_expression ::= and_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

exclusive_or_expression ::= exclusive_or_expression CARET and_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

inclusive_or_expression ::= exclusive_or_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

inclusive_or_expression ::= inclusive_or_expression VERTICAL_BAR exclusive_or_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

logical_and_expression ::= inclusive_or_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

logical_and_expression ::= logical_and_expression AND_OP inclusive_or_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

logical_xor_expression ::= logical_and_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

logical_xor_expression ::= logical_xor_expression XOR_OP logical_and_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

logical_or_expression ::= logical_xor_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

logical_or_expression ::= logical_or_expression OR_OP logical_xor_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

conditional_expression ::= logical_or_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

conditional_expression ::= logical_or_expression QUESTION expression COLON assignment_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_expression ::= conditional_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_expression ::= unary_expression assignment_operator assignment_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_operator ::= EQUAL ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_operator ::= MUL_ASSIGN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_operator ::= DIV_ASSIGN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_operator ::= MOD_ASSIGN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_operator ::= ADD_ASSIGN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_operator ::= SUB_ASSIGN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_operator ::= LEFT_ASSIGN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_operator ::= RIGHT_ASSIGN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_operator ::= AND_ASSIGN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_operator ::= XOR_ASSIGN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

assignment_operator ::= OR_ASSIGN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

expression ::= assignment_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

expression ::= expression COMMA assignment_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

constant_expression ::= conditional_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

declaration ::= function_prototype SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

declaration ::= init_declarator_list SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

declaration ::= PRECISION precision_qualifier type_specifier_no_prec SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

declaration ::= type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

declaration ::= type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

declaration ::= type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER LEFT_BRACKET RIGHT_BRACKET SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

declaration ::= type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

declaration ::= type_qualifier SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_prototype ::= function_declarator RIGHT_PAREN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_declarator ::= function_header ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_declarator ::= function_header_with_parameters ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_header_with_parameters ::= function_header parameter_declaration ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_header_with_parameters ::= function_header_with_parameters COMMA parameter_declaration ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_header ::= fully_specified_type IDENTIFIER LEFT_PAREN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

parameter_declarator ::= type_specifier IDENTIFIER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

parameter_declarator ::= type_specifier IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

parameter_declaration ::= parameter_type_qualifier parameter_qualifier parameter_declarator ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

parameter_declaration ::= parameter_qualifier parameter_declarator ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

parameter_declaration ::= parameter_type_qualifier parameter_qualifier parameter_type_specifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

parameter_declaration ::= parameter_qualifier parameter_type_specifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

parameter_qualifier ::= empty ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

parameter_qualifier ::= IN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

parameter_qualifier ::= OUT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

parameter_qualifier ::= INOUT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

parameter_type_specifier ::= type_specifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

init_declarator_list ::= single_declaration ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

init_declarator_list ::= init_declarator_list COMMA IDENTIFIER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

init_declarator_list ::= init_declarator_list COMMA IDENTIFIER LEFT_BRACKET RIGHT_BRACKET ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

init_declarator_list ::= init_declarator_list COMMA IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

init_declarator_list ::= init_declarator_list COMMA IDENTIFIER LEFT_BRACKET RIGHT_BRACKET EQUAL initializer ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

init_declarator_list ::= init_declarator_list COMMA IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET EQUAL initializer ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

init_declarator_list ::= init_declarator_list COMMA IDENTIFIER EQUAL initializer ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

single_declaration ::= fully_specified_type ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

single_declaration ::= fully_specified_type IDENTIFIER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

single_declaration ::= fully_specified_type IDENTIFIER LEFT_BRACKET RIGHT_BRACKET ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

single_declaration ::= fully_specified_type IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

single_declaration ::= fully_specified_type IDENTIFIER LEFT_BRACKET RIGHT_BRACKET EQUAL initializer ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

single_declaration ::= fully_specified_type IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET EQUAL initializer ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

single_declaration ::= fully_specified_type IDENTIFIER EQUAL initializer ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

single_declaration ::= INVARIANT IDENTIFIER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

fully_specified_type ::= type_specifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

fully_specified_type ::= type_qualifier type_specifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

invariant_qualifier ::= INVARIANT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

interpolation_qualifier ::= SMOOTH ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

interpolation_qualifier ::= FLAT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

interpolation_qualifier ::= NOPERSPECTIVE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

layout_qualifier ::= LAYOUT LEFT_PAREN layout_qualifier_id_list RIGHT_PAREN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

layout_qualifier_id_list ::= layout_qualifier_id ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

layout_qualifier_id_list ::= layout_qualifier_id_list COMMA layout_qualifier_id ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

layout_qualifier_id ::= IDENTIFIER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

layout_qualifier_id ::= IDENTIFIER EQUAL NUMBER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

parameter_type_qualifier ::= CONST ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_qualifier ::= storage_qualifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_qualifier ::= layout_qualifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_qualifier ::= layout_qualifier storage_qualifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_qualifier ::= interpolation_qualifier storage_qualifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_qualifier ::= interpolation_qualifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_qualifier ::= invariant_qualifier storage_qualifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_qualifier ::= invariant_qualifier interpolation_qualifier storage_qualifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_qualifier ::= INVARIANT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= CONST ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= ATTRIBUTE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= VARYING ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= CENTROID VARYING ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= IN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= OUT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= CENTROID IN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= CENTROID OUT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= PATCH IN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= PATCH OUT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= SAMPLE IN ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= SAMPLE OUT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

storage_qualifier ::= UNIFORM ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier ::= type_specifier_no_prec ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier ::= precision_qualifier type_specifier_no_prec ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_no_prec ::= type_specifier_nonarray ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_no_prec ::= type_specifier_nonarray LEFT_BRACKET RIGHT_BRACKET ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_no_prec ::= type_specifier_nonarray LEFT_BRACKET constant_expression RIGHT_BRACKET ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= VOID ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= FLOAT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DOUBLE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= INT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= UINT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= BOOL ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= VEC2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= VEC3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= VEC4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DVEC2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DVEC3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DVEC4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= BVEC2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= BVEC3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= BVEC4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= IVEC2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= IVEC3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= IVEC4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= UVEC2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= UVEC3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= UVEC4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= MAT2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= MAT3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= MAT4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= MAT2X2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= MAT2X3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= MAT2X4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= MAT3X2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= MAT3X3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= MAT3X4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= MAT4X2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= MAT4X3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= MAT4X4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DMAT2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DMAT3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DMAT4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DMAT2X2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DMAT2X3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DMAT2X4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DMAT3X2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DMAT3X3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DMAT3X4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DMAT4X2 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DMAT4X3 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= DMAT4X4 ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER1D ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER2D ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER3D ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLERCUBE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER1DSHADOW ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER2DSHADOW ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLERCUBESHADOW ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER1DARRAY ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER2DARRAY ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER1DARRAYSHADOW ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER2DARRAYSHADOW ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLERCUBEARRAY ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLERCUBEARRAYSHADOW ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= ISAMPLER1D ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= ISAMPLER2D ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= ISAMPLER3D ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= ISAMPLERCUBE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= ISAMPLER1DARRAY ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= ISAMPLER2DARRAY ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= ISAMPLERCUBEARRAY ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= USAMPLER1D ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= USAMPLER2D ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= USAMPLER3D ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= USAMPLERCUBE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= USAMPLER1DARRAY ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= USAMPLER2DARRAY ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= USAMPLERCUBEARRAY ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER2DRECT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER2DRECTSHADOW ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= ISAMPLER2DRECT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= USAMPLER2DRECT ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLERBUFFER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= ISAMPLERBUFFER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= USAMPLERBUFFER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER2DMS ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= ISAMPLER2DMS ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= USAMPLER2DMS ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= SAMPLER2DMSARRAY ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= ISAMPLER2DMSARRAY ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= USAMPLER2DMSARRAY ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= struct_specifier ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

type_specifier_nonarray ::= TYPE_NAME ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

precision_qualifier ::= HIGHP ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

precision_qualifier ::= MEDIUMP ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

precision_qualifier ::= LOWP ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

struct_specifier ::= STRUCT IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

struct_specifier ::= STRUCT LEFT_BRACE struct_declaration_list RIGHT_BRACE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

struct_declaration_list ::= struct_declaration ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

struct_declaration_list ::= struct_declaration_list struct_declaration ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

struct_declaration ::= type_specifier struct_declarator_list SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

struct_declaration ::= type_qualifier type_specifier struct_declarator_list SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

struct_declarator_list ::= struct_declarator ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

struct_declarator_list ::= struct_declarator_list COMMA struct_declarator ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

struct_declarator ::= IDENTIFIER ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

struct_declarator ::= IDENTIFIER LEFT_BRACKET RIGHT_BRACKET ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

struct_declarator ::= IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

initializer ::= assignment_expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

declaration_statement ::= declaration ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

statement ::= compound_statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

statement ::= simple_statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

simple_statement ::= declaration_statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

simple_statement ::= expression_statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

simple_statement ::= selection_statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

simple_statement ::= switch_statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

simple_statement ::= case_label ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

simple_statement ::= iteration_statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

simple_statement ::= jump_statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

compound_statement ::= LEFT_BRACE RIGHT_BRACE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

compound_statement ::= LEFT_BRACE statement_list RIGHT_BRACE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

statement_no_new_scope ::= compound_statement_no_new_scope ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

statement_no_new_scope ::= simple_statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

compound_statement_no_new_scope ::= LEFT_BRACE RIGHT_BRACE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

compound_statement_no_new_scope ::= LEFT_BRACE statement_list RIGHT_BRACE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

statement_list ::= statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

statement_list ::= statement_list statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

expression_statement ::= SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

expression_statement ::= expression SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

selection_statement ::= IF LEFT_PAREN expression RIGHT_PAREN selection_rest_statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

selection_rest_statement ::= statement ELSE statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

selection_rest_statement ::= statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

condition ::= expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

condition ::= fully_specified_type IDENTIFIER EQUAL initializer ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

switch_statement ::= SWITCH LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE switch_statement_list RIGHT_BRACE ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

switch_statement_list ::= empty ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

switch_statement_list ::= statement_list ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

case_label ::= CASE expression COLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

case_label ::= DEFAULT COLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

iteration_statement ::= WHILE LEFT_PAREN condition RIGHT_PAREN statement_no_new_scope ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

iteration_statement ::= DO statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

iteration_statement ::= FOR LEFT_PAREN for_init_statement for_rest_statement RIGHT_PAREN statement_no_new_scope ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

for_init_statement ::= expression_statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

for_init_statement ::= declaration_statement ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

conditionopt ::= empty ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

conditionopt ::= condition ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

for_rest_statement ::= conditionopt SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

for_rest_statement ::= conditionopt SEMICOLON expression ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

jump_statement ::= CONTINUE SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

jump_statement ::= BREAK SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

jump_statement ::= RETURN SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

jump_statement ::= RETURN expression SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

jump_statement ::= DISCARD SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

translation_unit ::= external_declaration_list ;
/.
case $rule_number: {
    ast(1) = new TranslationUnit(sym(1).declaration_list);
}   break;
./

external_declaration_list ::= external_declaration ;
/.
case $rule_number: {
    sym(1).declaration_list = new (_engine->pool()) List<Declaration *>(sym(1).declaration);
}   break;
./

external_declaration_list ::= external_declaration_list external_declaration ;
/.
case $rule_number: {
    sym(1).declaration_list = new (_engine->pool())  List<Declaration *>(sym(1).declaration_list, sym(2).declaration);
}   break;
./

external_declaration ::= function_definition ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

external_declaration ::= declaration ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

external_declaration ::= SEMICOLON ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

function_definition ::= function_prototype compound_statement_no_new_scope ;
/.
case $rule_number: {
    // ast(1) = new ...AST(...);
}   break;
./

empty ::= ;
/.
case $rule_number: {
    ast(1) = 0;
}   break;
./



/.
} // end switch
} // end Parser::reduce()
./