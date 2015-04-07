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
#line 1 "semantico.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "string.h"
#include "simbol_table.h" 
extern int yylex(void);
extern char *yytext;
extern int linea;
extern FILE *yyin;
void yyerror(char *s);
int yystopparser = 0;


#line 82 "semantico.tab.c" /* yacc.c:339  */

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
   by #include "semantico.tab.h".  */
#ifndef YY_YY_SEMANTICO_TAB_H_INCLUDED
# define YY_YY_SEMANTICO_TAB_H_INCLUDED
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
    CONSTANTE = 258,
    ENTERO = 259,
    DECIMAL = 260,
    BOOLEANO = 261,
    STRING = 262,
    SUMA = 263,
    RESTA = 264,
    MULTIPLICACION = 265,
    DIVISION = 266,
    COMPLEJO = 267,
    AUMENTAR = 268,
    DISMINUIR = 269,
    MAYOR = 270,
    MENOR = 271,
    IGUAL = 272,
    DIFERENTE = 273,
    VOID = 274,
    MAIN = 275,
    T_ENTERO = 276,
    T_DECIMAL = 277,
    T_BOOLEANO = 278,
    T_COMPLEJO = 279,
    ASIGNADOR = 280,
    DEFINE = 281,
    ID_MACRO = 282,
    ELSE = 283,
    FOR = 284,
    WHILE = 285,
    IF = 286,
    ELIF = 287,
    T_STRING = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 16 "semantico.y" /* yacc.c:355  */

        char *cadena;
        int entero;   

#line 161 "semantico.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SEMANTICO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 176 "semantico.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

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
      34,    35,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    68,    70,    73,    73,    75,    76,    78,
      79,    81,    82,    83,    84,    86,    88,    88,    90,    90,
      92,    92,    94,    95,    96,    97,    98,   101,   109,   121,
     122,   123,   124,   125,   128,   129,   130,   141,   142,   148,
     149,   162,   175,   190,   191,   193,   194,   203,   204,   205,
     206,   208,   222,   234,   235,   237,   238,   239,   246,   247,
     248,   250,   251,   252,   254,   256,   257,   270,   283,   299,
     300,   301,   302,   305,   308,   309,   312,   319,   328,   335
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANTE", "ENTERO", "DECIMAL",
  "BOOLEANO", "STRING", "SUMA", "RESTA", "MULTIPLICACION", "DIVISION",
  "COMPLEJO", "AUMENTAR", "DISMINUIR", "MAYOR", "MENOR", "IGUAL",
  "DIFERENTE", "VOID", "MAIN", "T_ENTERO", "T_DECIMAL", "T_BOOLEANO",
  "T_COMPLEJO", "ASIGNADOR", "DEFINE", "ID_MACRO", "ELSE", "FOR", "WHILE",
  "IF", "ELIF", "T_STRING", "'('", "')'", "'{'", "'}'", "';'", "','",
  "'['", "']'", "$accept", "programa", "principal", "macro",
  "lineascodigo", "lineacodigo", "linea", "invocarmetodo", "parametros",
  "parametroenvio", "parenvio", "valor", "crearvariable", "tipodato",
  "asignarvalor", "aritmetico", "opcomun", "opcomplemento", "oprcom",
  "tipoopr", "cambiarvalor", "cambvariable", "indis", "cambvalor",
  "buclecondicion", "condicionif", "condicionsi", "condicion",
  "condicional", "condicionno", "condicionessino", "condicionsino",
  "buclefor", "iniciafor", "buclewhile", YY_NULLPTR
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
     285,   286,   287,   288,    40,    41,   123,   125,    59,    44,
      91,    93
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,   -15,    19,    -5,     4,   -75,    -2,   -75,     7,    54,
       5,   -75,   -75,   -75,   -75,   -75,    -5,     8,   -75,     6,
      16,   -75,   -75,   -75,   -75,     9,    14,    17,   -75,    28,
       6,   -75,    34,    35,    39,    41,   -75,   -75,    -8,   -75,
     -75,    11,    50,   -11,    64,    64,   -75,   -75,   -75,   -75,
      52,   -75,    46,    55,   -75,    -8,   -75,   133,   133,   -75,
     133,   -75,   -75,    71,    68,   -75,   -75,   105,    79,    81,
      81,    74,    83,    78,   -75,     6,    64,   -75,   -75,   -75,
     -75,   -75,   -75,    88,    98,   133,   -75,   108,   -75,    50,
      52,    64,   -75,   -75,   -75,   -75,   118,   128,    76,    86,
     133,   133,   -75,    87,    84,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,    89,   -75,   -75,   -75,   -75,     6,
       6,   -75,    96,   126,    97,   104,     6,    -6,   102,   -75,
     -75,   106,   -75,   -75,   -75,    99,   -75,     6,   107,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     0,     2,     0,     0,
       0,    22,    23,    24,    25,    26,     6,     0,     5,     8,
       0,    29,    30,    31,    33,     0,     0,     0,    32,     0,
       7,    10,     0,     0,     0,     0,    14,    58,    61,    59,
      60,     0,    17,     0,     0,     0,     4,     9,    11,    12,
      27,    13,     0,     0,    62,     0,    75,    57,    55,    56,
      37,    51,    21,     0,    16,    19,    20,     0,     0,     0,
       0,     0,     0,     0,    28,     8,     0,    63,    74,    47,
      48,    49,    50,     0,     0,    38,    44,     0,    15,     0,
       0,     0,    69,    70,    71,    72,     0,     0,     0,     0,
      36,    35,    34,     0,     0,    42,    41,    40,    39,    43,
      46,    45,    18,    78,     0,    68,    67,    66,    65,     8,
       8,    73,     0,     0,     0,     0,     8,     0,     0,    79,
      64,     0,    53,    54,    52,     0,    76,     8,     0,    77
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   130,   -74,   -75,   119,   -75,   -75,   -75,
      61,    -9,   -75,   109,    63,    82,   -75,   -75,    66,   -54,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -42,    90,   101,
     -75,   103,   -75,   -75,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    29,    30,    31,    32,    63,    64,
      65,    70,    33,    34,    74,    59,    60,    85,    86,    83,
      35,   128,   134,    61,    36,    37,    38,    71,    96,    54,
      55,    56,    39,    68,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,   103,     1,    72,    84,     4,    87,   132,   133,    20,
      21,    22,    23,    24,    57,    11,    12,    13,    14,     5,
      52,     6,    28,    15,    53,     9,    10,    21,    22,    23,
      24,    87,    58,    66,   104,    25,    26,    27,     8,    28,
      17,    41,    50,    43,    19,   124,   125,    84,    44,   114,
      42,    45,   131,    62,    11,    12,    13,    14,    11,    12,
      13,    14,    15,   138,   101,    46,    15,    69,    11,    12,
      13,    14,    48,    49,   106,   108,    15,    73,   111,    51,
      66,   100,    11,    12,    13,    14,    75,   116,   118,    76,
      15,   105,    11,    12,    13,    14,    92,    93,    94,    95,
      15,   107,    11,    12,    13,    14,    88,    89,    90,    98,
      15,   110,    11,    12,    13,    14,   119,    91,    99,   122,
      15,   115,    11,    12,    13,    14,   120,   123,   121,   127,
      15,   117,    11,    12,    13,    14,   126,   135,   129,   137,
      15,    79,    80,    81,    82,   130,    18,   136,   139,    47,
     112,   109,    67,   113,     0,   102,    77,     0,    78,     0,
      97
};

static const yytype_int16 yycheck[] =
{
       9,    75,    19,    45,    58,    20,    60,    13,    14,     3,
      21,    22,    23,    24,     3,     4,     5,     6,     7,     0,
      28,    26,    33,    12,    32,    27,    19,    21,    22,    23,
      24,    85,    41,    42,    76,    29,    30,    31,    34,    33,
      35,    25,     3,    34,    36,   119,   120,   101,    34,    91,
      34,    34,   126,     3,     4,     5,     6,     7,     4,     5,
       6,     7,    12,   137,    73,    37,    12,     3,     4,     5,
       6,     7,    38,    38,    83,    84,    12,    25,    87,    38,
      89,     3,     4,     5,     6,     7,    40,    96,    97,    34,
      12,     3,     4,     5,     6,     7,    15,    16,    17,    18,
      12,     3,     4,     5,     6,     7,    35,    39,     3,    35,
      12,     3,     4,     5,     6,     7,    40,    38,    35,    35,
      12,     3,     4,     5,     6,     7,    40,    38,    41,     3,
      12,     3,     4,     5,     6,     7,    40,    35,    41,    40,
      12,     8,     9,    10,    11,    41,    16,    41,    41,    30,
      89,    85,    43,    90,    -1,    73,    55,    -1,    55,    -1,
      70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    43,    44,    20,     0,    26,    45,    34,    27,
      19,     4,     5,     6,     7,    12,    53,    35,    45,    36,
       3,    21,    22,    23,    24,    29,    30,    31,    33,    46,
      47,    48,    49,    54,    55,    62,    66,    67,    68,    74,
      76,    25,    34,    34,    34,    34,    37,    48,    38,    38,
       3,    38,    28,    32,    71,    72,    73,     3,    53,    57,
      58,    65,     3,    50,    51,    52,    53,    55,    75,     3,
      53,    69,    69,    25,    56,    40,    34,    71,    73,     8,
       9,    10,    11,    61,    61,    59,    60,    61,    35,    39,
       3,    38,    15,    16,    17,    18,    70,    70,    35,    35,
       3,    53,    57,    46,    69,     3,    53,     3,    53,    60,
       3,    53,    52,    56,    69,     3,    53,     3,    53,    40,
      40,    41,    35,    38,    46,    46,    40,     3,    63,    41,
      41,    46,    13,    14,    64,    35,    41,    40,    46,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    45,    45,    46,    46,    47,
      47,    48,    48,    48,    48,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    56,    56,    56,    57,    57,    58,
      58,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    62,    63,    64,    64,    65,    65,    65,    66,    66,
      66,    67,    67,    67,    68,    69,    69,    69,    69,    70,
      70,    70,    70,    71,    72,    72,    73,    74,    75,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     8,     4,     3,     1,     0,     2,
       1,     2,     2,     2,     1,     4,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     2,     2,     2,     1,     2,     3,
       3,     3,     3,     2,     1,     2,     2,     1,     1,     1,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     7,     3,     3,     3,     3,     1,
       1,     1,     1,     4,     2,     1,     7,    11,     3,     7
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
        case 22:
#line 94 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=(yyvsp[0].entero);}
#line 1358 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 95 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=(yyvsp[0].entero);}
#line 1364 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 96 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=(yyvsp[0].entero);}
#line 1370 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 97 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=(yyvsp[0].entero);}
#line 1376 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 98 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=(yyvsp[0].entero);}
#line 1382 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 101 "semantico.y" /* yacc.c:1646  */
    {
                                        if (buscar_elemento((yyvsp[0].cadena))==0){
                                          ins_inicio_lista((yyvsp[0].cadena), (yyvsp[-1].entero), 0);
                                        }
                                        else {
                                          printf("Aviso[linea %d]: variable %s previamente definida\n", linea, (yyvsp[0].cadena));
                                        }
                                      }
#line 1395 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 109 "semantico.y" /* yacc.c:1646  */
    {
                                                      if (buscar_elemento((yyvsp[-1].cadena))==0){
                                                        ins_inicio_lista((yyvsp[-1].cadena), (yyvsp[-2].entero), 0);
                                                      }
                                                      else {
                                                        printf("Aviso[linea %d]: variable %s previamente definida\n", linea, (yyvsp[-1].cadena));
                                                      }
                                                      if((yyvsp[-2].entero)!=(yyvsp[0].entero)){
                                                        printf("Error[linea %d]: se le asigna un tipo de dato diferente a la variable %s\n", linea, (yyvsp[-1].cadena));
                                                      }
                                                    }
#line 1411 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 121 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=1;}
#line 1417 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 122 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=2;}
#line 1423 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 123 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=3;}
#line 1429 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 124 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=4;}
#line 1435 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 125 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=5;}
#line 1441 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 128 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=(yyvsp[0].entero);}
#line 1447 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 129 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=(yyvsp[0].entero);}
#line 1453 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 130 "semantico.y" /* yacc.c:1646  */
    {
                                              int operando1 = obtener_tipo_elemento((yyvsp[0].cadena));
                                              if (operando1!=-1){
                                                (yyval.entero) = operando1;
                                              }
                                              else{
                                                printf("Error[linea %d]: la variable %s no esta definida o es de un tipo diferente\n", linea,(yyvsp[0].cadena));
                                                (yyval.entero) = -1;
                                              }
                                            }
#line 1468 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 141 "semantico.y" /* yacc.c:1646  */
    { (yyval.entero) = (yyvsp[0].entero); }
#line 1474 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 142 "semantico.y" /* yacc.c:1646  */
    {
                                              (yyval.entero) = check_operacion_aritmetica((yyvsp[-1].entero),((yyvsp[0].entero)%10),(int)((yyvsp[0].entero)/10)); 
                                            }
#line 1482 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 148 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero) = check_operacion_aritmetica((yyvsp[-2].entero),(yyvsp[0].entero),(yyvsp[-1].entero));}
#line 1488 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 149 "semantico.y" /* yacc.c:1646  */
    {
                                                    if (check_Variable((yyvsp[0].cadena))!=0){
                                                      int tipo = obtener_tipo_elemento((yyvsp[0].cadena));
                                                      if (tipo!=-1){
                                                        (yyval.entero) = check_operacion_aritmetica((yyvsp[-2].entero),tipo,(yyvsp[-1].entero));
                                                      }
                                                      else{
                                                        printf("Error[linea %d]: la variable %s es de un tipo diferente al valor que se le quiere asignar\n", linea,(yyvsp[0].cadena));
                                                        (yyval.entero) = -1;
                                                      }
                                                    }
                                                    else (yyval.entero) = -1;
                                                  }
#line 1506 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 162 "semantico.y" /* yacc.c:1646  */
    {
                                                    if (check_Variable((yyvsp[-2].cadena))!=0){
                                                      int tipo = obtener_tipo_elemento((yyvsp[-2].cadena));
                                                      if (tipo!=-1){
                                                        (yyval.entero) = check_operacion_aritmetica(tipo,(yyvsp[0].entero),(yyvsp[-1].entero));
                                                      }
                                                      else{
                                                        printf("Error[linea %d]: la variable %s es de un tipo diferente al valor que se le quiere asignar\n", linea,(yyvsp[-2].cadena));
                                                        (yyval.entero) = -1;
                                                      }
                                                    }
                                                    else (yyval.entero) = -1;
                                                  }
#line 1524 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 175 "semantico.y" /* yacc.c:1646  */
    {
                                                    int operando1 = obtener_tipo_elemento((yyvsp[-2].cadena));
                                                    int operando2 = obtener_tipo_elemento((yyvsp[0].cadena));
                                                    if (operando1!=-1 && operando2!=-1){
                                                      if (operando1==operando2){
                                                        (yyval.entero) = operando1;
                                                      }
                                                      else{
                                                        printf("Error[linea %d]: la variable %s es de un tipo diferente al de la variable %s\n", linea,(yyvsp[-2].cadena),(yyvsp[0].cadena));
                                                        (yyval.entero) = -1;
                                                      }
                                                    }
                                                    else (yyval.entero) = -1;
                                                  }
#line 1543 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 190 "semantico.y" /* yacc.c:1646  */
    { (yyval.entero) = (yyvsp[0].entero); }
#line 1549 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 191 "semantico.y" /* yacc.c:1646  */
    { (yyval.entero) = (yyvsp[0].entero); }
#line 1555 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 193 "semantico.y" /* yacc.c:1646  */
    { (yyval.entero) = 10*(yyvsp[-1].entero)+(yyvsp[0].entero); }
#line 1561 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 194 "semantico.y" /* yacc.c:1646  */
    {
                                            if (check_Variable((yyvsp[0].cadena))!=0){
                                              int tipo = obtener_tipo_elemento((yyvsp[0].cadena));
                                              (yyval.entero) = 10*(yyvsp[-1].entero)+tipo;
                                            }
                                            else (yyval.entero) = -1;
                                          }
#line 1573 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 203 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=(yyvsp[0].entero);}
#line 1579 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 204 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=(yyvsp[0].entero);}
#line 1585 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 205 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=(yyvsp[0].entero);}
#line 1591 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 206 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero)=(yyvsp[0].entero);}
#line 1597 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 208 "semantico.y" /* yacc.c:1646  */
    {
                                                    if (check_Variable((yyvsp[-2].cadena))!=0){
                                                      int tipo = obtener_tipo_elemento((yyvsp[-2].cadena));
                                                      if (tipo==(yyvsp[0].entero)){
                                                        (yyval.entero) = tipo;
                                                      }
                                                      else{
                                                        printf("Error[linea %d]: la variable %s es de un tipo diferente al valor que se le quiere asignar\n", linea,(yyvsp[-2].cadena));
                                                        (yyval.entero) = -1;
                                                      }
                                                    }
                                                    else (yyval.entero) = -1;
                                                  }
#line 1615 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 222 "semantico.y" /* yacc.c:1646  */
    {
                                        if (check_Variable((yyvsp[-1].cadena))!=0){
                                          int tipo = obtener_tipo_elemento((yyvsp[-1].cadena));
                                            if (tipo==1 || tipo==2 || tipo==5) { (yyval.entero) = tipo; }
											else{
												printf("Error[linea %d]: la variable %s es de un tipo diferente al valor que se le quiere asignar", linea,(yyvsp[-1].cadena));
												(yyval.entero) = -1;
											}
                                        }
                                        else (yyval.entero) = -1;
}
#line 1631 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 234 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[0].entero);}
#line 1637 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 235 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[0].entero);}
#line 1643 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 237 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[0].entero);}
#line 1649 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 238 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[0].entero);}
#line 1655 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 239 "semantico.y" /* yacc.c:1646  */
    {
                                        if (check_Variable((yyvsp[0].cadena))!=0){
                                          (yyval.entero) = obtener_tipo_elemento((yyvsp[0].cadena));
                                        }
                                        else (yyval.entero) = -1;
                                      }
#line 1666 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 256 "semantico.y" /* yacc.c:1646  */
    {check_operacion_logica((yyvsp[-2].entero),(yyvsp[0].entero),(yyvsp[-1].entero));}
#line 1672 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 257 "semantico.y" /* yacc.c:1646  */
    {
                                                        if (check_Variable((yyvsp[0].cadena))!=0){
                                                          int tipo = obtener_tipo_elemento((yyvsp[0].cadena));
                                                          if (tipo==(yyvsp[-2].entero)){
                                                            (yyval.entero) = check_operacion_logica((yyvsp[-2].entero),tipo,(yyvsp[-1].entero));
                                                          }
                                                          else{
                                                            printf("Error[linea %d]: la variable %s es de un tipo diferente al valor que se le quiere comparar\n", linea,(yyvsp[0].cadena));
                                                            (yyval.entero) = -1;
                                                          }
                                                        }
                                                        else (yyval.entero) = -1;
                                                      }
#line 1690 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 270 "semantico.y" /* yacc.c:1646  */
    {
                                                        if (check_Variable((yyvsp[-2].cadena))!=0){
                                                          int tipo = obtener_tipo_elemento((yyvsp[-2].cadena));
                                                          if (tipo==(yyvsp[0].entero)){
                                                            (yyval.entero) = check_operacion_logica(tipo,(yyvsp[-2].cadena),(yyvsp[-1].entero));
                                                          }
                                                          else{
                                                            printf("Error[linea %d]: la variable %s es de un tipo diferente al valor con el que se le quiere comparar\n", linea,(yyvsp[-2].cadena));
                                                            (yyval.entero) = -1;
                                                          }
                                                        }
                                                        else (yyval.entero) = -1;
                                                      }
#line 1708 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 283 "semantico.y" /* yacc.c:1646  */
    {
                                                        int operando1 = obtener_tipo_elemento((yyvsp[-2].cadena));
                                                        int operando2 = obtener_tipo_elemento((yyvsp[0].cadena));
                                                        if (operando1!=-1 && operando2!=-1){
                                                          if (operando1==operando2){
                                                            (yyval.entero) = check_operacion_logica((yyvsp[-2].cadena),(yyvsp[0].cadena),(yyvsp[-1].entero));
                                                          }
                                                          else{
                                                            printf("Error[linea %d]: la variable %s es de un tipo diferente al de la variable %s\n", linea,(yyvsp[-2].cadena),(yyvsp[0].cadena));
                                                            (yyval.entero) = -1;
                                                          }
                                                        }
                                                        else (yyval.entero) = -1;
                                                      }
#line 1727 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 299 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[0].entero);}
#line 1733 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 300 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[0].entero);}
#line 1739 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 301 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[0].entero);}
#line 1745 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 302 "semantico.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[0].entero);}
#line 1751 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 312 "semantico.y" /* yacc.c:1646  */
    {
                                                                    if ((yyvsp[-4].entero)!=3){
                                                                      printf("Error[linea %d]: la condicion del ciclo elif no es de tipo booleano\n", linea);
                                                                    } 
                                                                  }
#line 1761 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 321 "semantico.y" /* yacc.c:1646  */
    {
																			if ((yyvsp[-6].entero)!=3){
																				printf("Error[linea %d]: la condicion del ciclo for no es de tipo booleano\n", linea);
																			} 
																		}
#line 1771 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 328 "semantico.y" /* yacc.c:1646  */
    {
																				if (buscar_elemento((yyvsp[-1].cadena))==0){
																					ins_inicio_lista ((yyvsp[-1].cadena),(yyvsp[-2].entero),(yyvsp[0].entero));
																				}
																			}
#line 1781 "semantico.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 337 "semantico.y" /* yacc.c:1646  */
    {
                                                  if ((yyvsp[-4].entero)!=3){
                                                    printf("Error[linea %d]: la condicion del ciclo while no es de tipo booleano\n", linea);
                                                  } 
                                                }
#line 1791 "semantico.tab.c" /* yacc.c:1646  */
    break;


#line 1795 "semantico.tab.c" /* yacc.c:1646  */
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
#line 343 "semantico.y" /* yacc.c:1906  */


/**********************
 * Codigo C Adicional *
 **********************/

int check_Variable (char * constante){
  if (obtener_tipo_elemento(constante)==-1){ /* si la constante no esta en la tabla de simbolos */
    printf("Error[linea %d]: La variable %s no esta declarada\n", linea,constante);
    return 0;
  }
  else{
    /* */
    return 1;
  }
}

/**
 * @param operando1 tipo de dato (codigo definido en el archivo lex) del primer operando
 * @param operando2 tipo de dato (codigo definido en el archivo lex) del segundo operando
 * @param operador tipo del operador (codigo definido en el archivo lex) para los operandos
 * @return el tipo de dato resultante de la operacion, -1 en caso de error de tipos
 */
int check_operacion_aritmetica(int operando1, int operando2, int operador){
  if (operando1==-1 || operando2==-1){ /* si alguno de los dos operandos arrastra un error */
    return -1; /* continuar arrastrando el error */
  }
  if (operador==9){ /* si el operador es suma */

    /* si ambos son booleanos, hay un error */
    if (operando1==3 && operando2==3) { 
      printf("Error[linea %d]: no se pueden sumar datos de tipo booleanos\n", linea);
      return -1;
    }

    /* si ambos son del mismo tipo el resultado se mantiene del mismo tipo */
    else if (operando1==operando2) return operando1;
    
    /* si ambos son de tipos diferentes, hay un error */
    else if (operando1!=operando2) {
      printf("Error[linea %d]: no se pueden sumar datos de tipos diferentes\n", linea);
      return -1;
    }

  }
  else if (operador==8){ /* si el operador es resta */

    /* si ambos son booleanos, hay un error */
    if (operando1==3 && operando2==3) { 
      printf("Error[linea %d]: no se pueden restar datos de tipo booleanos\n", linea);
      return -1;
    }
    else if (operando1==4 && operando2==4) {
      printf("Error[linea %d]: no se pueden restar datos de tipo string\n", linea);
      return -1;
    }

    /* si ambos son del mismo tipo el resultado se mantiene del mismo tipo */
    else if (operando1==operando2) return operando1;
    
    /* si ambos son de tipos diferentes, hay un error */
    else if (operando1!=operando2) return -1;

  }

  else if (operador==7){ /* si el operador es multiplicacion */

    /* si ambos son booleanos, hay un error */
    if (operando1==3 && operando2==3) { 
      printf("Error[linea %d]: no se pueden multiplicar datos de tipo booleanos\n", linea);
      return -1;
    }
    else if (operando1==4 && operando2==4) {
      printf("Error[linea %d]: no se pueden multiplicar datos de tipo string\n", linea);
      return -1;
    }

    /* si ambos son del mismo tipo el resultado se mantiene del mismo tipo */
    else if (operando1==operando2) return operando1;
    
    /* si ambos son de tipos diferentes, hay un error */
    else if (operando1!=operando2) return -1;

  }

  else if (operador==6){ /* si el operador es division */

    /* si ambos son booleanos, hay un error */
    if (operando1==3 && operando2==3) { 
      printf("Error[linea %d]: no se pueden restar datos de tipo booleanos\n", linea);
      return -1;
    }
    else if (operando1==4 && operando2==4) {
      printf("Error[linea %d]: no se pueden restar datos de tipo string\n", linea);
      return -1;
    }

    /* si ambos son del mismo tipo el resultado se mantiene del mismo tipo */
    else if (operando1==operando2) return operando1;
    
    /* si ambos son de tipos diferentes, hay un error */
    else if (operando1!=operando2) return -1;

  }
}


int check_operacion_logica(int operando1, int operando2, int operador) {
  if (operando1==-1 || operando2==-1){ /* si alguno de los dos operandos arrastra un error */
    return -1; /* continuar arrastrando el error */
  }
  else if (operador == 77 || operador == 66){
    /* si ambos son booleanos, hay un error */
    if (operando1==3 && operando2==3) { 
      printf("Error[linea %d]: no se puede aplicar el operador logico a datos de tipo booleanos\n", linea);
      return -1;
    }
    else return 3;
  }
  else if (operador == 99 || operador == 88){
    /* si ambos son booleanos, hay un error */
    if (operando1==3 || operando2==3) { 
      printf("Error[linea %d]: no se puede aplicar el operador logico a datos de tipo booleanos\n", linea);
      return -1;
    }
    /* si ambos son string, hay un error */
    else if (operando1==4 || operando2==4) { 
      printf("Error[linea %d]: no se pueden aplicar los operadores logicos < o > a datos de tipo booleanos\n", linea);
      return -1;
    }
    else return 3;
  }
    
  }
