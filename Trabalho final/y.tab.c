/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "trabalhoFinal.y"


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


#define GetCurrentDir getcwd

extern  FILE *yyin;
void yyerror(const char * s);

extern int yylex();
extern int yyparse();

char *auxTermo = NULL;
char outfileName[] = "input_code.txt";
extern int lineCounter;

struct listIds *codeList = NULL;
struct listIds *simbTab = NULL;
int cont = 1, auxIds = 1, lines = 1, cont2 = 3, labels = 0;

char *fileName = "output.j";
FILE *file;



#line 101 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    COLCHETES_ABRE = 288,
    READ_WORD = 289,
    PRINT_WORD = 290,
    ASPAS = 291
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
#define READ_WORD 289
#define PRINT_WORD 290
#define ASPAS 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "trabalhoFinal.y"

    int ival;
    float fval;
    int bval;
    char * idval;
    char * aopval;

    struct listIds{
		int num;
        char *nome;
        struct listIds *prox;
    };
    struct valorar *a;

    struct listIds *id;
    
	struct {
		int **trueList, **falseList;
	} bexpr_type;
	struct {
		int **nextList;
	} stmt_type;
	int sType;


#line 251 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,    98,   103,   106,   106,   111,   112,   115,
     119,   138,   139,   141,   144,   145,   146,   147,   148,   149,
     150,   153,   168,   186,   187,   206,   209,   210,   213,   216,
     219,   220,   224,   225,   228,   235,   242,   252,   255,   258,
     262,   273,   274,   277,   278,   281,   284,   302,   315,   318,
     321,   322,   325,   326,   329,   332,   333,   334,   337,   342,
     347,   350,   351,   352,   353,   354,   355,   358
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT", "T_REAL", "T_BOOL", "IF_WORD",
  "THEN_WORD", "ELSE_WORD", "PROGRAM_WORD", "WHILE_WORD", "DO_WORD",
  "FOR_WORD", "BEGIN_WORD", "END_WORD", "VAR_WORD", "ARRAY_WORD",
  "OF_WORD", "INT", "FLOAT", "BOOL", "IDENTIFIER", "OPAD", "OPMUL",
  "RELATIONAL", "SEMI_COLON", "PONTO_PONTO", "VIRGULA", "DOIS_PONTOS",
  "ATRIBUICAO", "RIGHT_BRACKET", "LEFT_BRACKET", "COLCHETES_FECHA",
  "COLCHETES_ABRE", "READ_WORD", "PRINT_WORD", "ASPAS", "$accept",
  "programa", "$@1", "corpo", "comandoComposto", "$@2", "declaracoes",
  "declaracoesaux", "declaracaoDeVariavel", "listaDeComandos",
  "listaComandosaux", "comando", "listaIds", "atribuicao", "condicional",
  "condicionalAUX", "comandoWhile", "comandoFor", "expressao",
  "expressaoSimples", "literal", "intlit", "floatlit", "boollit", "fator",
  "seletor", "seletoraux", "termo", "opmul", "agregadoAux", "lit", "tipo",
  "tipoAgregado", "tipoSimples", "variavel", "vazio", "print", "idd",
  "read", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -69,    34,    36,   -69,    31,    45,   -69,   -69,    46,    47,
     -69,   -69,   -69,    60,    59,   -69,   -69,   -20,   -69,    69,
       4,   -69,    64,    38,   -69,     0,   -69,    56,   -69,    61,
      62,   -69,    63,   -69,   -69,   -69,   -69,    65,   -69,   -69,
     -69,   -69,   -69,   -69,    66,   -69,   -69,   -69,   -69,   -69,
     -69,     0,     2,    67,   -69,   -69,   -69,   -69,   -69,    72,
     -69,    80,    75,    68,    70,   -69,    76,    71,   -69,     0,
      58,    81,    37,     4,     0,     0,   -69,     0,    74,    77,
       0,    78,    29,    67,    57,   -69,    41,    38,   -69,    15,
      82,    72,   -69,     0,     0,    33,   -69,   -69,    82,   -69,
      -7,    58,   -69,   -69,     4,   -69,   -69,    39,     8,   -69,
     -69,    79,    82,   -69,   -69,    85,    86,     0,   -69,   -69,
     -69,    49,     0,    50,    83,   -69,    87,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,    59,     3,     9,     0,
       8,     5,     4,     0,     0,    59,    21,     0,     7,    13,
       0,    12,     0,     0,     6,     0,    59,     0,    59,     0,
       0,    16,     0,    14,    15,    18,    17,     0,    19,    20,
      22,    55,    56,    57,     0,    10,    52,    53,    37,    38,
      39,     0,     0,    30,    41,    34,    35,    36,    47,    33,
      40,    13,     0,    58,     0,    44,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,    24,    23,    51,     0,     0,    42,     0,
      31,    32,    46,     0,     0,     0,    67,    59,    65,    40,
       0,     0,    49,    54,     0,    27,    25,     0,     0,    43,
      59,     0,    66,    40,    50,     0,     0,     0,    60,    26,
      28,     0,     0,     0,     0,    59,    13,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,   -69,   -69,   106,   -69,   -69,   -69,   -69,   -25,
     -69,   -68,   -69,    53,   -69,   -69,   -69,   -69,   -47,   -66,
     -64,   -69,   -69,   -69,   -11,   -69,   -69,    42,   -69,   -69,
     -69,    32,   -69,   -69,   -18,    -6,   -69,   -69,   -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     7,    31,    15,     8,     9,    14,    19,
      20,    32,    17,    33,    34,   106,    35,    36,    52,    53,
      54,    55,    56,    57,    58,    63,    64,    59,    77,    71,
      86,    45,    46,    47,    60,    21,    38,   100,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      10,    61,    37,    83,    72,    89,    85,    22,    23,    73,
      25,    48,    49,    50,   110,    26,    27,    11,    48,    49,
      50,    28,    65,   104,    51,    28,    74,    90,   108,   111,
      75,    51,   117,    95,     3,    98,   115,   114,    29,    30,
     105,    41,    42,    43,    37,     4,   107,    48,    49,    50,
      97,   121,     5,   112,    44,    37,   123,    74,    84,    11,
      51,    74,    13,    74,    99,   109,    92,    88,   101,   116,
       6,    75,    75,   102,   122,   124,    48,    49,    50,   -47,
     -47,    16,   113,    24,    18,    40,    37,    62,    68,    75,
      78,    65,    66,    67,    69,    76,    28,    81,    87,    70,
     126,   -45,    94,    80,    65,    93,    74,    82,    96,   118,
     119,   120,   127,   125,    12,    79,     0,    91,     0,   103
};

static const yytype_int8 yycheck[] =
{
       6,    26,    20,    69,    51,    73,    70,    27,    28,     7,
       6,    18,    19,    20,    21,    11,    12,    13,    18,    19,
      20,    21,    28,     8,    31,    21,    24,    74,    94,    36,
      22,    31,    24,    80,     0,    82,   104,   101,    34,    35,
      25,     3,     4,     5,    62,     9,    93,    18,    19,    20,
      21,   117,    21,   100,    16,    73,   122,    24,    69,    13,
      31,    24,    15,    24,    82,    32,    77,    30,    27,    30,
      25,    22,    22,    32,    25,    25,    18,    19,    20,    22,
      23,    21,   100,    14,    25,    21,   104,    31,    25,    22,
      10,    97,    31,    31,    29,    23,    21,    21,    17,    33,
     125,    33,    25,    33,   110,    31,    24,    36,    30,    30,
      25,    25,    25,    30,     8,    62,    -1,    75,    -1,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     9,    21,    25,    40,    43,    44,
      72,    13,    41,    15,    45,    42,    21,    49,    25,    46,
      47,    72,    27,    28,    14,     6,    11,    12,    21,    34,
      35,    41,    48,    50,    51,    53,    54,    71,    73,    75,
      21,     3,     4,     5,    16,    68,    69,    70,    18,    19,
      20,    31,    55,    56,    57,    58,    59,    60,    61,    64,
      71,    46,    31,    62,    63,    72,    31,    31,    25,    29,
      33,    66,    55,     7,    24,    22,    23,    65,    10,    50,
      33,    21,    36,    56,    61,    57,    67,    17,    30,    48,
      55,    64,    61,    31,    25,    55,    30,    21,    55,    71,
      74,    27,    32,    68,     8,    25,    52,    55,    56,    32,
      21,    36,    55,    71,    57,    48,    30,    24,    30,    25,
      25,    56,    25,    56,    25,    30,    46,    25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    42,    41,    43,    43,    44,
      45,    46,    46,    47,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    50,    50,    51,    52,    52,    53,    54,
      55,    55,    56,    56,    57,    57,    57,    58,    59,    60,
      61,    61,    61,    62,    62,    63,    64,    64,    65,    66,
      67,    67,    68,    68,    69,    70,    70,    70,    71,    72,
      73,    74,    74,    74,    74,    74,    74,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     5,     2,     0,     4,     3,     1,     1,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     5,     3,     1,     7,    13,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     1,     1,     3,     1,     1,     3,
       3,     1,     1,     1,     4,     1,     1,     1,     2,     0,
       6,     2,     1,     2,     1,     1,     2,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 98 "trabalhoFinal.y"
            {generateHeader();}
#line 1515 "y.tab.c"
    break;

  case 3:
#line 99 "trabalhoFinal.y"
                                                   {printf("Programa\n");}
#line 1521 "y.tab.c"
    break;

  case 4:
#line 103 "trabalhoFinal.y"
                                         {printf("corpo\n");}
#line 1527 "y.tab.c"
    break;

  case 5:
#line 106 "trabalhoFinal.y"
                              {printf("comando composto\n");}
#line 1533 "y.tab.c"
    break;

  case 6:
#line 108 "trabalhoFinal.y"
                             { generateFooter();}
#line 1539 "y.tab.c"
    break;

  case 8:
#line 112 "trabalhoFinal.y"
                                 {printf("declaracoes\n");}
#line 1545 "y.tab.c"
    break;

  case 10:
#line 119 "trabalhoFinal.y"
                                                         { 
    // struct listIds *l;
    // l = $2;
    // codeList = NULL;
    // while(l != NULL){
    //     if($4 == T_INT){
    //         defineVar(l->nome,T_INT);
    //     }else if ($4 == T_REAL){
    //         defineVar(l->nome,T_REAL);
    //     }else if ($4 == T_BOOL){
    //         defineVar(l->nome,T_BOOL);
    //     }
    //     l = l->prox;
    // }

}
#line 1566 "y.tab.c"
    break;

  case 12:
#line 139 "trabalhoFinal.y"
                                             {printf("lista de comandos\n");}
#line 1572 "y.tab.c"
    break;

  case 14:
#line 144 "trabalhoFinal.y"
                                                         {printf("comando\n");}
#line 1578 "y.tab.c"
    break;

  case 15:
#line 145 "trabalhoFinal.y"
                                                         {printf("comando\n");}
#line 1584 "y.tab.c"
    break;

  case 16:
#line 146 "trabalhoFinal.y"
                                                         {printf("comando\n");}
#line 1590 "y.tab.c"
    break;

  case 17:
#line 147 "trabalhoFinal.y"
                                                         {printf("comando\n");}
#line 1596 "y.tab.c"
    break;

  case 18:
#line 148 "trabalhoFinal.y"
                                                         {printf("comando\n");}
#line 1602 "y.tab.c"
    break;

  case 19:
#line 149 "trabalhoFinal.y"
                                                         {printf("comando\n");}
#line 1608 "y.tab.c"
    break;

  case 20:
#line 150 "trabalhoFinal.y"
                                                         {printf("comando\n");}
#line 1614 "y.tab.c"
    break;

  case 21:
#line 153 "trabalhoFinal.y"
                                                         {
                // struct listIds *p, *a;
                // p = (malloc(sizeof(struct listIds)));
                // a = (malloc(sizeof(struct listIds)));
                // p->num = auxIds -1;
                // p->nome = $1;
                // p->prox = codeList;
                // a->num = cont2;
                // cont2++;
                // a->nome = p->nome;
                // a->prox = simbTab;
                // simbTab = a;
                // codeList = p;
                // auxIds++;
    }
#line 1634 "y.tab.c"
    break;

  case 22:
#line 168 "trabalhoFinal.y"
                                                         {
            // struct listIds *p,*a;
            //     p = (malloc(sizeof(struct listIds)));
            //     a = (malloc(sizeof(struct listIds)));
            //     p->num = auxIds -1;
            //     p->nome = $3;
            //     p->prox = codeList;
            //     codeList = p;
            //     a->num = cont2;
            //     cont2++;
            //     a->nome = p->nome;
            //     a->prox = simbTab;
            //     simbTab = a;
            //     auxIds = 1;
            //     $$ = codeList;
    }
#line 1655 "y.tab.c"
    break;

  case 24:
#line 187 "trabalhoFinal.y"
                                                               {
            //     int a = findVar($1);
            //     if(a != -1){
            //         fprintf(file, "L_%i\n", labels);
            //         if(strcmp($3->tipo, "INT")==0){
            //             fprintf(file, "ldc %.0f\n", $3->valor);
            //         }else if(strcmp($3->tipo, "FLOAT")==0){
            //             fprintf(file, "ldc %f\n", $3->valor);
            //         }else if(strcmp($3->tipo, "BOOL")==0){
            //             fprintf(file, "ldc %.0f\n", $3->valor);
            //         }else{
            //             fprintf(file, "iload %.0f\n", $3->valor);
            //         }
            //         fprintf(file, "istore %i\n", a);
            //         labels++;
            // }
                printf("atribuicao\n");}
#line 1677 "y.tab.c"
    break;

  case 25:
#line 206 "trabalhoFinal.y"
                                                                {printf("condicional\n");}
#line 1683 "y.tab.c"
    break;

  case 26:
#line 209 "trabalhoFinal.y"
                                                                              {printf("condicionalAUX\n");}
#line 1689 "y.tab.c"
    break;

  case 28:
#line 213 "trabalhoFinal.y"
                                                                                                   {printf("comando While\n");}
#line 1695 "y.tab.c"
    break;

  case 29:
#line 216 "trabalhoFinal.y"
                                                                                                                                                                                       {printf("comando For\n");}
#line 1701 "y.tab.c"
    break;

  case 30:
#line 219 "trabalhoFinal.y"
                                                         {printf("expressao\n");}
#line 1707 "y.tab.c"
    break;

  case 31:
#line 220 "trabalhoFinal.y"
                                           {printf("expressao\n");}
#line 1713 "y.tab.c"
    break;

  case 32:
#line 224 "trabalhoFinal.y"
                                                    {printf("EXP SIMPLES \n");}
#line 1719 "y.tab.c"
    break;

  case 33:
#line 225 "trabalhoFinal.y"
                                                    {printf("EXP SIMPLES \n");}
#line 1725 "y.tab.c"
    break;

  case 34:
#line 228 "trabalhoFinal.y"
                                                      {printf("Atribuido1\n");
        // struct valorar *p;
        // p=malloc(sizeof(struct valorar));
        // p->valor = $1;
        // p->tipo = strdup("INT");
        // $$ = p;
        }
#line 1737 "y.tab.c"
    break;

  case 35:
#line 235 "trabalhoFinal.y"
                                                      {printf("Atribuido2\n");
        // struct valorar *p;
        // p=malloc(sizeof(struct valorar));
        // p->valor = $1;
        // p->tipo = strdup("FLOAT");
        // $$ = p;
       }
#line 1749 "y.tab.c"
    break;

  case 36:
#line 242 "trabalhoFinal.y"
                                                      {printf("Atribuido3\n");}
#line 1755 "y.tab.c"
    break;

  case 37:
#line 252 "trabalhoFinal.y"
            {(yyval.ival) = (yyvsp[0].ival);}
#line 1761 "y.tab.c"
    break;

  case 38:
#line 255 "trabalhoFinal.y"
                {(yyval.fval) = (yyvsp[0].fval);}
#line 1767 "y.tab.c"
    break;

  case 39:
#line 258 "trabalhoFinal.y"
              {(yyval.bval) = (yyvsp[0].bval);}
#line 1773 "y.tab.c"
    break;

  case 40:
#line 262 "trabalhoFinal.y"
                                                   {printf("VARIAVEL \n");
        // int a = findVar($1);
        // //printf("okk\n");
        // if(a != -1){
        //     struct valorar *p;
        //     p=malloc(sizeof(struct valorar));
        //     p->valor = (float)a;
        //     p->tipo = strdup($1);
        //     $$ = p;
        // }
    }
#line 1789 "y.tab.c"
    break;

  case 41:
#line 273 "trabalhoFinal.y"
                                                    {printf("literal \n");(yyval.a) = (yyvsp[0].a);}
#line 1795 "y.tab.c"
    break;

  case 42:
#line 274 "trabalhoFinal.y"
                                                    {printf("expressao \n");}
#line 1801 "y.tab.c"
    break;

  case 44:
#line 278 "trabalhoFinal.y"
                             {printf("vazio \n");}
#line 1807 "y.tab.c"
    break;

  case 46:
#line 284 "trabalhoFinal.y"
                         {printf("TERMO\n");
        // if(strcmp($3->tipo, "INT")==0){
        //     fprintf(file, "ldc %.0f\n", $3->valor);
        // }else if(strcmp($3->tipo, "FLOAT")==0){
        //     fprintf(file, "ldc %f\n", $3->valor);
        // }else if(strcmp($3->tipo, "BOOL")==0){
        //     fprintf(file, "ldc %.0f\n", $3->valor);
        // }else{
        //     fprintf(file, "iload %.0f\n", $3->valor);
        // }
        // if(strcmp($2, "*")){
        //     fprintf(file, "imul\n");
        //     $$ = auxTermo;
        // }else if(strcmp($2, "/")){
        //     fprintf(file, "imul\n");
        //     $$ = auxTermo;
        // }
    }
#line 1830 "y.tab.c"
    break;

  case 47:
#line 302 "trabalhoFinal.y"
                         {printf("TERMO - FATOR\n");
        // if(strcmp($1->tipo, "INT")==0){
        //     fprintf(file, "ldc %.0f\n", $1->valor);
        // }else if(strcmp($1->tipo, "FLOAT")==0){
        //     fprintf(file, "ldc %f\n", $1->valor);
        // }else if(strcmp($1->tipo, "BOOL")==0){
        //     fprintf(file, "ldc %.0f\n", $1->valor);
        // }else{
        //     fprintf(file, "iload %.0f\n", $1->valor);
        // }
}
#line 1846 "y.tab.c"
    break;

  case 48:
#line 315 "trabalhoFinal.y"
               {(yyval.aopval) = (yyvsp[0].aopval);}
#line 1852 "y.tab.c"
    break;

  case 49:
#line 318 "trabalhoFinal.y"
                                                  {printf("agregado Aux \n");}
#line 1858 "y.tab.c"
    break;

  case 52:
#line 325 "trabalhoFinal.y"
                    {printf("TIPO \n");}
#line 1864 "y.tab.c"
    break;

  case 53:
#line 326 "trabalhoFinal.y"
                   {printf("TIPO \n");}
#line 1870 "y.tab.c"
    break;

  case 54:
#line 329 "trabalhoFinal.y"
                                                   {printf("TIPO AGREGADO\n");}
#line 1876 "y.tab.c"
    break;

  case 55:
#line 332 "trabalhoFinal.y"
                   {(yyval.sType)=T_INT;printf("TIPO INT\n");}
#line 1882 "y.tab.c"
    break;

  case 56:
#line 333 "trabalhoFinal.y"
                   {(yyval.sType)=T_REAL;printf("TIPO REAL\n");}
#line 1888 "y.tab.c"
    break;

  case 57:
#line 334 "trabalhoFinal.y"
                   {(yyval.sType)=T_BOOL;printf("TIPO BOOL\n");}
#line 1894 "y.tab.c"
    break;

  case 58:
#line 337 "trabalhoFinal.y"
                             {printf("Variavel\n");(yyval.idval) = (yyvsp[-1].idval);}
#line 1900 "y.tab.c"
    break;

  case 59:
#line 342 "trabalhoFinal.y"
       {printf("Vazio\n");}
#line 1906 "y.tab.c"
    break;

  case 67:
#line 358 "trabalhoFinal.y"
                                                       {printf("read\n");}
#line 1912 "y.tab.c"
    break;


#line 1916 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 361 "trabalhoFinal.y"




int main(int argv, char * argc[]) {
	FILE *myfile;
    file = fopen("output.j","w+");
	if(argv == 1) 
	{
		myfile = fopen("input_code.txt", "r");
	}
	if (!myfile) {
		printf("I can't open input code file!\n");
		char cCurrentPath[200];
		 if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
		     {
		     return -1;
		     }
		printf("%s\n",cCurrentPath);  
				getchar();

		return -1;

	}
	yyin = myfile;
	yyparse();
}

void yyerror(const char* s) {
	fprintf(stderr, "Erro de análise (sintática, Linha: %d): %s\n", lineCounter, s);
	exit(1);
}

void generateHeader()
{   
    fprintf(file,".source %s\n",outfileName);
	fprintf(file,".class public test\n.super java/lang/Object\n\n"); //code for defining class
	
    fprintf(file,".method public <init>()V \n");
	fprintf(file,"aload_0\n");
	fprintf(file,"invokenonvirtual java/lang/Object/<init>()V\n");
	fprintf(file,"return\n");
	fprintf(file,".end method\n\n");

	fprintf(file,".method public static main([Ljava/lang/String;)V\n");
	fprintf(file,".limit locals 100\n.limit stack 100\n");

	/* generate temporal vars for syso*/
	defineVar("1syso_int_var",T_INT);
	defineVar("1syso_float_var",T_REAL);
    printLine();
}

void generateFooter()
{
	fprintf(file,"\nreturn\n");
	fprintf(file,".end method\n");
}
 
void defineVar(char *id, int type){
    if(type == T_INT){
        fprintf(file, "iconst_0\nistore %i\n", cont);
    }else if(type == T_BOOL){
        fprintf(file, "iconst_0\nistore %i\n", cont);
    }else if(type == T_REAL){
        fprintf(file, "fconst_0\nfstore %i\n", cont);
    }
    cont++;
}

void printLine(){
    fprintf(file, ".line %i\n", lines);
    lines++;
}

void printSimb(){
    struct listIds *p;
    p = simbTab;
    while(p != NULL){
        printf("%i- %s\n",p->num, p->nome);
        p=p->prox;
    }
}

int findVar(char *nome){
    struct listIds *p;
    p = simbTab;
    while(p!=NULL){
        if(strcmp(p->nome, nome)==0){
            return p->num;
        }
        p = p->prox;
    }
    return -1;
}

void printnoj(int var){
    fprintf(file, "istore %i\n", var);
    fprintf(file, "getstatic      java/lang/System/out Ljava/io/PrintStream;");
    fprintf(file, "iload %i", var);
    fprintf(file, "invokevirtual java/io/PrintStream/println(I)V");

}
