/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INT = 258,
    T_REAL = 259,
    T_BOOL = 260,
    IF_WORD = 261,
    THEN_WORD = 262,
    ELSE_WORD = 263,
    PROGRAM_WORD = 264,
    WHILE_WORD = 265,
    DO_WORD = 266,
    FOR_WORD = 267,
    BEGIN_WORD = 268,
    END_WORD = 269,
    VAR_WORD = 270,
    ARRAY_WORD = 271,
    OF_WORD = 272,
    INT = 273,
    FLOAT = 274,
    BOOL = 275,
    IDENTIFIER = 276,
    OPAD = 277,
    OPMUL = 278,
    RELATIONAL = 279,
    SEMI_COLON = 280,
    PONTO_PONTO = 281,
    VIRGULA = 282,
    DOIS_PONTOS = 283,
    ATRIBUICAO = 284,
    RIGHT_BRACKET = 285,
    LEFT_BRACKET = 286,
    COLCHETES_FECHA = 287,
    COLCHETES_ABRE = 288
  };
#endif
/* Tokens.  */
#define T_INT 258
#define T_REAL 259
#define T_BOOL 260
#define IF_WORD 261
#define THEN_WORD 262
#define ELSE_WORD 263
#define PROGRAM_WORD 264
#define WHILE_WORD 265
#define DO_WORD 266
#define FOR_WORD 267
#define BEGIN_WORD 268
#define END_WORD 269
#define VAR_WORD 270
#define ARRAY_WORD 271
#define OF_WORD 272
#define INT 273
#define FLOAT 274
#define BOOL 275
#define IDENTIFIER 276
#define OPAD 277
#define OPMUL 278
#define RELATIONAL 279
#define SEMI_COLON 280
#define PONTO_PONTO 281
#define VIRGULA 282
#define DOIS_PONTOS 283
#define ATRIBUICAO 284
#define RIGHT_BRACKET 285
#define LEFT_BRACKET 286
#define COLCHETES_FECHA 287
#define COLCHETES_ABRE 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "trabalhoFinal.y"

    int ival;
    float fval;
    int bval;
    char * idval;
    char * aopval;


#line 132 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
