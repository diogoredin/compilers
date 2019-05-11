/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "gram.y"
/* $Id: diy.y,v 1.0 2019/02/06 17:25:13 prs Exp $ */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"

extern int yylex();
void yyerror(char *s);
extern int yyselect(Node*);
void declare(int pub, int cnst, Node *type, char *name, Node *value);
void enter(int pub, int typ, char *name);
int checkargs(char *name, Node *args);
int nostring(Node *arg1, Node *arg2);
int intonly(Node *arg, int);
int noassign(Node *arg1, Node *arg2);

static int ncicl;
static char *fpar;
extern int yylineno, trace;

extern FILE *yyin;
extern FILE *out;

#ifndef YYDEBUG
#define yyname 0
#endif
#line 32 "gram.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* node pointer */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 64 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INT 257
#define REAL 258
#define ID 259
#define STR 260
#define DO 261
#define WHILE 262
#define IF 263
#define THEN 264
#define FOR 265
#define IN 266
#define UPTO 267
#define DOWNTO 268
#define STEP 269
#define BREAK 270
#define CONTINUE 271
#define VOID 272
#define INTEGER 273
#define STRING 274
#define NUMBER 275
#define CONST 276
#define PUBLIC 277
#define INCR 278
#define DECR 279
#define IFX 280
#define ELSE 281
#define ATR 282
#define NE 283
#define GE 284
#define LE 285
#define UMINUS 286
#define NOT 287
#define REF 288
#define PROG 289
#define LOCAL 290
#define POSINC 291
#define POSDEC 292
#define PTR 293
#define CALL 294
#define START 295
#define PARAM 296
#define NIL 297
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,   21,    0,   22,    0,
   20,   20,   18,   18,    1,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    3,    3,    4,    4,    5,    5,
   23,    6,    7,    7,    8,   10,   10,    9,   24,    9,
   25,    9,   26,    9,    9,    9,    9,    9,    9,    9,
   14,   14,   15,   15,   11,   11,   19,   19,   13,   13,
   12,   12,   16,   16,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,
};
static const YYINT yylen[] = {                            2,
    0,    3,    5,    6,    5,    6,    0,    6,    0,    6,
    0,    1,    0,    1,    2,    2,    2,    3,    3,    4,
    3,    4,    3,    4,    4,    3,    1,    2,    1,    3,
    0,    6,    0,    3,    2,    1,    1,    1,    0,    6,
    0,   10,    0,   10,    4,    6,    2,    1,    4,    2,
    0,    1,    3,    3,    0,    2,    0,    1,    1,    2,
    1,    3,    1,    4,    1,    2,    3,    1,    1,    1,
    2,    2,    2,    2,    2,    2,    2,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    4,    3,
};
static const YYINT yydefred[] = {                         1,
    0,    0,   12,    0,    2,    0,    0,    0,    0,    0,
    0,    9,   14,   15,   16,   17,    0,    0,    0,    0,
    0,    3,    5,    0,    0,   10,    4,    6,    0,    0,
    0,    0,    0,    0,    8,    0,    0,    0,   29,   19,
   23,   18,   21,    0,    0,    0,   27,   31,   26,    0,
   35,    0,    0,   22,   20,   24,   33,   28,   25,   30,
    0,    0,   68,   70,    0,   69,   39,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   38,   48,    0,   59,
    0,    0,    0,   50,    0,    0,    0,    0,    0,    0,
    0,   75,   76,   73,   72,   71,   66,    0,   34,    0,
    0,   60,    0,   52,   77,   78,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   74,   47,    0,   94,    0,    0,   36,    0,   37,
    0,    0,   92,   58,    0,    0,   32,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   64,   93,    0,    0,    0,    0,   53,   54,
   49,    0,    0,    0,    0,    0,   40,   46,    0,    0,
    0,    0,    0,    0,   41,   43,    0,    0,   42,   44,
};
static const YYINT yydgoto[] = {                          1,
   37,   23,   26,   49,   38,   78,   61,   39,  128,  129,
  172,  126,   81,  103,  130,   88,   83,   14,  135,    4,
   24,   19,   57,   87,  177,  178,
};
static const YYINT yysindex[] = {                         0,
 -234,  -40,    0, -190,    0, -238,   -5,   -5,   -5, -210,
 -205,    0,    0,    0,    0,    0, -186,  -56,   39,  -52,
  -44,    0,    0,   39,  -35,    0,    0,    0,   30,   38,
   40,   45, -162, -225,    0,  -42, -150,    5,    0,    0,
    0,    0,    0,   52,   55,   59,    0,    0,    0,   61,
    0,  -42, -210,    0,    0,    0,    0,    0,    0,    0,
  761,   69,    0,    0,  -24,    0,    0,  828, -137, -137,
 -137, -137,  828,  828, -137,  828,    0,    0,   71,    0,
  840,  -22,   94,    0,  828,  713,  840, -227,  105,   43,
 -131,    0,    0,    0,    0,    0,    0,  131,    0, -128,
 -128,    0,   15,    0,    0,    0,  828,  828,  828,  828,
  828,  828,  828,  828,  828,  828,  828,  828,  828,  828,
  828,    0,    0,  161,    0,   28,  349,    0, -118,    0,
  840,  828,    0,    0,   86,   87,    0,  349,  246,  380,
  387,  418,  418,   70,   70,   70,   70,  138,  138,  116,
  116,  116,    0,    0,  828,  828, -130,   63,    0,    0,
    0,  349,  277,  840,  828,  828,    0,    0,  312,  312,
  828,  -98,  -91,  349,    0,    0,  840,  840,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
 -114,    0,    0,    0,    0,    0,  -82,  -82,  -82,    0,
    0,    0,    0,    0,    0,    0,    0,  139,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -33,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   57,  338,    0,    0,    0,    0,    0,   33,    0,   -3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  124,
  124,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   75,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  633,    0,  203,
    9,  608,  676,  415,  729,  764,  799,  511,  549,  444,
  455,  481,    0,    0,    0,    0,  651,    0,    0,    0,
    0,  140,    0,    0,    0,    0,    0,    0,  -75,  -75,
    0,    0,    0,  -73,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   14,  169,  166,  143,    0,  -16,    0,  -30,  -36, -116,
   26,    0,    0,    0,  119,  775, 1040,   79,   96,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1211
static const YYINT yytable[] = {                         63,
   34,   63,   22,   63,   63,   36,   27,   63,   63,   63,
   63,   63,  108,   63,  157,   86,   47,   11,    5,   50,
   12,    2,   60,   17,   80,   63,   63,   63,   63,   63,
   79,   45,   46,   63,   63,   50,   13,   63,   63,   63,
   63,   63,    3,   63,  102,   52,   90,  168,   53,   90,
  105,  106,   90,   18,  107,   63,   63,   63,   63,   63,
  179,  180,    7,    8,    9,   65,   85,   90,  154,   65,
   65,  155,   20,   65,   65,   65,   65,   65,   25,   65,
   48,    6,    7,    8,    9,   10,   15,   16,   40,   63,
   63,   65,   65,   65,   65,  122,   41,   44,   42,  121,
  110,   90,  122,   43,  119,  117,  121,  118,   51,  120,
   54,  119,  117,   55,  118,   61,  120,   56,   61,   58,
   63,   90,  116,  111,  115,   65,  122,   84,  134,   99,
  121,  110,   90,   85,  132,  119,  117,  122,  118,  137,
  120,  121,  110,  156,  159,  160,  119,  117,  122,  118,
  164,  120,  123,  116,  111,  115,   65,   11,   11,   11,
   11,   11,  175,  122,  116,  111,  115,  121,  110,  176,
  122,  133,  119,  117,  121,  118,   13,  120,    7,  119,
   62,   51,   57,   62,  120,   55,  109,   56,   28,   35,
  116,  111,  115,  122,   59,  173,  136,  121,  110,  104,
    0,    0,  119,  117,    0,  118,    0,  120,    0,    0,
    0,    0,   29,   30,   31,   32,    0,  109,    0,    0,
  116,  111,  115,    0,    0,   21,    0,   63,  109,   21,
   63,   33,    0,   63,   63,   63,    0,    7,    8,    9,
    0,    0,    0,   91,   63,   63,   91,    0,   63,   63,
   63,   63,    0,  153,  109,  105,  106,   63,    0,  107,
   63,   91,   63,   63,   63,   63,    0,    0,    0,   90,
    0,    0,   90,    0,    0,   90,   90,   90,  122,   63,
   63,   63,  121,  110,  109,    0,    0,  119,  117,    0,
  118,    0,  120,   65,    0,   91,   65,    0,    0,   65,
   65,   65,    0,    0,  161,  116,  111,  115,    0,  122,
    0,    0,    0,  121,  110,   65,   65,   65,  119,  117,
    0,  118,    0,  120,    0,    0,   91,    0,    0,  165,
  166,    0,    0,    0,    0,  167,  116,  111,  115,    0,
    0,    0,    0,    0,  122,  112,  113,  114,  121,  110,
    0,    0,    0,  119,  117,    0,  118,    0,  120,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  131,  109,
   65,  116,  111,  115,   65,   65,  112,  113,  114,   65,
   65,  122,   65,    0,   65,  121,  110,  112,  113,  114,
  119,  117,    0,  118,    0,  120,   65,   65,   65,   65,
  109,    0,    0,    0,    0,    0,    0,    0,  116,  111,
  115,    0,  122,  112,  113,  114,  121,  110,    0,  122,
    0,  119,  117,  121,  118,    0,  120,    0,  119,  117,
    0,  118,    0,  120,    0,  109,    0,    0,    0,  116,
  111,  115,    0,  112,  113,  114,  116,  111,  115,    0,
  122,    0,   86,    0,  121,   86,    0,    0,   86,  119,
  117,   65,  118,   91,  120,    0,   91,    0,    0,   91,
   91,   91,  109,   86,   86,   86,   86,  116,    0,  115,
   81,   81,    0,    0,   81,   81,   81,   81,   81,    0,
   81,   82,   82,    0,    0,   82,   82,   82,   82,   82,
    0,   82,   81,   81,   81,   81,    0,   86,    0,    0,
    0,    0,    0,   82,   82,   82,   82,   83,   83,    0,
    0,   83,   83,   83,   83,   83,    0,   83,  112,  113,
  114,    0,    0,    0,    0,    0,   81,    0,   86,   83,
   83,   83,   83,    0,    0,    0,    0,   82,   79,    0,
    0,   79,    0,   79,   79,   79,    0,    0,    0,  112,
  113,  114,    0,    0,    0,    0,    0,   81,    0,   79,
   79,   79,   79,   83,    0,    0,    0,    0,   82,    0,
  171,    0,    0,    0,    0,    0,   80,    0,    0,   80,
    0,   80,   80,   80,  112,  113,  114,    0,    0,    0,
    0,    0,    0,   79,   83,    0,    0,   80,   80,   80,
   80,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   65,   65,   65,    0,    0,    0,    0,    0,    0,    0,
    0,  112,  113,  114,   79,    0,    0,    0,    0,    0,
    0,   80,    0,    0,    0,   89,    0,    0,   89,    0,
    0,   89,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  112,  113,  114,    0,   89,    0,   89,  112,
  113,  114,   80,   67,    0,   86,   67,    0,   86,    0,
    0,   86,   86,   86,    0,    0,    0,    0,   45,    0,
   45,   67,   45,    0,    0,   45,    0,   86,   86,   86,
   89,  113,  114,    0,   81,    0,    0,   81,    0,   45,
   81,   81,   81,   88,    0,   82,   88,    0,   82,   88,
    0,   82,   82,   82,    0,   67,   81,   81,   81,    0,
    0,   89,    0,    0,   88,    0,   88,   82,   82,   82,
    0,   83,    0,    0,   83,    0,    0,   83,   83,   83,
   72,    0,   76,  125,   75,    0,    0,   74,    0,    0,
    0,    0,    0,   83,   83,   83,   87,    0,   88,   87,
    0,   79,   87,   45,   79,   45,   45,   79,   79,   79,
    0,    0,    0,    0,    0,    0,    0,   87,   87,   87,
   87,    0,    0,   79,   79,   79,    0,    0,   72,   88,
   76,   85,   75,    0,   85,   74,    0,   85,    0,   80,
    0,    0,   80,    0,    0,   80,   80,   80,    0,   77,
    0,   87,   85,   85,   85,   85,    0,    0,    0,    0,
    0,   80,   80,   80,    0,   82,   84,    0,   73,   84,
    0,    0,   84,   91,   92,   93,   94,    0,    0,   97,
    0,    0,   87,    0,    0,   82,   85,   84,   84,   84,
   84,   82,    0,    0,    0,   72,    0,   76,   89,   75,
    0,   89,   74,    0,   89,   89,   89,   72,    0,   76,
    0,   75,    0,   48,   74,    0,   73,   85,    0,    0,
   89,   84,    0,   67,    0,    0,   67,    0,   77,   67,
   67,   67,    0,    0,    0,   82,   45,   45,   45,   45,
   45,   45,   45,   45,    0,   45,    0,    0,    0,    0,
   45,   45,   84,    0,    0,    0,    0,    0,   45,   45,
    0,    0,    0,    0,    0,    0,   88,    0,   82,   88,
    0,    0,   88,   88,   88,    0,    0,    0,    0,    0,
    0,   82,   82,   73,    0,    0,    0,    0,   88,    0,
    0,    0,   48,    0,    0,   73,    0,    0,    0,   63,
   64,   65,   66,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   87,
   70,   71,   87,    0,    0,   87,   87,   87,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   87,   87,   87,    0,    0,   62,   63,   64,   65,
   66,   67,    0,   68,   85,   69,    0,   85,    0,    0,
   85,   85,   85,    7,    8,    9,    0,    0,   70,   71,
    0,    0,    0,    0,    0,    0,   85,   85,   85,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   84,
    0,    0,   84,    0,    0,   84,   84,   84,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   84,   84,   84,   63,   64,   65,   66,    0,    0,
    0,    0,    0,    0,    0,   62,   63,   64,   65,   66,
   67,    0,   68,    0,   69,   70,   71,   89,    0,  100,
  101,    0,   95,   96,    0,   98,    0,   70,   71,    0,
    0,    0,    0,    0,  124,  127,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  138,  139,  140,  141,
  142,  143,  144,  145,  146,  147,  148,  149,  150,  151,
  152,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  158,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  162,  163,    0,    0,    0,    0,
    0,    0,    0,    0,  169,  170,    0,    0,    0,    0,
  174,
};
static const YYINT yycheck[] = {                         33,
   45,   35,   59,   37,   38,   41,   59,   41,   42,   43,
   44,   45,   35,   47,  131,   40,   59,    4,   59,   36,
  259,  256,   53,   10,   61,   59,   60,   61,   62,   33,
   61,  257,  258,   37,   38,   52,   42,   41,   42,   43,
   44,   45,  277,   47,   81,   41,   38,  164,   44,   41,
  278,  279,   44,  259,  282,   59,   60,   61,   62,   93,
  177,  178,  273,  274,  275,   33,   91,   59,   41,   37,
   38,   44,  259,   41,   42,   43,   44,   45,   40,   47,
  123,  272,  273,  274,  275,  276,    8,    9,   59,   93,
  124,   59,   60,   61,   62,   33,   59,  260,   59,   37,
   38,   93,   33,   59,   42,   43,   37,   45,  259,   47,
   59,   42,   43,   59,   45,   41,   47,   59,   44,   59,
  124,  259,   60,   61,   62,   93,   33,   59,  257,   59,
   37,   38,  124,   91,  266,   42,   43,   33,   45,  125,
   47,   37,   38,  262,   59,   59,   42,   43,   33,   45,
  281,   47,   59,   60,   61,   62,  124,  272,  273,  274,
  275,  276,  261,   33,   60,   61,   62,   37,   38,  261,
   33,   41,   42,   43,   37,   45,  259,   47,   40,   42,
   41,  125,   59,   44,   47,  261,  124,  261,   20,   24,
   60,   61,   62,   33,   52,  170,  101,   37,   38,   81,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,   -1,  124,   -1,   -1,
   60,   61,   62,   -1,   -1,  282,   -1,  261,  124,  282,
  264,  276,   -1,  267,  268,  269,   -1,  273,  274,  275,
   -1,   -1,   -1,   41,  278,  279,   44,   -1,  282,  283,
  284,  285,   -1,   93,  124,  278,  279,  261,   -1,  282,
  264,   59,  266,  267,  268,  269,   -1,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   33,  283,
  284,  285,   37,   38,  124,   -1,   -1,   42,   43,   -1,
   45,   -1,   47,  261,   -1,   93,  264,   -1,   -1,  267,
  268,  269,   -1,   -1,   59,   60,   61,   62,   -1,   33,
   -1,   -1,   -1,   37,   38,  283,  284,  285,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,  124,   -1,   -1,  267,
  268,   -1,   -1,   -1,   -1,   59,   60,   61,   62,   -1,
   -1,   -1,   -1,   -1,   33,  283,  284,  285,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,  124,
   33,   60,   61,   62,   37,   38,  283,  284,  285,   42,
   43,   33,   45,   -1,   47,   37,   38,  283,  284,  285,
   42,   43,   -1,   45,   -1,   47,   59,   60,   61,   62,
  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   61,
   62,   -1,   33,  283,  284,  285,   37,   38,   -1,   33,
   -1,   42,   43,   37,   45,   -1,   47,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,  124,   -1,   -1,   -1,   60,
   61,   62,   -1,  283,  284,  285,   60,   61,   62,   -1,
   33,   -1,   38,   -1,   37,   41,   -1,   -1,   44,   42,
   43,  124,   45,  261,   47,   -1,  264,   -1,   -1,  267,
  268,  269,  124,   59,   60,   61,   62,   60,   -1,   62,
   37,   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,
   47,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   59,   60,   61,   62,   -1,   93,   -1,   -1,
   -1,   -1,   -1,   59,   60,   61,   62,   37,   38,   -1,
   -1,   41,   42,   43,   44,   45,   -1,   47,  283,  284,
  285,   -1,   -1,   -1,   -1,   -1,   93,   -1,  124,   59,
   60,   61,   62,   -1,   -1,   -1,   -1,   93,   38,   -1,
   -1,   41,   -1,   43,   44,   45,   -1,   -1,   -1,  283,
  284,  285,   -1,   -1,   -1,   -1,   -1,  124,   -1,   59,
   60,   61,   62,   93,   -1,   -1,   -1,   -1,  124,   -1,
  269,   -1,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,
   -1,   43,   44,   45,  283,  284,  285,   -1,   -1,   -1,
   -1,   -1,   -1,   93,  124,   -1,   -1,   59,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  283,  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  283,  284,  285,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  283,  284,  285,   -1,   59,   -1,   61,  283,
  284,  285,  124,   41,   -1,  261,   44,   -1,  264,   -1,
   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   38,   -1,
   40,   59,   42,   -1,   -1,   45,   -1,  283,  284,  285,
   93,  284,  285,   -1,  261,   -1,   -1,  264,   -1,   59,
  267,  268,  269,   38,   -1,  261,   41,   -1,  264,   44,
   -1,  267,  268,  269,   -1,   93,  283,  284,  285,   -1,
   -1,  124,   -1,   -1,   59,   -1,   61,  283,  284,  285,
   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,
   38,   -1,   40,   41,   42,   -1,   -1,   45,   -1,   -1,
   -1,   -1,   -1,  283,  284,  285,   38,   -1,   93,   41,
   -1,  261,   44,  123,  264,  125,  126,  267,  268,  269,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   61,
   62,   -1,   -1,  283,  284,  285,   -1,   -1,   38,  124,
   40,   38,   42,   -1,   41,   45,   -1,   44,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,   59,
   -1,   93,   59,   60,   61,   62,   -1,   -1,   -1,   -1,
   -1,  283,  284,  285,   -1,   61,   38,   -1,  126,   41,
   -1,   -1,   44,   69,   70,   71,   72,   -1,   -1,   75,
   -1,   -1,  124,   -1,   -1,   81,   93,   59,   60,   61,
   62,   87,   -1,   -1,   -1,   38,   -1,   40,  261,   42,
   -1,  264,   45,   -1,  267,  268,  269,   38,   -1,   40,
   -1,   42,   -1,  123,   45,   -1,  126,  124,   -1,   -1,
  283,   93,   -1,  261,   -1,   -1,  264,   -1,   59,  267,
  268,  269,   -1,   -1,   -1,  131,  256,  257,  258,  259,
  260,  261,  262,  263,   -1,  265,   -1,   -1,   -1,   -1,
  270,  271,  124,   -1,   -1,   -1,   -1,   -1,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,  261,   -1,  164,  264,
   -1,   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
   -1,  177,  178,  126,   -1,   -1,   -1,   -1,  283,   -1,
   -1,   -1,  123,   -1,   -1,  126,   -1,   -1,   -1,  257,
  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,
  278,  279,  264,   -1,   -1,  267,  268,  269,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  283,  284,  285,   -1,   -1,  256,  257,  258,  259,
  260,  261,   -1,  263,  261,  265,   -1,  264,   -1,   -1,
  267,  268,  269,  273,  274,  275,   -1,   -1,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,  283,  284,  285,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  283,  284,  285,  257,  258,  259,  260,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,
  261,   -1,  263,   -1,  265,  278,  279,   68,   -1,  270,
  271,   -1,   73,   74,   -1,   76,   -1,  278,  279,   -1,
   -1,   -1,   -1,   -1,   85,   86,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  107,  108,  109,  110,
  111,  112,  113,  114,  115,  116,  117,  118,  119,  120,
  121,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  132,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  155,  156,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  165,  166,   -1,   -1,   -1,   -1,
  171,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 297
#define YYUNDFTOKEN 326
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","REAL","ID","STR",
"DO","WHILE","IF","THEN","FOR","IN","UPTO","DOWNTO","STEP","BREAK","CONTINUE",
"VOID","INTEGER","STRING","NUMBER","CONST","PUBLIC","INCR","DECR","IFX","ELSE",
"ATR","NE","GE","LE","UMINUS","NOT","REF","PROG","LOCAL","POSINC","POSDEC",
"PTR","CALL","START","PARAM","NIL",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file :",
"file : file error ';'",
"file : file public tipo ID ';'",
"file : file public CONST tipo ID ';'",
"file : file public tipo ID init",
"file : file public CONST tipo ID init",
"$$1 :",
"file : file public tipo ID $$1 finit",
"$$2 :",
"file : file public VOID ID $$2 finit",
"public :",
"public : PUBLIC",
"ptr :",
"ptr : '*'",
"tipo : INTEGER ptr",
"tipo : STRING ptr",
"tipo : NUMBER ptr",
"init : ATR ID ';'",
"init : ATR INT ';'",
"init : ATR '-' INT ';'",
"init : ATR STR ';'",
"init : ATR CONST STR ';'",
"init : ATR REAL ';'",
"init : ATR '-' REAL ';'",
"finit : '(' params ')' blocop",
"finit : '(' ')' blocop",
"blocop : ';'",
"blocop : bloco ';'",
"params : param",
"params : params ',' param",
"$$3 :",
"bloco : '{' $$3 decls list end '}'",
"decls :",
"decls : decls param ';'",
"param : tipo ID",
"stmt : base",
"stmt : brk",
"base : ';'",
"$$4 :",
"base : DO $$4 stmt WHILE expr ';'",
"$$5 :",
"base : FOR lv IN expr UPTO expr step DO $$5 stmt",
"$$6 :",
"base : FOR lv IN expr DOWNTO expr step DO $$6 stmt",
"base : IF expr THEN stmt",
"base : IF expr THEN stmt ELSE stmt",
"base : expr ';'",
"base : bloco",
"base : lv '#' expr ';'",
"base : error ';'",
"end :",
"end : brk",
"brk : BREAK intp ';'",
"brk : CONTINUE intp ';'",
"step :",
"step : STEP expr",
"intp :",
"intp : INT",
"list : base",
"list : list base",
"args : expr",
"args : args ',' expr",
"lv : ID",
"lv : ID '[' expr ']'",
"expr : lv",
"expr : '*' lv",
"expr : lv ATR expr",
"expr : INT",
"expr : STR",
"expr : REAL",
"expr : '-' expr",
"expr : '~' expr",
"expr : '&' lv",
"expr : expr '!'",
"expr : INCR lv",
"expr : DECR lv",
"expr : lv INCR",
"expr : lv DECR",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr NE expr",
"expr : expr '=' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '(' expr ')'",
"expr : ID '(' args ')'",
"expr : ID '(' ')'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 213 "gram.y"

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

void declare(int pub, int cnst, Node *type, char *name, Node *value)
{
  int typ;
  if (!value) {
    if (!pub && cnst) yyerror("local constants must be initialised");
    return;
  }
  if (value->attrib = INT && value->value.i == 0 && type->value.i > 10)
  	return; /* NULL pointer */
  if ((typ = value->info) % 10 > 5) typ -= 5;
  if (type->value.i != typ)
    yyerror("wrong types in initialization");
}
void enter(int pub, int typ, char *name) {
	fpar = malloc(32); /* 31 arguments, at most */
	fpar[0] = 0; /* argument count */
	if (IDfind(name, (long*)IDtest) < 20)
		IDnew(typ+20, name, (long)fpar);
	IDpush();
	if (typ != 4) IDnew(typ, name, 0);
}

int checkargs(char *name, Node *args) {
	char *arg;
	int typ;
        if ((typ = IDsearch(name, (long*)&arg,IDlevel(),1)) < 20) {
		yyerror("ident not a function");
		return 0;
	}
	if (args == 0 && arg[0] == 0)
		;
	else if (args == 0 && arg[0] != 0)
		yyerror("function requires no arguments");
	else if (args != 0 && arg[0] == 0)
		yyerror("function requires arguments");
	else {
		int err = 0, null, i = arg[0], typ;
		do {
			Node *n;
			if (i == 0) {
				yyerror("too many arguments.");
				err = 1;
				break;
			}
			n = RIGHT_CHILD(args);
			typ = n->info;
			if (typ % 10 > 5) typ -= 5; /* remove CONST */
			null =  (n->attrib == INT && n->value.i == 0 && arg[i] > 10) ? 1 : 0;
			if (!null && arg[i] != typ) {
				yyerror("wrong argument type");
				err = 1;
				break;
			}
			args = LEFT_CHILD(args);
			i--;
		} while (args->attrib != NIL);
		if (!err && i > 0)
			yyerror("missing arguments");
	}
	return typ % 20;
}

int nostring(Node *arg1, Node *arg2) {
	if (arg1->info % 5 == 2 || arg2->info % 5 == 2)
		yyerror("can not use strings");
	return arg1->info % 5 == 3 || arg2->info % 5 == 3 ? 3 : 1;
}

int intonly(Node *arg, int novar) {
	if (arg->info % 5 != 1)
		yyerror("only integers can be used");
	if (arg->info % 10 > 5)
		yyerror("argument is constant");
	return 1;
}

int noassign(Node *arg1, Node *arg2) {
	int t1 = arg1->info, t2 = arg2->info;
	if (t1 == t2) return 0;
	if (t1 == 3 && t2 == 1) return 0; /* real := int */
	if (t1 == 1 && t2 == 3) return 0; /* int := real */
	if (t1 == 2 && t2 == 11) return 0; /* string := int* */
	if (t1 == 2 && arg2->attrib == INT && arg2->value.i == 0)
		return 0; /* string := 0 */
	if (t1 > 10 && t1 < 20 && arg2->attrib == INT && arg2->value.i == 0)
		return 0; /* pointer := 0 */
	return 1;
}

void function(int pub, Node *type, char *name, Node *body)
{
	Node *bloco = LEFT_CHILD(body);
	IDpop();
	if (bloco != 0) { /* not a forward declaration */
		long par;
		int fwd = IDfind(name, &par);
		if (fwd > 40) yyerror("duplicate function");
		else IDreplace(fwd+40, name, par);
	}
}
#line 749 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 64 "gram.y"
	{ Node* n = uniNode(PROG, 0); if (trace) printNode(n, 0, (char**)yyname); yyselect(n); }
break;
case 3:
#line 66 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->value.i, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-3].i, 0, yystack.l_mark[-2].n, yystack.l_mark[-1].s, 0); }
break;
case 4:
#line 67 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->value.i+5, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-4].i, 1, yystack.l_mark[-2].n, yystack.l_mark[-1].s, 0); }
break;
case 5:
#line 68 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->value.i, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-3].i, 0, yystack.l_mark[-2].n, yystack.l_mark[-1].s, yystack.l_mark[0].n); }
break;
case 6:
#line 69 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->value.i+5, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-4].i, 1, yystack.l_mark[-2].n, yystack.l_mark[-1].s, yystack.l_mark[0].n); }
break;
case 7:
#line 70 "gram.y"
	{ enter(yystack.l_mark[-2].i, yystack.l_mark[-1].n->value.i, yystack.l_mark[0].s); }
break;
case 8:
#line 70 "gram.y"
	{ function(yystack.l_mark[-4].i, yystack.l_mark[-3].n, yystack.l_mark[-2].s, yystack.l_mark[0].n); }
break;
case 9:
#line 71 "gram.y"
	{ enter(yystack.l_mark[-2].i, 4, yystack.l_mark[0].s); }
break;
case 10:
#line 71 "gram.y"
	{ function(yystack.l_mark[-4].i, intNode(VOID, 4), yystack.l_mark[-2].s, yystack.l_mark[0].n); }
break;
case 11:
#line 74 "gram.y"
	{ yyval.i = 0; }
break;
case 12:
#line 75 "gram.y"
	{ yyval.i = 1; }
break;
case 13:
#line 78 "gram.y"
	{ yyval.i = 0; }
break;
case 14:
#line 79 "gram.y"
	{ yyval.i = 10; }
break;
case 15:
#line 82 "gram.y"
	{ yyval.n = intNode(INTEGER, 1+yystack.l_mark[0].i); }
break;
case 16:
#line 83 "gram.y"
	{ yyval.n = intNode(STRING, 2+yystack.l_mark[0].i); }
break;
case 17:
#line 84 "gram.y"
	{ yyval.n = intNode(NUMBER, 3+yystack.l_mark[0].i); }
break;
case 18:
#line 87 "gram.y"
	{ yyval.n = strNode(ID, yystack.l_mark[-1].s); yyval.n->info = IDfind(yystack.l_mark[-1].s, 0) + 10; }
break;
case 19:
#line 88 "gram.y"
	{ yyval.n = intNode(INT, yystack.l_mark[-1].i); yyval.n->info = 1; }
break;
case 20:
#line 89 "gram.y"
	{ yyval.n = intNode(INT, -yystack.l_mark[-1].i); yyval.n->info = 1; }
break;
case 21:
#line 90 "gram.y"
	{ yyval.n = strNode(STR, yystack.l_mark[-1].s); yyval.n->info = 2; }
break;
case 22:
#line 91 "gram.y"
	{ yyval.n = strNode(CONST, yystack.l_mark[-1].s); yyval.n->info = 2+5; }
break;
case 23:
#line 92 "gram.y"
	{ yyval.n = realNode(REAL, yystack.l_mark[-1].r); yyval.n->info = 3; }
break;
case 24:
#line 93 "gram.y"
	{ yyval.n = realNode(REAL, -yystack.l_mark[-1].r); yyval.n->info = 3; }
break;
case 25:
#line 96 "gram.y"
	{ yyval.n = binNode('(', yystack.l_mark[0].n, yystack.l_mark[-2].n); }
break;
case 26:
#line 97 "gram.y"
	{ yyval.n = binNode('(', yystack.l_mark[0].n, 0); }
break;
case 27:
#line 100 "gram.y"
	{ yyval.n = 0; }
break;
case 28:
#line 101 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 30:
#line 105 "gram.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 31:
#line 108 "gram.y"
	{ IDpush(); }
break;
case 32:
#line 108 "gram.y"
	{ yyval.n = binNode('{', yystack.l_mark[-1].n ? binNode(';', yystack.l_mark[-2].n, yystack.l_mark[-1].n) : yystack.l_mark[-2].n, yystack.l_mark[-3].n); IDpop(); }
break;
case 33:
#line 111 "gram.y"
	{ yyval.n = 0; }
break;
case 34:
#line 112 "gram.y"
	{ yyval.n = binNode(';', yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 35:
#line 115 "gram.y"
	{ yyval.n = binNode(PARAM, yystack.l_mark[-1].n, strNode(ID, yystack.l_mark[0].s));
                                  IDnew(yystack.l_mark[-1].n->value.i, yystack.l_mark[0].s, 0);
                                  if (IDlevel() == 1) fpar[++fpar[0]] = yystack.l_mark[-1].n->value.i;
                                }
break;
case 38:
#line 125 "gram.y"
	{ yyval.n = nilNode(VOID); }
break;
case 39:
#line 126 "gram.y"
	{ ncicl++; }
break;
case 40:
#line 126 "gram.y"
	{ yyval.n = binNode(WHILE, binNode(DO, nilNode(START), yystack.l_mark[-3].n), yystack.l_mark[-1].n); ncicl--; }
break;
case 41:
#line 127 "gram.y"
	{ ncicl++; }
break;
case 42:
#line 127 "gram.y"
	{ yyval.n = binNode(';', binNode(ATR, yystack.l_mark[-6].n, yystack.l_mark[-8].n), binNode(FOR, binNode(IN, nilNode(START), binNode(LE, uniNode(PTR, yystack.l_mark[-8].n), yystack.l_mark[-4].n)), binNode(';', yystack.l_mark[0].n, binNode(ATR, binNode('+', uniNode(PTR, yystack.l_mark[-8].n), yystack.l_mark[-3].n), yystack.l_mark[-8].n)))); ncicl--; }
break;
case 43:
#line 128 "gram.y"
	{ ncicl++; }
break;
case 44:
#line 128 "gram.y"
	{ yyval.n = binNode(';', binNode(ATR, yystack.l_mark[-6].n, yystack.l_mark[-8].n), binNode(FOR, binNode(IN, nilNode(START), binNode(GE, uniNode(PTR, yystack.l_mark[-8].n), yystack.l_mark[-4].n)), binNode(';', yystack.l_mark[0].n, binNode(ATR, binNode('-', uniNode(PTR, yystack.l_mark[-8].n), yystack.l_mark[-3].n), yystack.l_mark[-8].n)))); ncicl--; }
break;
case 45:
#line 129 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 46:
#line 130 "gram.y"
	{ yyval.n = binNode(ELSE, binNode(IF, yystack.l_mark[-4].n, yystack.l_mark[-2].n), yystack.l_mark[0].n); }
break;
case 47:
#line 131 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 48:
#line 132 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 49:
#line 133 "gram.y"
	{ yyval.n = binNode('#', yystack.l_mark[-1].n, yystack.l_mark[-3].n); }
break;
case 50:
#line 134 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 51:
#line 137 "gram.y"
	{ yyval.n = 0; }
break;
case 53:
#line 140 "gram.y"
	{ yyval.n = intNode(BREAK, yystack.l_mark[-1].i); if (yystack.l_mark[-1].i <= 0 || yystack.l_mark[-1].i > ncicl) yyerror("invalid break argument"); }
break;
case 54:
#line 141 "gram.y"
	{ yyval.n = intNode(CONTINUE, yystack.l_mark[-1].i); if (yystack.l_mark[-1].i <= 0 || yystack.l_mark[-1].i > ncicl) yyerror("invalid continue argument"); }
break;
case 55:
#line 144 "gram.y"
	{ yyval.n = intNode(INT, 1); }
break;
case 56:
#line 145 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 57:
#line 148 "gram.y"
	{ yyval.i = 1; }
break;
case 60:
#line 153 "gram.y"
	{ yyval.n = binNode(';', yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 61:
#line 156 "gram.y"
	{ yyval.n = binNode(',', nilNode(NIL), yystack.l_mark[0].n); }
break;
case 62:
#line 157 "gram.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 63:
#line 160 "gram.y"
	{ long pos; int typ = IDfind(yystack.l_mark[0].s, &pos);
                          if (pos == 0) yyval.n = strNode(ID, yystack.l_mark[0].s);
                          else yyval.n = intNode(LOCAL, pos);
			  yyval.n->info = typ;
			}
break;
case 64:
#line 165 "gram.y"
	{ Node *n;
                            long pos; int siz, typ = IDfind(yystack.l_mark[-3].s, &pos);
                            if (typ / 10 != 1 && typ % 5 != 2) yyerror("not a pointer");
                            if (pos == 0) n = strNode(ID, yystack.l_mark[-3].s);
                            else n = intNode(LOCAL, pos);
                            yyval.n = binNode('[', n, yystack.l_mark[-1].n);
			    if (typ >= 10) typ -= 10;
                            else if (typ % 5 == 2) typ = 1;
			    if (typ >= 5) typ -= 5;
			    yyval.n->info = typ;
			  }
break;
case 65:
#line 178 "gram.y"
	{ yyval.n = uniNode(PTR, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 66:
#line 179 "gram.y"
	{ yyval.n = uniNode(PTR, uniNode(PTR, yystack.l_mark[0].n)); if (yystack.l_mark[0].n->info % 5 == 2) yyval.n->info = 1; else if (yystack.l_mark[0].n->info / 10 == 1) yyval.n->info = yystack.l_mark[0].n->info % 10; else yyerror("can dereference lvalue"); }
break;
case 67:
#line 180 "gram.y"
	{ yyval.n = binNode(ATR, yystack.l_mark[0].n, yystack.l_mark[-2].n); if (yyval.n->info % 10 > 5) yyerror("constant value to assignment"); if (noassign(yystack.l_mark[-2].n, yystack.l_mark[0].n)) yyerror("illegal assignment"); yyval.n->info = yystack.l_mark[-2].n->info; }
break;
case 68:
#line 181 "gram.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 69:
#line 182 "gram.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); yyval.n->info = 2; }
break;
case 70:
#line 183 "gram.y"
	{ yyval.n = realNode(REAL, yystack.l_mark[0].r); yyval.n->info = 3; }
break;
case 71:
#line 184 "gram.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; nostring(yystack.l_mark[0].n, yystack.l_mark[0].n);}
break;
case 72:
#line 185 "gram.y"
	{ yyval.n = uniNode(NOT, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n, 0); }
break;
case 73:
#line 186 "gram.y"
	{ yyval.n = uniNode(REF, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info + 10; }
break;
case 74:
#line 187 "gram.y"
	{ yyval.n = uniNode('!', yystack.l_mark[-1].n); yyval.n->info = 3; intonly(yystack.l_mark[-1].n, 0); }
break;
case 75:
#line 188 "gram.y"
	{ yyval.n = uniNode(INCR, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n, 1); }
break;
case 76:
#line 189 "gram.y"
	{ yyval.n = uniNode(DECR, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n, 1); }
break;
case 77:
#line 190 "gram.y"
	{ yyval.n = uniNode(POSINC, yystack.l_mark[-1].n); yyval.n->info = intonly(yystack.l_mark[-1].n, 1); }
break;
case 78:
#line 191 "gram.y"
	{ yyval.n = uniNode(POSDEC, yystack.l_mark[-1].n); yyval.n->info = intonly(yystack.l_mark[-1].n, 1); }
break;
case 79:
#line 192 "gram.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 80:
#line 193 "gram.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 81:
#line 194 "gram.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 82:
#line 195 "gram.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 83:
#line 196 "gram.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0); }
break;
case 84:
#line 197 "gram.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 85:
#line 198 "gram.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 86:
#line 199 "gram.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 87:
#line 200 "gram.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 88:
#line 201 "gram.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 89:
#line 202 "gram.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 90:
#line 203 "gram.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0); }
break;
case 91:
#line 204 "gram.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0); }
break;
case 92:
#line 205 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; yyval.n->info = yystack.l_mark[-1].n->info; }
break;
case 93:
#line 206 "gram.y"
	{ yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n);
                            yyval.n->info = checkargs(yystack.l_mark[-3].s, yystack.l_mark[-1].n); }
break;
case 94:
#line 208 "gram.y"
	{ yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-2].s), nilNode(VOID));
                          yyval.n->info = checkargs(yystack.l_mark[-2].s, 0); }
break;
#line 1318 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
