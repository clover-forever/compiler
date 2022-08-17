/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    VAR = 258,
    NEWLINE = 259,
    INT = 260,
    FLOAT = 261,
    BOOL = 262,
    STRING = 263,
    CHAR = 264,
    INC = 265,
    DEC = 266,
    GEQ = 267,
    LOR = 268,
    LAND = 269,
    ADD_ASSIGN = 270,
    SUB_ASSIGN = 271,
    IF = 272,
    ELSE = 273,
    FOR = 274,
    SWITCH = 275,
    CASE = 276,
    PRINT = 277,
    TRUE = 278,
    FALSE = 279,
    DEFAULT = 280,
    RETURN = 281,
    FUNC = 282,
    FUNCOPEN = 283,
    PACKAGE = 284,
    IDENT = 285,
    EQL = 286,
    NEQ = 287,
    LEQ = 288,
    MUL_ASSIGN = 289,
    QUO_ASSIGN = 290,
    REM_ASSIGN = 291,
    PRINTLN = 292,
    INT_LIT = 293,
    STRING_LIT = 294,
    FLOAT_LIT = 295,
    BOOL_LIT = 296,
    CHAR_LIT = 297,
    AND = 298,
    OR = 299
  };
#endif
/* Tokens.  */
#define VAR 258
#define NEWLINE 259
#define INT 260
#define FLOAT 261
#define BOOL 262
#define STRING 263
#define CHAR 264
#define INC 265
#define DEC 266
#define GEQ 267
#define LOR 268
#define LAND 269
#define ADD_ASSIGN 270
#define SUB_ASSIGN 271
#define IF 272
#define ELSE 273
#define FOR 274
#define SWITCH 275
#define CASE 276
#define PRINT 277
#define TRUE 278
#define FALSE 279
#define DEFAULT 280
#define RETURN 281
#define FUNC 282
#define FUNCOPEN 283
#define PACKAGE 284
#define IDENT 285
#define EQL 286
#define NEQ 287
#define LEQ 288
#define MUL_ASSIGN 289
#define QUO_ASSIGN 290
#define REM_ASSIGN 291
#define PRINTLN 292
#define INT_LIT 293
#define STRING_LIT 294
#define FLOAT_LIT 295
#define BOOL_LIT 296
#define CHAR_LIT 297
#define AND 298
#define OR 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 63 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    float f_val;
    char *s_val;
    bool b_val;
    char c_val;
    /* ... */

#line 151 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
