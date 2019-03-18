%{
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"
void yyerror(char *s);
%}
%%
"for"			return FOR;
[0-9]+			yylval.i = strtol(yytext, 0, 10); return INT;
.			yyerror("Unknown character");
%%
int yywrap(void) { return 1; }
char *getyytext() { return yytext; }
