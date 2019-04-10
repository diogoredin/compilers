%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "tabid.h"

extern int yylex();
int yyerror(char *s);
extern FILE *yyin;

static char buf[80];
static int gt, pos, dim(Node*);
static void *gtr, *root, *swr, gotos();
static Node *name(Node*), *swf(Node*), *swg(int pop);

%}

%union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* tree node */
};

%token <i> INT
%token <r> REAL
%token <s> ID STR

%token DO WHILE IF THEN FOR IN UPTO DOWNTO STEP BREAK CONTINUE
%token VOID INTEGER STRING NUMBER CONST PUBLIC INCR DECR
%token ATR NE GE LE ELSE

%%

file : decl

decl : type ID init
	| type ID
	| type '*' ID init
	| type '*' ID
	| PUBLIC type '*' ID init
	| PUBLIC type '*' ID
	| PUBLIC type ID init
	| PUBLIC type ID
	| PUBLIC CONST type ID init
	| PUBLIC CONST type ID
	| PUBLIC CONST type '*' ID init
	| PUBLIC CONST type '*' ID
	| CONST type ID init
	| CONST type ID
	| CONST type '*' ID init
	| CONST type '*' ID
	;

type : INTEGER
	| STRING
	| NUMBER
	| VOID
	;

init : INT
	| STR
	| CONST STR
	| REAL
	| ID
	;

%%

int yyerror(char *s) { printf("%s\n",s); return 1; }
char *dupstr(const char*s) { return strdup(s); }
int main(int argc, char *argv[]) {
	extern YYSTYPE yylval;
	int tk;
	yyin = fopen(argv[1], "r");
	if ( yyin==NULL ) {
		fclose(yyin);
	} else {
		while (tk = yylex()) {
			if (tk > YYERRCODE)
				printf("%d:\t%s\n", tk, yyname[tk]);
			else
				printf("%d:\t%c\n", tk, tk);
		}
		return 0;
	}
}