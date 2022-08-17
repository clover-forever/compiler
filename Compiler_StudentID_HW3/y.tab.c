/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "compiler_hw3.y" /* yacc.c:339  */

    #include "compiler_hw_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;
    
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
       
    }

    /* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */
    #define CODEGEN(...) \
        do { \
            for (int i = 0; i < g_indent_cnt; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    /* Symbol table function - you can add new functions if needed. */
    
    int if_series_comp_id = 0;
    struct symbol_table symbolTable[M];
    int case_id = 0;
    int case_pre_num = 0;
    int case_arr[N];
    int scopeID = 0; // synbolTable[0] = scopeID 1 
    int first_insert = 1;
    int addr_cnt = -1;
    int inside_each_scope_id[M];
    char *indent = "";
    char error_message[M] = "";
    int num_of_ForClause = 0;
    int forLevel = 0;
    char left[10] = "";
    char right[10] = "";
    int previous_for = 0;
    int forNum = 0;
    
    /* Global variables */
    bool g_has_error = false;
    FILE *fout = NULL; //for write j.file
    int g_indent_cnt = 0;

#line 119 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
#line 63 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char *s_val;
    bool b_val;
    char c_val;
    /* ... */

#line 256 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 273 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    61,     2,     2,    51,     2,     2,
      56,    57,    49,    47,    58,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    63,
      45,    52,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    54,    55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   123,   124,   128,   129,   130,   134,   140,
     140,   149,   150,   151,   155,   158,   161,   164,   167,   170,
     174,   174,   182,   183,   184,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   202,   220,   241,   242,
     243,   247,   316,   325,   337,   344,   351,   358,   365,   372,
     376,   380,   381,   382,   383,   384,   385,   386,   387,   391,
     391,   399,   399,   407,   407,   416,   416,   436,   439,   442,
     445,   448,   451,   457,   479,   485,   507,   513,   534,   556,
     578,   600,   622,   644,   650,   669,   688,   694,   703,   712,
     733,   739,   742,   764,   767,   770,   774,   777,   808,   814,
     819,   824,   828,   833,   838,   843,   848,   856,   860,   870,
     871,   875,   881,   887,   888,   892,   892,   900,   900,   940,
     940,   943,   943,   949,   953,   956,   958,   953,   978,  1046,
    1049,  1052,  1058,  1077,  1099,  1099,  1107,  1110
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "NEWLINE", "INT", "FLOAT", "BOOL",
  "STRING", "CHAR", "INC", "DEC", "GEQ", "LOR", "LAND", "ADD_ASSIGN",
  "SUB_ASSIGN", "IF", "ELSE", "FOR", "SWITCH", "CASE", "PRINT", "TRUE",
  "FALSE", "DEFAULT", "RETURN", "FUNC", "FUNCOPEN", "PACKAGE", "IDENT",
  "EQL", "NEQ", "LEQ", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN", "PRINTLN",
  "INT_LIT", "STRING_LIT", "FLOAT_LIT", "BOOL_LIT", "CHAR_LIT", "'['",
  "']'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'='", "'!'",
  "AND", "OR", "'('", "')'", "','", "'{'", "'}'", "'\"'", "':'", "';'",
  "$accept", "Program", "GlobalStatementList", "GlobalStatement",
  "PackageStmt", "FunctionDeclStmt", "$@1", "ParameterList", "ReturnType",
  "FuncBlock", "$@2", "StatementList", "Statement", "DeclarationStmt",
  "SimpleStmt", "AssignmentStmt", "IncDecStmt", "Type", "UseFunction",
  "TrainsitParaList", "CaseStmt", "$@3", "$@4", "$@5", "SwitchStmt", "$@6",
  "assign_op", "Expression", "Expression1", "Expression2", "Expression3",
  "Expression4", "Expression5", "PrimaryExpr", "Operand", "IndexExpr",
  "Literal", "IfStmt", "IfCondition", "IfBlock", "IfBlockStart",
  "IfBlockEnd", "Else", "ForStmt", "$@7", "MulForStmt", "$@8",
  "for_condition", "$@9", "$@10", "ForEnd", "ForClause", "$@11", "$@12",
  "$@13", "ConversionExpr", "unary_op", "PrintStmt", "Block", "$@14",
  "ReturnStmt", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    91,    93,    60,    62,    43,    45,    42,
      47,    37,    61,    33,   298,   299,    40,    41,    44,   123,
     125,    34,    58,    59
};
# endif

#define YYPACT_NINF -159

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-159)))

#define YYTABLE_NINF -120

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,  -159,   -18,     5,    22,     7,  -159,    34,  -159,  -159,
    -159,  -159,  -159,  -159,    -6,    40,   102,   -43,  -159,  -159,
    -159,  -159,  -159,  -159,   140,    46,  -159,  -159,  -159,  -159,
    -159,    -7,   102,  -159,  -159,  -159,   253,    48,  -159,   280,
     302,    -1,     8,  -159,  -159,  -159,   280,    32,    38,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,   280,  -159,    64,    76,
    -159,   108,   111,  -159,  -159,    63,  -159,  -159,  -159,   174,
     106,    59,    -5,    -2,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,   103,  -159,   280,   117,  -159,   122,   102,  -159,   115,
      71,  -159,  -159,  -159,   280,    72,   115,   120,   280,    -3,
     253,    90,  -159,  -159,  -159,  -159,   280,  -159,  -159,   280,
    -159,  -159,  -159,  -159,  -159,  -159,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,  -159,
     129,  -159,  -159,  -159,   101,  -159,   144,     1,   104,   105,
     107,     3,   104,  -159,    17,     6,  -159,   135,  -159,    11,
     106,   115,    59,    -5,    -5,    -5,    -5,    -5,    -5,    -2,
      -2,  -159,  -159,  -159,   280,  -159,   280,    -8,  -159,   253,
    -159,  -159,  -159,   104,   104,  -159,  -159,  -159,   307,  -159,
    -159,  -159,  -159,    10,  -159,  -159,   115,  -159,  -159,   194,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,   127,   116,   104,
     104,  -159,   109,   280,  -159,  -159,  -159,  -159,   115,   118,
    -159,   280,  -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,     0,     0,     2,     4,     0,     6,     9,
       8,     1,     3,     5,     0,    13,    49,     0,    44,    45,
      47,    46,    48,    11,    19,     0,    14,    15,    17,    16,
      18,     0,    49,    20,    10,    12,    24,     0,    35,   101,
       0,     0,     0,    99,   100,    63,   101,    97,     0,   102,
     103,   104,   105,   129,   130,   131,   101,   134,     0,   101,
      22,     0,     0,    38,    40,     0,    34,    31,    30,    39,
      74,    76,    83,    86,    90,    91,    93,    95,    96,    28,
      29,     0,    94,   101,     0,    27,     0,    49,    97,   108,
       0,    65,    59,    61,   101,     0,   137,    58,   101,     0,
      24,     0,    21,    23,    25,    26,   101,    42,    43,   101,
      68,    69,    70,    71,    72,    67,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   117,
       0,    92,    32,    33,    36,   111,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,    98,   101,   106,     0,
      73,    41,    75,    80,    81,    82,    79,    77,    78,    84,
      85,    87,    88,    89,   101,   116,   101,     0,   107,    24,
     112,   110,    66,     0,     0,   132,    64,    50,     0,   133,
     135,   128,   124,    39,   118,   121,    37,   113,   114,   101,
      60,    62,    51,    54,    52,    55,    53,     0,     0,     0,
       0,   109,     0,   101,   120,   123,   122,    56,   125,     0,
     126,   101,   127
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,   163,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,   -97,   -58,  -159,  -158,  -159,  -159,   -14,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,   -39,    62,    57,
     -91,   -38,   -70,  -159,   138,  -159,  -159,    13,  -159,  -159,
    -159,     4,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
      12,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -134,  -159,
    -159
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    14,    17,    31,    34,
      36,    59,    60,    61,    62,    63,    64,    65,    66,   144,
      67,   139,   140,    95,    68,   138,   116,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    90,   136,
     137,   171,   168,    80,    81,   130,   164,   184,   199,   200,
     204,   185,   198,   209,   211,    82,    83,    84,    85,   100,
      86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,   103,    23,   147,   172,   169,   182,    96,   176,    39,
     109,     1,     9,   131,    24,    25,   109,    99,    35,   109,
     107,   108,    11,   109,   109,   110,   111,   153,   154,   155,
     156,   157,   158,   188,     2,    10,     3,    92,    13,   190,
     191,    93,   124,   125,   112,   113,   114,   126,   127,   128,
      15,    57,    33,   212,   146,   141,   161,   162,   163,   145,
     175,   170,   115,   179,    94,   205,   205,   149,   181,  -119,
      16,   118,   189,   134,   177,   178,    32,   151,    87,    37,
      38,    18,    19,    20,    21,    22,   159,   160,    97,   103,
     119,   120,   121,    39,    98,  -115,    40,    41,    42,    43,
      44,    45,    46,   101,   122,   123,    47,    18,    19,    20,
      21,    22,   104,    48,    49,   105,    50,    51,    52,   106,
     117,   132,   129,    53,    54,   183,   133,   186,   109,    55,
     135,   103,    56,   165,   142,    57,   102,    58,    37,    38,
      18,    19,    20,    21,    22,    26,    27,    28,    29,    30,
     143,   148,    39,   166,  -115,    40,    41,    42,    43,    44,
      45,    46,   167,    57,   208,    47,   202,   173,    12,   174,
     207,   150,    48,    49,   152,    50,    51,    52,    91,   203,
     187,   210,    53,    54,   107,   108,     0,   109,    55,   110,
     111,    56,     0,   201,    57,   180,    58,    37,    38,    18,
      19,    20,    21,    22,     0,     0,     0,     0,   112,   113,
     114,    39,   206,  -115,    40,    41,    42,    43,    44,    45,
      46,     0,     0,     0,    47,     0,   115,     0,     0,     0,
       0,    48,    49,     0,    50,    51,    52,     0,     0,     0,
       0,    53,    54,     0,     0,     0,     0,    55,     0,     0,
      56,     0,     0,    57,   170,    58,    37,    38,    18,    19,
      20,    21,    22,     0,     0,     0,     0,     0,     0,     0,
      39,     0,     0,    40,    41,    42,    43,    44,    45,    46,
       0,     0,     0,    47,     0,    18,    19,    20,    21,    22,
      48,    49,     0,    50,    51,    52,     0,     0,     0,     0,
      53,    54,     0,    43,    44,     0,    55,     0,     0,    56,
      88,     0,    57,     0,    58,     0,     0,     0,    49,     0,
      50,    51,    52,     0,     0,     0,     0,    53,    54,     0,
       0,     0,    88,    55,     0,     0,    56,   192,     0,     0,
      49,    58,    50,    51,    52,   193,     0,   194,   195,   196,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
       0,     0,     0,    58,     0,     0,     0,     0,   197
};

static const yytype_int16 yycheck[] =
{
      39,    59,    16,   100,   138,     4,   164,    46,   142,    17,
      13,     4,    30,    83,    57,    58,    13,    56,    32,    13,
      10,    11,     0,    13,    13,    15,    16,   118,   119,   120,
     121,   122,   123,   167,    27,    30,    29,    38,     4,   173,
     174,    42,    47,    48,    34,    35,    36,    49,    50,    51,
      56,    59,    59,   211,    57,    94,   126,   127,   128,    98,
      57,    60,    52,    57,    56,   199,   200,   106,    57,    59,
      30,    12,   169,    87,    57,    58,    30,   116,    30,     3,
       4,     5,     6,     7,     8,     9,   124,   125,    56,   147,
      31,    32,    33,    17,    56,    19,    20,    21,    22,    23,
      24,    25,    26,    39,    45,    46,    30,     5,     6,     7,
       8,     9,     4,    37,    38,     4,    40,    41,    42,    56,
      14,     4,    19,    47,    48,   164,     4,   166,    13,    53,
      59,   189,    56,     4,    62,    59,    60,    61,     3,     4,
       5,     6,     7,     8,     9,     5,     6,     7,     8,     9,
      30,    61,    17,    52,    19,    20,    21,    22,    23,    24,
      25,    26,    18,    59,   203,    30,    39,    62,     5,    62,
      61,   109,    37,    38,   117,    40,    41,    42,    40,    63,
     167,    63,    47,    48,    10,    11,    -1,    13,    53,    15,
      16,    56,    -1,   189,    59,    60,    61,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    34,    35,
      36,    17,   200,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    52,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    41,    42,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      56,    -1,    -1,    59,    60,    61,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,     5,     6,     7,     8,     9,
      37,    38,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,
      47,    48,    -1,    23,    24,    -1,    53,    -1,    -1,    56,
      30,    -1,    59,    -1,    61,    -1,    -1,    -1,    38,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    -1,    30,    53,    -1,    -1,    56,    30,    -1,    -1,
      38,    61,    40,    41,    42,    38,    -1,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    27,    29,    65,    66,    67,    68,    69,    30,
      30,     0,    67,     4,    70,    56,    30,    71,     5,     6,
       7,     8,     9,    81,    57,    58,     5,     6,     7,     8,
       9,    72,    30,    59,    73,    81,    74,     3,     4,    17,
      20,    21,    22,    23,    24,    25,    26,    30,    37,    38,
      40,    41,    42,    47,    48,    53,    56,    59,    61,    75,
      76,    77,    78,    79,    80,    81,    82,    84,    88,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     107,   108,   119,   120,   121,   122,   124,    30,    30,    91,
     102,    98,    38,    42,    56,    87,    91,    56,    56,    91,
     123,    39,    60,    76,     4,     4,    56,    10,    11,    13,
      15,    16,    34,    35,    36,    52,    90,    14,    12,    31,
      32,    33,    45,    46,    47,    48,    49,    50,    51,    19,
     109,    96,     4,     4,    81,    59,   103,   104,    89,    85,
      86,    91,    62,    30,    83,    91,    57,    75,    61,    91,
      92,    91,    93,    94,    94,    94,    94,    94,    94,    95,
      95,    96,    96,    96,   110,     4,    52,    18,   106,     4,
      60,   105,   122,    62,    62,    57,   122,    57,    58,    57,
      60,    57,    78,    91,   111,   115,    91,   101,   122,    75,
     122,   122,    30,    38,    40,    41,    42,    61,   116,   112,
     113,   105,    39,    63,   114,   122,   114,    61,    91,   117,
      63,   118,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    67,    68,    70,
      69,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      74,    73,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    78,    78,
      78,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    85,
      84,    86,    84,    87,    84,    89,    88,    90,    90,    90,
      90,    90,    90,    91,    91,    92,    92,    93,    93,    93,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      95,    96,    96,    97,    97,    97,    98,    98,    98,    99,
      99,    99,   100,   100,   100,   100,   100,   101,   102,   103,
     103,   104,   105,   106,   106,   108,   107,   110,   109,   112,
     111,   113,   111,   114,   116,   117,   118,   115,   119,   120,
     120,   120,   121,   121,   123,   122,   124,   124
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     2,     0,
       8,     2,     4,     0,     1,     1,     1,     1,     1,     0,
       0,     4,     1,     2,     0,     2,     2,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     3,     5,     1,     1,
       1,     3,     2,     2,     1,     1,     1,     1,     1,     0,
       4,     3,     3,     3,     3,     3,     5,     1,     0,     0,
       5,     0,     5,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     3,     1,
       1,     0,     1,     1,     1,     1,     3,     4,     1,     4,
       2,     1,     1,     2,     2,     0,     3,     0,     3,     0,
       3,     0,     3,     1,     0,     0,     0,     8,     4,     1,
       1,     1,     4,     4,     0,     4,     1,     2
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
        case 8:
#line 134 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("package: %s\n", (yyvsp[0].s_val));
    }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 140 "compiler_hw3.y" /* yacc.c:1646  */
    {
        indent = ((yyvsp[0].s_val));
        printf("func: %s\n", (yyvsp[0].s_val)); 
    }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 143 "compiler_hw3.y" /* yacc.c:1646  */
    {
        dump_symbol();
    }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 155 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("int32");
    }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 158 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("float32");
    }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 161 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("string");
    }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 164 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("bool");
    }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 167 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.c_val) = ("char");
    }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 174 "compiler_hw3.y" /* yacc.c:1646  */
    {
        create_symbol();
        printf("func_signature: ("")'V'\n");
        insert_symbol(indent, "func");
    }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 202 "compiler_hw3.y" /* yacc.c:1646  */
    {
        insert_symbol((yyvsp[-1].s_val), (yyvsp[0].s_val));
        if(strcmp(getType((yyvsp[0].s_val)), "int32") == 0){
            CODEGEN("ldc 0\nistore %d\n", get_address((yyvsp[-1].s_val)));
        }
        else if(strcmp(getType((yyvsp[0].s_val)), "float32") == 0){
            CODEGEN("ldc 0.0\nfstore %d\n", get_address((yyvsp[-1].s_val)));
        }
        else if(strcmp(getType((yyvsp[0].s_val)), "string") == 0){
            CODEGEN("ldc \"\"\nastore %d\n", get_address((yyvsp[-1].s_val)));
        }
        else if(strcmp(getType((yyvsp[0].s_val)), "bool") == 0){
            CODEGEN("ldc 0\nistore %d\n", get_address((yyvsp[-1].s_val)));
        }
        else if(strcmp(getType((yyvsp[0].s_val)), "char") == 0){
            CODEGEN("ldc \'\'\nastore %d\n", get_address((yyvsp[-1].s_val)));
        }
    }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 220 "compiler_hw3.y" /* yacc.c:1646  */
    { // ldc will CODEGEN at expression->...->literal
        insert_symbol((yyvsp[-3].s_val), (yyvsp[-2].s_val)); 
        if(strcmp(getType((yyvsp[-2].s_val)), "int32") == 0){
            CODEGEN("istore %d\n", get_address((yyvsp[-3].s_val)));
        }
        else if(strcmp(getType((yyvsp[-2].s_val)), "float32") == 0){
            CODEGEN("fstore %d\n", get_address((yyvsp[-3].s_val)));
        }
        else if(strcmp(getType((yyvsp[-2].s_val)), "string") == 0){
            CODEGEN("astore %d\n", get_address((yyvsp[-3].s_val)));
        }
        else if(strcmp(getType((yyvsp[-2].s_val)), "bool") == 0){
            CODEGEN("istore %d\n", get_address((yyvsp[-3].s_val)));
        }
        else if(strcmp(getType((yyvsp[-2].s_val)), "char") == 0){
            CODEGEN("astore %d\n", get_address((yyvsp[-3].s_val)));
        }
    }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 247 "compiler_hw3.y" /* yacc.c:1646  */
    {
        strcpy(left, getType((yyvsp[-2].s_val)));
        strcpy(right, getType((yyvsp[0].s_val)));
        if(strcmp((yyvsp[-1].s_val), "ASSIGN") == 0){ // =
            if(strcmp(left, right) != 0){ // error: when assign, type mismatched
                g_has_error = 1;
                printf(error_message, "invalid operation: %s (mismatched types %s and %s)", (yyvsp[-1].s_val), left, right);
                yyerror(error_message);
            }
            else{
                if(strcmp(getType((yyvsp[0].s_val)), "int32") == 0){
                    CODEGEN("istore %d\n", get_address((yyvsp[-2].s_val)));
                }
                else if(strcmp(getType((yyvsp[0].s_val)), "float32") == 0){
                    CODEGEN("fstore %d\n", get_address((yyvsp[-2].s_val)));
                }
                else if(strcmp(getType((yyvsp[0].s_val)), "string") == 0){
                    CODEGEN("astore %d\n", get_address((yyvsp[-2].s_val)));
                }
                else if(strcmp(getType((yyvsp[0].s_val)), "bool") == 0){
                    CODEGEN("istore %d\n", get_address((yyvsp[-2].s_val)));
                }
                else if(strcmp(getType((yyvsp[0].s_val)), "char") == 0){
                    CODEGEN("astore %d\n", get_address((yyvsp[-2].s_val)));
                }
            }
        }
        else{
            if(strcmp((yyvsp[-1].s_val), "ADD_ASSIGN") == 0){
                if("int32" == getType((yyvsp[0].s_val))){
                    CODEGEN("iadd\nistore %d\n", get_address((yyvsp[-2].s_val)));
                }
                else{
                    CODEGEN("fadd\nfstore %d\n", get_address((yyvsp[-2].s_val)));
                }
            }
            else if((yyvsp[-1].s_val) == "SUB_ASSIGN"){
                if(strcmp(getType((yyvsp[0].s_val)), "int32") == 0){
                    CODEGEN("isub\nistore %d\n", get_address((yyvsp[-2].s_val)));
                }
                else{
                    CODEGEN("fsub\nfstore %d\n", get_address((yyvsp[-2].s_val)));
                }
            }
            else if(strcmp((yyvsp[-1].s_val), "MUL_ASSIGN") == 0){
                if(strcmp(getType((yyvsp[0].s_val)), "int32") == 0){
                    CODEGEN("imul\nistore %d\n", get_address((yyvsp[-2].s_val)));
                }
                else if(strcmp(getType((yyvsp[0].s_val)), "float32") == 0){
                    CODEGEN("fmul\nfstore %d\n",get_address((yyvsp[-2].s_val)));
                }
            }
            else if(strcmp((yyvsp[-1].s_val), "QUO_ASSIGN") == 0){
                if(strcmp(getType((yyvsp[0].s_val)), "int32") == 0){
                    CODEGEN("idiv\nistore %d\n", get_address((yyvsp[-2].s_val)));
                }
                else if(strcmp(getType((yyvsp[0].s_val)), "float32") == 0){
                    CODEGEN("fdiv\nfstore %d\n", get_address((yyvsp[-2].s_val)));
                }
            }
            else if(strcmp((yyvsp[-1].s_val), "REM_ASSIGN") == 0){ // only int32
                CODEGEN("irem\nistore %d\n", get_address((yyvsp[-2].s_val)));
            }
        }
        printf("%s\n",(yyvsp[-1].s_val));
    }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 316 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("INC\n");
        if(strcmp(getType((yyvsp[-1].s_val)), "int32") == 0){
            CODEGEN("iload %d\nldc 1\niadd\nistore %d\n", get_address((yyvsp[-1].s_val)), get_address((yyvsp[-1].s_val)));
        }
        else if(strcmp(getType((yyvsp[-1].s_val)), "float32") == 0){
            CODEGEN("fload %d\nldc 1.0\nfadd\nfstore %d\n", get_address((yyvsp[-1].s_val)), get_address((yyvsp[-1].s_val)));
        }
    }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 325 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("DEC\n");
        if(strcmp(getType((yyvsp[-1].s_val)), "int32") == 0){
            CODEGEN("iload %d\nldc 1\nisub\nistore %d\n", get_address((yyvsp[-1].s_val)), get_address((yyvsp[-1].s_val)));
        }
        else if(strcmp(getType((yyvsp[-1].s_val)), "float32") == 0){
            CODEGEN("fload %d\nldc 1.0\nfsub\nfstore %d\n", get_address((yyvsp[-1].s_val)), get_address((yyvsp[-1].s_val)));
        }
    }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 337 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("int32");
        if(scopeID - 1 >= 0){ // record type
            symbolTable[scopeID - 1].type[addr_cnt] = ("int32");
            symbolTable[scopeID - 1].func_sig[addr_cnt] = ("-");
        }
    }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 344 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("float32");  
        if(scopeID - 1 >= 0){
            symbolTable[scopeID - 1].type[addr_cnt] = "float32";
            symbolTable[scopeID - 1].func_sig[addr_cnt] = "-";
        }
    }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 351 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("string");  
        if(scopeID - 1 >= 0){
            symbolTable[scopeID - 1].type[addr_cnt] = ("string");
            symbolTable[scopeID - 1].func_sig[addr_cnt] = ("-");
        }      
    }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 358 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("bool"); 
        if(scopeID - 1 >= 0){
            symbolTable[scopeID - 1].type[addr_cnt] = ("bool");
            symbolTable[scopeID - 1].func_sig[addr_cnt] = ("-");
        }             
    }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 365 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.c_val) = ("char"); 
        if(scopeID - 1 >= 0){
            symbolTable[scopeID - 1].type[addr_cnt] = ("char");
            symbolTable[scopeID - 1].func_sig[addr_cnt] = ("-");
        }   
    }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 391 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("case %d\n", (yyvsp[0].i_val));
        case_arr[case_id] = (yyvsp[0].i_val);
        CODEGEN("L_case_%d:\n", case_id);
        case_id++;
    }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 396 "compiler_hw3.y" /* yacc.c:1646  */
    {
        CODEGEN("\tgoto L_switch_end_%d\n", case_pre_num);
    }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 399 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("case %c\n", (yyvsp[0].c_val));
        case_arr[case_id] = (yyvsp[0].c_val);
        CODEGEN("L_case_%c:\n", case_id);
        case_id++;
    }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 404 "compiler_hw3.y" /* yacc.c:1646  */
    {
        CODEGEN("\tgoto L_switch_end_%d\n", case_pre_num);
    }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 407 "compiler_hw3.y" /* yacc.c:1646  */
    {
        case_arr[case_id] = -1; // default
        CODEGEN("L_case_%d:\n", case_id);
    }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 410 "compiler_hw3.y" /* yacc.c:1646  */
    {
        CODEGEN("\tgoto L_switch_end_%d\n", case_pre_num);
    }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 416 "compiler_hw3.y" /* yacc.c:1646  */
    {
        CODEGEN("iload %d\ngoto L_switch_begin_%d\n", get_address((yyvsp[0].s_val)), case_pre_num);
    }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 418 "compiler_hw3.y" /* yacc.c:1646  */
    {
        CODEGEN("L_switch_begin_%d:\nlookupswitch\n", case_pre_num);
        int i = case_pre_num;
        while(i <= case_id){
            if(case_arr[i] == -1){
                CODEGEN("\tdefault: L_case_%d\n", i);
            }
            else{
                CODEGEN("\t%d: L_case_%d\n", case_arr[i], i);
            }
            i++;
        }  
        CODEGEN("L_switch_end_%d:\n", case_pre_num);
        case_pre_num = ++case_id;
    }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 436 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = "ASSIGN";
    }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 439 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("ADD_ASSIGN");
    }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 442 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("SUB_ASSIGN");
    }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 445 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("MUL_ASSIGN");
    }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 448 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("QUO_ASSIGN");
    }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 451 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("REM_ASSIGN");
    }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 457 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char *leftType = getType((yyvsp[-2].s_val));
        char *rightType = getType((yyvsp[0].s_val));
        (yyval.s_val) = ("bool");
        // type error
        strcpy(left, getType((yyvsp[-2].s_val)));
        strcpy(right, getType((yyvsp[0].s_val)));
        if(strcmp(left, "bool") != 0 || strcmp(right, "bool") != 0){
            if(strcmp(left, "bool") != 0){
                printf(error_message, "invalid operation: (operator LOR not defined on %s)", left);
            }
            else if(strcmp(right, "bool") != 0){
                printf(error_message, "invalid operation: (operator LOR not defined on %s)", right);
            }
            yyerror(error_message);
            g_has_error = 1;
        }
        else{
            CODEGEN("ior\n");
        }
        printf("LOR\n"); 
    }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 479 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ((yyvsp[0].s_val));
    }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 485 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        char *leftType = getType((yyvsp[-2].s_val));
        char *rightType = getType((yyvsp[0].s_val));
        (yyval.s_val) = ("bool"); 
        // type error
        strcpy(left, getType((yyvsp[-2].s_val)));
        strcpy(right, getType((yyvsp[0].s_val)));
        if(strcmp(left, "bool") != 0 || strcmp(right, "bool") != 0){
            if(strcmp(left, "bool") != 0){
                printf(error_message, "invalid operation: (operator LAND not defined on %s)", left);
            }
            else if(strcmp(right, "bool") != 0){
                printf(error_message, "invalid operation: (operator LAND not defined on %s)", right);
            }
            yyerror(error_message);
            g_has_error = 1;
        }
        else{
            CODEGEN("iand\n");
        }
        printf("LAND\n"); 
    }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 507 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ((yyvsp[0].s_val));
    }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 513 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        (yyval.s_val) = ("bool"); // return type is bool
        // type error
        strcpy(left, getType((yyvsp[-2].s_val)));
        strcpy(right, getType((yyvsp[0].s_val)));
        if(strcmp(left, right) != 0){
            g_has_error = 1;
            printf(error_message, "invalid operation: LSS (mismatched types %s and %s)", left, right);
            yyerror(error_message);
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fcmpl\n");
            }
            CODEGEN("iflt L_cmp_begin_%d\n\ticonst_0\n\tgoto L_cmp_end_%d\nL_cmp_begin_%d:\n\ticonst_1\nL_cmp_end_%d:\n", if_series_comp_id, if_series_comp_id, if_series_comp_id, if_series_comp_id++);
        }
        printf("LSS\n");
    }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 534 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("bool"); 
        // type error                               
        strcpy(left, getType((yyvsp[-2].s_val)));
        strcpy(right, getType((yyvsp[0].s_val)));
        if(strcmp(left, right) != 0){
            g_has_error = 1;
            printf(error_message, "invalid operation: GTR (mismatched types %s and %s)", left, right);
            yyerror(error_message);
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fcmpl\n");
            }
            CODEGEN("ifgt L_cmp_begin_%d\n\ticonst_0\n\tgoto L_cmp_end_%d\nL_cmp_begin_%d:\n\ticonst_1\nL_cmp_end_%d:\n", if_series_comp_id, if_series_comp_id, if_series_comp_id, if_series_comp_id);
            if_series_comp_id++;
        }
        printf("GTR\n");
    }
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 556 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        // type error      
        (yyval.s_val) = ("bool");            
        strcpy(left, getType((yyvsp[-2].s_val)));
        strcpy(right, getType((yyvsp[0].s_val)));
        if(strcmp(left, right) != 0){ 
            g_has_error = 1;
            printf(error_message, "invalid operation: LEQ (mismatched types %s and %s)", left, right);
            yyerror(error_message);
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fcmpl\n");
            }
            CODEGEN("ifle L_cmp_begin_%d\n\ticonst_0\n\tgoto L_cmp_end_%d\nL_cmp_begin_%d:\n\ticonst_1\nL_cmp_end_%d:\n", if_series_comp_id, if_series_comp_id, if_series_comp_id, if_series_comp_id);
            if_series_comp_id++;
        }
        printf("LEQ\n"); 
    }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 578 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        // type error
        strcpy(left, getType((yyvsp[-2].s_val)));
        strcpy(right, getType((yyvsp[0].s_val)));
        if(strcmp(left, right) != 0){
            g_has_error = 1;
            printf(error_message, "invalid operation: GEQ (mismatched types %s and %s)", left, right);
            yyerror(error_message); 
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fcmpl\n");
            }
            CODEGEN("ifge L_cmp_begin_%d\n\ticonst_0\n\tgoto L_cmp_end_%d\nL_cmp_begin_%d:\n\ticonst_1\nL_cmp_end_%d:\n", if_series_comp_id, if_series_comp_id, if_series_comp_id, if_series_comp_id);
            if_series_comp_id++;
        }
        (yyval.s_val) = ("bool");
        printf("GEQ\n");
    }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 600 "compiler_hw3.y" /* yacc.c:1646  */
    {
        // type error
        (yyval.s_val) = ("bool");
        strcpy(left, getType((yyvsp[-2].s_val)));
        strcpy(right, getType((yyvsp[0].s_val)));
        if(strcmp(left, right) != 0){
            g_has_error = 1;
            printf(error_message, "invalid operation: EQL (mismatched types %s and %s)", left, right);
            yyerror(error_message);  
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fcmpl\n");
            }
            CODEGEN("ifeq L_cmp_begin_%d\n\ticonst_0\n\tgoto L_cmp_end_%d\nL_cmp_begin_%d:\n\ticonst_1\nL_cmp_end_%d:\n", if_series_comp_id, if_series_comp_id, if_series_comp_id, if_series_comp_id);
            if_series_comp_id++;
        }
        printf("EQL\n");
    }
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 622 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        (yyval.s_val) = ("bool");
        // type error
        strcpy(left, getType((yyvsp[-2].s_val)));
        strcpy(right, getType((yyvsp[0].s_val)));
        if(strcmp(left, right) != 0){
            g_has_error = 1;
            printf(error_message, "invalid operation: NEQ (mismatched types %s and %s)", left, right);
            yyerror(error_message);
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fcmpl\n");
            }
            CODEGEN("ifne L_cmp_begin_%d\n\ticonst_0\n\tgoto L_cmp_end_%d\nL_cmp_begin_%d:\n\ticonst_1\nL_cmp_end_%d:\n", if_series_comp_id, if_series_comp_id, if_series_comp_id, if_series_comp_id);
            if_series_comp_id++;
        }
        printf("NEQ\n");
    }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 644 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ((yyvsp[0].s_val));
    }
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 650 "compiler_hw3.y" /* yacc.c:1646  */
    {
        // type error
        strcpy(left, getType((yyvsp[-2].s_val)));
        strcpy(right, getType((yyvsp[0].s_val)));
        if(strcmp(left, right) != 0){ 
            printf(error_message, "invalid operation: ADD (mismatched types %s and %s)", left,right);
            yyerror(error_message);
            g_has_error = 1;
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("iadd\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fadd\n");
            }
        }
        printf("ADD\n");
    }
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 669 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        // type error
        strcpy(left, getType((yyvsp[-2].s_val)));
        strcpy(right, getType((yyvsp[0].s_val)));
        if(strcmp(left, right) != 0){
            printf(error_message, "invalid operation: SUB (mismatched types %s and %s)", left,right);
            yyerror(error_message);
            g_has_error = 1;        
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){                        
                CODEGEN("fsub\n");
            }
        }
        printf("SUB\n"); 
    }
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 688 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ((yyvsp[0].s_val));
    }
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 694 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp(getType((yyvsp[-2].s_val)), "int32") == 0 && strcmp(getType((yyvsp[0].s_val)), "int32") == 0){
            CODEGEN("imul\n");
        }
        else{ // int32/float32 or float32/int32 or float32/float32
            CODEGEN("fmul\n");
        }
        printf("MUL\n");
    }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 703 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp(getType((yyvsp[-2].s_val)), "int32") == 0 && strcmp(getType((yyvsp[0].s_val)), "int32") == 0){
            CODEGEN("idiv\n");
        }
        else{ // int32/float32 or float32/int32 or float32/float32
            CODEGEN("fdiv\n");
        }
        printf("QUO\n"); 
    }
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 712 "compiler_hw3.y" /* yacc.c:1646  */
    {
        // type error
        strcpy(left, getType((yyvsp[-2].s_val)));
        strcpy(right, getType((yyvsp[0].s_val)));                               
        if(strcmp(left, "int32") != 0 || strcmp(right, "int32") != 0){
            g_has_error = 1;
            if(strcmp(left, "int32") != 0){
                printf(error_message, "invalid operation: (operator REM not defined on %s)", left);
                g_has_error = 1;
            }
            else{
                printf(error_message, "invalid operation: (operator REM not defined on %s)", right);
                g_has_error = 1;
            }
            yyerror(error_message);                                
        }
        else{
            CODEGEN("irem\n");
        }
        printf("REM\n"); 
    }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 733 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ((yyvsp[0].s_val));
    }
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 739 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ((yyvsp[0].s_val));
    }
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 742 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("%s\n", (yyvsp[-1].s_val)); 
        (yyval.s_val) = (getType((yyvsp[0].s_val)));
        if(strcmp((yyvsp[-1].s_val), "POS") == 0){
            ; // do nothing
        }
        else if(strcmp((yyvsp[-1].s_val), "NEG") == 0){
            if(strcmp(getType((yyvsp[0].s_val)), "int32") == 0){
                CODEGEN("ineg\n");
            }
            else if(strcmp(getType((yyvsp[0].s_val)), "float32") == 0){
                CODEGEN("fneg\n");
            }
        }
        else if(strcmp(getType((yyvsp[-1].s_val)), "NOT") == 0){
            CODEGEN("iconst_1\n");
            CODEGEN("ixor\n");
        } 
    }
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 764 "compiler_hw3.y" /* yacc.c:1646  */
    { // literal, indent, (expression)
        (yyval.s_val) = ((yyvsp[0].s_val));
    }
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 767 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = (getType((yyvsp[0].s_val)));
    }
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 774 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ((yyvsp[0].s_val));
    }
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 777 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ((yyvsp[0].s_val)); 
        int isdefined = 0;
        int ii = 0;
        while(ii < scopeID){
            int jj = 0;
            while(jj < N){
                if(strcmp(symbolTable[ii].name[jj], (yyvsp[0].s_val)) == 0){
                    isdefined = 1;
                }
                jj++;
            }
            ii++;
        }
        if(isdefined == 0){ // error: undefine
            g_has_error = 1;
            printf("error:%d: undefined: %s\n", yylineno + 1, (yyvsp[0].s_val));
        }
        lookup_symbol((yyvsp[0].s_val));
        if(strcmp(getType((yyvsp[0].s_val)), "float32") == 0){
            CODEGEN("fload %d\n", get_address((yyvsp[0].s_val)));
        }
        else if(strcmp(getType((yyvsp[0].s_val)), "int32") == 0){
            CODEGEN("iload %d\n", get_address((yyvsp[0].s_val)));
        }
        else if(strcmp(getType((yyvsp[0].s_val)), "bool") == 0 
                || strcmp(getType((yyvsp[0].s_val)), "string") == 0
                || strcmp(getType((yyvsp[0].s_val)), "char") == 0){ // string or bool or char
            CODEGEN("aload %d\n", get_address((yyvsp[0].s_val)));
        }
    }
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 808 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = (getType((yyvsp[-1].s_val)));
    }
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 814 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("TRUE 1\n");
        (yyval.s_val) = ("bool");
        CODEGEN("iconst_1\n");
    }
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 819 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("FALSE 0\n");
        (yyval.s_val) = ("bool");
        CODEGEN("iconst_0\n");
    }
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 828 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("int32"); 
        printf("INT_LIT %d\n", (yyvsp[0].i_val)); 
        CODEGEN("ldc %d\n", (yyvsp[0].i_val));
    }
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 833 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("float32"); 
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
        CODEGEN("ldc %f\n", (yyvsp[0].f_val));
    }
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 838 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("bool");
        printf("BOOL_LIT %d\n", (yyvsp[0].b_val));
        CODEGEN("ldc %d\n", (yyvsp[0].b_val));
    }
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 843 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("char");
        printf("CHAR_LIT %c\n", (yyvsp[0].c_val));
        CODEGEN("ldc %c\n", (yyvsp[0].c_val));
    }
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 848 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("string");
        printf("STRING_LIT %s\n", (yyvsp[-1].s_val));
        CODEGEN("ldc \"%s\"\n", (yyvsp[-1].s_val)); 
    }
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 860 "compiler_hw3.y" /* yacc.c:1646  */
    {
         if(strcmp("bool", getType((yyvsp[0].s_val))) != 0){
            printf(error_message, "non-bool (type %s) used as for condition", getType((yyvsp[0].s_val)));
            yyerror(error_message);
            g_has_error = 1;
        }
    }
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 875 "compiler_hw3.y" /* yacc.c:1646  */
    {
        create_symbol();
    }
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 881 "compiler_hw3.y" /* yacc.c:1646  */
    {
        dump_symbol();
    }
#line 2512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 892 "compiler_hw3.y" /* yacc.c:1646  */
    {
        forLevel++;
    }
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 894 "compiler_hw3.y" /* yacc.c:1646  */
    {
        forLevel--;
    }
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 900 "compiler_hw3.y" /* yacc.c:1646  */
    {
        forNum++;
        if(forLevel == 1){
            previous_for = forNum;
        }
        else{
            ;
        }
        CODEGEN("L%d_for_begin:\n", forNum); 
    }
#line 2543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 910 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(num_of_ForClause != 0){
            if(forLevel == 1){
                CODEGEN("\tgoto L%d_for_Post\n", previous_for); 
            }
            else if(forLevel != 1){
                CODEGEN("\tgoto L%d_for_Post\n", forNum);
            }
        }
        else{
            if(forLevel == 1){
                CODEGEN("\tgoto L%d_for_begin\n", previous_for); 
            }
            else if(forLevel != 1){
                CODEGEN("\tgoto L%d_for_begin\n", forNum); 
            }
        }

        // multi level for loop
        if(forLevel == 1){
            CODEGEN("L%d_for_exit:\n", previous_for); 
        }
        else if(forLevel != 1){
            CODEGEN("L%d_for_exit:\n", forNum);
        }
        num_of_ForClause--;
    }
#line 2575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 940 "compiler_hw3.y" /* yacc.c:1646  */
    { // for(x > 0)
        CODEGEN("\tifeq L%d_for_exit \n", forNum); 
    }
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 943 "compiler_hw3.y" /* yacc.c:1646  */
    { // for(int i = 0; i < 10; i++)
        CODEGEN("L%d_for_Block:\n", forNum); 
    }
#line 2591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 953 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        num_of_ForClause++; 
        CODEGEN("L%d_for_Condition:\n", forNum);
    }
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 956 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        CODEGEN("\tifeq L%d_for_exit \n\tgoto L%d_for_Block \n", forNum, forNum); 
    }
#line 2608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 958 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        CODEGEN("L%d_for_Post:\n", forNum); 
    }
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 960 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        CODEGEN("\tgoto L%d_for_Condition \n", forNum); 
    }
#line 2624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 978 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("%c2%c\n", getType((yyvsp[-1].s_val))[0], getType((yyvsp[-3].s_val))[0]);
        CODEGEN("%c2%c\n", getType((yyvsp[-1].s_val))[0], getType((yyvsp[-3].s_val))[0]);
        (yyval.s_val) = (getType((yyvsp[-3].s_val)));
    }
#line 2634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1046 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("POS");
    }
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1049 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("NEG");
    }
#line 2650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1052 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = ("NOT");
    }
#line 2658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1058 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char tmp[10] = ""; 
        strcpy(tmp, getType((yyvsp[-1].s_val)));
        printf("PRINT %s\n", tmp);
        CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\n");
        if(strcmp(getType((yyvsp[-1].s_val)), "int32") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/print(I)V\n");
        }
        else if(strcmp(getType((yyvsp[-1].s_val)), "float32") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/print(F)V\n");
        }
        else if(strcmp(getType((yyvsp[-1].s_val)), "bool") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/print(Z)V\n");
            // CODEGEN("invokevirtual java/io/PrintStream/print(Ljava/lang/BOOL;)V\n");
        }
        else if(strcmp(getType((yyvsp[-1].s_val)), "string") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        }
    }
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1077 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char tmp[10] = ""; 
        strcpy(tmp, getType((yyvsp[-1].s_val)));
        printf("PRINTLN %s\n", tmp);
        CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\n");
        if(strcmp(getType((yyvsp[-1].s_val)), "int32") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/println(I)V\n");
        }
        else if(strcmp(getType((yyvsp[-1].s_val)), "float32") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/println(F)V\n");
        }
        else if(strcmp(getType((yyvsp[-1].s_val)), "bool") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/println(Z)V\n");
            // CODEGEN("invokevirtual java/io/PrintStream/print(Ljava/lang/BOOL;)V\n");
        }
        else if(strcmp(getType((yyvsp[-1].s_val)), "string") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
        }
    }
#line 2706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1099 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        create_symbol();
    }
#line 2714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1101 "compiler_hw3.y" /* yacc.c:1646  */
    {
        dump_symbol();
    }
#line 2722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1107 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("return\n");
    }
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1110 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("return\n");
    }
#line 2738 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2742 "y.tab.c" /* yacc.c:1646  */
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
#line 1115 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */

void initial(){
    int i = 0;
    while(i < M){
        int j = 0;
        while(j < N){
            symbolTable[i].name[j] = "";
            symbolTable[i].type[j] = "";
            symbolTable[i].addr[j] = -2;
            symbolTable[i].index[j] = -1;
            symbolTable[i].func_sig[j] = "";
            symbolTable[i].lineno[j] = 0;
            symbolTable[i].scope_level[j] = 0;
            j++;
        }
        i++;
    }
}

void initial2(int scope){
    int j = 0;
    while(j < N){
        symbolTable[scope].type[j] = "";
        symbolTable[scope].name[j] = "";
        symbolTable[scope].func_sig[j] = "";
        symbolTable[scope].addr[j] = -2;
        symbolTable[scope].index[j] = -1;
        symbolTable[scope].scope_level[j] = 0;
        symbolTable[scope].lineno[j] = 0;
        j++;
    }
    inside_each_scope_id[scope] = 0;
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", argv[1]);
        exit(1);
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    CODEGEN(".source hw3.j\n");
    CODEGEN(".class public Main\n");
    CODEGEN(".super java/lang/Object\n");
    CODEGEN(".method public static main([Ljava/lang/String;)V\n");
    CODEGEN(".limit stack 100\n");
    CODEGEN(".limit locals 100\n\n");

    /* Symbol table init */
    // Add your code

    yylineno = 0;
    initial();
    create_symbol(); 
    yyparse();

    /* Symbol table dump */
    // Add your code

	printf("Total lines: %d\n", yylineno);
    CODEGEN("\treturn\n.end method\n");
    fclose(fout);
    fclose(yyin);

    if (g_has_error) {
       remove(bytecode_filename);
    }
    dump_symbol();
    yylex_destroy();
    return 0;
}

static void create_symbol() {     
    printf("> Create symbol table (scope level %d)\n", scopeID++);
}

static void insert_symbol(char *indent, char *type) {
    int id = 0;
    if(first_insert == 0){
        id = scopeID - 1;
    }
    int i = 0;
    while(i < N){
        if(strcmp(indent, symbolTable[scopeID - 1].name[i]) == 0){ // redefine
            printf(error_message, "%s redeclared in this block. previous declaration at line %d",
                    indent, symbolTable[scopeID - 1].lineno[i]);
            yyerror(error_message);
            g_has_error = 1;
        }
        i++;
    }
    if(id >= 0){
        symbolTable[id].type[inside_each_scope_id[id]] = type;
        symbolTable[id].name[inside_each_scope_id[id]] = indent;
        symbolTable[id].addr[inside_each_scope_id[id]] = addr_cnt;
        symbolTable[id].index[inside_each_scope_id[id]] = inside_each_scope_id[id];
        if(strcmp(indent, "main") == 0){
            symbolTable[id].lineno[inside_each_scope_id[id]] = yylineno + 1;
            symbolTable[id].func_sig[inside_each_scope_id[id]] = "()V";
        }
        else if(strcmp(indent, "main") != 0){
            symbolTable[id].lineno[inside_each_scope_id[id]] = yylineno;
            symbolTable[id].func_sig[inside_each_scope_id[id]] = "-";
        }
        printf("> Insert `%s` (addr: %d) to scope level %d\n", indent, addr_cnt, id);
        inside_each_scope_id[id]++;
        addr_cnt++;
        if(first_insert == 1){
            first_insert = 0;
        }
    }
}

static void lookup_symbol(char* indent) {
    int flag = 0;
    int id = scopeID - 1;
    while(id >= 0){
        if(flag != 0){
            break;
        }
        int i = 0;
        while(i < N){
            if(strcmp(indent, symbolTable[id].name[i]) == 0){
                printf("IDENT (name=%s, address=%d)\n", indent,symbolTable[id].addr[i]);
                flag = 1;
                break;
            }
            i++;
        }
        id--;
    }
}

static void dump_symbol() {
    int id = 0;
    if (scopeID == 0){
        id = 0;
    }
    else{
        id = scopeID - 1;
    }
    printf("\n> Dump symbol table (scope level: %d)\n", id);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "Index", "Name", "Type", "Addr", "Lineno", "Func_sig");
    int j = 0;
    while(j < N){
        if(symbolTable[id].index[j] != -1){
            printf("%-10d%-10s%-10s%-10d%-10d%-10s\n",
                    j, symbolTable[id].name[j], symbolTable[id].type[j], symbolTable[id].addr[j],symbolTable[id].lineno[j], symbolTable[id].func_sig[j]);
        }
        j++;
    } 
    printf("\n");
    // reset
    initial2(scopeID - 1);
    scopeID --;
}

char *getType(char *indent){
    if(strcmp("float32", indent) == 0 || strcmp("int32", indent) == 0 
        || strcmp("bool", indent) == 0 || strcmp("string", indent) == 0
        || strcmp("char", indent) == 0){
        return strdup(indent);
    }
    else{
        int i = scopeID - 1;
        while(i >= 0){
            int j = 0;
            while(j < N){
                if(strcmp(indent, symbolTable[i].name[j]) == 0){
                    return strdup(symbolTable[i].type[j]);
                }
                j++;
            }
            i--;
        }
        return strdup("ERROR");
    }
}

int get_address(char *indent){
    int i = scopeID - 1;
    while(i >= 0){
        int j = 0;
        while(j < N){
            if(strcmp(indent, symbolTable[i].name[j]) == 0){
                return symbolTable[i].addr[j];
            }
            j++;
        }
        i--;
    }
    return 0;
}
