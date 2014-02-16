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



#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "utils.h"
#include "wmc.h"
#include "lang.h"

     void
     yyerror (char const *s)
     {
       fprintf (stderr, "%s\n", s);
     }

static const char err_syntax[]	= "Syntax error";
static const char err_number[]	= "Number expected";
static const char err_ident[]	= "Identifier expected";
static const char err_assign[]	= "'=' expected";
static const char err_popen[]	= "'(' expected";
static const char err_pclose[]	= "')' expected";
static const char err_colon[]	= "':' expected";
static const char err_msg[]	= "Message expected";

/* Scanner switches */
int want_nl = 0;		/* Request next newlinw */
int want_line = 0;		/* Request next complete line */
int want_file = 0;		/* Request next ident as filename */

node_t *nodehead = NULL;	/* The list of all parsed elements */
static node_t *nodetail = NULL;
lan_blk_t *lanblockhead;	/* List of parsed elements transposed */

static int base = 16;		/* Current printout base to use (8, 10 or 16) */
static WCHAR *cast = NULL;	/* Current typecast to use */

static int last_id = 0;		/* The last message ID parsed */
static int last_sev = 0;	/* Last severity code parsed */
static int last_fac = 0;	/* Last facility code parsed */
static WCHAR *last_sym = NULL;/* Last alias symbol parsed */
static int have_sev;		/* Set if severity parsed for current message */
static int have_fac;		/* Set if facility parsed for current message */
static int have_sym;		/* Set is symbol parsed for current message */

static cp_xlat_t *cpxlattab = NULL;	/* Codepage translation table */
static int ncpxlattab = 0;

/* Prototypes */
static WCHAR *merge(WCHAR *s1, WCHAR *s2);
static lanmsg_t *new_lanmsg(lan_cp_t *lcp, WCHAR *msg);
static msg_t *add_lanmsg(msg_t *msg, lanmsg_t *lanmsg);
static msg_t *complete_msg(msg_t *msg, int id);
static void add_node(node_e type, void *p);
static void do_add_token(tok_e type, token_t *tok, const char *code);
static void test_id(int id);
static int check_languages(node_t *head);
static lan_blk_t *block_messages(node_t *head);
static void add_cpxlat(int lan, int cpin, int cpout);
static cp_xlat_t *find_cpxlat(int lan);




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
   by #include "mcy.tab.h".  */
#ifndef YY_YY_MCY_TAB_H_INCLUDED
# define YY_YY_MCY_TAB_H_INCLUDED
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
    tSEVNAMES = 258,
    tFACNAMES = 259,
    tLANNAMES = 260,
    tBASE = 261,
    tCODEPAGE = 262,
    tTYPEDEF = 263,
    tNL = 264,
    tSYMNAME = 265,
    tMSGEND = 266,
    tSEVERITY = 267,
    tFACILITY = 268,
    tLANGUAGE = 269,
    tMSGID = 270,
    tIDENT = 271,
    tLINE = 272,
    tFILE = 273,
    tCOMMENT = 274,
    tNUMBER = 275,
    tTOKEN = 276
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{


	WCHAR		*str;
	unsigned	num;
	token_t		*tok;
	lanmsg_t	*lmp;
	msg_t		*msg;
	lan_cp_t	lcp;


};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MCY_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */



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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

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
      23,    24,     2,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,     2,
       2,    22,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   130,   131,   134,   135,   136,   137,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   171,
     172,   178,   179,   180,   183,   190,   191,   197,   198,   199,
     202,   209,   210,   213,   214,   215,   221,   222,   223,   226,
     234,   235,   236,   237,   240,   241,   242,   248,   249,   250,
     253,   263,   264,   265,   266,   269,   270,   280,   280,   283,
     288,   291,   292,   293,   294,   297,   298,   299,   300,   303,
     304,   305,   308,   316,   317,   320,   328,   329,   335,   336,
     337,   340,   348,   377,   378,   379,   382,   383,   384,   385,
     391,   392,   395,   398,   401
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tSEVNAMES", "tFACNAMES", "tLANNAMES",
  "tBASE", "tCODEPAGE", "tTYPEDEF", "tNL", "tSYMNAME", "tMSGEND",
  "tSEVERITY", "tFACILITY", "tLANGUAGE", "tMSGID", "tIDENT", "tLINE",
  "tFILE", "tCOMMENT", "tNUMBER", "tTOKEN", "'='", "'('", "')'", "':'",
  "'+'", "$accept", "file", "items", "decl", "global", "smaps", "smap",
  "fmaps", "fmap", "alias", "lmaps", "lmap", "optcp", "cmaps", "cmap",
  "clan", "msg", "$@1", "msgid", "id", "sevfacsym", "sym", "sev", "fac",
  "bodies", "body", "lang", "lines", "token", "setnl", "setline",
  "setfile", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    61,    40,    41,    58,    43
};
# endif

#define YYPACT_NINF -37

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-37)))

#define YYTABLE_NINF -105

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     132,   -37,    18,    44,    46,    47,    48,    49,    50,   -37,
      10,   113,   -37,   -37,   -37,   -37,   -37,    11,   -37,    14,
     -37,    19,   -37,    85,   -37,    20,   -37,   147,   -37,   -13,
     -37,   -37,    87,   -37,    66,   -37,    80,   -37,    82,   -37,
     -37,   -37,    64,   -37,   -37,   -37,   107,   -37,    51,    52,
      53,     3,   -37,   -37,   -37,   -37,   -37,   -37,     7,   -37,
      54,   -37,     8,   -37,    55,   -37,    17,   -37,    56,   -37,
     -37,   -37,    15,   -37,    57,   -37,   -37,   -37,   148,   -37,
      88,   -37,    90,   -37,    58,    -3,   -37,   -37,   -37,   -37,
     -37,   -37,   109,   -37,   -37,   -37,   -37,   114,   -37,   -37,
     -37,   -37,   121,   -37,   -37,   -37,   -37,   122,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,    38,   -37,   129,   -37,    36,
     -37,    36,   -37,     0,   -37,     2,    91,   -37,   -37,   144,
     149,   -37,   -37,   -37,    37,   -37,   123,   -37,     5,   -37,
     -37,   -37,   -37,   -37,     4,   -37,   -37,   -37,   -37,   -37,
      39,   124,   -37,   -37,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     3,     5,     6,    75,    12,     0,    16,     0,
      20,     0,    30,     0,    24,     0,    27,     0,    70,    71,
       1,     4,    67,    11,     0,    15,     0,    19,     0,    29,
      28,    23,     0,    26,    25,    72,     0,    69,     0,     0,
       0,     0,    78,    76,    77,    33,   100,   101,     0,    31,
       0,    39,     0,    37,     0,    48,     0,    46,     0,    59,
      65,    66,     0,    57,     0,    74,    73,    81,     0,    84,
       0,    87,     0,    90,     0,    68,    88,   103,    10,     9,
      32,    36,     0,    14,    13,    38,    42,     0,    18,    17,
      47,    53,     0,    22,    21,    58,    64,     0,    80,    79,
      83,    82,    86,    85,    95,     0,    89,     0,    35,    43,
      41,    43,    52,     0,    63,     0,     0,    98,    96,     0,
       0,    34,    40,    51,     0,    62,     0,    94,     0,    99,
      91,    97,    45,    44,     0,    61,    60,    93,    92,    50,
      54,     0,    49,    56,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,   -37,    77,   -37,   -37,    35,   -37,     1,   -27,
     -37,    29,   -37,   -37,    30,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,    41,   -37,   -37,   -36,   -37,
     -37,   -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    58,    59,    62,    63,   131,
      66,    67,   152,    72,    73,    74,    14,    51,    15,    47,
      32,    52,    53,    54,    85,    86,    87,   129,    60,   115,
     117,   134
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,   133,    68,   135,    83,   149,   147,    45,    88,    93,
      30,    84,    33,    46,   148,    35,   103,    84,    98,    16,
      37,    41,   150,    56,    56,  -104,    64,   136,    57,    57,
      68,    89,    94,    56,    34,    70,    71,    36,    57,   104,
      17,    99,    38,    42,   111,    18,   113,    20,    22,    24,
      26,    28,    77,    79,    81,    91,    96,   101,   106,   114,
     126,   130,   144,    95,   151,    69,    19,    55,    21,    23,
      25,    27,    29,    78,    80,    82,    92,    97,   102,   107,
    -102,    61,    56,    65,    70,    71,    39,    57,    31,   110,
     138,   112,   137,    90,   132,   100,    56,    48,    56,    49,
      50,    57,   105,    57,    56,    40,    56,    56,    75,    57,
     118,    57,    57,    -2,     1,   120,     2,     3,     4,     5,
       6,     7,   122,   124,   145,   153,   116,    76,     8,   119,
     127,     0,     9,     1,   121,     2,     3,     4,     5,     6,
       7,   123,   125,   146,   154,   139,   128,     8,    43,   108,
     142,     9,     0,     0,     0,   140,     0,     0,     0,     0,
       0,   141,     0,    44,   109,   143
};

static const yytype_int8 yycheck[] =
{
      36,     1,    38,     1,     1,     1,     1,    20,     1,     1,
       0,    14,     1,    26,     9,     1,     1,    14,     1,     1,
       1,     1,    18,    16,    16,    25,    62,    25,    21,    21,
      66,    24,    24,    16,    23,    20,    21,    23,    21,    24,
      22,    24,    23,    23,    80,     1,    82,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
      22,    25,    25,    62,    25,     1,    22,     1,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,     1,    16,     1,    20,    21,     1,    21,    11,     1,
     126,     1,     1,    58,   121,    66,    16,    10,    16,    12,
      13,    21,    72,    21,    16,    20,    16,    16,     1,    21,
       1,    21,    21,     0,     1,     1,     3,     4,     5,     6,
       7,     8,     1,     1,     1,     1,    85,    20,    15,    20,
       1,    -1,    19,     1,    20,     3,     4,     5,     6,     7,
       8,    20,    20,    20,    20,     1,    17,    15,     1,     1,
       1,    19,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    16,    16,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    15,    19,
      28,    29,    30,    31,    43,    45,     1,    22,     1,    22,
       1,    22,     1,    22,     1,    22,     1,    22,     1,    22,
       0,    30,    47,     1,    23,     1,    23,     1,    23,     1,
      20,     1,    23,     1,    16,    20,    26,    46,    10,    12,
      13,    44,    48,    49,    50,     1,    16,    21,    32,    33,
      55,     1,    34,    35,    55,     1,    37,    38,    55,     1,
      20,    21,    40,    41,    42,     1,    20,     1,    22,     1,
      22,     1,    22,     1,    14,    51,    52,    53,     1,    24,
      33,     1,    22,     1,    24,    35,     1,    22,     1,    24,
      38,     1,    22,     1,    24,    41,     1,    22,     1,    16,
       1,    55,     1,    55,     1,    56,    52,    57,     1,    20,
       1,    20,     1,    20,     1,    20,    22,     1,    17,    54,
      25,    36,    36,     1,    58,     1,    25,     1,    55,     1,
      11,    17,     1,    16,    25,     1,    20,     1,     9,     1,
      18,    25,    39,     1,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    27,    28,    29,    29,    30,    30,    30,    30,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    32,    32,    32,    33,    33,    33,    34,    34,    34,
      35,    35,    35,    36,    36,    36,    37,    37,    37,    38,
      38,    38,    38,    38,    39,    39,    39,    40,    40,    40,
      41,    41,    41,    41,    41,    42,    42,    44,    43,    45,
      45,    46,    46,    46,    46,    47,    47,    47,    47,    48,
      48,    48,    49,    49,    49,    50,    50,    50,    51,    51,
      51,    52,    53,    53,    53,    53,    54,    54,    54,    54,
      55,    55,    56,    57,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     5,
       5,     3,     2,     5,     5,     3,     2,     5,     5,     3,
       2,     5,     5,     3,     2,     3,     3,     2,     3,     3,
       2,     1,     2,     1,     4,     3,     2,     1,     2,     1,
       4,     3,     2,     0,     2,     2,     1,     2,     1,     7,
       6,     4,     3,     2,     0,     2,     2,     1,     2,     1,
       5,     5,     4,     3,     2,     1,     1,     0,     4,     3,
       2,     0,     1,     2,     2,     0,     2,     2,     2,     3,
       3,     2,     3,     3,     2,     3,     3,     2,     1,     2,
       1,     4,     5,     5,     4,     2,     1,     2,     1,     2,
       1,     1,     0,     0,     0
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
#define yylex(x) NULL
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

    {
		if(!check_languages(nodehead))
			xyyerror("No messages defined\n");
		lanblockhead = block_messages(nodehead);
	}

    break;

  case 6:

    { add_node(nd_msg, (yyvsp[0].msg)); }

    break;

  case 7:

    { add_node(nd_comment, (yyvsp[0].str)); }

    break;

  case 8:

    { xyyerror(err_syntax); /* `Catch all' error */ }

    break;

  case 10:

    { xyyerror(err_pclose); }

    break;

  case 11:

    { xyyerror(err_popen); }

    break;

  case 12:

    { xyyerror(err_assign); }

    break;

  case 14:

    { xyyerror(err_pclose); }

    break;

  case 15:

    { xyyerror(err_popen); }

    break;

  case 16:

    { xyyerror(err_assign); }

    break;

  case 18:

    { xyyerror(err_pclose); }

    break;

  case 19:

    { xyyerror(err_popen); }

    break;

  case 20:

    { xyyerror(err_assign); }

    break;

  case 22:

    { xyyerror(err_pclose); }

    break;

  case 23:

    { xyyerror(err_popen); }

    break;

  case 24:

    { xyyerror(err_assign); }

    break;

  case 25:

    { cast = (yyvsp[0].str); }

    break;

  case 26:

    { xyyerror(err_number); }

    break;

  case 27:

    { xyyerror(err_assign); }

    break;

  case 28:

    {
		switch(base)
		{
		case 8:
		case 10:
		case 16:
			base = (yyvsp[0].num);
			break;
		default:
			xyyerror("Numberbase must be 8, 10 or 16\n");
		}
	}

    break;

  case 29:

    { xyyerror(err_number); }

    break;

  case 30:

    { xyyerror(err_assign); }

    break;

  case 33:

    { xyyerror(err_ident); }

    break;

  case 34:

    {
		(yyvsp[-3].tok)->token = (yyvsp[-1].num);
		(yyvsp[-3].tok)->alias = (yyvsp[0].str);
		if((yyvsp[-1].num) & (~0x3))
			xyyerror("Severity value out of range (0x%08x > 0x3)\n", (yyvsp[-1].num));
		do_add_token(tok_severity, (yyvsp[-3].tok), "severity");
	}

    break;

  case 35:

    { xyyerror(err_number); }

    break;

  case 36:

    { xyyerror(err_assign); }

    break;

  case 39:

    { xyyerror(err_ident); }

    break;

  case 40:

    {
		(yyvsp[-3].tok)->token = (yyvsp[-1].num);
		(yyvsp[-3].tok)->alias = (yyvsp[0].str);
		if((yyvsp[-1].num) & (~0xfff))
			xyyerror("Facility value out of range (0x%08x > 0xfff)\n", (yyvsp[-1].num));
		do_add_token(tok_facility, (yyvsp[-3].tok), "facility");
	}

    break;

  case 41:

    { xyyerror(err_number); }

    break;

  case 42:

    { xyyerror(err_assign); }

    break;

  case 43:

    { (yyval.str) = NULL; }

    break;

  case 44:

    { (yyval.str) = (yyvsp[0].str); }

    break;

  case 45:

    { xyyerror(err_ident); }

    break;

  case 48:

    { xyyerror(err_ident); }

    break;

  case 49:

    {
		(yyvsp[-6].tok)->token = (yyvsp[-4].num);
		(yyvsp[-6].tok)->alias = (yyvsp[-1].str);
		(yyvsp[-6].tok)->codepage = (yyvsp[0].num);
		do_add_token(tok_language, (yyvsp[-6].tok), "language");
		if(!find_language((yyvsp[-4].num)) && !find_cpxlat((yyvsp[-4].num)))
			mcy_warning("Language 0x%x not built-in, using codepage %d; use explicit codepage to override\n", (yyvsp[-4].num), WMC_DEFAULT_CODEPAGE);
	}

    break;

  case 50:

    { xyyerror("Filename expected\n"); }

    break;

  case 51:

    { xyyerror(err_colon); }

    break;

  case 52:

    { xyyerror(err_number); }

    break;

  case 53:

    { xyyerror(err_assign); }

    break;

  case 54:

    { (yyval.num) = 0; }

    break;

  case 55:

    { (yyval.num) = (yyvsp[0].num); }

    break;

  case 56:

    { xyyerror("Codepage-number expected\n"); }

    break;

  case 59:

    { xyyerror(err_ident); }

    break;

  case 60:

    {
		static const char err_nocp[] = "Codepage %d not builtin; cannot convert\n";
		if(find_cpxlat((yyvsp[-4].num)))
			xyyerror("Codepage translation already defined for language 0x%x\n", (yyvsp[-4].num));
		if((yyvsp[-2].num) && (yyvsp[-2].num) != CP_UTF8 && !find_codepage((yyvsp[-2].num)))
			xyyerror(err_nocp, (yyvsp[-2].num));
		if((yyvsp[0].num) && (yyvsp[0].num) != CP_UTF8 && !find_codepage((yyvsp[0].num)))
			xyyerror(err_nocp, (yyvsp[0].num));
		add_cpxlat((yyvsp[-4].num), (yyvsp[-2].num), (yyvsp[0].num));
	}

    break;

  case 61:

    { xyyerror(err_number); }

    break;

  case 62:

    { xyyerror(err_colon); }

    break;

  case 63:

    { xyyerror(err_number); }

    break;

  case 64:

    { xyyerror(err_assign); }

    break;

  case 65:

    { (yyval.num) = (yyvsp[0].num); }

    break;

  case 66:

    {
		if((yyvsp[0].tok)->type != tok_language)
			xyyerror("Language name or code expected\n");
		(yyval.num) = (yyvsp[0].tok)->token;
	}

    break;

  case 67:

    { test_id((yyvsp[-1].num)); }

    break;

  case 68:

    { (yyval.msg) = complete_msg((yyvsp[0].msg), (yyvsp[-3].num)); }

    break;

  case 69:

    {
		if((yyvsp[0].num) & (~0xffff))
			xyyerror("Message ID value out of range (0x%08x > 0xffff)\n", (yyvsp[0].num));
		(yyval.num) = (yyvsp[0].num);
	}

    break;

  case 70:

    { xyyerror(err_assign); }

    break;

  case 71:

    { (yyval.num) = ++last_id; }

    break;

  case 72:

    { (yyval.num) = last_id = (yyvsp[0].num); }

    break;

  case 73:

    { (yyval.num) = last_id += (yyvsp[0].num); }

    break;

  case 74:

    { xyyerror(err_number); }

    break;

  case 75:

    { have_sev = have_fac = have_sym = 0; }

    break;

  case 76:

    { if(have_sev) xyyerror("Severity already defined\n"); have_sev = 1; }

    break;

  case 77:

    { if(have_fac) xyyerror("Facility already defined\n"); have_fac = 1; }

    break;

  case 78:

    { if(have_sym) xyyerror("Symbolname already defined\n"); have_sym = 1; }

    break;

  case 79:

    { last_sym = (yyvsp[0].str); }

    break;

  case 80:

    { xyyerror(err_ident); }

    break;

  case 81:

    { xyyerror(err_assign); }

    break;

  case 82:

    {
		token_t *tok = lookup_token((yyvsp[0].tok)->name);
		if(!tok)
			xyyerror("Undefined severityname\n");
		if(tok->type != tok_severity)
			xyyerror("Identifier is not of class 'severity'\n");
		last_sev = tok->token;
	}

    break;

  case 83:

    { xyyerror(err_ident); }

    break;

  case 84:

    { xyyerror(err_assign); }

    break;

  case 85:

    {
		token_t *tok = lookup_token((yyvsp[0].tok)->name);
		if(!tok)
			xyyerror("Undefined facilityname\n");
		if(tok->type != tok_facility)
			xyyerror("Identifier is not of class 'facility'\n");
		last_fac = tok->token;
	}

    break;

  case 86:

    { xyyerror(err_ident); }

    break;

  case 87:

    { xyyerror(err_assign); }

    break;

  case 88:

    { (yyval.msg) = add_lanmsg(NULL, (yyvsp[0].lmp)); }

    break;

  case 89:

    { (yyval.msg) = add_lanmsg((yyvsp[-1].msg), (yyvsp[0].lmp)); }

    break;

  case 90:

    { xyyerror("'Language=...' (start of message text-definition) expected\n"); }

    break;

  case 91:

    { (yyval.lmp) = new_lanmsg(&(yyvsp[-3].lcp), (yyvsp[-1].str)); }

    break;

  case 92:

    {
		token_t *tok = lookup_token((yyvsp[-1].tok)->name);
		cp_xlat_t *cpx;
		if(!tok)
			xyyerror("Undefined language\n");
		if(tok->type != tok_language)
			xyyerror("Identifier is not of class 'language'\n");
		if((cpx = find_cpxlat(tok->token)))
		{
			set_codepage((yyval.lcp).codepage = cpx->cpin);
		}
		else if(!tok->codepage)
		{
			const language_t *lan = find_language(tok->token);
			if(!lan)
			{
				/* Just set default; warning was given while parsing languagenames */
				set_codepage((yyval.lcp).codepage = WMC_DEFAULT_CODEPAGE);
			}
			else
			{
				/* The default seems to be to use the DOS codepage... */
				set_codepage((yyval.lcp).codepage = lan->doscp);
			}
		}
		else
			set_codepage((yyval.lcp).codepage = tok->codepage);
		(yyval.lcp).language = tok->token;
	}

    break;

  case 93:

    { xyyerror("Missing newline\n"); }

    break;

  case 94:

    { xyyerror(err_ident); }

    break;

  case 95:

    { xyyerror(err_assign); }

    break;

  case 96:

    { (yyval.str) = (yyvsp[0].str); }

    break;

  case 97:

    { (yyval.str) = merge((yyvsp[-1].str), (yyvsp[0].str)); }

    break;

  case 98:

    { xyyerror(err_msg); }

    break;

  case 99:

    { xyyerror(err_msg); }

    break;

  case 100:

    { (yyval.tok) = xmalloc(sizeof(token_t)); memset((yyval.tok),0,sizeof(*(yyval.tok))); (yyval.tok)->name = (yyvsp[0].str); }

    break;

  case 101:

    { (yyval.tok) = (yyvsp[0].tok); }

    break;

  case 102:

    { want_nl = 1; }

    break;

  case 103:

    { want_line = 1; }

    break;

  case 104:

    { want_file = 1; }

    break;



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



static WCHAR *merge(WCHAR *s1, WCHAR *s2)
{
	int l1 = unistrlen(s1);
	int l2 = unistrlen(s2);
	s1 = xrealloc(s1, (l1 + l2 + 1) * sizeof(*s1));
	unistrcpy(s1+l1, s2);
	free(s2);
	return s1;
}

static void do_add_token(tok_e type, token_t *tok, const char *code)
{
	token_t *tp = lookup_token(tok->name);
	if(tp)
	{
		if(tok->type != type)
			mcy_warning("Type change in token\n");
		if(tp != tok)
			xyyerror("Overlapping token not the same\n");
		/* else its already defined and changed */
		if(tok->fixed)
			xyyerror("Redefinition of %s\n", code);
		tok->fixed = 1;
	}
	else
	{
		add_token(type, tok->name, tok->token, tok->codepage, tok->alias, 1);
		free(tok);
	}
}

static lanmsg_t *new_lanmsg(lan_cp_t *lcp, WCHAR *msg)
{
	lanmsg_t *lmp = xmalloc(sizeof(lanmsg_t));
	lmp->lan = lcp->language;
	lmp->cp  = lcp->codepage;
	lmp->msg = msg;
	lmp->len = unistrlen(msg) + 1;	/* Include termination */
	lmp->file = input_name;
	lmp->line = line_number;
	if(lmp->len > 4096)
		mcy_warning("Message exceptionally long; might be a missing termination\n");
	return lmp;
}

static msg_t *add_lanmsg(msg_t *msg, lanmsg_t *lanmsg)
{
	int i;
	if(!msg)
	{
		msg = xmalloc(sizeof(msg_t));
		memset( msg, 0, sizeof(*msg) );
	}
	msg->msgs = xrealloc(msg->msgs, (msg->nmsgs+1) * sizeof(*(msg->msgs)));
	msg->msgs[msg->nmsgs] = lanmsg;
	msg->nmsgs++;
	for(i = 0; i < msg->nmsgs-1; i++)
	{
		if(msg->msgs[i]->lan == lanmsg->lan)
			xyyerror("Message for language 0x%x already defined\n", lanmsg->lan);
	}
	return msg;
}

static int sort_lanmsg(const void *p1, const void *p2)
{
	return (*(const lanmsg_t * const *)p1)->lan - (*(const lanmsg_t * const*)p2)->lan;
}

static msg_t *complete_msg(msg_t *mp, int id)
{
	assert(mp != NULL);
	mp->id = id;
	if(have_sym)
		mp->sym = last_sym;
	else
		xyyerror("No symbolic name defined for message id %d\n", id);
	mp->sev = last_sev;
	mp->fac = last_fac;
	qsort(mp->msgs, mp->nmsgs, sizeof(*(mp->msgs)), sort_lanmsg);
	mp->realid = id | (last_sev << 30) | (last_fac << 16);
	if(custombit)
		mp->realid |= 1 << 29;
	mp->base = base;
	mp->cast = cast;
	return mp;
}

static void add_node(node_e type, void *p)
{
	node_t *ndp = xmalloc(sizeof(node_t));
	memset( ndp, 0, sizeof(*ndp) );
	ndp->type = type;
	ndp->u.all = p;

	if(nodetail)
	{
		ndp->prev = nodetail;
		nodetail->next = ndp;
		nodetail = ndp;
	}
	else
	{
		nodehead = nodetail = ndp;
	}
}

static void test_id(int id)
{
	node_t *ndp;
	for(ndp = nodehead; ndp; ndp = ndp->next)
	{
		if(ndp->type != nd_msg)
			continue;
		if(ndp->u.msg->id == id && ndp->u.msg->sev == last_sev && ndp->u.msg->fac == last_fac)
			xyyerror("MessageId %d with facility 0x%x and severity 0x%x already defined\n", id, last_fac, last_sev);
	}
}

static int check_languages(node_t *head)
{
	static const char err_missing[] = "Missing definition for language 0x%x; MessageID %d, facility 0x%x, severity 0x%x\n";
	node_t *ndp;
	int nm = 0;
	msg_t *msg = NULL;

	for(ndp = head; ndp; ndp = ndp->next)
	{
		if(ndp->type != nd_msg)
			continue;
		if(!nm)
		{
			msg = ndp->u.msg;
		}
		else
		{
			int i;
			msg_t *m1;
			msg_t *m2;
			if(ndp->u.msg->nmsgs > msg->nmsgs)
			{
				m1 = ndp->u.msg;
				m2 = msg;
			}
			else
			{
				m1 = msg;
				m2 = ndp->u.msg;
			}

			for(i = 0; i < m1->nmsgs; i++)
			{
				if(i > m2->nmsgs)
					error(err_missing, m1->msgs[i]->lan, m2->id, m2->fac, m2->sev);
				else if(m1->msgs[i]->lan < m2->msgs[i]->lan)
					error(err_missing, m1->msgs[i]->lan, m2->id, m2->fac, m2->sev);
				else if(m1->msgs[i]->lan > m2->msgs[i]->lan)
					error(err_missing, m2->msgs[i]->lan, m1->id, m1->fac, m1->sev);
			}
		}
		nm++;
	}
	return nm;
}

#define MSGRID(x)	((*(const msg_t * const*)(x))->realid)
static int sort_msg(const void *p1, const void *p2)
{
	return MSGRID(p1) > MSGRID(p2) ? 1 : (MSGRID(p1) == MSGRID(p2) ? 0 : -1);
	/* return (*(msg_t **)p1)->realid - (*(msg_t **)p1)->realid; */
}

/*
 * block_messages() basically transposes the messages
 * from ID/language based list to a language/ID
 * based list.
 */
static lan_blk_t *block_messages(node_t *head)
{
	lan_blk_t *lbp;
	lan_blk_t *lblktail = NULL;
	lan_blk_t *lblkhead = NULL;
	msg_t **msgtab = NULL;
	node_t *ndp;
	int nmsg = 0;
	int i;
	int nl;
	int factor = unicodeout ? 2 : 1;

	for(ndp = head; ndp; ndp = ndp->next)
	{
		if(ndp->type != nd_msg)
			continue;
		msgtab = xrealloc(msgtab, (nmsg+1) * sizeof(*msgtab));
		msgtab[nmsg++] = ndp->u.msg;
	}

	assert(nmsg != 0);
	qsort(msgtab, nmsg, sizeof(*msgtab), sort_msg);

	for(nl = 0; nl < msgtab[0]->nmsgs; nl++)	/* This should be equal for all after check_languages() */
	{
		lbp = xmalloc(sizeof(lan_blk_t));
		memset( lbp, 0, sizeof(*lbp) );
		if(!lblktail)
		{
			lblkhead = lblktail = lbp;
		}
		else
		{
			lblktail->next = lbp;
			lbp->prev = lblktail;
			lblktail = lbp;
		}
		lbp->nblk = 1;
		lbp->blks = xmalloc(sizeof(*lbp->blks));
		lbp->blks[0].idlo = msgtab[0]->realid;
		lbp->blks[0].idhi = msgtab[0]->realid;
		/* The plus 4 is the entry header; (+3)&~3 is DWORD alignment */
		lbp->blks[0].size = ((factor * msgtab[0]->msgs[nl]->len + 3) & ~3) + 4;
		lbp->blks[0].msgs = xmalloc(sizeof(*lbp->blks[0].msgs));
		lbp->blks[0].nmsg = 1;
		lbp->blks[0].msgs[0] = msgtab[0]->msgs[nl];
		lbp->lan = msgtab[0]->msgs[nl]->lan;

		for(i = 1; i < nmsg; i++)
		{
			block_t *blk = &(lbp->blks[lbp->nblk-1]);
			if(msgtab[i]->realid == blk->idhi+1)
			{
				blk->size += ((factor * msgtab[i]->msgs[nl]->len + 3) & ~3) + 4;
				blk->idhi++;
				blk->msgs = xrealloc(blk->msgs, (blk->nmsg+1) * sizeof(*blk->msgs));
				blk->msgs[blk->nmsg++] = msgtab[i]->msgs[nl];
			}
			else
			{
				lbp->nblk++;
				lbp->blks = xrealloc(lbp->blks, lbp->nblk * sizeof(*lbp->blks));
				blk = &(lbp->blks[lbp->nblk-1]);
				blk->idlo = msgtab[i]->realid;
				blk->idhi = msgtab[i]->realid;
				blk->size = ((factor * msgtab[i]->msgs[nl]->len + 3) & ~3) + 4;
				blk->msgs = xmalloc(sizeof(*blk->msgs));
				blk->nmsg = 1;
				blk->msgs[0] = msgtab[i]->msgs[nl];
			}
		}
	}
	free(msgtab);
	return lblkhead;
}

static int sc_xlat(const void *p1, const void *p2)
{
	return ((const cp_xlat_t *)p1)->lan - ((const cp_xlat_t *)p2)->lan;
}

static void add_cpxlat(int lan, int cpin, int cpout)
{
	cpxlattab = xrealloc(cpxlattab, (ncpxlattab+1) * sizeof(*cpxlattab));
	cpxlattab[ncpxlattab].lan   = lan;
	cpxlattab[ncpxlattab].cpin  = cpin;
	cpxlattab[ncpxlattab].cpout = cpout;
	ncpxlattab++;
	qsort(cpxlattab, ncpxlattab, sizeof(*cpxlattab), sc_xlat);
}

static cp_xlat_t *find_cpxlat(int lan)
{
	cp_xlat_t t;

	if(!cpxlattab) return NULL;

	t.lan = lan;
	return (cp_xlat_t *)bsearch(&t, cpxlattab, ncpxlattab, sizeof(*cpxlattab), sc_xlat);
}
