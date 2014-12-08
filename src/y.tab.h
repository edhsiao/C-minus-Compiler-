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
    PLUS = 268,
    MINUS = 269,
    TIMES = 270,
    OVER = 271,
    LT = 272,
    LTEQ = 273,
    GT = 274,
    GTEQ = 275,
    EQ = 276,
    NEQ = 277,
    ASSIGN = 278,
    SEMICOLON = 279,
    COMMA = 280,
    LPAREN = 281,
    RPAREN = 282,
    LBRACKET = 283,
    RBRACKET = 284,
    LBRACE = 285,
    RBRACE = 286,
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
#define PLUS 268
#define MINUS 269
#define TIMES 270
#define OVER 271
#define LT 272
#define LTEQ 273
#define GT 274
#define GTEQ 275
#define EQ 276
#define NEQ 277
#define ASSIGN 278
#define SEMICOLON 279
#define COMMA 280
#define LPAREN 281
#define RPAREN 282
#define LBRACKET 283
#define RBRACKET 284
#define LBRACE 285
#define RBRACE 286
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
