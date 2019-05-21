/*
generated at Tue May 21 11:04:20 2019
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

#define NOTRACE 1

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

#define GLOBAL 0

extern FILE *outfp;
extern int lbl;
extern char *mklbl(int n);
extern char **yynames;

int trash;
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
#define yycorpo_NT 1
#define yyinstrucoes_NT 2
#define yypars2_NT 3
#define yyinstrucao_NT 4
#define yyexpressao_NT 5
#define yylvalue_NT 6
#define yystack_NT 7
#define yydupexp_NT 8
#define yylvalue2_NT 9

struct yystate {
	short cost[10];
	struct {
		unsigned int yycorpo:2;
		unsigned int yyinstrucoes:2;
		unsigned int yypars2:2;
		unsigned int yyinstrucao:5;
		unsigned int yyexpressao:5;
		unsigned int yylvalue:2;
		unsigned int yystack:2;
		unsigned int yydupexp:1;
		unsigned int yylvalue2:1;
	} rule;
};

static short yynts_0[] = { 0 };
static short yynts_1[] = { yyinstrucoes_NT, 0 };
static short yynts_2[] = { yypars2_NT, yyinstrucoes_NT, 0 };
static short yynts_3[] = { yyinstrucoes_NT, yyinstrucao_NT, 0 };
static short yynts_4[] = { yyinstrucao_NT, 0 };
static short yynts_5[] = { yyinstrucao_NT, yyinstrucao_NT, 0 };
static short yynts_6[] = { yyexpressao_NT, 0 };
static short yynts_7[] = { yycorpo_NT, 0 };
static short yynts_8[] = { yyexpressao_NT, yyexpressao_NT, 0 };
static short yynts_9[] = { yylvalue_NT, yyexpressao_NT, 0 };
static short yynts_10[] = { yylvalue_NT, 0 };
static short yynts_11[] = { yystack_NT, 0 };
static short yynts_12[] = { yydupexp_NT, yylvalue_NT, 0 };
static short yynts_13[] = { yylvalue2_NT, yyexpressao_NT, 0 };
static short yynts_14[] = { yystack_NT, yystack_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_0,	/* 4 */
	yynts_0,	/* 5 */
	yynts_3,	/* 6 */
	yynts_4,	/* 7 */
	yynts_5,	/* 8 */
	yynts_0,	/* 9 */
	yynts_6,	/* 10 */
	yynts_7,	/* 11 */
	yynts_0,	/* 12 */
	yynts_6,	/* 13 */
	yynts_6,	/* 14 */
	yynts_8,	/* 15 */
	yynts_8,	/* 16 */
	yynts_8,	/* 17 */
	yynts_8,	/* 18 */
	yynts_8,	/* 19 */
	yynts_8,	/* 20 */
	yynts_8,	/* 21 */
	yynts_8,	/* 22 */
	yynts_8,	/* 23 */
	yynts_8,	/* 24 */
	yynts_8,	/* 25 */
	yynts_8,	/* 26 */
	yynts_9,	/* 27 */
	yynts_0,	/* 28 */
	yynts_0,	/* 29 */
	yynts_10,	/* 30 */
	yynts_11,	/* 31 */
	yynts_0,	/* 32 */
	yynts_12,	/* 33 */
	yynts_6,	/* 34 */
	yynts_10,	/* 35 */
	yynts_10,	/* 36 */
	yynts_8,	/* 37 */
	yynts_8,	/* 38 */
	yynts_8,	/* 39 */
	yynts_8,	/* 40 */
	yynts_8,	/* 41 */
	yynts_8,	/* 42 */
	yynts_8,	/* 43 */
	yynts_8,	/* 44 */
	yynts_8,	/* 45 */
	yynts_8,	/* 46 */
	yynts_8,	/* 47 */
	yynts_8,	/* 48 */
	yynts_8,	/* 49 */
	yynts_8,	/* 50 */
	yynts_6,	/* 51 */
	yynts_6,	/* 52 */
	yynts_10,	/* 53 */
	yynts_10,	/* 54 */
	yynts_6,	/* 55 */
	yynts_0,	/* 56 */
	yynts_13,	/* 57 */
	yynts_10,	/* 58 */
	yynts_14,	/* 59 */
	yynts_6,	/* 60 */
	yynts_0,	/* 61 */
};

static short yydecode_corpo[] = {
	0,
	1,
	2,
	3,
};

static short yydecode_instrucoes[] = {
	0,
	6,
	7,
};

static short yydecode_pars2[] = {
	0,
	4,
	5,
};

static short yydecode_instrucao[] = {
	0,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	15,
	16,
	17,
	18,
	19,
	20,
	21,
	22,
	23,
	24,
	25,
	26,
	27,
};

static short yydecode_expressao[] = {
	0,
	28,
	29,
	30,
	31,
	32,
	33,
	34,
	35,
	36,
	37,
	38,
	39,
	40,
	41,
	42,
	43,
	44,
	45,
	46,
	47,
	48,
	49,
	50,
	51,
	52,
	53,
	54,
};

static short yydecode_lvalue[] = {
	0,
	56,
	57,
};

static short yydecode_stack[] = {
	0,
	59,
	60,
	61,
};

static short yydecode_dupexp[] = {
	0,
	55,
};

static short yydecode_lvalue2[] = {
	0,
	58,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 9)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yycorpo_NT:	return yydecode_corpo[((struct yystate *)state)->rule.yycorpo];
	case yyinstrucoes_NT:	return yydecode_instrucoes[((struct yystate *)state)->rule.yyinstrucoes];
	case yypars2_NT:	return yydecode_pars2[((struct yystate *)state)->rule.yypars2];
	case yyinstrucao_NT:	return yydecode_instrucao[((struct yystate *)state)->rule.yyinstrucao];
	case yyexpressao_NT:	return yydecode_expressao[((struct yystate *)state)->rule.yyexpressao];
	case yylvalue_NT:	return yydecode_lvalue[((struct yystate *)state)->rule.yylvalue];
	case yystack_NT:	return yydecode_stack[((struct yystate *)state)->rule.yystack];
	case yydupexp_NT:	return yydecode_dupexp[((struct yystate *)state)->rule.yydupexp];
	case yylvalue2_NT:	return yydecode_lvalue2[((struct yystate *)state)->rule.yylvalue2];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_corpo(NODEPTR_TYPE, int);
static void yyclosure_instrucoes(NODEPTR_TYPE, int);
static void yyclosure_instrucao(NODEPTR_TYPE, int);
static void yyclosure_expressao(NODEPTR_TYPE, int);
static void yyclosure_lvalue(NODEPTR_TYPE, int);

static void yyclosure_corpo(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	if (c + 0 < p->cost[yyinstrucao_NT]) {
		p->cost[yyinstrucao_NT] = c + 0;
		p->rule.yyinstrucao = 4;
		yyclosure_instrucao(a, c + 0);
	}
}

static void yyclosure_instrucoes(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	if (c + 0 < p->cost[yycorpo_NT]) {
		p->cost[yycorpo_NT] = c + 0;
		p->rule.yycorpo = 2;
		yyclosure_corpo(a, c + 0);
	}
}

static void yyclosure_instrucao(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	if (c + 0 < p->cost[yyinstrucoes_NT]) {
		p->cost[yyinstrucoes_NT] = c + 0;
		p->rule.yyinstrucoes = 2;
		yyclosure_instrucoes(a, c + 0);
	}
}

static void yyclosure_expressao(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	if (c + 0 < p->cost[yystack_NT]) {
		p->cost[yystack_NT] = c + 0;
		p->rule.yystack = 2;
	}
	if (c + 1 < p->cost[yydupexp_NT]) {
		p->cost[yydupexp_NT] = c + 1;
		p->rule.yydupexp = 1;
	}
	if (c + 1 < p->cost[yyinstrucao_NT]) {
		p->cost[yyinstrucao_NT] = c + 1;
		p->rule.yyinstrucao = 3;
		yyclosure_instrucao(a, c + 1);
	}
}

static void yyclosure_lvalue(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	if (c + 1 < p->cost[yylvalue2_NT]) {
		p->cost[yylvalue2_NT] = c + 1;
		p->rule.yylvalue2 = 1;
	}
	if (c + 1 < p->cost[yyexpressao_NT]) {
		p->cost[yyexpressao_NT] = c + 1;
		p->rule.yyexpressao = 3;
		yyclosure_expressao(a, c + 1);
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
	p->cost[9] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 59: /* ARG */
		return;
	case 257: /* INT */
		/* expressao: INT */
		if (1 + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = 1 + 0;
			p->rule.yyexpressao = 1;
			yyclosure_expressao(a, 1 + 0);
		}
		break;
	case 258: /* NUM */
		return;
	case 259: /* IDENTIF */
		/* pars2: IDENTIF */
		if (0 + 0 < p->cost[yypars2_NT]) {
			p->cost[yypars2_NT] = 0 + 0;
			p->rule.yypars2 = 2;
		}
		/* lvalue: IDENTIF */
		if (1 + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = 1 + 0;
			p->rule.yylvalue = 1;
			yyclosure_lvalue(a, 1 + 0);
		}
		break;
	case 260: /* STRN */
		/* expressao: STRN */
		if (3 + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = 3 + 0;
			p->rule.yyexpressao = 2;
			yyclosure_expressao(a, 3 + 0);
		}
		break;
	case 261: /* WHILE */
		return;
	case 262: /* IF */
		return;
	case 263: /* END */
		return;
	case 264: /* RETURN */
		return;
	case 265: /* VOID */
		return;
	case 266: /* PUBLIC */
		return;
	case 267: /* CONST */
		return;
	case 268: /* THEN */
		return;
	case 269: /* ELSE */
		return;
	case 270: /* DO */
		return;
	case 271: /* FOR */
		return;
	case 272: /* IN */
		return;
	case 273: /* STEP */
		return;
	case 274: /* UPTO */
		return;
	case 275: /* DOWNTO */
		return;
	case 276: /* BREAK */
		return;
	case 277: /* CONTINUE */
		return;
	case 278: /* INTEGER */
		return;
	case 279: /* STRING */
		return;
	case 280: /* NUMBER */
		return;
	case 281: /* SHIFT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: SHIFT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 10;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 282: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: GE(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 20;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 283: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: LE(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 21;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 284: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: EQ(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 18;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 285: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: NE(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 19;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 286: /* INC */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: INC(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 8;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 287: /* DEC */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: DEC(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 9;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 288: /* ATRIB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: ATRIB(dupexp,lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydupexp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 6;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 289: /* ADDR */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: ADDR(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 0;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 26;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 290: /* POINTER */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: POINTER(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 27;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 291: /* IFX */
		return;
	case 292: /* LIST */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* instrucao: LIST(instrucao,instrucao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrucao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrucao_NT] + 0;
		if (c + 0 < p->cost[yyinstrucao_NT]) {
			p->cost[yyinstrucao_NT] = c + 0;
			p->rule.yyinstrucao = 1;
			yyclosure_instrucao(a, c + 0);
		}
		break;
	case 293: /* VECTOR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* lvalue: VECTOR(lvalue2,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue2_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 3;
		if (c + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = c + 0;
			p->rule.yylvalue = 2;
			yyclosure_lvalue(a, c + 0);
		}
		break;
	case 294: /* ELIF */
		return;
	case 295: /* CALL */
		yylabel(LEFT_CHILD(a),a);
		if (	/* expressao: CALL(IDENTIF) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* IDENTIF */
		) {
			c = 2;
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 5;
				yyclosure_expressao(a, c + 0);
			}
		}
		break;
	case 296: /* CALL2 */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expressao: CALL2(IDENTIF,stack) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* IDENTIF */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystack_NT] + 3;
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 4;
				yyclosure_expressao(a, c + 0);
			}
		}
		break;
	case 297: /* NEG */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: NEG(expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 2;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 24;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 298: /* FACT */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: FACT(expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 0;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 25;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 299: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: AND(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 7;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 22;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 300: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: OR(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 7;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 23;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 301: /* PROG */
		return;
	case 302: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: ADD(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 14;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 303: /* SUBT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: SUBT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 15;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 304: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: MUL(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 11;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 305: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: DIV(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 12;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 306: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: LT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 17;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 307: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: GT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 16;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 308: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: MOD(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 13;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 309: /* PARAMS */
		return;
	case 310: /* PARS2 */
		/* pars2: PARS2 */
		if (0 + 0 < p->cost[yypars2_NT]) {
			p->cost[yypars2_NT] = 0 + 0;
			p->rule.yypars2 = 1;
		}
		break;
	case 311: /* PARS */
		return;
	case 312: /* PINTR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* corpo: PINTR(pars2,instrucoes) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yypars2_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrucoes_NT] + 0;
		if (c + 0 < p->cost[yycorpo_NT]) {
			p->cost[yycorpo_NT] = c + 0;
			p->rule.yycorpo = 3;
			yyclosure_corpo(a, c + 0);
		}
		break;
	case 313: /* INTR */
		return;
	case 314: /* DECL */
		return;
	case 315: /* DECLS */
		return;
	case 316: /* INIT */
		return;
	case 317: /* NIL */
		/* corpo: NIL */
		if (0 + 0 < p->cost[yycorpo_NT]) {
			p->cost[yycorpo_NT] = 0 + 0;
			p->rule.yycorpo = 1;
			yyclosure_corpo(a, 0 + 0);
		}
		/* stack: NIL */
		if (0 + 0 < p->cost[yystack_NT]) {
			p->cost[yystack_NT] = 0 + 0;
			p->rule.yystack = 3;
		}
		break;
	case 318: /* PNTR */
		return;
	case 319: /* EXPS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* stack: EXPS(stack,stack) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yystack_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystack_NT] + 0;
		if (c + 0 < p->cost[yystack_NT]) {
			p->cost[yystack_NT] = c + 0;
			p->rule.yystack = 1;
		}
		break;
	case 320: /* EXP */
		return;
	case 321: /* MALL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* instrucao: MALL(lvalue,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyinstrucao_NT]) {
			p->cost[yyinstrucao_NT] = c + 0;
			p->rule.yyinstrucao = 20;
			yyclosure_instrucao(a, c + 0);
		}
		break;
	case 322: /* BODY */
		return;
	case 323: /* JZ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instrucao: JZ(expressao,ETIQ) */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 6;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(LT(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 306 && /* LT */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 8;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(LE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 283 && /* LE */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 9;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(GT(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 307 && /* GT */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 10;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(GE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 282 && /* GE */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 11;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(EQ(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 284 && /* EQ */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 12;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(NE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 285 && /* NE */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 13;
				yyclosure_instrucao(a, c + 0);
			}
		}
		break;
	case 324: /* ETIQ */
		return;
	case 325: /* LABEL */
		/* instrucao: LABEL */
		if (1 + 0 < p->cost[yyinstrucao_NT]) {
			p->cost[yyinstrucao_NT] = 1 + 0;
			p->rule.yyinstrucao = 2;
			yyclosure_instrucao(a, 1 + 0);
		}
		break;
	case 326: /* JNZ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instrucao: JNZ(expressao,ETIQ) */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 7;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(LT(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 306 && /* LT */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 14;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(LE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 283 && /* LE */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 15;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(GT(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 307 && /* GT */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 16;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(GE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 282 && /* GE */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 17;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(EQ(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 284 && /* EQ */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 18;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(NE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 285 && /* NE */
			OP_LABEL(RIGHT_CHILD(a)) == 324 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 19;
				yyclosure_instrucao(a, c + 0);
			}
		}
		break;
	case 327: /* JMP */
		/* instrucao: JMP */
		if (1 + 0 < p->cost[yyinstrucao_NT]) {
			p->cost[yyinstrucao_NT] = 1 + 0;
			p->rule.yyinstrucao = 5;
			yyclosure_instrucao(a, 1 + 0);
		}
		break;
	case 328: /* INSTRS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* instrucoes: INSTRS(instrucoes,instrucao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrucoes_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrucao_NT] + 0;
		if (c + 0 < p->cost[yyinstrucoes_NT]) {
			p->cost[yyinstrucoes_NT] = c + 0;
			p->rule.yyinstrucoes = 1;
			yyclosure_instrucoes(a, c + 0);
		}
		break;
	case 329: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: UMINUS(expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 7;
			yyclosure_expressao(a, c + 0);
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
	case 61: /* stack: NIL */
	case 56: /* lvalue: IDENTIF */
	case 32: /* expressao: CALL(IDENTIF) */
	case 29: /* expressao: STRN */
	case 28: /* expressao: INT */
	case 12: /* instrucao: JMP */
	case 9: /* instrucao: LABEL */
	case 5: /* pars2: IDENTIF */
	case 4: /* pars2: PARS2 */
	case 1: /* corpo: NIL */
		break;
	case 60: /* stack: expressao */
	case 58: /* lvalue2: lvalue */
	case 55: /* dupexp: expressao */
	case 30: /* expressao: lvalue */
	case 11: /* instrucao: corpo */
	case 10: /* instrucao: expressao */
	case 7: /* instrucoes: instrucao */
	case 2: /* corpo: instrucoes */
		kids[0] = p;
		break;
	case 59: /* stack: EXPS(stack,stack) */
	case 57: /* lvalue: VECTOR(lvalue2,expressao) */
	case 50: /* expressao: OR(expressao,expressao) */
	case 49: /* expressao: AND(expressao,expressao) */
	case 48: /* expressao: LE(expressao,expressao) */
	case 47: /* expressao: GE(expressao,expressao) */
	case 46: /* expressao: NE(expressao,expressao) */
	case 45: /* expressao: EQ(expressao,expressao) */
	case 44: /* expressao: LT(expressao,expressao) */
	case 43: /* expressao: GT(expressao,expressao) */
	case 42: /* expressao: SUBT(expressao,expressao) */
	case 41: /* expressao: ADD(expressao,expressao) */
	case 40: /* expressao: MOD(expressao,expressao) */
	case 39: /* expressao: DIV(expressao,expressao) */
	case 38: /* expressao: MUL(expressao,expressao) */
	case 37: /* expressao: SHIFT(expressao,expressao) */
	case 33: /* expressao: ATRIB(dupexp,lvalue) */
	case 27: /* instrucao: MALL(lvalue,expressao) */
	case 8: /* instrucao: LIST(instrucao,instrucao) */
	case 6: /* instrucoes: INSTRS(instrucoes,instrucao) */
	case 3: /* corpo: PINTR(pars2,instrucoes) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 54: /* expressao: POINTER(lvalue) */
	case 53: /* expressao: ADDR(lvalue) */
	case 52: /* expressao: FACT(expressao) */
	case 51: /* expressao: NEG(expressao) */
	case 36: /* expressao: DEC(lvalue) */
	case 35: /* expressao: INC(lvalue) */
	case 34: /* expressao: UMINUS(expressao) */
	case 14: /* instrucao: JNZ(expressao,ETIQ) */
	case 13: /* instrucao: JZ(expressao,ETIQ) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 26: /* instrucao: JNZ(NE(expressao,expressao),ETIQ) */
	case 25: /* instrucao: JNZ(EQ(expressao,expressao),ETIQ) */
	case 24: /* instrucao: JNZ(GE(expressao,expressao),ETIQ) */
	case 23: /* instrucao: JNZ(GT(expressao,expressao),ETIQ) */
	case 22: /* instrucao: JNZ(LE(expressao,expressao),ETIQ) */
	case 21: /* instrucao: JNZ(LT(expressao,expressao),ETIQ) */
	case 20: /* instrucao: JZ(NE(expressao,expressao),ETIQ) */
	case 19: /* instrucao: JZ(EQ(expressao,expressao),ETIQ) */
	case 18: /* instrucao: JZ(GE(expressao,expressao),ETIQ) */
	case 17: /* instrucao: JZ(GT(expressao,expressao),ETIQ) */
	case 16: /* instrucao: JZ(LE(expressao,expressao),ETIQ) */
	case 15: /* instrucao: JZ(LT(expressao,expressao),ETIQ) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		break;
	case 31: /* expressao: CALL2(IDENTIF,stack) */
		kids[0] = RIGHT_CHILD(p);
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
	case 1: /* corpo: NIL */
#line 40 "factorial.brg"

		break;
	case 2: /* corpo: instrucoes */
#line 41 "factorial.brg"

		break;
	case 3: /* corpo: PINTR(pars2,instrucoes) */
#line 42 "factorial.brg"

		break;
	case 4: /* pars2: PARS2 */
#line 44 "factorial.brg"

		break;
	case 5: /* pars2: IDENTIF */
#line 45 "factorial.brg"

		break;
	case 6: /* instrucoes: INSTRS(instrucoes,instrucao) */
#line 47 "factorial.brg"

		break;
	case 7: /* instrucoes: instrucao */
#line 48 "factorial.brg"

		break;
	case 8: /* instrucao: LIST(instrucao,instrucao) */
#line 50 "factorial.brg"

		break;
	case 9: /* instrucao: LABEL */
#line 51 "factorial.brg"
{ fprintf(outfp, pfLABEL, p->value.s); }
		break;
	case 10: /* instrucao: expressao */
#line 52 "factorial.brg"
{ fprintf(outfp, pfTRASH, 4); }
		break;
	case 11: /* instrucao: corpo */
#line 53 "factorial.brg"

		break;
	case 12: /* instrucao: JMP */
#line 54 "factorial.brg"
{ fprintf(outfp, pfJMP, p->value.s); }
		break;
	case 13: /* instrucao: JZ(expressao,ETIQ) */
#line 55 "factorial.brg"
{ fprintf(outfp, pfJZ, p->SUB(1)->value.s); }
		break;
	case 14: /* instrucao: JNZ(expressao,ETIQ) */
#line 56 "factorial.brg"
{ fprintf(outfp, pfJNZ, p->SUB(1)->value.s); }
		break;
	case 15: /* instrucao: JZ(LT(expressao,expressao),ETIQ) */
#line 57 "factorial.brg"
{ fprintf(outfp, pfJGE, p->SUB(1)->value.s); }
		break;
	case 16: /* instrucao: JZ(LE(expressao,expressao),ETIQ) */
#line 58 "factorial.brg"
{ fprintf(outfp, pfJGT, p->SUB(1)->value.s); }
		break;
	case 17: /* instrucao: JZ(GT(expressao,expressao),ETIQ) */
#line 59 "factorial.brg"
{ fprintf(outfp, pfJLE, p->SUB(1)->value.s); }
		break;
	case 18: /* instrucao: JZ(GE(expressao,expressao),ETIQ) */
#line 60 "factorial.brg"
{ fprintf(outfp, pfJLT, p->SUB(1)->value.s); }
		break;
	case 19: /* instrucao: JZ(EQ(expressao,expressao),ETIQ) */
#line 61 "factorial.brg"
{ fprintf(outfp, pfJNE, p->SUB(1)->value.s); }
		break;
	case 20: /* instrucao: JZ(NE(expressao,expressao),ETIQ) */
#line 62 "factorial.brg"
{ fprintf(outfp, pfJEQ, p->SUB(1)->value.s); }
		break;
	case 21: /* instrucao: JNZ(LT(expressao,expressao),ETIQ) */
#line 63 "factorial.brg"
{ fprintf(outfp, pfJLT, p->SUB(1)->value.s); }
		break;
	case 22: /* instrucao: JNZ(LE(expressao,expressao),ETIQ) */
#line 64 "factorial.brg"
{ fprintf(outfp, pfJLE, p->SUB(1)->value.s); }
		break;
	case 23: /* instrucao: JNZ(GT(expressao,expressao),ETIQ) */
#line 65 "factorial.brg"
{ fprintf(outfp, pfJGT, p->SUB(1)->value.s); }
		break;
	case 24: /* instrucao: JNZ(GE(expressao,expressao),ETIQ) */
#line 66 "factorial.brg"
{ fprintf(outfp, pfJGE, p->SUB(1)->value.s); }
		break;
	case 25: /* instrucao: JNZ(EQ(expressao,expressao),ETIQ) */
#line 67 "factorial.brg"
{ fprintf(outfp, pfJEQ, p->SUB(1)->value.s); }
		break;
	case 26: /* instrucao: JNZ(NE(expressao,expressao),ETIQ) */
#line 68 "factorial.brg"
{ fprintf(outfp, pfJNE, p->SUB(1)->value.s); }
		break;
	case 27: /* instrucao: MALL(lvalue,expressao) */
#line 69 "factorial.brg"
{ fprintf(outfp, pfALLOC);}
		break;
	case 28: /* expressao: INT */
#line 71 "factorial.brg"
{ fprintf(outfp, pfIMM, p->value.i); printf("INT: %d\n", p->value.i);}
		break;
	case 29: /* expressao: STRN */
#line 72 "factorial.brg"
{ int l = ++lbl; char *s = p->value.s;
                                              fprintf(outfp, pfRODATA pfALIGN pfLABEL, mklbl(l));
                                              do fprintf(outfp, pfCHAR, (unsigned char)*s); while (*s++ != 0);
                                              fprintf(outfp, pfTEXT pfADDR, mklbl(l)); }
		break;
	case 30: /* expressao: lvalue */
#line 76 "factorial.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 31: /* expressao: CALL2(IDENTIF,stack) */
#line 77 "factorial.brg"
{ fprintf(outfp, pfCALL pfTRASH pfPUSH, p->SUB(0)->value.s, stk); printf("CALL2- 2 args\n"); stk = 0;}
		break;
	case 32: /* expressao: CALL(IDENTIF) */
#line 78 "factorial.brg"
{ fprintf(outfp, pfCALL pfPUSH, p->SUB(0)->value.s); printf("CALL\n");}
		break;
	case 33: /* expressao: ATRIB(dupexp,lvalue) */
#line 79 "factorial.brg"
{ fprintf(outfp, pfSTORE); printf("STORE: %d\n", p->SUB(0)->value.i);}
		break;
	case 34: /* expressao: UMINUS(expressao) */
#line 80 "factorial.brg"
{ fprintf(outfp, pfNEG); printf("UMINUS: %d\n", p->SUB(0)->value.i);}
		break;
	case 35: /* expressao: INC(lvalue) */
#line 81 "factorial.brg"
{ fprintf(outfp, pfINCR, 1);}
		break;
	case 36: /* expressao: DEC(lvalue) */
#line 82 "factorial.brg"
{ fprintf(outfp, pfDECR, 1);}
		break;
	case 37: /* expressao: SHIFT(expressao,expressao) */
#line 83 "factorial.brg"
{ fprintf(outfp, pfSHTL); }
		break;
	case 38: /* expressao: MUL(expressao,expressao) */
#line 84 "factorial.brg"
{ fprintf(outfp, pfMUL); }
		break;
	case 39: /* expressao: DIV(expressao,expressao) */
#line 85 "factorial.brg"
{ fprintf(outfp, pfDIV); }
		break;
	case 40: /* expressao: MOD(expressao,expressao) */
#line 86 "factorial.brg"
{ fprintf(outfp, pfMOD); }
		break;
	case 41: /* expressao: ADD(expressao,expressao) */
#line 87 "factorial.brg"
{ fprintf(outfp, pfADD); }
		break;
	case 42: /* expressao: SUBT(expressao,expressao) */
#line 88 "factorial.brg"
{ fprintf(outfp, pfSUB); }
		break;
	case 43: /* expressao: GT(expressao,expressao) */
#line 89 "factorial.brg"
{ fprintf(outfp, pfGT); }
		break;
	case 44: /* expressao: LT(expressao,expressao) */
#line 90 "factorial.brg"
{ fprintf(outfp, pfLT); }
		break;
	case 45: /* expressao: EQ(expressao,expressao) */
#line 91 "factorial.brg"
{ fprintf(outfp, pfEQ); }
		break;
	case 46: /* expressao: NE(expressao,expressao) */
#line 92 "factorial.brg"
{ fprintf(outfp, pfNE); }
		break;
	case 47: /* expressao: GE(expressao,expressao) */
#line 93 "factorial.brg"
{ fprintf(outfp, pfGE); }
		break;
	case 48: /* expressao: LE(expressao,expressao) */
#line 94 "factorial.brg"
{ fprintf(outfp, pfLE); }
		break;
	case 49: /* expressao: AND(expressao,expressao) */
#line 95 "factorial.brg"
{ char *l = mklbl(++lbl); 
                                             fprintf(outfp, pfSWAP pfDUP pfJZ pfTRASH pfLABEL pfSWAP pfTRASH, l, 4, l, 4); }
		break;
	case 50: /* expressao: OR(expressao,expressao) */
#line 97 "factorial.brg"
{ char *l = mklbl(++lbl); 
                                             fprintf(outfp, pfSWAP pfDUP pfJNZ pfTRASH pfLABEL pfSWAP pfTRASH, l, 4, l, 4);  }
		break;
	case 51: /* expressao: NEG(expressao) */
#line 99 "factorial.brg"
{ fprintf(outfp, pfIMM pfEQ, 0);}
		break;
	case 52: /* expressao: FACT(expressao) */
#line 100 "factorial.brg"

		break;
	case 53: /* expressao: ADDR(lvalue) */
#line 101 "factorial.brg"
{ /* empty */ }
		break;
	case 54: /* expressao: POINTER(lvalue) */
#line 102 "factorial.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 55: /* dupexp: expressao */
#line 105 "factorial.brg"
{ fprintf(outfp, pfDUP); }
		break;
	case 56: /* lvalue: IDENTIF */
#line 107 "factorial.brg"
{ if (p->user == GLOBAL)
                          {fprintf(outfp, pfADDR, p->value.s); printf("GLOBAL - %s\n", p->value.s);}
                        else
                          {fprintf(outfp, pfLOCAL, p->user); printf("LOCAL - %d (%s) \n", p->user, p->value.s);}
                    }
		break;
	case 57: /* lvalue: VECTOR(lvalue2,expressao) */
#line 112 "factorial.brg"
{fprintf(outfp, pfIMM pfMUL pfADD, 4);printf("VECTOR - lvalue\n");}
		break;
	case 58: /* lvalue2: lvalue */
#line 114 "factorial.brg"
{ fprintf(outfp, pfLOAD); printf("LOAD - lvalue - %d\n", p->user); }
		break;
	case 59: /* stack: EXPS(stack,stack) */
#line 116 "factorial.brg"

		break;
	case 60: /* stack: expressao */
#line 117 "factorial.brg"
{ stk += 4; printf("a stack %d\n", stk);}
		break;
	case 61: /* stack: NIL */
#line 118 "factorial.brg"
{ stk = 0; printf("o nil\n");}
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yycorpo == 0) {
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 120 "factorial.brg"


void function(char *name, int enter, Node *body) {
  int i;
  int tipo = IDfind(name, 0);

  if (tipo >= 32) 
      tipo -= 32;

  extern int trace;

  if(trace) printNode(body, stdout, yynames);
  if (body == 0 || body->attrib == NIL) /* forward declaration */
    fprintf(outfp, pfEXTRN, name);
  else { /* function body */
    if (strcmp(name, "entry") == 0) // para a funcao entry
      fprintf(outfp, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, "_entry", pfFUNC, "_entry", enter);
    else
    fprintf(outfp, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, name, pfFUNC, name, enter);
    if (yyselect(body) == 1) yyerror("No match for syntactic tree.");
    if(tipo != 0)
    { fprintf(outfp, pfLOCAL pfLOAD pfPOP pfLEAVE pfRET, -4);}

    else fprintf(outfp, pfLEAVE pfRET); /* just in case there is no 'return' */
  }
}


void declare(char *name, Node * value) {
  int tipo = IDfind(name, 0);

  if (tipo == 0 || value == 0)
    fprintf(outfp, pfBSS pfALIGN pfLABEL pfBYTE pfTEXT, name, 4);
  else {
    if ((tipo & 0x15) >= 9) fprintf(outfp, pfRODATA);    //CONS
    else fprintf(outfp, pfDATA);

    fprintf(outfp, pfALIGN);

    if ((tipo & 0x31) >= 17){                            //PUBLIC
      if ((tipo & 0x3) == 1) fprintf(outfp, pfGLOBL, name, pfINTEGER);
      else if ((tipo & 0x3) == 2) fprintf(outfp, pfGLOBL, name, pfSTR);
    }
    
    fprintf(outfp, pfLABEL, name);

    if ((tipo & 0x7) >= 5) fprintf(outfp, pfID, value->value.s);  //PTR
    else if ((tipo & 0x3) == 1) fprintf(outfp, pfINTEGER, value->value.i);
    else if ((tipo & 0x3) == 1) fprintf(outfp, pfSTR, value->value.s);

    fprintf(outfp, pfTEXT);
  }
}