#ifndef BURG_INCLUDED

#define BURG_INCLUDED



/* $Id: pburg.h,v 2.1 2011/12/22 21:53:18 drh Exp $ */

/* iburg.c: */

extern void *alloc(int nbytes);



typedef enum { TERM=1, NONTERM } Kind;

typedef struct rule *Rule;

typedef struct term *Term;

struct term {		/* terminals: */

	char *name;		/* terminal name */

	Kind kind;		/* TERM */

	int esn;		/* external symbol number */

	int arity;		/* operator arity */

	Term link;		/* next terminal in esn order */

	Rule rules;		/* rules whose pattern starts with term */

};



typedef struct nonterm *Nonterm;

struct nonterm {	/* nonterminals: */

	char *name;		/* nonterminal name */

	Kind kind;		/* NONTERM */

	int number;		/* identifying number */

	int lhscount;		/* # times nt appears in a rule lhs */

	int reached;		/* 1 iff reached from start nonterminal */

	Rule rules;		/* rules w/nonterminal on lhs */

	Rule chain;		/* chain rules w/nonterminal on rhs */

	Nonterm link;		/* next terminal in number order */

};

extern Nonterm nonterm(char *id);

extern Term term(char *id, int esn);



typedef struct tree *Tree;

struct tree {		/* tree patterns: */

	void *op;		/* a terminal or nonterminal */

	Tree left, right;	/* operands */

	int nterms;		/* number of terminal nodes in this tree */

};

extern Tree tree(char *op, Tree left, Tree right);



struct rule {		/* rules: */

	Nonterm lhs;		/* lefthand side nonterminal */

	Tree pattern;		/* rule pattern */

	int ern;		/* external rule number */

	int packed;		/* packed external rule number */

	int cost;		/* cost, if a constant */

	char *code;		/* cost, if an expression */

	char *template;		/* assembler template */

	int lineno;		/* first line of assembler template */

	Rule link;		/* next rule in ern order */

	Rule next;		/* next rule with same pattern root */

	Rule chain;		/* next chain rule with same rhs */

	Rule decode;		/* next rule with same lhs */

	Rule kids;		/* next rule with same _kids pattern */

};

extern Rule rule(char *id, Tree pattern, char *template, char *code, int line);



/* gram.y: */

void yyerror(char *fmt, ...);

int yyparse(void);

void yywarn(char *fmt, ...);

extern int errcnt;

extern FILE *yyin;

extern FILE *outfp;



#endif

