%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "node.h"
#include "y.tab.h"

#ifndef YYERRCODE
#define YYERRCODE 256
#endif
#define YYDEBUG 1

void evaluate(Node *p);
void yyerror(char *s);
extern int yylex();
extern FILE *yyin;

%}

%union {
	int i;
	char *s;
	Node *n;
};

%token<i> INT
%token<s> ID STR
%token VOID INTEGER STRING PUBLIC NUMBER CONST IF THEN ELSE WHILE DO FOR IN STEP UPTO DOWNTO BREAK CONTINUE

%%
start:;
%%

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