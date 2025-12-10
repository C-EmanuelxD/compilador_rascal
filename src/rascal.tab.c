/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/rascal.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <vector>
    #include <string>
    #include "ast.h"

    extern int yylex();
    extern int yylineno;
    extern char* yytext;
    void yyerror(const char *s);

    Programa* root = nullptr;

#line 87 "src/rascal.tab.c"

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

#include "rascal.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_PROGRAM = 3,                  /* T_PROGRAM  */
  YYSYMBOL_T_BEGIN = 4,                    /* T_BEGIN  */
  YYSYMBOL_T_END = 5,                      /* T_END  */
  YYSYMBOL_T_VAR = 6,                      /* T_VAR  */
  YYSYMBOL_T_PROCEDURE = 7,                /* T_PROCEDURE  */
  YYSYMBOL_T_FUNCTION = 8,                 /* T_FUNCTION  */
  YYSYMBOL_T_IF = 9,                       /* T_IF  */
  YYSYMBOL_T_THEN = 10,                    /* T_THEN  */
  YYSYMBOL_T_ELSE = 11,                    /* T_ELSE  */
  YYSYMBOL_T_WHILE = 12,                   /* T_WHILE  */
  YYSYMBOL_T_DO = 13,                      /* T_DO  */
  YYSYMBOL_T_OR = 14,                      /* T_OR  */
  YYSYMBOL_T_AND = 15,                     /* T_AND  */
  YYSYMBOL_T_NOT = 16,                     /* T_NOT  */
  YYSYMBOL_T_DIV = 17,                     /* T_DIV  */
  YYSYMBOL_T_READ = 18,                    /* T_READ  */
  YYSYMBOL_T_WRITE = 19,                   /* T_WRITE  */
  YYSYMBOL_T_TRUE = 20,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 21,                   /* T_FALSE  */
  YYSYMBOL_T_INTEGER = 22,                 /* T_INTEGER  */
  YYSYMBOL_T_BOOLEAN = 23,                 /* T_BOOLEAN  */
  YYSYMBOL_T_SEMICOLON = 24,               /* T_SEMICOLON  */
  YYSYMBOL_T_COLON = 25,                   /* T_COLON  */
  YYSYMBOL_T_PONTO = 26,                   /* T_PONTO  */
  YYSYMBOL_T_VIRGULA = 27,                 /* T_VIRGULA  */
  YYSYMBOL_T_LPAREN = 28,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 29,                  /* T_RPAREN  */
  YYSYMBOL_T_ATRIB = 30,                   /* T_ATRIB  */
  YYSYMBOL_T_IGUAL = 31,                   /* T_IGUAL  */
  YYSYMBOL_T_DIFERENTE = 32,               /* T_DIFERENTE  */
  YYSYMBOL_T_MENOR = 33,                   /* T_MENOR  */
  YYSYMBOL_T_MENORIGUAL = 34,              /* T_MENORIGUAL  */
  YYSYMBOL_T_MAIOR = 35,                   /* T_MAIOR  */
  YYSYMBOL_T_MAIORIGUAL = 36,              /* T_MAIORIGUAL  */
  YYSYMBOL_T_MAIS = 37,                    /* T_MAIS  */
  YYSYMBOL_T_MENOS = 38,                   /* T_MENOS  */
  YYSYMBOL_T_VEZES = 39,                   /* T_VEZES  */
  YYSYMBOL_T_ERRO = 40,                    /* T_ERRO  */
  YYSYMBOL_T_NUM = 41,                     /* T_NUM  */
  YYSYMBOL_T_ID = 42,                      /* T_ID  */
  YYSYMBOL_LOWER_THAN_ELSE = 43,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_programa = 45,                  /* programa  */
  YYSYMBOL_bloco = 46,                     /* bloco  */
  YYSYMBOL_declaracao_var_vazio = 47,      /* declaracao_var_vazio  */
  YYSYMBOL_declaracao_subrotina_vazio = 48, /* declaracao_subrotina_vazio  */
  YYSYMBOL_secao_declaracao_variaveis = 49, /* secao_declaracao_variaveis  */
  YYSYMBOL_repeticao_declaracao = 50,      /* repeticao_declaracao  */
  YYSYMBOL_declaracao_vars = 51,           /* declaracao_vars  */
  YYSYMBOL_lista_identificadores = 52,     /* lista_identificadores  */
  YYSYMBOL_tipo = 53,                      /* tipo  */
  YYSYMBOL_secao_declaracao_subrotinas = 54, /* secao_declaracao_subrotinas  */
  YYSYMBOL_declaracao_subrotina = 55,      /* declaracao_subrotina  */
  YYSYMBOL_procedimento = 56,              /* procedimento  */
  YYSYMBOL_funcao = 57,                    /* funcao  */
  YYSYMBOL_parametros_gerais_subrotina = 58, /* parametros_gerais_subrotina  */
  YYSYMBOL_lista_parametros = 59,          /* lista_parametros  */
  YYSYMBOL_secao_parametros = 60,          /* secao_parametros  */
  YYSYMBOL_bloco_subrotina = 61,           /* bloco_subrotina  */
  YYSYMBOL_comando_composto = 62,          /* comando_composto  */
  YYSYMBOL_lista_comandos = 63,            /* lista_comandos  */
  YYSYMBOL_comando = 64,                   /* comando  */
  YYSYMBOL_atribuicao = 65,                /* atribuicao  */
  YYSYMBOL_chamada_procedimento = 66,      /* chamada_procedimento  */
  YYSYMBOL_condicional = 67,               /* condicional  */
  YYSYMBOL_repeticao = 68,                 /* repeticao  */
  YYSYMBOL_leitura = 69,                   /* leitura  */
  YYSYMBOL_escrita = 70,                   /* escrita  */
  YYSYMBOL_expressao = 71,                 /* expressao  */
  YYSYMBOL_relacao = 72,                   /* relacao  */
  YYSYMBOL_expressao_simples = 73,         /* expressao_simples  */
  YYSYMBOL_termo = 74,                     /* termo  */
  YYSYMBOL_fator = 75,                     /* fator  */
  YYSYMBOL_lista_expressoes_vazio = 76,    /* lista_expressoes_vazio  */
  YYSYMBOL_lista_expressoes = 77           /* lista_expressoes  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_uint8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   115,   123,   124,   127,   128,   130,   133,
     137,   142,   148,   153,   160,   161,   164,   168,   174,   175,
     177,   190,   204,   205,   208,   212,   217,   222,   229,   236,
     240,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     256,   261,   268,   271,   275,   279,   284,   289,   290,   295,
     296,   297,   298,   299,   300,   303,   304,   305,   306,   307,
     308,   311,   312,   313,   314,   317,   321,   326,   327,   328,
     329,   330,   333,   334,   337,   341
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_PROGRAM", "T_BEGIN",
  "T_END", "T_VAR", "T_PROCEDURE", "T_FUNCTION", "T_IF", "T_THEN",
  "T_ELSE", "T_WHILE", "T_DO", "T_OR", "T_AND", "T_NOT", "T_DIV", "T_READ",
  "T_WRITE", "T_TRUE", "T_FALSE", "T_INTEGER", "T_BOOLEAN", "T_SEMICOLON",
  "T_COLON", "T_PONTO", "T_VIRGULA", "T_LPAREN", "T_RPAREN", "T_ATRIB",
  "T_IGUAL", "T_DIFERENTE", "T_MENOR", "T_MENORIGUAL", "T_MAIOR",
  "T_MAIORIGUAL", "T_MAIS", "T_MENOS", "T_VEZES", "T_ERRO", "T_NUM",
  "T_ID", "LOWER_THAN_ELSE", "$accept", "programa", "bloco",
  "declaracao_var_vazio", "declaracao_subrotina_vazio",
  "secao_declaracao_variaveis", "repeticao_declaracao", "declaracao_vars",
  "lista_identificadores", "tipo", "secao_declaracao_subrotinas",
  "declaracao_subrotina", "procedimento", "funcao",
  "parametros_gerais_subrotina", "lista_parametros", "secao_parametros",
  "bloco_subrotina", "comando_composto", "lista_comandos", "comando",
  "atribuicao", "chamada_procedimento", "condicional", "repeticao",
  "leitura", "escrita", "expressao", "relacao", "expressao_simples",
  "termo", "fator", "lista_expressoes_vazio", "lista_expressoes", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-40)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,   -21,    28,    21,   -78,    62,    18,    51,    44,   -78,
     -78,    18,    48,    38,   -78,    47,    49,    88,    44,    69,
     -78,   -78,    79,   -78,    63,    65,    76,    76,    52,   -78,
      81,   -78,   -78,   -78,   -78,   -78,   -78,    18,    82,    83,
      85,    46,    46,    84,    86,    45,   -78,    31,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,    54,    30,   -78,    62,
      63,   -78,     2,   -78,   -78,    46,     2,     2,   -78,    87,
     100,    64,    -1,   -78,    98,    18,    46,    46,    46,   -78,
      52,    63,    18,   -78,    88,   -78,    89,   -78,    90,    -1,
      -1,    46,     8,     2,   -78,   -78,   -78,   -78,   -78,   -78,
       2,     2,    46,     2,     2,     2,     8,    53,   -78,    91,
      94,    93,   -78,   -78,   -78,   -78,   -78,    62,   -78,    95,
     105,    -1,    -1,    -1,    -3,   -78,   -78,   -78,   -78,   -78,
     -78,    46,   -78,   -78,   -78,     8,   -78,   -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     6,     5,
      12,     8,     0,     0,     2,     0,     0,     0,     7,     0,
      18,    19,     0,     9,     0,     0,    22,    22,     0,     3,
       0,    16,    10,    15,    14,    11,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    29,    31,
      32,    33,    34,    35,    36,    17,     0,     0,    24,     4,
       0,    38,     0,    68,    69,     0,     0,     0,    67,    65,
       0,    47,    55,    61,     0,     0,    72,    72,     0,    28,
       0,     0,     0,    23,     0,    20,     0,    71,     0,    56,
      57,    72,     0,     0,    49,    50,    51,    52,    53,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    74,     0,
      73,     0,    40,    30,    26,    25,    27,     4,    70,     0,
      42,    60,    58,    59,    48,    64,    63,    62,    44,    45,
      46,     0,    41,    21,    66,     0,    75,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   112,   -78,   -78,   -78,   107,   -33,   -50,
     -78,   108,   -78,   -78,    96,   -78,    43,    10,   -15,   -78,
     -77,   -78,   -78,   -78,   -78,   -78,   -78,   -41,   -78,    26,
     -60,   -57,   -52,   -78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,    84,    17,     9,    11,    12,    13,    35,
      18,    19,    20,    21,    38,    57,    58,    85,    46,    47,
      48,    49,    50,    51,    52,    53,    54,   108,   102,    71,
      72,    73,   109,   110
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    74,    29,   113,    56,    87,    89,    90,     1,    40,
      86,    93,    28,   -39,   103,   120,   104,    41,    62,   -39,
      42,     3,    63,    64,    88,   111,    43,    44,     4,   128,
      65,   114,   -39,   121,   100,   101,    79,   112,   105,   119,
     122,   123,   107,    68,    69,     5,   125,   126,   127,    56,
      45,    15,    16,    40,    82,    80,    28,   -39,   137,    83,
      10,    41,    62,    24,    42,    25,    63,    64,     6,   116,
      43,    44,    23,    77,    65,    78,   -39,    14,    93,    81,
      25,    25,   129,    66,    67,    33,    34,    68,    69,    26,
     136,    27,    28,    31,    45,    94,    95,    96,    97,    98,
      99,   100,   101,    32,    37,    55,    59,    36,    60,    61,
      92,   106,    75,   117,    76,    91,   135,     8,    22,   118,
     130,   131,   132,    39,   134,   115,    30,   133,   124
};

static const yytype_uint8 yycheck[] =
{
      41,    42,    17,    80,    37,    62,    66,    67,     3,     1,
      60,    14,     4,     5,    15,    92,    17,     9,    16,    11,
      12,    42,    20,    21,    65,    77,    18,    19,     0,   106,
      28,    81,    24,    93,    37,    38,     5,    78,    39,    91,
     100,   101,    75,    41,    42,    24,   103,   104,   105,    82,
      42,     7,     8,     1,    24,    24,     4,     5,   135,    29,
      42,     9,    16,    25,    12,    27,    20,    21,     6,    84,
      18,    19,    24,    28,    28,    30,    24,    26,    14,    25,
      27,    27,    29,    37,    38,    22,    23,    41,    42,    42,
     131,    42,     4,    24,    42,    31,    32,    33,    34,    35,
      36,    37,    38,    24,    28,    24,    24,    42,    25,    24,
      10,    13,    28,    24,    28,    28,    11,     5,    11,    29,
      29,    27,    29,    27,    29,    82,    18,   117,   102
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    45,    42,     0,    24,     6,    46,    47,    49,
      42,    50,    51,    52,    26,     7,     8,    48,    54,    55,
      56,    57,    51,    24,    25,    27,    42,    42,     4,    62,
      55,    24,    24,    22,    23,    53,    42,    28,    58,    58,
       1,     9,    12,    18,    19,    42,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    24,    52,    59,    60,    24,
      25,    24,    16,    20,    21,    28,    37,    38,    41,    42,
      71,    73,    74,    75,    71,    28,    28,    28,    30,     5,
      24,    25,    24,    29,    47,    61,    53,    75,    71,    74,
      74,    28,    10,    14,    31,    32,    33,    34,    35,    36,
      37,    38,    72,    15,    17,    39,    13,    52,    71,    76,
      77,    76,    71,    64,    53,    60,    62,    24,    29,    76,
      64,    74,    74,    74,    73,    75,    75,    75,    64,    29,
      29,    27,    29,    61,    29,    11,    71,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    47,    47,    48,    48,    49,    50,
      50,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    57,    58,    58,    59,    59,    60,    61,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    66,    67,    67,    68,    69,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    76,    76,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     0,     1,     0,     1,     2,     2,
       3,     3,     1,     3,     1,     1,     2,     3,     1,     1,
       5,     7,     0,     3,     1,     3,     3,     2,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       3,     4,     4,     6,     4,     4,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     3,
       3,     1,     3,     3,     3,     1,     4,     1,     1,     1,
       3,     2,     0,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* programa: T_PROGRAM T_ID T_SEMICOLON bloco T_PONTO  */
#line 104 "src/rascal.y"
                                                       {
        root = new Programa((yyvsp[-3].sval));
        
        if ((yyvsp[-1].ptr_dados_bloco)->vars) root->variaveis_globais = *((yyvsp[-1].ptr_dados_bloco)->vars);
        if ((yyvsp[-1].ptr_dados_bloco)->subs) root->subrotinas_globais = *((yyvsp[-1].ptr_dados_bloco)->subs);
        root->bloco_principal = (yyvsp[-1].ptr_dados_bloco)->corpo;

        delete (yyvsp[-1].ptr_dados_bloco);
        free((yyvsp[-3].sval));
    }
#line 1525 "src/rascal.tab.c"
    break;

  case 3: /* bloco: declaracao_var_vazio declaracao_subrotina_vazio comando_composto  */
#line 115 "src/rascal.y"
                                                                            {
        (yyval.ptr_dados_bloco) = new BlocoData();
        (yyval.ptr_dados_bloco)->vars = (yyvsp[-2].vec_decl_var);
        (yyval.ptr_dados_bloco)->subs = (yyvsp[-1].vec_decl_sub);
        (yyval.ptr_dados_bloco)->corpo = (yyvsp[0].ptr_bloco_cmd);
    }
#line 1536 "src/rascal.tab.c"
    break;

  case 4: /* declaracao_var_vazio: %empty  */
#line 123 "src/rascal.y"
                      { (yyval.vec_decl_var) = new std::vector<DeclararVar*>(); }
#line 1542 "src/rascal.tab.c"
    break;

  case 5: /* declaracao_var_vazio: secao_declaracao_variaveis  */
#line 124 "src/rascal.y"
                                     { (yyval.vec_decl_var) = (yyvsp[0].vec_decl_var); }
#line 1548 "src/rascal.tab.c"
    break;

  case 6: /* declaracao_subrotina_vazio: %empty  */
#line 127 "src/rascal.y"
                      { (yyval.vec_decl_sub) = new std::vector<DeclararSubrotina*>(); }
#line 1554 "src/rascal.tab.c"
    break;

  case 7: /* declaracao_subrotina_vazio: secao_declaracao_subrotinas  */
#line 128 "src/rascal.y"
                                      { (yyval.vec_decl_sub) = (yyvsp[0].vec_decl_sub); }
#line 1560 "src/rascal.tab.c"
    break;

  case 8: /* secao_declaracao_variaveis: T_VAR repeticao_declaracao  */
#line 130 "src/rascal.y"
                                                            { (yyval.vec_decl_var) = (yyvsp[0].vec_decl_var); }
#line 1566 "src/rascal.tab.c"
    break;

  case 9: /* repeticao_declaracao: declaracao_vars T_SEMICOLON  */
#line 133 "src/rascal.y"
                                      { 
            (yyval.vec_decl_var) = new std::vector<DeclararVar*>();
            (yyval.vec_decl_var)->push_back((yyvsp[-1].ptr_decl_var));
        }
#line 1575 "src/rascal.tab.c"
    break;

  case 10: /* repeticao_declaracao: repeticao_declaracao declaracao_vars T_SEMICOLON  */
#line 137 "src/rascal.y"
                                                           {
            (yyval.vec_decl_var) = (yyvsp[-2].vec_decl_var);
            (yyval.vec_decl_var)->push_back((yyvsp[-1].ptr_decl_var));
        }
#line 1584 "src/rascal.tab.c"
    break;

  case 11: /* declaracao_vars: lista_identificadores T_COLON tipo  */
#line 142 "src/rascal.y"
                                                        {
        (yyval.ptr_decl_var) = new DeclararVar(*(yyvsp[-2].vec_str), (yyvsp[0].type_val));
        delete (yyvsp[-2].vec_str);
    }
#line 1593 "src/rascal.tab.c"
    break;

  case 12: /* lista_identificadores: T_ID  */
#line 148 "src/rascal.y"
               {
            (yyval.vec_str) = new std::vector<std::string>();
            (yyval.vec_str)->push_back(std::string((yyvsp[0].sval)));
            free((yyvsp[0].sval));
        }
#line 1603 "src/rascal.tab.c"
    break;

  case 13: /* lista_identificadores: lista_identificadores T_VIRGULA T_ID  */
#line 153 "src/rascal.y"
                                               {
            (yyval.vec_str) = (yyvsp[-2].vec_str);
            (yyval.vec_str)->push_back(std::string((yyvsp[0].sval)));
            free((yyvsp[0].sval));
        }
#line 1613 "src/rascal.tab.c"
    break;

  case 14: /* tipo: T_BOOLEAN  */
#line 160 "src/rascal.y"
                    { (yyval.type_val) = TP_BOOL; }
#line 1619 "src/rascal.tab.c"
    break;

  case 15: /* tipo: T_INTEGER  */
#line 161 "src/rascal.y"
                    { (yyval.type_val) = TP_INT; }
#line 1625 "src/rascal.tab.c"
    break;

  case 16: /* secao_declaracao_subrotinas: declaracao_subrotina T_SEMICOLON  */
#line 164 "src/rascal.y"
                                           {
            (yyval.vec_decl_sub) = new std::vector<DeclararSubrotina*>();
            (yyval.vec_decl_sub)->push_back((yyvsp[-1].ptr_decl_sub));
        }
#line 1634 "src/rascal.tab.c"
    break;

  case 17: /* secao_declaracao_subrotinas: secao_declaracao_subrotinas declaracao_subrotina T_SEMICOLON  */
#line 168 "src/rascal.y"
                                                                       {
            (yyval.vec_decl_sub) = (yyvsp[-2].vec_decl_sub);
            (yyval.vec_decl_sub)->push_back((yyvsp[-1].ptr_decl_sub));
        }
#line 1643 "src/rascal.tab.c"
    break;

  case 18: /* declaracao_subrotina: procedimento  */
#line 174 "src/rascal.y"
                       { (yyval.ptr_decl_sub) = (yyvsp[0].ptr_decl_sub); }
#line 1649 "src/rascal.tab.c"
    break;

  case 19: /* declaracao_subrotina: funcao  */
#line 175 "src/rascal.y"
                 { (yyval.ptr_decl_sub) = (yyvsp[0].ptr_decl_sub); }
#line 1655 "src/rascal.tab.c"
    break;

  case 20: /* procedimento: T_PROCEDURE T_ID parametros_gerais_subrotina T_SEMICOLON bloco_subrotina  */
#line 177 "src/rascal.y"
                                                                                            {
        DeclararProcedimento* proc = new DeclararProcedimento((yyvsp[-3].sval));
        if ((yyvsp[-2].vec_decl_var)) proc->parametros = *((yyvsp[-2].vec_decl_var));
        
        if ((yyvsp[0].ptr_dados_bloco)->vars) proc->variaveis_locais = *((yyvsp[0].ptr_dados_bloco)->vars);
        proc->corpo = (yyvsp[0].ptr_dados_bloco)->corpo;

        (yyval.ptr_decl_sub) = proc;
        free((yyvsp[-3].sval));
        delete (yyvsp[-2].vec_decl_var);
        delete (yyvsp[0].ptr_dados_bloco);
    }
#line 1672 "src/rascal.tab.c"
    break;

  case 21: /* funcao: T_FUNCTION T_ID parametros_gerais_subrotina T_COLON tipo T_SEMICOLON bloco_subrotina  */
#line 190 "src/rascal.y"
                                                                                                  {
        DeclararFuncao* func = new DeclararFuncao((yyvsp[-5].sval), (yyvsp[-2].type_val));
        if ((yyvsp[-4].vec_decl_var)) func->parametros = *((yyvsp[-4].vec_decl_var));
        
        if ((yyvsp[0].ptr_dados_bloco)->vars) func->variaveis_locais = *((yyvsp[0].ptr_dados_bloco)->vars);
        func->corpo = (yyvsp[0].ptr_dados_bloco)->corpo;

        (yyval.ptr_decl_sub) = func;
        free((yyvsp[-5].sval));
        delete (yyvsp[-4].vec_decl_var);
        delete (yyvsp[0].ptr_dados_bloco);
    }
#line 1689 "src/rascal.tab.c"
    break;

  case 22: /* parametros_gerais_subrotina: %empty  */
#line 204 "src/rascal.y"
                      { (yyval.vec_decl_var) = new std::vector<DeclararVar*>(); }
#line 1695 "src/rascal.tab.c"
    break;

  case 23: /* parametros_gerais_subrotina: T_LPAREN lista_parametros T_RPAREN  */
#line 205 "src/rascal.y"
                                             { (yyval.vec_decl_var) = (yyvsp[-1].vec_decl_var); }
#line 1701 "src/rascal.tab.c"
    break;

  case 24: /* lista_parametros: secao_parametros  */
#line 208 "src/rascal.y"
                           {
            (yyval.vec_decl_var) = new std::vector<DeclararVar*>();
            (yyval.vec_decl_var)->push_back((yyvsp[0].ptr_decl_var));
        }
#line 1710 "src/rascal.tab.c"
    break;

  case 25: /* lista_parametros: lista_parametros T_SEMICOLON secao_parametros  */
#line 212 "src/rascal.y"
                                                        {
            (yyval.vec_decl_var) = (yyvsp[-2].vec_decl_var);
            (yyval.vec_decl_var)->push_back((yyvsp[0].ptr_decl_var));
        }
#line 1719 "src/rascal.tab.c"
    break;

  case 26: /* secao_parametros: lista_identificadores T_COLON tipo  */
#line 217 "src/rascal.y"
                                                          {
        (yyval.ptr_decl_var) = new DeclararVar(*(yyvsp[-2].vec_str), (yyvsp[0].type_val));
        delete (yyvsp[-2].vec_str);
    }
#line 1728 "src/rascal.tab.c"
    break;

  case 27: /* bloco_subrotina: declaracao_var_vazio comando_composto  */
#line 222 "src/rascal.y"
                                                            {
        (yyval.ptr_dados_bloco) = new BlocoData();
        (yyval.ptr_dados_bloco)->vars = (yyvsp[-1].vec_decl_var);
        (yyval.ptr_dados_bloco)->subs = nullptr; 
        (yyval.ptr_dados_bloco)->corpo = (yyvsp[0].ptr_bloco_cmd);
    }
#line 1739 "src/rascal.tab.c"
    break;

  case 28: /* comando_composto: T_BEGIN lista_comandos T_END  */
#line 229 "src/rascal.y"
                                                    {
        (yyval.ptr_bloco_cmd) = new CmdBeginEnd();
        (yyval.ptr_bloco_cmd)->comandos = *((yyvsp[-1].vec_cmd));
        delete (yyvsp[-1].vec_cmd);
    }
#line 1749 "src/rascal.tab.c"
    break;

  case 29: /* lista_comandos: comando  */
#line 236 "src/rascal.y"
                  {
            (yyval.vec_cmd) = new std::vector<Comando*>();
            if ((yyvsp[0].ptr_comando) != nullptr) (yyval.vec_cmd)->push_back((yyvsp[0].ptr_comando));
        }
#line 1758 "src/rascal.tab.c"
    break;

  case 30: /* lista_comandos: lista_comandos T_SEMICOLON comando  */
#line 240 "src/rascal.y"
                                             {
            (yyval.vec_cmd) = (yyvsp[-2].vec_cmd);
            if ((yyvsp[0].ptr_comando) != nullptr) (yyval.vec_cmd)->push_back((yyvsp[0].ptr_comando));
        }
#line 1767 "src/rascal.tab.c"
    break;

  case 31: /* comando: atribuicao  */
#line 246 "src/rascal.y"
                     { (yyval.ptr_comando) = (yyvsp[0].ptr_comando); }
#line 1773 "src/rascal.tab.c"
    break;

  case 32: /* comando: chamada_procedimento  */
#line 247 "src/rascal.y"
                               { (yyval.ptr_comando) = (yyvsp[0].ptr_comando); }
#line 1779 "src/rascal.tab.c"
    break;

  case 33: /* comando: condicional  */
#line 248 "src/rascal.y"
                      { (yyval.ptr_comando) = (yyvsp[0].ptr_comando); }
#line 1785 "src/rascal.tab.c"
    break;

  case 34: /* comando: repeticao  */
#line 249 "src/rascal.y"
                    { (yyval.ptr_comando) = (yyvsp[0].ptr_comando); }
#line 1791 "src/rascal.tab.c"
    break;

  case 35: /* comando: leitura  */
#line 250 "src/rascal.y"
                  { (yyval.ptr_comando) = (yyvsp[0].ptr_comando); }
#line 1797 "src/rascal.tab.c"
    break;

  case 36: /* comando: escrita  */
#line 251 "src/rascal.y"
                  { (yyval.ptr_comando) = (yyvsp[0].ptr_comando); }
#line 1803 "src/rascal.tab.c"
    break;

  case 37: /* comando: comando_composto  */
#line 252 "src/rascal.y"
                           { (yyval.ptr_comando) = (yyvsp[0].ptr_bloco_cmd); }
#line 1809 "src/rascal.tab.c"
    break;

  case 38: /* comando: error T_SEMICOLON  */
#line 253 "src/rascal.y"
                            {yyerrok;(yyval.ptr_comando) = nullptr;  printf("Erro sintatico recuperado. Continuando analise\n");}
#line 1815 "src/rascal.tab.c"
    break;

  case 39: /* comando: %empty  */
#line 254 "src/rascal.y"
                      { (yyval.ptr_comando) = nullptr; }
#line 1821 "src/rascal.tab.c"
    break;

  case 40: /* atribuicao: T_ID T_ATRIB expressao  */
#line 256 "src/rascal.y"
                                        {
        (yyval.ptr_comando) = new CmdAtribuicao((yyvsp[-2].sval), (yyvsp[0].ptr_expr));
        free((yyvsp[-2].sval));
    }
#line 1830 "src/rascal.tab.c"
    break;

  case 41: /* chamada_procedimento: T_ID T_LPAREN lista_expressoes_vazio T_RPAREN  */
#line 261 "src/rascal.y"
                                                                        {
        (yyval.ptr_comando) = new CmdChamadaProc((yyvsp[-3].sval), *((yyvsp[-1].vec_expr)));
        free((yyvsp[-3].sval));
        delete (yyvsp[-1].vec_expr);
    }
#line 1840 "src/rascal.tab.c"
    break;

  case 42: /* condicional: T_IF expressao T_THEN comando  */
#line 268 "src/rascal.y"
                                                              {
            (yyval.ptr_comando) = new CmdIf((yyvsp[-2].ptr_expr), (yyvsp[0].ptr_comando), nullptr);
        }
#line 1848 "src/rascal.tab.c"
    break;

  case 43: /* condicional: T_IF expressao T_THEN comando T_ELSE comando  */
#line 271 "src/rascal.y"
                                                       {
            (yyval.ptr_comando) = new CmdIf((yyvsp[-4].ptr_expr), (yyvsp[-2].ptr_comando), (yyvsp[0].ptr_comando));
        }
#line 1856 "src/rascal.tab.c"
    break;

  case 44: /* repeticao: T_WHILE expressao T_DO comando  */
#line 275 "src/rascal.y"
                                               {
        (yyval.ptr_comando) = new CmdWhile((yyvsp[-2].ptr_expr), (yyvsp[0].ptr_comando));
    }
#line 1864 "src/rascal.tab.c"
    break;

  case 45: /* leitura: T_READ T_LPAREN lista_identificadores T_RPAREN  */
#line 279 "src/rascal.y"
                                                            {
        (yyval.ptr_comando) = new CmdRead(*(yyvsp[-1].vec_str));
        delete (yyvsp[-1].vec_str);
    }
#line 1873 "src/rascal.tab.c"
    break;

  case 46: /* escrita: T_WRITE T_LPAREN lista_expressoes_vazio T_RPAREN  */
#line 284 "src/rascal.y"
                                                               {
        (yyval.ptr_comando) = new CmdWrite(*(yyvsp[-1].vec_expr));
        delete (yyvsp[-1].vec_expr);
    }
#line 1882 "src/rascal.tab.c"
    break;

  case 47: /* expressao: expressao_simples  */
#line 289 "src/rascal.y"
                                 { (yyval.ptr_expr) = (yyvsp[0].ptr_expr); }
#line 1888 "src/rascal.tab.c"
    break;

  case 48: /* expressao: expressao_simples relacao expressao_simples  */
#line 290 "src/rascal.y"
                                                           {
                 (yyval.ptr_expr) = new ExprBinaria((yyvsp[-2].ptr_expr), (TipoOperacao)(yyvsp[-1].ival), (yyvsp[0].ptr_expr));
             }
#line 1896 "src/rascal.tab.c"
    break;

  case 49: /* relacao: T_IGUAL  */
#line 295 "src/rascal.y"
                  { (yyval.ival) = OP_IGUAL; }
#line 1902 "src/rascal.tab.c"
    break;

  case 50: /* relacao: T_DIFERENTE  */
#line 296 "src/rascal.y"
                      { (yyval.ival) = OP_DIFERENTE; }
#line 1908 "src/rascal.tab.c"
    break;

  case 51: /* relacao: T_MENOR  */
#line 297 "src/rascal.y"
                  { (yyval.ival) = OP_MENOR; }
#line 1914 "src/rascal.tab.c"
    break;

  case 52: /* relacao: T_MENORIGUAL  */
#line 298 "src/rascal.y"
                       { (yyval.ival) = OP_MENOR_IGUAL; }
#line 1920 "src/rascal.tab.c"
    break;

  case 53: /* relacao: T_MAIOR  */
#line 299 "src/rascal.y"
                  { (yyval.ival) = OP_MAIOR; }
#line 1926 "src/rascal.tab.c"
    break;

  case 54: /* relacao: T_MAIORIGUAL  */
#line 300 "src/rascal.y"
                       { (yyval.ival) = OP_MAIOR_IGUAL; }
#line 1932 "src/rascal.tab.c"
    break;

  case 55: /* expressao_simples: termo  */
#line 303 "src/rascal.y"
                { (yyval.ptr_expr) = (yyvsp[0].ptr_expr); }
#line 1938 "src/rascal.tab.c"
    break;

  case 56: /* expressao_simples: T_MAIS termo  */
#line 304 "src/rascal.y"
                       { (yyval.ptr_expr) = (yyvsp[0].ptr_expr);}
#line 1944 "src/rascal.tab.c"
    break;

  case 57: /* expressao_simples: T_MENOS termo  */
#line 305 "src/rascal.y"
                        { (yyval.ptr_expr) = new ExprUnaria(OP_SUB, (yyvsp[0].ptr_expr)); }
#line 1950 "src/rascal.tab.c"
    break;

  case 58: /* expressao_simples: expressao_simples T_MAIS termo  */
#line 306 "src/rascal.y"
                                         { (yyval.ptr_expr) = new ExprBinaria((yyvsp[-2].ptr_expr), OP_ADD, (yyvsp[0].ptr_expr)); }
#line 1956 "src/rascal.tab.c"
    break;

  case 59: /* expressao_simples: expressao_simples T_MENOS termo  */
#line 307 "src/rascal.y"
                                          { (yyval.ptr_expr) = new ExprBinaria((yyvsp[-2].ptr_expr), OP_SUB, (yyvsp[0].ptr_expr)); }
#line 1962 "src/rascal.tab.c"
    break;

  case 60: /* expressao_simples: expressao_simples T_OR termo  */
#line 308 "src/rascal.y"
                                       { (yyval.ptr_expr) = new ExprBinaria((yyvsp[-2].ptr_expr), OP_OR, (yyvsp[0].ptr_expr)); }
#line 1968 "src/rascal.tab.c"
    break;

  case 61: /* termo: fator  */
#line 311 "src/rascal.y"
                { (yyval.ptr_expr) = (yyvsp[0].ptr_expr); }
#line 1974 "src/rascal.tab.c"
    break;

  case 62: /* termo: termo T_VEZES fator  */
#line 312 "src/rascal.y"
                              { (yyval.ptr_expr) = new ExprBinaria((yyvsp[-2].ptr_expr), OP_MUL, (yyvsp[0].ptr_expr)); }
#line 1980 "src/rascal.tab.c"
    break;

  case 63: /* termo: termo T_DIV fator  */
#line 313 "src/rascal.y"
                            { (yyval.ptr_expr) = new ExprBinaria((yyvsp[-2].ptr_expr), OP_DIV, (yyvsp[0].ptr_expr)); }
#line 1986 "src/rascal.tab.c"
    break;

  case 64: /* termo: termo T_AND fator  */
#line 314 "src/rascal.y"
                            { (yyval.ptr_expr) = new ExprBinaria((yyvsp[-2].ptr_expr), OP_AND, (yyvsp[0].ptr_expr)); }
#line 1992 "src/rascal.tab.c"
    break;

  case 65: /* fator: T_ID  */
#line 317 "src/rascal.y"
               {
            (yyval.ptr_expr) = new ExprComVariavel((yyvsp[0].sval));
            free((yyvsp[0].sval));
        }
#line 2001 "src/rascal.tab.c"
    break;

  case 66: /* fator: T_ID T_LPAREN lista_expressoes_vazio T_RPAREN  */
#line 321 "src/rascal.y"
                                                        {
            (yyval.ptr_expr) = new ExprChamadaFunc((yyvsp[-3].sval), *((yyvsp[-1].vec_expr)));
            free((yyvsp[-3].sval));
            delete (yyvsp[-1].vec_expr);
        }
#line 2011 "src/rascal.tab.c"
    break;

  case 67: /* fator: T_NUM  */
#line 326 "src/rascal.y"
                { (yyval.ptr_expr) = new ExprValorInteiro((yyvsp[0].ival)); }
#line 2017 "src/rascal.tab.c"
    break;

  case 68: /* fator: T_TRUE  */
#line 327 "src/rascal.y"
                 { (yyval.ptr_expr) = new ExprValorBool(true); }
#line 2023 "src/rascal.tab.c"
    break;

  case 69: /* fator: T_FALSE  */
#line 328 "src/rascal.y"
                  { (yyval.ptr_expr) = new ExprValorBool(false); }
#line 2029 "src/rascal.tab.c"
    break;

  case 70: /* fator: T_LPAREN expressao T_RPAREN  */
#line 329 "src/rascal.y"
                                      { (yyval.ptr_expr) = (yyvsp[-1].ptr_expr); }
#line 2035 "src/rascal.tab.c"
    break;

  case 71: /* fator: T_NOT fator  */
#line 330 "src/rascal.y"
                      { (yyval.ptr_expr) = new ExprUnaria(OP_NOT, (yyvsp[0].ptr_expr)); }
#line 2041 "src/rascal.tab.c"
    break;

  case 72: /* lista_expressoes_vazio: %empty  */
#line 333 "src/rascal.y"
                      { (yyval.vec_expr) = new std::vector<Expressao*>(); }
#line 2047 "src/rascal.tab.c"
    break;

  case 73: /* lista_expressoes_vazio: lista_expressoes  */
#line 334 "src/rascal.y"
                           { (yyval.vec_expr) = (yyvsp[0].vec_expr); }
#line 2053 "src/rascal.tab.c"
    break;

  case 74: /* lista_expressoes: expressao  */
#line 337 "src/rascal.y"
                    {
            (yyval.vec_expr) = new std::vector<Expressao*>();
            (yyval.vec_expr)->push_back((yyvsp[0].ptr_expr));
        }
#line 2062 "src/rascal.tab.c"
    break;

  case 75: /* lista_expressoes: lista_expressoes T_VIRGULA expressao  */
#line 341 "src/rascal.y"
                                               {
            (yyval.vec_expr) = (yyvsp[-2].vec_expr);
            (yyval.vec_expr)->push_back((yyvsp[0].ptr_expr));
        }
#line 2071 "src/rascal.tab.c"
    break;


#line 2075 "src/rascal.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 346 "src/rascal.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe na linha %d: %s. Token encontrado: '%s'\n", yylineno, s, yytext);
}
