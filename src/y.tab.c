/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 5 "tc.y" /* yacc.c:339  */

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include "list/list.h"
#include "hash/hash.h"

#define YYSTYPE type_t
static int savedLineNo;
static int saved_col;
static TreeNode * savedTree; /* stores syntax tree for later return */

typedef union type_t type_t;

union type_t
{
	TreeNode *node;
	char *str;
	int op;
};

extern int yychar;

int yyerror(char * message)
{
  int i;
  //Node temp;

  fprintf(listing,"\nSyntax error at line %d: col %d, at ",lineno,col);
  printToken(yychar, next_token);
  fprintf(listing,"Current line:\n%s\n",current_line);

  for(i = 1; i < strlen(current_line); i++)
    fprintf(listing,"-");

/*  printf("Testing...\n");
  temp = l->current;
  list_root(l);
  while(l->current != NULL)
  {
    printf("%d: %s\n", l->current->id, l->current->str);
    l->current = l->current->next;
  }
  l->current = temp;
//  list_kill(l);
  printf("\nTest complete.\n");
*/
  fprintf(listing,"^\n");
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with the C Minus scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void) { 
  yyparse();
  return savedTree;
}


#line 133 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    RETURN = 261,
    VOID = 262,
    WHILE = 263,
    ID = 264,
    NUM = 265,
    PLUS = 266,
    MINUS = 267,
    TIMES = 268,
    OVER = 269,
    LT = 270,
    LTEQ = 271,
    GT = 272,
    GTEQ = 273,
    EQ = 274,
    NEQ = 275,
    ASSIGN = 276,
    SEMICOLON = 277,
    COMMA = 278,
    LPAREN = 279,
    RPAREN = 280,
    LBRACKET = 281,
    RBRACKET = 282,
    LBRACE = 283,
    RBRACE = 284,
    ERROR = 285
  };
#endif
/* Tokens.  */
#define ELSE 258
#define IF 259
#define INT 260
#define RETURN 261
#define VOID 262
#define WHILE 263
#define ID 264
#define NUM 265
#define PLUS 266
#define MINUS 267
#define TIMES 268
#define OVER 269
#define LT 270
#define LTEQ 271
#define GT 272
#define GTEQ 273
#define EQ 274
#define NEQ 275
#define ASSIGN 276
#define SEMICOLON 277
#define COMMA 278
#define LPAREN 279
#define RPAREN 280
#define LBRACKET 281
#define RBRACKET 282
#define LBRACE 283
#define RBRACE 284
#define ERROR 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 244 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    87,    99,   103,   105,   109,   118,   117,
     134,   138,   145,   144,   163,   165,   168,   180,   184,   193,
     192,   208,   216,   234,   237,   249,   252,   254,   256,   258,
     260,   264,   266,   269,   275,   284,   292,   297,   304,   311,
     317,   328,   327,   346,   353,   355,   364,   368,   372,   376,
     380,   384,   390,   397,   399,   408,   412,   418,   425,   429,
     433,   439,   445,   447,   449,   457,   456,   469,   471,   474,
     486
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ELSE", "IF", "INT", "RETURN", "VOID",
  "WHILE", "ID", "NUM", "PLUS", "MINUS", "TIMES", "OVER", "LT", "LTEQ",
  "GT", "GTEQ", "EQ", "NEQ", "ASSIGN", "SEMICOLON", "COMMA", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "ERROR", "$accept",
  "program", "declaration_list", "declaration", "var_declaration", "@1",
  "type_specifier", "fun_declaration", "@2", "params", "param_list",
  "param", "@3", "compound_stmt", "local_declarations", "stmt_list",
  "stmt", "expr_stmt", "selection_stmt", "iteration_stmt", "return_stmt",
  "expr", "var", "@4", "simple_expr", "relop", "additive_expr", "addop",
  "term", "mulop", "factor", "call", "@5", "args", "arg_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
# endif

#define YYPACT_NINF -89

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-89)))

#define YYTABLE_NINF -69

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       9,   -89,   -89,     6,     9,   -89,   -89,     2,   -89,   -89,
     -89,    -3,   -89,    23,    11,    53,    33,    52,    55,    72,
      57,    64,   -89,    62,    65,    67,     9,   -89,    68,   -89,
     -89,   -89,    63,     9,   -89,   -89,    79,    44,    70,   -89,
      73,     0,    71,    18,   -89,   -89,     3,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,    74,    77,   -89,    14,    42,   -89,
     -89,     3,   -89,    78,     3,    75,    80,    81,   -89,     3,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,     3,
      -7,   -89,   -89,    -7,    82,   -89,    76,     3,    50,   -89,
     -89,   -89,    66,    42,   -89,    61,    61,    83,   -89,    84,
      85,    99,   -89,   -89,   -89,     3,    61,   -89,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    11,     0,     2,     4,     5,     0,     6,     1,
       3,     8,     7,     0,     0,     0,     0,     0,    11,     0,
       0,    14,    17,     0,    18,     0,     0,     9,     0,    23,
      13,    16,     0,    25,    20,    22,     0,     0,     8,    54,
       0,     0,     0,    40,    64,    32,     0,    21,    27,    24,
      26,    28,    29,    30,     0,    62,    39,     0,    53,    58,
      63,     0,    36,     0,     0,     0,     0,     0,    31,     0,
      45,    55,    56,    47,    46,    48,    49,    50,    51,     0,
       0,    59,    60,     0,     0,    37,     0,     0,     0,    61,
      38,    62,    43,    52,    57,     0,     0,     0,    70,     0,
      67,    33,    35,    42,    66,     0,     0,    69,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,   107,    86,   -89,    60,   -89,   -89,   -89,
     -89,    87,   -89,    89,   -89,   -89,   -88,   -89,   -89,   -89,
     -89,   -41,   -22,   -89,   -89,   -89,    24,   -89,    32,   -89,
      34,   -89,   -89,   -89,   -89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    13,     7,     8,    14,    20,
      21,    22,    28,    48,    33,    37,    49,    50,    51,    52,
      53,    54,    55,    65,    56,    79,    57,    80,    58,    83,
      59,    60,    66,    99,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      63,    39,    43,    44,    39,    67,     9,   101,   102,    43,
      44,    11,    43,    44,     1,    70,     2,    46,   108,    12,
      84,   -12,    62,    86,    46,    71,    72,    46,    90,    73,
      74,    75,    76,    77,    78,    16,   -44,   -44,     1,   -44,
      18,   -44,   -65,   -44,   -41,    39,    97,    98,    40,    15,
      41,    39,    42,    43,    44,    81,    82,    91,    91,    43,
      44,    91,    39,    17,   107,    40,    45,    41,    46,    42,
      43,    44,    29,    47,    46,   -68,    19,    71,    72,    23,
     -15,    24,    25,    45,    27,    46,    19,    26,    38,    29,
      34,   -19,    12,    36,    32,    29,    68,    61,    69,    64,
      85,    87,   106,    92,    88,    96,    89,    95,   105,   104,
     103,    10,    93,    31,    30,     0,     0,    94,     0,    35
};

static const yytype_int8 yycheck[] =
{
      41,     1,     9,    10,     1,    46,     0,    95,    96,     9,
      10,     9,     9,    10,     5,     1,     7,    24,   106,    22,
      61,    24,    22,    64,    24,    11,    12,    24,    69,    15,
      16,    17,    18,    19,    20,    24,    22,    23,     5,    25,
       7,    27,    24,    29,    26,     1,    87,    88,     4,    26,
       6,     1,     8,     9,    10,    13,    14,    79,    80,     9,
      10,    83,     1,    10,   105,     4,    22,     6,    24,     8,
       9,    10,    28,    29,    24,    25,    16,    11,    12,    27,
      25,     9,    25,    22,    22,    24,    26,    23,     9,    28,
      27,    26,    22,    33,    26,    28,    22,    24,    21,    28,
      22,    26,     3,    79,    24,    29,    25,    25,    23,    25,
      27,     4,    80,    26,    25,    -1,    -1,    83,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,    32,    33,    34,    35,    37,    38,     0,
      34,     9,    22,    36,    39,    26,    24,    10,     7,    37,
      40,    41,    42,    27,     9,    25,    23,    22,    43,    28,
      44,    42,    26,    45,    27,    35,    37,    46,     9,     1,
       4,     6,     8,     9,    10,    22,    24,    29,    44,    47,
      48,    49,    50,    51,    52,    53,    55,    57,    59,    61,
      62,    24,    22,    52,    28,    54,    63,    52,    22,    21,
       1,    11,    12,    15,    16,    17,    18,    19,    20,    56,
      58,    13,    14,    60,    52,    22,    52,    26,    24,    25,
      52,    53,    57,    59,    61,    25,    29,    52,    52,    64,
      65,    47,    47,    27,    25,    23,     3,    52,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    35,    36,    35,
      37,    37,    39,    38,    40,    40,    41,    41,    42,    43,
      42,    44,    45,    45,    46,    46,    47,    47,    47,    47,
      47,    48,    48,    49,    49,    50,    51,    51,    52,    52,
      53,    54,    53,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    57,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    63,    62,    64,    64,    65,
      65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     0,     7,
       1,     1,     0,     7,     1,     1,     3,     1,     2,     0,
       5,     4,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     5,     2,     3,     3,     1,
       1,     0,     5,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     0,     5,     1,     0,     3,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 84 "tc.y" /* yacc.c:1646  */
    { savedTree = (yyvsp[0]).node; }
#line 1402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "tc.y" /* yacc.c:1646  */
    {
			    TreeNode * t = (yyvsp[-1]).node;
			    if (t != NULL)
			    {
				while (t->sibling != NULL)
				    t = t->sibling;
				t->sibling = (yyvsp[0]).node;
				(yyval).node = (yyvsp[-1]).node;
			    }
			    else (yyval).node = (yyvsp[0]).node;
			}
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 100 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[0]).node; }
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 104 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[0]).node; }
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 106 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[0]).node; }
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).node = newDeclNode(Var);
			  (yyval).node->type = (yyvsp[-2]).str;
			  (yyval).node->name = copyString(tokenString);
			  if(lookup(h, tokenString) != NULL) printf("%s is previously declared\n", tokenString);
			  else insert(h, tokenString, (yyvsp[-2]).str, lineno, 0, 0);
			}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 118 "tc.y" /* yacc.c:1646  */
    {
			  savedLineNo = lineno; 
			  (yyval).str = copyString(tokenString);
			}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 123 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).node = newDeclNode(Var);
			  (yyval).node->type= copyString("Array");
			  (yyval).node->name = (yyvsp[-4]).str;
			  (yyval).node->lineno = savedLineNo;
			  (yyval).node->val = atoi(tokenString); /* $5.op; */
			  if(lookup(h, (yyvsp[-4]).str) != NULL) printf("%s is previously declared\n", (yyvsp[-4]).str);
			  else insert(h, (yyvsp[-4]).str, "Array", savedLineNo, 0, atoi(tokenString));
			}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).str = copyString("Integer");
			}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 139 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).str = copyString("Void");
			}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 145 "tc.y" /* yacc.c:1646  */
    {
			  printf("New scope\n");
			  savedLineNo = lineno;
			  (yyval).str = copyString(tokenString);
			}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 151 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).node = newDeclNode(Fun);
			  (yyval).node->name = (yyvsp[-4]).str;
			  (yyval).node->lineno = savedLineNo;
			  (yyval).node->type = (yyvsp[-6]).str;
			  (yyval).node->child[0] = (yyvsp[-2]).node;
			  (yyval).node->child[1] = (yyvsp[0]).node;
			  if(lookup(h, (yyvsp[-4]).str) != NULL) printf("%s is previously declared\n", (yyvsp[-4]).str);
			  else insert(h, (yyvsp[-4]).str, (yyvsp[-6]).str, savedLineNo, 0, 0);
			}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 164 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[0]).node; }
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 169 "tc.y" /* yacc.c:1646  */
    {
			  TreeNode * t = (yyvsp[-2]).node;
			  if (t != NULL)
			  {
				while (t->sibling != NULL)
				t = t->sibling;
				t->sibling = (yyvsp[0]).node;
				(yyval).node = (yyvsp[-2]).node;
			  }
			  else (yyval).node = (yyvsp[0]).node;
			}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 181 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[0]).node; }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 185 "tc.y" /* yacc.c:1646  */
    {
		  (yyval).node = newDeclNode(Param);
		  (yyval).node->type = (yyvsp[-1]).str;
		  (yyval).node->name = copyString(tokenString);
		  if(lookup(h, tokenString) != NULL) printf("%s is previously declared\n", tokenString);
		  else insert(h, tokenString, (yyvsp[-1]).str, 0, 0, 0);
		}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 193 "tc.y" /* yacc.c:1646  */
    {
		  savedLineNo = lineno;
		  (yyval).str = copyString(tokenString);
		}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 198 "tc.y" /* yacc.c:1646  */
    {
		  (yyval).node = newDeclNode(Param);
		  (yyval).node->type = (yyvsp[-4]).str;
		  (yyval).node->name = (yyvsp[-2]).str;
		  (yyval).node->lineno = savedLineNo;
		  if(lookup(h, (yyvsp[-2]).str) != NULL) printf("%s is previously declared\n", (yyvsp[-2]).str);
		  else insert(h, (yyvsp[-2]).str, "Array", savedLineNo, 0, 0);
		}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 209 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).node = newStmtNode(Cmpd);
			  (yyval).node->child[0] = (yyvsp[-2]).node;
			  (yyval).node->child[1] = (yyvsp[-1]).node;
			}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 217 "tc.y" /* yacc.c:1646  */
    {
				  TreeNode * t = (yyvsp[-1]).node;
				/*printf("t is %p\n", t); fflush(stdout);*/
				  if (t != NULL)
				  {
					while (t->sibling != NULL)
					{
						t = t->sibling;
					}
					t->sibling = (yyvsp[0]).node;
					(yyval).node = (yyvsp[-1]).node;
				  }
				  else
				  {
					 (yyval).node = (yyvsp[0]).node;
				  }
				}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 234 "tc.y" /* yacc.c:1646  */
    { (yyval).node = NULL; printf("New scope\n"); }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 238 "tc.y" /* yacc.c:1646  */
    {
			  TreeNode * t = (yyvsp[-1]).node;
			  if (t != NULL)
			  {
				while (t->sibling != NULL)
				t = t->sibling;
				t->sibling = (yyvsp[0]).node;
				(yyval).node = (yyvsp[-1]).node;
			  }
			  else (yyval).node = (yyvsp[0]).node;
			}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 249 "tc.y" /* yacc.c:1646  */
    { (yyval).node = NULL; }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 253 "tc.y" /* yacc.c:1646  */
    { saved_col = col; (yyval).node = (yyvsp[0]).node; }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 255 "tc.y" /* yacc.c:1646  */
    { saved_col = col; (yyval).node = (yyvsp[0]).node; }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 257 "tc.y" /* yacc.c:1646  */
    { saved_col = col; (yyval).node = (yyvsp[0]).node; }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 259 "tc.y" /* yacc.c:1646  */
    { saved_col = col; (yyval).node = (yyvsp[0]).node; }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 261 "tc.y" /* yacc.c:1646  */
    { saved_col = col; (yyval).node = (yyvsp[0]).node; }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 265 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[-1]).node; }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 270 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).node = newStmtNode(If);
			  (yyval).node->child[0] = (yyvsp[-2]).node;
			  (yyval).node->child[1] = (yyvsp[0]).node;
			}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 276 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).node = newStmtNode(If);
			  (yyval).node->child[0] = (yyvsp[-4]).node;
			  (yyval).node->child[1] = (yyvsp[-2]).node;
			  (yyval).node->child[2] = (yyvsp[0]).node;
			}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 285 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).node = newStmtNode(Iter);
			  (yyval).node->child[0] = (yyvsp[-2]).node;
			  (yyval).node->child[1] = (yyvsp[0]).node;
			}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 293 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).node = newStmtNode(Return);
			  (yyval).node->child[0] = NULL;
			}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 298 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).node = newStmtNode(Return);
			  (yyval).node->child[0] = (yyvsp[-1]).node;
			}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 305 "tc.y" /* yacc.c:1646  */
    {
		  (yyval).node = newStmtNode(Assign);
		  (yyval).node->child[0] = (yyvsp[-2]).node;
		  (yyval).node->op = ASSIGN; 
		  (yyval).node->child[1] = (yyvsp[0]).node;
		}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 312 "tc.y" /* yacc.c:1646  */
    {
		  (yyval).node = (yyvsp[0]).node;
		}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 318 "tc.y" /* yacc.c:1646  */
    {
		  if(lookup(h, tokenString) == NULL)
		  {
		    printf("%s undeclared \n", tokenString);
		    insert(h, tokenString, "undeclared", 0, 0, 0);
		  }
		  (yyval).node = newExpNode(Id);
		  (yyval).node->name = copyString(tokenString);
		}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 328 "tc.y" /* yacc.c:1646  */
    {
		  savedLineNo = lineno;
		  (yyval).str = copyString(tokenString);
		}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 333 "tc.y" /* yacc.c:1646  */
    {
		  (yyval).node = newExpNode(Id);
		  (yyval).node->name = (yyvsp[-3]).str;
		  (yyval).node->lineno = savedLineNo;
		  (yyval).node->child[1] = (yyvsp[-1]).node;
		  if(lookup(h, (yyvsp[-3]).str) == NULL)
		  {
		    printf("%s undeclared\n", (yyvsp[-3]).str);
		    insert(h, (yyvsp[-3]).str, "undeclared", 0, 0, 0);
		  }
		}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 347 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).node = newExpNode(Op);
			  (yyval).node->child[0] = (yyvsp[-2]).node;
			  (yyval).node->op = (yyvsp[-1]).op;
			  (yyval).node->child[2] = (yyvsp[0]).node;
			}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 354 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[0]).node; }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 356 "tc.y" /* yacc.c:1646  */
    {
			  (yyval).node = newErrNode();
			  (yyval).node->name = copyString(current_line);
			  (yyval).node->expected = copyString("Relation or Additive expression (eg '1 != 0' or '4 + 6')");
			  (yyval).node->col = col;
			}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 365 "tc.y" /* yacc.c:1646  */
    {
		  (yyval).op = LTEQ;
		}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 369 "tc.y" /* yacc.c:1646  */
    { 
		  (yyval).op = LT;
		}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 373 "tc.y" /* yacc.c:1646  */
    { 
		  (yyval).op = GT;
		}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 377 "tc.y" /* yacc.c:1646  */
    { 
		  (yyval).op = GTEQ;
		}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 381 "tc.y" /* yacc.c:1646  */
    { 
		  (yyval).op = EQ;
		}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 385 "tc.y" /* yacc.c:1646  */
    { 
		  (yyval).op = NEQ;
		}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 391 "tc.y" /* yacc.c:1646  */
    {
				(yyval).node = newExpNode(Op);
				(yyval).node->child[0] = (yyvsp[-2]).node;
				(yyval).node->child[1] = (yyvsp[0]).node;
				(yyval).node->op = (yyvsp[-1]).op;
			}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 398 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[0]).node; }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 400 "tc.y" /* yacc.c:1646  */
    {
		  (yyval).node = newErrNode();
		  (yyval).node->name = copyString(current_line);
		  (yyval).node->expected = copyString("Term (eg '5' or var_name)");
		  (yyval).node->col =  col;
			}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 409 "tc.y" /* yacc.c:1646  */
    {
		  (yyval).op = PLUS;
		}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 413 "tc.y" /* yacc.c:1646  */
    {
		  (yyval).op = MINUS;
		}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 419 "tc.y" /* yacc.c:1646  */
    {
			(yyval).node = newExpNode(Op);
				(yyval).node->child[0] = (yyvsp[-2]).node;
				(yyval).node->child[1] = (yyvsp[0]).node;
				(yyval).node->op = (yyvsp[-1]).op;
		}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 426 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[0]).node; }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 430 "tc.y" /* yacc.c:1646  */
    { 
		  (yyval).op = TIMES;
		}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 434 "tc.y" /* yacc.c:1646  */
    {
		  (yyval).op = OVER;
		}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 440 "tc.y" /* yacc.c:1646  */
    {
		  /*$$.node = newExpNode(Factor);
		  $$.node->child[0] = $2.node;*/
		  (yyval).node = (yyvsp[-1]).node;
		}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 446 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[0]).node; }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 448 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[0]).node; }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 450 "tc.y" /* yacc.c:1646  */
    { 
		  (yyval).node = newExpNode(Const);
		  (yyval).node->val = atoi(next_token);
		}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 457 "tc.y" /* yacc.c:1646  */
    {
		  savedLineNo = lineno;
		  (yyval).str = copyString(tokenString);
		}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 462 "tc.y" /* yacc.c:1646  */
    {
		  (yyval).node = newStmtNode(Call);
		  (yyval).node->name = (yyvsp[-3]).str;
		  (yyval).node->child[0] = (yyvsp[-1]).node;
		}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 470 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[0]).node; }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 471 "tc.y" /* yacc.c:1646  */
    { (yyval).node = NULL; }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 475 "tc.y" /* yacc.c:1646  */
    {
			  TreeNode * t = (yyvsp[-2]).node;
        	          if (t != NULL)
        	          {
				while (t->sibling != NULL)
				t = t->sibling;
				t->sibling = (yyvsp[0]).node;
				(yyval).node = (yyvsp[-2]).node;
			  }
			  else (yyval).node = (yyvsp[0]).node;
			}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 487 "tc.y" /* yacc.c:1646  */
    { (yyval).node = (yyvsp[0]).node; }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2018 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
