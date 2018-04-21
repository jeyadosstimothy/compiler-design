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
#line 1 "threeaddr.y" /* yacc.c:339  */

	#include<bits/stdc++.h>
	typedef long long ll;
	using namespace std;
	int yylex();
	void yyerror(char *s);
	
	//for 3addr
	int tempcount=0;
	int getTemp();
	typedef struct node
	{
		string  addr, array;
		pair<string,vector<ll> > type;
		vector<ll> trueList,falseList,nextList;
		int instNum;
	}NODE;

	NODE* makeNode()
	{
		NODE *temp=new NODE();
		ostringstream ss;
		ss<<"t"<<getTemp();
		temp->addr=ss.str();
		ss.str("");
		temp->array="";
		return temp;
	}
	NODE* makeNode(string *x)
	{
		NODE *temp=new NODE();
		temp->addr=*x;
		temp->array="";
		return temp;
	}

	//for symbol table
	deque<string> s;
	deque<int> vars;
	deque<int> blocks;
	int blocknum=-1,varnum=0;
	string currType;
	map<ll,map<string,pair<pair<string,vector<ll> >,string> > > table;//blockno,varname,type,dimensions,value
	map<string,ll> width;
	ll getWidth(pair<string,vector<ll> > type);
	string to_string(ll val);
	ll to_int(string val);
	void insertID(int bno,string varname);
	void printTable();

	// for backpatch
	int instCounter=0;
	map<ll,string> instList;
	int nextInst();
	vector<ll> merge(vector<ll> a,vector<ll> b);
	void backpatch(vector<ll> list,int num);
	void displayInst();

	//for Control Flow Graph
	map<ll,vector<string> > basicBlock;
	set<ll> leaders;
	vector<vector<ll> > bbgraph;
	void genBasicBlock();
	void findLeaders();


#line 133 "threeaddr.tab.c" /* yacc.c:339  */

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
   by #include "threeaddr.tab.h".  */
#ifndef YY_YY_THREEADDR_TAB_H_INCLUDED
# define YY_YY_THREEADDR_TAB_H_INCLUDED
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
    KEY = 258,
    AND = 259,
    OR = 260,
    NOT = 261,
    RELOP = 262,
    ID = 263,
    VAL = 264,
    SC = 265,
    CM = 266,
    PL = 267,
    MI = 268,
    MUL = 269,
    DIV = 270,
    POW = 271,
    OP = 272,
    CL = 273,
    AO = 274,
    AC = 275,
    EQ = 276,
    BO = 277,
    BC = 278,
    UNR = 279,
    TRUE = 280,
    FALSE = 281,
    IF = 282,
    ELSE = 283,
    WHILE = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 68 "threeaddr.y" /* yacc.c:355  */

	typedef struct node NODE;
	string *str;
	NODE *node;


#line 210 "threeaddr.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_THREEADDR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 227 "threeaddr.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   118

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    82,    82,    82,    90,    91,    92,    93,    94,    95,
      97,   102,   109,   116,   116,   136,   141,   141,   142,   142,
     148,   148,   150,   150,   152,   152,   155,   157,   158,   166,
     177,   187,   189,   195,   201,   203,   204,   205,   212,   213,
     215,   216,   218,   219,   220,   221,   223,   224,   225,   227,
     228,   230,   231,   238,   241,   242
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KEY", "AND", "OR", "NOT", "RELOP", "ID",
  "VAL", "SC", "CM", "PL", "MI", "MUL", "DIV", "POW", "OP", "CL", "AO",
  "AC", "EQ", "BO", "BC", "UNR", "TRUE", "FALSE", "IF", "ELSE", "WHILE",
  "$accept", "ss", "$@1", "stmt", "if", "ifelse", "while", "block", "$@2",
  "stmt_list", "decl", "$@3", "id", "arr", "d", "$@4", "a", "l", "r",
  "bool", "bb", "m", "n", "e", "t", "f", "g", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

#define YYPACT_NINF -39

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-39)))

#define YYTABLE_NINF -54

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -39,    19,     3,   -39,    16,    15,   -39,    34,   -39,   -39,
     -39,   -39,   -39,   -39,    72,   -39,   -39,    57,    42,   -39,
      62,    62,     3,    20,    79,     3,    62,    62,    77,    78,
      89,    70,   -39,    62,    62,    69,    35,     1,   -39,    85,
      92,    68,    81,    20,    20,   -39,   -39,    17,   -39,    61,
      20,   -39,    37,    95,    86,    98,    16,    99,    91,   -39,
      26,    62,    62,   -39,    62,    62,    62,   -39,   -39,   -39,
      36,     0,   -39,   -39,   -39,    62,    38,   -39,   -39,    42,
     -39,   -39,   -39,   -39,     1,     1,   -39,   -39,   -39,   -39,
      20,    20,     3,    68,   -39,   -39,    89,   -39,   -39,    80,
       3,   -39,   -39,   -39,   -39,     3,   -39
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    17,     1,     0,     0,    13,     0,    40,    16,
       4,     5,     6,     7,    40,     9,     8,     0,    23,    18,
       0,     0,    17,     0,     0,     0,     0,     0,     0,    20,
      26,    52,    54,     0,     0,    45,     0,    44,    48,    50,
       0,    31,    40,     0,     0,    38,    39,     0,    34,     0,
       0,    15,     0,     0,     0,     0,     0,     0,    53,    55,
       0,     0,     0,    29,     0,     0,     0,    28,    14,    35,
       0,     0,    40,    40,    40,     0,     0,    30,    27,    23,
      21,    24,    19,    51,    42,    43,    46,    47,    49,    36,
       0,     0,     0,    37,    40,    22,    26,    33,    32,    10,
       0,    25,    41,    12,    40,     0,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -39,   -23,   -39,   -39,   -39,   -39,   -39,    90,
     -39,   -39,    55,    39,    18,   -39,   -39,    -2,    88,   -36,
     -38,    -7,   -39,   -17,    33,    27,    83
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     9,    10,    11,    12,    13,    22,    14,
      15,    30,    19,    29,    57,    96,    16,    35,    40,    47,
      48,    25,   104,    49,    37,    38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,    24,    51,    36,    41,    69,     4,    75,    70,    52,
      41,     5,    61,    62,    76,    64,    65,    60,    83,     3,
      17,    72,    73,    17,    18,     6,    43,    71,    31,    32,
       7,    58,     8,    33,    20,    74,    21,    44,    61,    62,
      72,    73,    72,    73,    83,    45,    46,    61,    62,    61,
      62,    23,    97,    98,    89,    63,    94,    77,    93,    58,
      58,    28,    58,    58,    58,    90,    91,    92,    75,    99,
      31,    32,    -3,    61,    62,    33,    26,   103,    27,    34,
      61,    62,   106,   -53,   -53,   -53,    54,   100,    26,    20,
      17,    86,    87,    88,    84,    85,    50,   105,    17,    55,
      56,    66,    67,    17,    68,    78,    79,    80,   102,    82,
      26,    81,    42,     0,   101,    53,    59,     0,    95
};

static const yytype_int8 yycheck[] =
{
       2,     8,    25,    20,    21,    43,     3,     7,    44,    26,
      27,     8,    12,    13,    50,    14,    15,    34,    18,     0,
      22,     4,     5,    25,     8,    22,     6,    44,     8,     9,
      27,    33,    29,    13,    19,    18,    21,    17,    12,    13,
       4,     5,     4,     5,    18,    25,    26,    12,    13,    12,
      13,    17,    90,    91,    18,    20,    18,    20,    75,    61,
      62,    19,    64,    65,    66,    72,    73,    74,     7,    92,
       8,     9,     0,    12,    13,    13,    19,   100,    21,    17,
      12,    13,   105,    14,    15,    16,     9,    94,    19,    19,
      92,    64,    65,    66,    61,    62,    17,   104,   100,    21,
      11,    16,    10,   105,    23,    10,    20,     9,    28,    10,
      19,    56,    22,    -1,    96,    27,    33,    -1,    79
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,     0,     3,     8,    22,    27,    29,    33,
      34,    35,    36,    37,    39,    40,    46,    47,     8,    42,
      19,    21,    38,    17,    51,    51,    19,    21,    19,    43,
      41,     8,     9,    13,    17,    47,    53,    54,    55,    56,
      48,    53,    39,     6,    17,    25,    26,    49,    50,    53,
      17,    33,    53,    48,     9,    21,    11,    44,    47,    56,
      53,    12,    13,    20,    14,    15,    16,    10,    23,    50,
      49,    53,     4,     5,    18,     7,    49,    20,    10,    20,
       9,    42,    10,    18,    54,    54,    55,    55,    55,    18,
      51,    51,    51,    53,    18,    43,    45,    50,    50,    33,
      51,    44,    28,    33,    52,    51,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    32,    31,    33,    33,    33,    33,    33,    33,
      34,    35,    36,    38,    37,    39,    39,    39,    41,    40,
      42,    42,    43,    43,    45,    44,    44,    46,    46,    47,
      47,    48,    49,    49,    49,    50,    50,    50,    50,    50,
      51,    52,    53,    53,    53,    53,    54,    54,    54,    55,
      55,    56,    56,    56,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       6,    10,     7,     0,     4,     3,     1,     0,     0,     5,
       2,     4,     4,     0,     0,     4,     0,     4,     4,     4,
       4,     1,     4,     4,     1,     2,     3,     3,     1,     1,
       0,     0,     3,     3,     1,     1,     3,     3,     1,     3,
       1,     3,     1,     1,     1,     2
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
#line 82 "threeaddr.y" /* yacc.c:1646  */
    {
			blocknum++;
			blocks.push_back(blocknum);
			vars.push_back(varnum);
			varnum=0;
		}
#line 1377 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "threeaddr.y" /* yacc.c:1646  */
    {}
#line 1383 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 90 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)->nextList=(yyvsp[0].node)->nextList;}
#line 1389 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)->nextList=(yyvsp[0].node)->nextList;}
#line 1395 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 92 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)->nextList=(yyvsp[0].node)->nextList;}
#line 1401 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 93 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)->nextList=(yyvsp[0].node)->nextList;}
#line 1407 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 94 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)->nextList=(yyvsp[0].node)->nextList;}
#line 1413 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 95 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)->nextList=(yyvsp[0].node)->nextList;}
#line 1419 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 97 "threeaddr.y" /* yacc.c:1646  */
    {
								(yyval.node)=new NODE();
								backpatch((yyvsp[-3].node)->trueList,(yyvsp[-1].node)->instNum);
								(yyval.node)->nextList=merge((yyvsp[-3].node)->falseList,(yyvsp[0].node)->nextList);
							}
#line 1429 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 102 "threeaddr.y" /* yacc.c:1646  */
    {
											(yyval.node)=new NODE();
											backpatch((yyvsp[-7].node)->trueList,(yyvsp[-5].node)->instNum);
											backpatch((yyvsp[-7].node)->falseList,(yyvsp[-1].node)->instNum);
											(yyval.node)->nextList=merge((yyvsp[-4].node)->nextList,(yyvsp[-2].node)->nextList);
											(yyval.node)->nextList=merge((yyval.node)->nextList,(yyvsp[0].node)->nextList);
										}
#line 1441 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 109 "threeaddr.y" /* yacc.c:1646  */
    {
									(yyval.node)=new NODE();
									backpatch((yyvsp[-3].node)->trueList,(yyvsp[-1].node)->instNum);
									backpatch((yyvsp[0].node)->nextList,(yyvsp[-5].node)->instNum);
									instList[nextInst()]="goto "+to_string((yyvsp[-5].node)->instNum);
									(yyval.node)->nextList=(yyvsp[-3].node)->falseList;
								}
#line 1453 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 116 "threeaddr.y" /* yacc.c:1646  */
    {
			blocknum++;
			blocks.push_back(blocknum);
			for(int i=0;i<s.size();i++)
			{
				insertID(blocknum,s[i]);
			}
			vars.push_back(varnum);
			varnum=0;
		}
#line 1468 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 127 "threeaddr.y" /* yacc.c:1646  */
    {
			blocks.pop_back();
			for(int i=0;i<varnum;i++)
				s.pop_back();
			varnum=vars.back();
			vars.pop_back();	
			(yyval.node)=new NODE();
			(yyval.node)->nextList=(yyvsp[-1].node)->nextList;
		}
#line 1482 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 136 "threeaddr.y" /* yacc.c:1646  */
    {
								(yyval.node)=new NODE();
								backpatch((yyvsp[-2].node)->nextList,(yyvsp[-1].node)->instNum);
								(yyval.node)->nextList=(yyvsp[0].node)->nextList;
							}
#line 1492 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 141 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)->nextList=(yyvsp[0].node)->nextList;}
#line 1498 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 141 "threeaddr.y" /* yacc.c:1646  */
    {}
#line 1504 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 142 "threeaddr.y" /* yacc.c:1646  */
    {
				varnum++;s.push_back(*(yyvsp[-1].str)+" "+*(yyvsp[0].str));
				insertID(blocks.back(),*(yyvsp[-1].str)+" "+*(yyvsp[0].str));
				currType=*(yyvsp[-1].str);
			}
#line 1514 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 146 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();}
#line 1520 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 148 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.str)=new string(*(yyvsp[-1].str)+*(yyvsp[0].str));}
#line 1526 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 148 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.str)=new string(*(yyvsp[-3].str)+*(yyvsp[-2].str)+*(yyvsp[-1].str)+*(yyvsp[0].str));}
#line 1532 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.str)=new string(*(yyvsp[-3].str)+*(yyvsp[-2].str)+*(yyvsp[-1].str)+*(yyvsp[0].str));}
#line 1538 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 150 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.str)=new string("");}
#line 1544 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 152 "threeaddr.y" /* yacc.c:1646  */
    {
			varnum++;s.push_back(currType+" "+*(yyvsp[0].str));
			insertID(blocks.back(),currType+" "+*(yyvsp[0].str));
		}
#line 1553 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 155 "threeaddr.y" /* yacc.c:1646  */
    {}
#line 1559 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 157 "threeaddr.y" /* yacc.c:1646  */
    {instList[nextInst()]=(yyvsp[-3].node)->array+"["+(yyvsp[-3].node)->addr+"] = "+(yyvsp[-1].node)->addr;	}
#line 1565 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 158 "threeaddr.y" /* yacc.c:1646  */
    {
	  					if(table[blocks.back()].find(*(yyvsp[-3].str))==table[blocks.back()].end())
						{
							yyerror("variable not declared");
						}
	  					instList[nextInst()]=*(yyvsp[-3].str)+" = "+(yyvsp[-1].node)->addr;
	  					(yyval.node)=new NODE();
	  				}
#line 1578 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 167 "threeaddr.y" /* yacc.c:1646  */
    {
					(yyval.node)=makeNode();
					(yyval.node)->array=*(yyvsp[-3].str);
					if(table[blocks.back()].find(*(yyvsp[-3].str))==table[blocks.back()].end())
					{
						yyerror("variable not declared");
					}
					(yyval.node)->type=table[blocks.back()][*(yyvsp[-3].str)].first;
					instList[nextInst()]=(yyval.node)->addr+" = "+(yyvsp[-1].node)->addr+" * "+to_string(getWidth((yyval.node)->type));
				}
#line 1593 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 178 "threeaddr.y" /* yacc.c:1646  */
    {
		 			NODE *myTemp=makeNode();
		 			(yyval.node)=makeNode();
		 			(yyval.node)->array=(yyvsp[-3].node)->array;
		 			(yyval.node)->type=(yyvsp[-3].node)->type;
		 			(yyval.node)->type.second.erase((yyval.node)->type.second.begin());
		 			instList[nextInst()]=myTemp->addr + " = "+(yyvsp[-1].node)->addr +" * "+to_string(getWidth((yyval.node)->type));
		 			instList[nextInst()]=(yyval.node)->addr+" = "+(yyvsp[-3].node)->addr+ " + " + myTemp->addr;
		 		}
#line 1607 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 187 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1613 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 189 "threeaddr.y" /* yacc.c:1646  */
    {
					(yyval.node)=new NODE();
					backpatch((yyvsp[-3].node)->falseList,(yyvsp[-1].node)->instNum);
					(yyval.node)->trueList=merge((yyvsp[-3].node)->trueList,(yyvsp[0].node)->trueList);
					(yyval.node)->falseList=(yyvsp[0].node)->falseList;
				}
#line 1624 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 195 "threeaddr.y" /* yacc.c:1646  */
    {
	 				(yyval.node)=new NODE();
	 				backpatch((yyvsp[-3].node)->trueList,(yyvsp[-1].node)->instNum);
	 				(yyval.node)->trueList=(yyvsp[0].node)->trueList;
	 				(yyval.node)->falseList=merge((yyvsp[-3].node)->falseList,(yyvsp[0].node)->falseList);
				}
#line 1635 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 201 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)->trueList=(yyvsp[0].node)->trueList;(yyval.node)->falseList=(yyvsp[0].node)->falseList;}
#line 1641 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 203 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)->trueList=(yyvsp[0].node)->falseList;(yyval.node)->falseList=(yyvsp[0].node)->trueList;}
#line 1647 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 204 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)->trueList=(yyvsp[-1].node)->trueList;(yyval.node)->falseList=(yyvsp[-1].node)->falseList;}
#line 1653 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 205 "threeaddr.y" /* yacc.c:1646  */
    {
	    				(yyval.node)=new NODE();
	    				(yyval.node)->trueList.push_back(nextInst());
	    				instList[(yyval.node)->trueList.back()]="if "+(yyvsp[-2].node)->addr+" "+*(yyvsp[-1].str)+" "+(yyvsp[0].node)->addr+" goto";
	    				(yyval.node)->falseList.push_back(nextInst());
	    				instList[(yyval.node)->falseList.back()]="goto";
	    			}
#line 1665 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 212 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)->trueList.push_back(nextInst());instList[(yyval.node)->trueList.back()]="goto";}
#line 1671 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 213 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)->falseList.push_back(nextInst());instList[(yyval.node)->falseList.back()]="goto";}
#line 1677 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 215 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)=new NODE();(yyval.node)->instNum=instCounter;}
#line 1683 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 216 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=new NODE();(yyval.node)->nextList.push_back(nextInst());instList[(yyval.node)->nextList.back()]="goto";}
#line 1689 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 218 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=makeNode();instList[nextInst()]=(yyval.node)->addr+" = "+(yyvsp[-2].node)->addr+" + "+(yyvsp[0].node)->addr;}
#line 1695 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 219 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=makeNode();instList[nextInst()]=(yyval.node)->addr+" = "+(yyvsp[-2].node)->addr+" - "+(yyvsp[0].node)->addr;}
#line 1701 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 220 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1707 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 221 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=makeNode();instList[nextInst()]=(yyval.node)->addr+" = "+(yyvsp[0].node)->array+"["+(yyvsp[0].node)->addr+"]";}
#line 1713 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 223 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=makeNode();instList[nextInst()]=(yyval.node)->addr+" = "+(yyvsp[-2].node)->addr+" * "+(yyvsp[0].node)->addr;}
#line 1719 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 224 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=makeNode();instList[nextInst()]=(yyval.node)->addr+" = "+(yyvsp[-2].node)->addr+" / "+(yyvsp[0].node)->addr;}
#line 1725 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 225 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1731 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 227 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=makeNode();instList[nextInst()]=(yyval.node)->addr+" = "+(yyvsp[-2].node)->addr+" ^ "+(yyvsp[0].node)->addr;}
#line 1737 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 228 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1743 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 230 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 1749 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 231 "threeaddr.y" /* yacc.c:1646  */
    {
	 		if(table[blocks.back()].find(*(yyvsp[0].str))==table[blocks.back()].end())
			{
				yyerror("variable not declared");
			}
			(yyval.node)=makeNode((yyvsp[0].str));
		}
#line 1761 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 238 "threeaddr.y" /* yacc.c:1646  */
    {
	 		(yyval.node)=makeNode();instList[nextInst()]=(yyval.node)->addr+" = "+(yyvsp[0].node)->array+"["+(yyvsp[0].node)->addr+"]";
	 	}
#line 1769 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 241 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=makeNode((yyvsp[0].str));}
#line 1775 "threeaddr.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 242 "threeaddr.y" /* yacc.c:1646  */
    {(yyval.node)=makeNode();instList[nextInst()]=(yyval.node)->addr+" = - "+(yyvsp[0].node)->addr;}
#line 1781 "threeaddr.tab.c" /* yacc.c:1646  */
    break;


#line 1785 "threeaddr.tab.c" /* yacc.c:1646  */
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
#line 244 "threeaddr.y" /* yacc.c:1906  */

//for DAG
bool isInt(string s)
{
	bool flag=true;
	for(ll i=0;i<s.length();i++)
	{
		if(s[i]<'0' || s[i]>'9')
			flag=false;
	}
	return flag;
}
typedef struct dNode
{
	string op,name;
	vector<string> resVars;
	bool isGenerated;
	vector<struct dNode*> children;
}dagNode;

vector<vector<dagNode*> > dagBlock;
map<string,ll> dagVarCount;

dagNode* getDAGNode(string name, string op)
{
	dagNode *x=new dagNode();
	x->op=op;
	x->resVars.push_back(name+"_"+to_string(dagVarCount[name]));
	dagVarCount[name]++;
	x->isGenerated=false;
	return x;
}
dagNode* getDAGNode(string name)
{
	dagNode *x=new dagNode();
	if(isInt(name))
	{
		x->name=name;
	}
	else
		x->name=name+"_"+to_string(dagVarCount[name]);
	x->isGenerated=false;
	dagVarCount[name]++;
	return x;
}

string getVarName(dagNode *curr)
{
	if(curr->name!="")
		return curr->name;
	if(curr->resVars.size()>0)
		return curr->resVars.front();
	return "<not found>";
}
string getVarName(string var)
{
	return var.substr(0,var.rfind("_"));
}
void dfsDAG(dagNode *curr,string tab="\t")
{
	if(curr->op!="")
		cout<<tab<<"OP: "<<curr->op<<endl;
	if(curr->name!="")
		cout<<tab<<"NAME: "<<curr->name<<endl;
	if(curr->resVars.size()>0)
	{
		cout<<tab<<"ResVars: ";
		for(ll i=0;i<curr->resVars.size();i++)
		{
			cout<<curr->resVars[i]<<" ";
		}
		cout<<endl;
	}	
	for(ll i=0;i<curr->children.size();i++)
	{
		cout<<tab<<"child "<<(i+1)<<":"<<endl;
		dfsDAG(curr->children[i],tab+"\t");
	}
}
void displayDAG()
{
	cout<<"DAG:"<<endl;
	for(ll i=0;i<dagBlock.size();i++)
	{
		cout<<"Block "<<i<<":"<<endl;
		for(ll j=0;j<dagBlock[i].size();j++)
		{
			dfsDAG(dagBlock[i][j]);
			cout<<endl;
		}
	}
}
bool findDagNode(map<string,dagNode*> dagMap,dagNode *res,string op1,string op,string op2="")
{
	for(map<string,dagNode*>::iterator it=dagMap.begin();it!=dagMap.end();it++)
	{
		dagNode *curr=it->second;
		if(curr->op==op)
		{
			if(curr->children.size()==2 && op2!="")
			{
				bool one=(getVarName(curr->children[0]->name)==op1),two=(getVarName(curr->children[1]->name)==op2);
				for(int i=0;i<curr->children[0]->resVars.size();i++)
				{
					if(op1==getVarName(curr->children[0]->resVars[i]))
						one=true;
				}
				for(int i=0;i<curr->children[1]->resVars.size();i++)
				{
					if(op2==getVarName(curr->children[1]->resVars[i]))
						two=true;
				}
				if(one && two)
				{
					res=curr;
					return true;
				}
			}
			if(curr->children.size()==1)
			{
				bool one=(getVarName(curr->children[0]->name)==op1);
				for(int i=0;i<curr->children[0]->resVars.size();i++)
				{
					if(op1==getVarName(curr->children[0]->resVars[i]))
						one=true;
				}
				if(one)
				{
					res=curr;
					return true;
				}
			}
		}
	}
	return false;
}
void genDAG(ll bno)
{
	vector<string> inst=basicBlock[bno];
	map<string,dagNode*> dagMap;
	for(ll i=0;i<inst.size();i++)
	{
		istringstream ss(inst[i]);
		string temp;
		vector<string> splits;
		while(ss>>temp)
		{
			splits.push_back(temp);
		}
		if(splits.size()>0 && splits[0]=="if" || splits[0]=="goto")
			continue;
		if(splits.size()==5)
		{
			dagNode *op1,*op2,*res;
			if(findDagNode(dagMap,res,splits[2],splits[3],splits[4]))
			{
				res->resVars.push_back(splits[0]+"_"+to_string(dagVarCount[splits[0]]));
				dagMap[splits[0]]=res;
				continue;
			}
			if(dagMap.find(splits[2])!=dagMap.end())
				op1=dagMap[splits[2]];
			else
				op1=getDAGNode(splits[2]);
			if(dagMap.find(splits[4])!=dagMap.end())
				op2=dagMap[splits[4]];
			else
				op2=getDAGNode(splits[4]);
			res=getDAGNode(splits[0],splits[3]);
			res->children.push_back(op1);
			res->children.push_back(op2);
			for(ll j=0;j<dagBlock[bno].size();j++)
			{
				if(dagBlock[bno][j]==op1 || dagBlock[bno][j]==op2)
				{
					dagBlock[bno].erase(dagBlock[bno].begin()+j);
					j--;
				}
			}
			dagBlock[bno].push_back(res);
			dagMap[splits[2]]=op1;
			dagMap[splits[4]]=op2;
			dagMap[splits[0]]=res;
		}
		else if(splits.size()==3)
		{
			dagNode *op1,*res;
			if(splits[2].find("[")!=-1)
			{
				dagNode *op2;
				ll ind=splits[2].find("[");
				string base=splits[2].substr(0,ind),offset=splits[2].substr(ind+1,splits[2].find("]")-ind-1);
				if(dagMap.find(base)!=dagMap.end())
					op1=dagMap[base];
				else
					op1=getDAGNode(base);
				if(dagMap.find(offset)!=dagMap.end())
					op2=dagMap[offset];
				else
					op2=getDAGNode(offset);
				res=getDAGNode(splits[0],"=[]");
				res->children.push_back(op1);
				res->children.push_back(op2);
				for(ll j=0;j<dagBlock[bno].size();j++)
				{
					if(dagBlock[bno][j]==op1 || dagBlock[bno][j]==op2)
					{
						dagBlock[bno].erase(dagBlock[bno].begin()+j);
						j--;
					}
				}
				dagBlock[bno].push_back(res);
				dagMap[base]=op1;
				dagMap[offset]=op2;
				dagMap[splits[0]]=res;
				continue;
			}
			if(splits[0].find("[")!=-1)
			{
				dagNode *op2,*op3;
				ll ind=splits[0].find("[");
				string base=splits[0].substr(0,ind),offset=splits[0].substr(ind+1,splits[0].find("]")-ind-1);
				if(dagMap.find(base)!=dagMap.end())
					op1=dagMap[base];
				else
					op1=getDAGNode(base);
				if(dagMap.find(offset)!=dagMap.end())
					op2=dagMap[offset];
				else
					op2=getDAGNode(offset);
				if(dagMap.find(splits[2])!=dagMap.end())
					op3=dagMap[splits[2]];
				else
					op3=getDAGNode(splits[2]);
				res=getDAGNode(base,"[]=");
				res->children.push_back(op1);
				res->children.push_back(op2);
				res->children.push_back(op3);
				for(ll j=0;j<dagBlock[bno].size();j++)
				{
					if(dagBlock[bno][j]==op1 || dagBlock[bno][j]==op2 || dagBlock[bno][j]==op3)
					{
						dagBlock[bno].erase(dagBlock[bno].begin()+j);
						j--;
					}
				}
				dagBlock[bno].push_back(res);
				dagMap[base]=op1;
				dagMap[offset]=op2;
				dagMap[splits[2]]=op3;
				continue;
			}
			if(findDagNode(dagMap,res,splits[2],splits[1]))
			{
				res->resVars.push_back(splits[0]+"_"+to_string(dagVarCount[splits[0]]));
				dagMap[splits[0]]=res;
				continue;
			}
			if(dagMap.find(splits[2])!=dagMap.end())
			{
				op1=dagMap[splits[2]];
				op1->resVars.push_back(splits[0]+"_"+to_string(dagVarCount[splits[0]]));
				dagVarCount[splits[0]]++;
				dagMap[splits[0]]=op1;
			}
			else
			{
				op1=getDAGNode(splits[2]);
				op1->resVars.push_back(splits[0]+"_"+to_string(dagVarCount[splits[0]]));
				dagVarCount[splits[0]]++;
				dagBlock[bno].push_back(op1);
				dagMap[splits[0]]=op1;
				dagMap[splits[2]]=op1;
			}
			
		}
	}
}


void dagToThreeAddr(dagNode *curr)
{
	if(curr->isGenerated)
	{
		return;
	}
	for(ll i=0;i<curr->children.size();i++)
	{
		dagToThreeAddr(curr->children[i]);
	}
	if(curr->children.size()<2)
		return;
	if(curr->children.size()==2)
	{
		cout<<curr->resVars.front()<<" = "<<getVarName(curr->children[0])<<" "<<curr->op<<" "<<getVarName(curr->children[1])<<endl;
	}
	curr->isGenerated=true;
}
void genThreeAddr()
{
	cout<<"New Three Address:"<<endl;
	for(ll i=0;i<dagBlock.size();i++)
	{
		cout<<"Block "<<i<<": "<<endl;
		for(ll j=0;j<dagBlock[i].size();j++)
		{
			dagToThreeAddr(dagBlock[i][j]);
		}
		cout<<endl;
	}
}
void genDAG()
{
	dagBlock.resize(basicBlock.size());
	for(ll i=0;i<dagBlock.size();i++)
		genDAG(i);
}
void genFlowGraph()
{
	bbgraph.resize(basicBlock.size());
	for(map<ll,vector<string> >::iterator it=basicBlock.begin();it!=basicBlock.end();it++)
	{
		ll ind=-1;
		string lastStmt=it->second.back();
		if((ind=lastStmt.rfind("goto"))!=-1)
		{
			bbgraph[it->first].push_back(to_int(lastStmt.substr(ind+5)));
			if(ind!=0 && it->first!=basicBlock.size()-1)
			{
				bbgraph[it->first].push_back(it->first+1);
			}
		}
		else
		{
			if(it->first!=basicBlock.size()-1)
				bbgraph[it->first].push_back(it->first+1);
		}
	}
}
void displayFlowGraph()
{
	cout<<"Flow Graph:"<<endl;
	for(ll i=0;i<bbgraph.size();i++)
	{
		cout<<i<<": ";
		for(ll j=0;j<bbgraph[i].size();j++)
		{
			cout<<bbgraph[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void findLeaders()
{
	bool flag=true;
	for(map<ll,string>::iterator it=instList.begin();it!=instList.end();it++)
	{
		if(flag)
		{
			leaders.insert(it->first);
			int ind=it->second.rfind("goto");
			if(ind!=-1)
			{
				leaders.insert(to_int(it->second.substr(ind+5)));
				flag=true;
				continue;
			}
			flag=false;
		}
		int ind=it->second.rfind("goto");
		if(ind!=-1)
		{
			leaders.insert(to_int(it->second.substr(ind+5)));
			flag=true;
			continue;
		}
	}
}
void displayLeaders()
{
	cout<<"Leaders:"<<endl;
	for(set<ll>::iterator it=leaders.begin();it!=leaders.end();it++)
	{
		cout<<*it<<endl;
	}
}
void genBasicBlock()
{
	findLeaders();
	map<ll,ll> lineToBlock;
	ll bbno=-1;
	for(map<ll,string>::iterator it=instList.begin();it!=instList.end();it++)
	{
		if(leaders.find(it->first)!=leaders.end())
		{
			bbno++;
		}
		lineToBlock[it->first]=bbno;
	}
	bbno=-1;
	for(map<ll,string>::iterator it=instList.begin();it!=instList.end();it++)
	{
		if(leaders.find(it->first)!=leaders.end())
		{
			bbno++;
		}
		int ind=-1;
		string bbinst=it->second;
		if((ind=it->second.rfind("goto"))!=-1)
		{
			bbinst=it->second.substr(0,ind+5) + to_string(lineToBlock[to_int(it->second.substr(ind+5))]);
		}
		basicBlock[bbno].push_back(bbinst);
	}
}
void displayBasicBlocks()
{
	cout<<"Basic Blocks:"<<endl;
	for(map<ll,vector<string> >::iterator it=basicBlock.begin();it!=basicBlock.end();it++)
	{
		cout<<"Block "<<it->first<<":"<<endl;
		for(ll i=0;i<it->second.size();i++)
		{
			cout<<"\t"<<it->second[i]<<endl;
		}
		cout<<endl;
	}
}
void displayInst()
{
	cout<<"Three Address Statements:"<<endl;
	for(map<ll,string>::iterator it=instList.begin();it!=instList.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<endl;
}

int getTemp()
{
	return tempcount++;
}
int nextInst()
{
	return instCounter++;
}
vector<ll> merge(vector<ll> a,vector<ll> b)
{
	a.insert(a.end(),b.begin(),b.end());
	return a;
}
void backpatch(vector<ll> list,int num)
{
	for(ll i=0;i<list.size();i++)
	{
		if(instList[list[i]].find("goto")==instList[list[i]].length()-4)
		{
			instList[list[i]]+=" "+to_string(num);
		}
	}
}
void insertID(int bno,string varname)
{
	string type,value;
	int ind=varname.find(" ");
	if(ind!=-1)
	{
		type=varname.substr(0,ind);
		varname=varname.substr(ind+1);
	}
	ind=varname.find("=");
	value="";
	if(ind!=-1)
	{
		value=varname.substr(ind+1);
		varname=varname.substr(0,ind);
	}
	ind=varname.find("[");
	vector<ll> dims;
	if(ind!=-1)
	{
		string indexes=varname.substr(ind);
		varname=varname.substr(0,ind);
		for(ll i=0;i<indexes.length();i++)
		{
			if(indexes[i]=='[' || indexes[i]==']')
				indexes[i]=' ';
		}
		istringstream in(indexes.c_str());
		int dim;
		while(in>>dim)
		{
			dims.push_back(dim);
		}
	}
	if(table[bno].find(varname)!=table[bno].end())
	{
		yyerror("variable already declared");
	}
	table[bno][varname]=make_pair(make_pair(type,dims),value);
}
ll getWidth(pair<string,vector<ll> > type)
{
	ll ans=width[type.first];
	for(ll i=1;i<type.second.size();i++)
	{
		ans=ans*type.second[i];
	}
	return ans;
}
void printTable()
{
	cout<<"Symbol Table:"<<endl;
	for(map<ll,map<string,pair<pair<string,vector<ll> >,string> > >::iterator it=table.begin();it!=table.end();it++)
	{
		cout<<"Block "<<it->first<<":"<<endl;
		for(map<string,pair<pair<string,vector<ll> >,string> >::iterator it2=it->second.begin();it2!=it->second.end();it2++)
		{
			cout<<it2->first<<" "<<it2->second.first.first<<" "<<it2->second.second;
			for(vector<ll>::iterator it3=it2->second.first.second.begin();it3!=it2->second.first.second.end();it3++)
				cout<<*it3<<' ';
			cout<<endl;
		}
		cout<<endl;
	}
}
void setWidths()
{
	width["int"]=4;
	width["float"]=4;
	width["char"]=1;
	width["double"]=8;
}
string to_string(ll val)
{
	ostringstream ss;
	ss<<val;
	return ss.str();
}
ll to_int(string val)
{
	istringstream ss(val);
	ll x;
	ss>>x;
	return x;
}
void readThreeAddress(int start=0)
{
	string inst;
	while(getline(cin,inst))
		instList[start++]=inst;
}
void yyerror(char* s)
{
	cout<<s<<endl;
	exit(0);
}
int main()
{
	setWidths();
	yyparse();
	//readThreeAddress();
	printTable();
	displayInst();
	genBasicBlock();
	displayBasicBlocks();
	genFlowGraph();
	displayFlowGraph();
	//comment the following if the code has control statements
	//use only with no control flows
	
	genDAG();
	displayDAG();
	genThreeAddr();
}
