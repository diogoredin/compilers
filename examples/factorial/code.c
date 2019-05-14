/*
generated at Thu May  9 23:13:23 2013
by $Id: pburg.c,v 2.3a 2012/10/07 00:51:11 prs Exp $
*/
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.3a"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#endif

#line 1 "factorial.brg"

/* Instruction selection with postfix.h
 */
    
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "postfix.h"
#include "y.tab.h"

#ifndef U_
#define U_ "_"
#endif

extern FILE *outfp;
extern int lbl;
extern char *mklbl(int n);
extern char **yynames;

static int stk;
static int sameVar(NODEPTR_TYPE p) {
  return strcmp(p->SUB(0)->value.s, p->SUB(1)->SUB(0)->value.s) ? 0x7fff : 2;
}
static int sameLoc(NODEPTR_TYPE p) {
  return p->SUB(0)->value.s == p->SUB(1)->SUB(0)->value.s ? 0x7fff : 2;
}

#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
static void yylabel(NODEPTR_TYPE,NODEPTR_TYPE);
static int yyrule(void*, int);


static YYCONST char *yyntname[] = {
	0,
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
	/* 258 */ "INT",
	/* 259 */ "NUM",
	/* 260 */ "IDENTIF",
	/* 261 */ "STRN",
	/* 262 */ "WHILE",
	/* 263 */ "IF",
	/* 264 */ "END",
	/* 265 */ "RETURN",
	/* 266 */ "VOID",
	/* 267 */ "PUBLIC",
	/* 268 */ "CONST",
	/* 269 */ "THEN",
	/* 270 */ "ELSE",
	/* 271 */ "DO",
	/* 272 */ "FOR",
	/* 273 */ "IN",
	/* 274 */ "STEP",
	/* 275 */ "UPTO",
	/* 276 */ "DOWNTO",
	/* 277 */ "BREAK",
	/* 278 */ "CONTINUE",
	/* 279 */ "INTEGER",
	/* 280 */ "STRING",
	/* 281 */ "NUMBER",
	/* 282 */ "GE",
	/* 283 */ "LE",
	/* 284 */ "EQ",
	/* 285 */ "NE",
	/* 286 */ "INC",
	/* 287 */ "DEC",
	/* 288 */ "ATRIB",
	/* 289 */ "ADDR",
	/* 290 */ "POINTER",
	/* 291 */ "IFX",
	/* 292 */ "CALL",
	/* 293 */ "NEG",
	/* 294 */ "FACT",
	/* 295 */ "AND",
	/* 296 */ "OR",
	/* 297 */ "PROG",
	/* 298 */ "ADD",
	/* 299 */ "SUBT",
	/* 300 */ "MUL",
	/* 301 */ "DIV",
	/* 302 */ "LT",
	/* 303 */ "GT",
	/* 304 */ "MOD",
	/* 305 */ "PARAMS",
	/* 306 */ "PARS2",
	/* 307 */ "PARS",
	/* 308 */ "INTRS",
	/* 309 */ "PINTR",
	/* 310 */ "INTR",
	/* 311 */ "DECL",
	/* 312 */ "DECLS",
	/* 313 */ "INIT",
	/* 314 */ "NIL",
	/* 315 */ "PNTR",
	/* 316 */ "EXPS",
	/* 317 */ "EXP",
	/* 318 */ "MALL",
	/* 319 */ "BODY",
	/* 320 */ "JZ",
	/* 321 */ "ETIQ",
	/* 322 */ "LABEL",
	/* 323 */ "JNZ",
	/* 324 */ "JMP",
	/* 325 */ "UMINUS",
	""
};

struct yystate {
	short cost[1];
	struct {
	} rule;
};


static short *yynts[] = {
};


static YYCONST char *yystring[] = {
/* 0 */	0,
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 0)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}


static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[10];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	return 1;
}

#line 34 "factorial.brg"


void function(char *name, int enter, Node *body) {
  int i;
  extern int trace;

  if(trace) printNode(body, stdout, yynames);
  if (body == 0) /* forward declaration */
    fprintf(outfp, pfEXTRN, name);
  else { /* function body */
    fprintf(outfp, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, name, pfFUNC, name, enter);
    if (yyselect(body) == 1) yyerror("No match for syntactic tree.");
    fprintf(outfp, pfLEAVE pfRET); /* just in case there is no 'return' */
    freeNode(body);
  }
}

void program(int enter, Node *body) {
  function("_main", enter, body);
  fprintf(outfp, pfEXTRN pfEXTRN pfEXTRN pfEXTRN,
  		U_"prints", U_"printi", U_"println", U_"readi");
}

void declare(char *name, int value) {
  IDnew(INTEGER, name, 0);
  if (value == 0)
    fprintf(outfp, pfBSS pfALIGN pfLABEL pfBYTE pfTEXT, name, 4);
  else
    fprintf(outfp, pfDATA pfALIGN pfLABEL pfINTEGER pfTEXT, name, value);
}
