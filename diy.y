%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
extern int yylex();
void yyerror(char *s);
%}

%union {
	int i;			/* integer value */
};

%token <i> INT
%token FOR
%%
file	:
	;
%%
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
