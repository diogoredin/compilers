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
extern int yylex();
extern FILE *yyin;
void yyerror(char *s);
%}

%union {
	int i;
	char *s;
};

%token<i> INT
%token<s> ID STR

%token PRINT
%token INTEGER
%token STRING
%token PUBLIC
%token NUMBER
%token CONST
%token IF
%token THEN
%token ELSE
%token WHILE
%token DO
%token FOR
%token IN
%token STEP
%token UPTO
%token DOWNTO
%token BREAK
%token CONTINUE

%%
start:;
%%

char *dupstr(const char*s) { return strdup(s); }

int main(int argc, char *argv[]) {

	yyin = fopen(argv[1], "r");
	
	if ( yyin==NULL ) {
		fclose(yyin);
	} else {
		yyparse();
	}

}