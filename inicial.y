%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "y.tab.h"

#ifndef YYERRCODE
#define YYERRCODE 256
#endif
#define YYDEBUG 1

void yyerror(char *s);
extern int yylex();
extern FILE *yyin;

%}

%union {
	int i;
	float fp;
	int exp;
	char *s;
};

%token<i> INT
%token<s> ID STR
%token<n> REAL
%token VOID INTEGER STRING PUBLIC NUMBER CONST IF THEN ELSE WHILE DO FOR IN STEP UPTO DOWNTO BREAK CONTINUE
%token GE LE NEQ ASSIGN INC DEC LF

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