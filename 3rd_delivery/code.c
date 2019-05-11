/*
generated at Sat May 11 22:28:34 2019
by $Id: pburg.c,v 2.5 2017/11/16 09:41:42 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.5"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#else
#define YYCONST
#endif

#line 1 "code.brg"

#include <stdio.h>
#include "node.h"
#include "tabid.h"
#include "y.tab.h"
#include "postfix.h"

extern FILE *yyout;
static int lbl;
static char *mklbl(int n);
#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yyfile_NT 1

static YYCONST char *yyntname[] = {
	0,
	"file",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "",
	/* 38 */ "MOD",
 "", "",
	/* 41 */ "FUNC",
 "",
	/* 43 */ "MUL",
	/* 44 */ "ADD",
	/* 45 */ "COM",
	/* 46 */ "SUB",
 "",
	/* 48 */ "DIV",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "END",
	/* 61 */ "LT",
	/* 62 */ "ASSIGN",
	/* 63 */ "GT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "",
	/* 258 */ "INT",
	/* 259 */ "REAL",
	/* 260 */ "ID",
	/* 261 */ "STR",
	/* 262 */ "DO",
	/* 263 */ "WHILE",
	/* 264 */ "IF",
	/* 265 */ "THEN",
	/* 266 */ "FOR",
	/* 267 */ "IN",
	/* 268 */ "UPTO",
	/* 269 */ "DOWNTO",
	/* 270 */ "STEP",
	/* 271 */ "BREAK",
	/* 272 */ "CONTINUE",
	/* 273 */ "VOID",
	/* 274 */ "INTEGER",
	/* 275 */ "STRING",
	/* 276 */ "NUMBER",
	/* 277 */ "CONST",
	/* 278 */ "PUBLIC",
	/* 279 */ "INCR",
	/* 280 */ "DECR",
	/* 281 */ "IFX",
	/* 282 */ "ELSE",
	/* 283 */ "ATR",
	/* 284 */ "NE",
	/* 285 */ "GE",
	/* 286 */ "LE",
	/* 287 */ "UMINUS",
	/* 288 */ "NOT",
	/* 289 */ "REF",
	/* 290 */ "PROG",
	/* 291 */ "LOCAL",
	/* 292 */ "POSINC",
	/* 293 */ "POSDEC",
	/* 294 */ "PTR",
	/* 295 */ "CALL",
	/* 296 */ "START",
	/* 297 */ "PARAM",
	/* 298 */ "NIL",
	""
};

struct yystate {
	short cost[2];
	struct {
		unsigned int yyfile:1;
	} rule;
};

static short yynts_0[] = { 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"file: PROG",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_file[] = {
	0,
	1,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 1)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yyfile_NT:	return yydecode_file[((struct yystate *)state)->rule.yyfile];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}


static void yylabel(NODEPTR_TYPE a, NODEPTR_TYPE u) {
	int c;
	struct yystate *p;

	if (!a)
		PANIC("yylabel", "Null tree in", OP_LABEL(u));
	STATE_LABEL(a) = p = (struct yystate *)malloc(sizeof *p);
	memset(p, 0, sizeof *p);
	p->cost[1] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 37: /* MOD */
		return;
	case 40: /* FUNC */
		return;
	case 42: /* MUL */
		return;
	case 43: /* ADD */
		return;
	case 44: /* COM */
		return;
	case 45: /* SUB */
		return;
	case 47: /* DIV */
		return;
	case 59: /* END */
		return;
	case 60: /* LT */
		return;
	case 61: /* ASSIGN */
		return;
	case 62: /* GT */
		return;
	case 257: /* INT */
		return;
	case 258: /* REAL */
		return;
	case 259: /* ID */
		return;
	case 260: /* STR */
		return;
	case 261: /* DO */
		return;
	case 262: /* WHILE */
		return;
	case 263: /* IF */
		return;
	case 264: /* THEN */
		return;
	case 265: /* FOR */
		return;
	case 266: /* IN */
		return;
	case 267: /* UPTO */
		return;
	case 268: /* DOWNTO */
		return;
	case 269: /* STEP */
		return;
	case 270: /* BREAK */
		return;
	case 271: /* CONTINUE */
		return;
	case 272: /* VOID */
		return;
	case 273: /* INTEGER */
		return;
	case 274: /* STRING */
		return;
	case 275: /* NUMBER */
		return;
	case 276: /* CONST */
		return;
	case 277: /* PUBLIC */
		return;
	case 278: /* INCR */
		return;
	case 279: /* DECR */
		return;
	case 280: /* IFX */
		return;
	case 281: /* ELSE */
		return;
	case 282: /* ATR */
		return;
	case 283: /* NE */
		return;
	case 284: /* GE */
		return;
	case 285: /* LE */
		return;
	case 286: /* UMINUS */
		return;
	case 287: /* NOT */
		return;
	case 288: /* REF */
		return;
	case 289: /* PROG */
		/* file: PROG */
		yytrace(a, 1, 1 + 0, p->cost[yyfile_NT]);
		if (1 + 0 < p->cost[yyfile_NT]) {
			p->cost[yyfile_NT] = 1 + 0;
			p->rule.yyfile = 1;
		}
		break;
	case 290: /* LOCAL */
		return;
	case 291: /* POSINC */
		return;
	case 292: /* POSDEC */
		return;
	case 293: /* PTR */
		return;
	case 294: /* CALL */
		return;
	case 295: /* START */
		return;
	case 296: /* PARAM */
		return;
	case 297: /* NIL */
		return;
	default:
		PANIC("yylabel", "Bad terminal", OP_LABEL(a));
	}
}

static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	case 1: /* file: PROG */
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[0];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* file: PROG */
#line 18 "code.brg"
{ fprintf(yyout, pfIMM pfPOP pfRET, 0); }
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yyfile == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 19 "code.brg"


extern char **yynames;

static int sameVar(NODEPTR_TYPE p) {
	return strcmp(LEFT_CHILD(p)->value.s, LEFT_CHILD(RIGHT_CHILD(p))->value.s) ? 0x7fff : 2;
}

static int data(int t, char *s, int a, int user) {
	if (s) fprintf(yyout, pfLABEL pfINTEGER, s, 0);
	return 1;
}

static char *mklbl(int n) {
	static char buf[20];
	sprintf(buf, "_#i%d", n);
	return strdup(buf);
}

static void outstr(char *s) {
	while (*s) fprintf(yyout, pfCHAR, (unsigned char)*s++);
	fprintf(yyout, pfCHAR, 0);
}

void evaluate(Node *p) {
	extern int trace, errors;

	if (errors) return;
	if (trace) printNode(p, stdout, yynames);

	fprintf(yyout, pfTEXT pfALIGN pfGLOBL pfLABEL, "_main", pfFUNC, "_main");
	
	yyselect(p);
	fprintf(yyout, pfRET pfDATA);

	IDevery(data,0);
	fprintf(yyout, pfEXTRN pfEXTRN pfEXTRN pfEXTRN, "_prints", "_printi", "_println", "_readi");
}