/*
generated at Mon May 13 18:50:31 2019
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
#include "y.tab.h" /* for STR and INT in isSTR and isINT */
#include "postfix.h"
extern FILE *yyout;
static int lbl;
static char *mklbl(int n);
static int isSTR(Node *p) { return p->info == STR ? 1 : MAX_COST; }
static int isINT(Node *p) { return p->info == INT ? 1 : MAX_COST; }
#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yyprog_NT 1
#define yydecls_NT 2
#define yyinstrs_NT 3
#define yydecl_NT 4
#define yyinstr_NT 5
#define yystrs_NT 6
#define yystr_NT 7
#define yyexpr_NT 8

static YYCONST char *yyntname[] = {
	0,
	"prog",
	"decls",
	"instrs",
	"decl",
	"instr",
	"strs",
	"str",
	"expr",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
	/* 44 */ "ADD",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
	/* 62 */ "ASSIGN",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "",
	/* 258 */ "PRINT",
	/* 259 */ "INT",
	/* 260 */ "STR",
	/* 261 */ "ID",
	/* 262 */ "NIL",
	/* 263 */ "INSTRS",
	/* 264 */ "PROG",
	/* 265 */ "DECLS",
	/* 266 */ "EXPR",
	""
};

struct yystate {
	short cost[9];
	struct {
		unsigned int yyprog:1;
		unsigned int yydecls:2;
		unsigned int yyinstrs:2;
		unsigned int yydecl:2;
		unsigned int yyinstr:1;
		unsigned int yystrs:3;
		unsigned int yystr:2;
		unsigned int yyexpr:3;
	} rule;
};

static short yynts_0[] = { yydecls_NT, yyinstrs_NT, 0 };
static short yynts_1[] = { 0 };
static short yynts_2[] = { yydecls_NT, yydecl_NT, 0 };
static short yynts_3[] = { yyinstrs_NT, yyinstr_NT, 0 };
static short yynts_4[] = { yystrs_NT, 0 };
static short yynts_5[] = { yystrs_NT, yystr_NT, 0 };
static short yynts_6[] = { yystrs_NT, yyexpr_NT, 0 };
static short yynts_7[] = { yystr_NT, 0 };
static short yynts_8[] = { yyexpr_NT, 0 };
static short yynts_9[] = { yyexpr_NT, yyexpr_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_1,	/* 4 */
	yynts_1,	/* 5 */
	yynts_1,	/* 6 */
	yynts_3,	/* 7 */
	yynts_4,	/* 8 */
	yynts_5,	/* 9 */
	yynts_6,	/* 10 */
	yynts_7,	/* 11 */
	yynts_8,	/* 12 */
	yynts_1,	/* 13 */
	yynts_1,	/* 14 */
	yynts_1,	/* 15 */
	yynts_1,	/* 16 */
	yynts_9,	/* 17 */
	yynts_1,	/* 18 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"prog: PROG(decls,instrs)",
/* 2 */	"decls: NIL",
/* 3 */	"decls: DECLS(decls,decl)",
/* 4 */	"decl: ASSIGN(ID,STR)",
/* 5 */	"decl: ASSIGN(ID,INT)",
/* 6 */	"instrs: NIL",
/* 7 */	"instrs: INSTRS(instrs,instr)",
/* 8 */	"instr: PRINT(strs)",
/* 9 */	"strs: EXPR(strs,str)",
/* 10 */	"strs: EXPR(strs,expr)",
/* 11 */	"strs: str",
/* 12 */	"strs: expr",
/* 13 */	"str: ID",
/* 14 */	"str: STR",
/* 15 */	"expr: ID",
/* 16 */	"expr: INT",
/* 17 */	"expr: ADD(expr,expr)",
/* 18 */	"expr: ADD(INT,INT)",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_prog[] = {
	0,
	1,
};

static short yydecode_decls[] = {
	0,
	2,
	3,
};

static short yydecode_instrs[] = {
	0,
	6,
	7,
};

static short yydecode_decl[] = {
	0,
	4,
	5,
};

static short yydecode_instr[] = {
	0,
	8,
};

static short yydecode_strs[] = {
	0,
	9,
	10,
	11,
	12,
};

static short yydecode_str[] = {
	0,
	13,
	14,
};

static short yydecode_expr[] = {
	0,
	15,
	16,
	17,
	18,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 8)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yyprog_NT:	return yydecode_prog[((struct yystate *)state)->rule.yyprog];
	case yydecls_NT:	return yydecode_decls[((struct yystate *)state)->rule.yydecls];
	case yyinstrs_NT:	return yydecode_instrs[((struct yystate *)state)->rule.yyinstrs];
	case yydecl_NT:	return yydecode_decl[((struct yystate *)state)->rule.yydecl];
	case yyinstr_NT:	return yydecode_instr[((struct yystate *)state)->rule.yyinstr];
	case yystrs_NT:	return yydecode_strs[((struct yystate *)state)->rule.yystrs];
	case yystr_NT:	return yydecode_str[((struct yystate *)state)->rule.yystr];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_str(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);

static void yyclosure_str(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 11, c + 0, p->cost[yystrs_NT]);
	if (c + 0 < p->cost[yystrs_NT]) {
		p->cost[yystrs_NT] = c + 0;
		p->rule.yystrs = 3;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 12, c + 0, p->cost[yystrs_NT]);
	if (c + 0 < p->cost[yystrs_NT]) {
		p->cost[yystrs_NT] = c + 0;
		p->rule.yystrs = 4;
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
	p->cost[2] =
	p->cost[3] =
	p->cost[4] =
	p->cost[5] =
	p->cost[6] =
	p->cost[7] =
	p->cost[8] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: ADD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 17, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 3;
			yyclosure_expr(a, c + 0);
		}
		if (	/* expr: ADD(INT,INT) */
			OP_LABEL(LEFT_CHILD(a)) == 258 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 258 /* INT */
		) {
			c = 1;
			yytrace(a, 18, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 4;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 61: /* ASSIGN */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* decl: ASSIGN(ID,STR) */
			OP_LABEL(LEFT_CHILD(a)) == 260 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* STR */
		) {
			c = 0;
			yytrace(a, 4, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 1;
			}
		}
		if (	/* decl: ASSIGN(ID,INT) */
			OP_LABEL(LEFT_CHILD(a)) == 260 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 258 /* INT */
		) {
			c = 0;
			yytrace(a, 5, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 2;
			}
		}
		break;
	case 257: /* PRINT */
		yylabel(LEFT_CHILD(a),a);
		/* instr: PRINT(strs) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yystrs_NT] + 0;
		yytrace(a, 8, c + 0, p->cost[yyinstr_NT]);
		if (c + 0 < p->cost[yyinstr_NT]) {
			p->cost[yyinstr_NT] = c + 0;
			p->rule.yyinstr = 1;
		}
		break;
	case 258: /* INT */
		/* expr: INT */
		yytrace(a, 16, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 2;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 259: /* STR */
		/* str: STR */
		yytrace(a, 14, 0 + 0, p->cost[yystr_NT]);
		if (0 + 0 < p->cost[yystr_NT]) {
			p->cost[yystr_NT] = 0 + 0;
			p->rule.yystr = 2;
			yyclosure_str(a, 0 + 0);
		}
		break;
	case 260: /* ID */
		/* str: ID */
		c = (isSTR(a));
		yytrace(a, 13, c + 0, p->cost[yystr_NT]);
		if (c + 0 < p->cost[yystr_NT]) {
			p->cost[yystr_NT] = c + 0;
			p->rule.yystr = 1;
			yyclosure_str(a, c + 0);
		}
		/* expr: ID */
		c = (isINT(a));
		yytrace(a, 15, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 1;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 261: /* NIL */
		/* decls: NIL */
		yytrace(a, 2, 0 + 0, p->cost[yydecls_NT]);
		if (0 + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = 0 + 0;
			p->rule.yydecls = 1;
		}
		/* instrs: NIL */
		yytrace(a, 6, 0 + 0, p->cost[yyinstrs_NT]);
		if (0 + 0 < p->cost[yyinstrs_NT]) {
			p->cost[yyinstrs_NT] = 0 + 0;
			p->rule.yyinstrs = 1;
		}
		break;
	case 262: /* INSTRS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* instrs: INSTRS(instrs,instr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 0;
		yytrace(a, 7, c + 0, p->cost[yyinstrs_NT]);
		if (c + 0 < p->cost[yyinstrs_NT]) {
			p->cost[yyinstrs_NT] = c + 0;
			p->rule.yyinstrs = 2;
		}
		break;
	case 263: /* PROG */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* prog: PROG(decls,instrs) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrs_NT] + 0;
		yytrace(a, 1, c + 0, p->cost[yyprog_NT]);
		if (c + 0 < p->cost[yyprog_NT]) {
			p->cost[yyprog_NT] = c + 0;
			p->rule.yyprog = 1;
		}
		break;
	case 264: /* DECLS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* decls: DECLS(decls,decl) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecl_NT] + 0;
		yytrace(a, 3, c + 0, p->cost[yydecls_NT]);
		if (c + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = c + 0;
			p->rule.yydecls = 2;
		}
		break;
	case 265: /* EXPR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* strs: EXPR(strs,str) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yystrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystr_NT] + 0;
		yytrace(a, 9, c + 0, p->cost[yystrs_NT]);
		if (c + 0 < p->cost[yystrs_NT]) {
			p->cost[yystrs_NT] = c + 0;
			p->rule.yystrs = 1;
		}
		/* strs: EXPR(strs,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yystrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 0;
		yytrace(a, 10, c + 0, p->cost[yystrs_NT]);
		if (c + 0 < p->cost[yystrs_NT]) {
			p->cost[yystrs_NT] = c + 0;
			p->rule.yystrs = 2;
		}
		break;
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
	case 17: /* expr: ADD(expr,expr) */
	case 10: /* strs: EXPR(strs,expr) */
	case 9: /* strs: EXPR(strs,str) */
	case 7: /* instrs: INSTRS(instrs,instr) */
	case 3: /* decls: DECLS(decls,decl) */
	case 1: /* prog: PROG(decls,instrs) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 18: /* expr: ADD(INT,INT) */
	case 16: /* expr: INT */
	case 15: /* expr: ID */
	case 14: /* str: STR */
	case 13: /* str: ID */
	case 6: /* instrs: NIL */
	case 5: /* decl: ASSIGN(ID,INT) */
	case 4: /* decl: ASSIGN(ID,STR) */
	case 2: /* decls: NIL */
		break;
	case 8: /* instr: PRINT(strs) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 12: /* strs: expr */
	case 11: /* strs: str */
		kids[0] = p;
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[2];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* prog: PROG(decls,instrs) */
#line 15 "code.brg"
{ fprintf(yyout, pfIMM pfPOP pfRET, 0); }
		break;
	case 2: /* decls: NIL */
#line 16 "code.brg"
{ fprintf(yyout, pfEXTRN pfEXTRN pfEXTRN, "_println", "_prints", "_printi"); }
		break;
	case 3: /* decls: DECLS(decls,decl) */
#line 17 "code.brg"

		break;
	case 4: /* decl: ASSIGN(ID,STR) */
#line 18 "code.brg"
{ fprintf(yyout, pfTEXT pfALIGN pfLABEL pfSTR, p->SUB(0)->value.s, p->SUB(1)->value.s); }
		break;
	case 5: /* decl: ASSIGN(ID,INT) */
#line 19 "code.brg"
{ fprintf(yyout, pfTEXT pfALIGN pfLABEL pfINTEGER, p->SUB(0)->value.s, p->SUB(1)->value.i); }
		break;
	case 6: /* instrs: NIL */
#line 20 "code.brg"
{ fprintf(yyout, pfTEXT pfALIGN pfGLOBL pfLABEL, "_main", pfFUNC, "_main"); }
		break;
	case 7: /* instrs: INSTRS(instrs,instr) */
#line 21 "code.brg"
{ /* no code between instructions */ }
		break;
	case 8: /* instr: PRINT(strs) */
#line 22 "code.brg"
{ fprintf(yyout, pfCALL, "_println"); }
		break;
	case 9: /* strs: EXPR(strs,str) */
#line 23 "code.brg"
{ fprintf(yyout, pfARG1 pfCALL pfTRASH, "_prints", pfWORD); }
		break;
	case 10: /* strs: EXPR(strs,expr) */
#line 24 "code.brg"
{ fprintf(yyout, pfARG1 pfCALL pfTRASH, "_printi", pfWORD); }
		break;
	case 11: /* strs: str */
#line 25 "code.brg"
{ fprintf(yyout, pfARG1 pfCALL pfTRASH, "_prints", pfWORD); }
		break;
	case 12: /* strs: expr */
#line 26 "code.brg"
{ fprintf(yyout, pfARG1 pfCALL pfTRASH, "_printi", pfWORD); }
		break;
	case 13: /* str: ID */
#line 27 "code.brg"
{ fprintf(yyout, pfADDR, p->value.s); }
		break;
	case 14: /* str: STR */
#line 28 "code.brg"
{ lbl++; fprintf(yyout, pfRODATA pfALIGN pfLABEL pfSTR pfTEXT pfADDR, mklbl(lbl), p->value.s, mklbl(lbl)); }
		break;
	case 15: /* expr: ID */
#line 29 "code.brg"
{ fprintf(yyout, pfADDRV, p->value.s); }
		break;
	case 16: /* expr: INT */
#line 30 "code.brg"
{ fprintf(yyout, pfIMM, p->value.i); }
		break;
	case 17: /* expr: ADD(expr,expr) */
#line 31 "code.brg"
{ fprintf(yyout, pfADD); }
		break;
	case 18: /* expr: ADD(INT,INT) */
#line 32 "code.brg"
{ fprintf(yyout, pfIMM, p->SUB(0)->value.i + p->SUB(1)->value.i); }
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yyprog == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 33 "code.brg"

static char *mklbl(int n) {
  static char buf[20];
  sprintf(buf, "_#i%d", n);
  return strdup(buf);
}
