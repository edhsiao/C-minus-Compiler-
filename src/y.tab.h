/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
    ELSE = 258,
    IF = 259,
    INT = 260,
    FLOAT = 261,
    RETURN = 262,
    VOID = 263,
    WHILE = 264,
    ID = 265,
    NUM = 266,
    NUM_FLOAT = 267,
    SOMA = 268,
    SUB = 269,
    MUL = 270,
    DIV = 271,
    MENOR = 272,
    MENORIG = 273,
    MAIOR = 274,
    MAIORIG = 275,
    IG = 276,
    DIF = 277,
    ATRIB = 278,
    PV = 279,
    VIRG = 280,
    AP = 281,
    FP = 282,
    ACOL = 283,
    FCOL = 284,
    ACH = 285,
    FCH = 286,
    ERROR = 287
  };
#endif
/* Tokens.  */
#define ELSE 258
#define IF 259
#define INT 260
#define FLOAT 261
#define RETURN 262
#define VOID 263
#define WHILE 264
#define ID 265
#define NUM 266
#define NUM_FLOAT 267
#define SOMA 268
#define SUB 269
#define MUL 270
#define DIV 271
#define MENOR 272
#define MENORIG 273
#define MAIOR 274
#define MAIORIG 275
#define IG 276
#define DIF 277
#define ATRIB 278
#define PV 279
#define VIRG 280
#define AP 281
#define FP 282
#define ACOL 283
#define FCOL 284
#define ACH 285
#define FCH 286
#define ERROR 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
