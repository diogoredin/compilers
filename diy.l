%{
#include <stdlib.h> 
#include <string.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"

void yyerror(char *s);
char *dupstr(const char *s);

int comment_nest = 0;
%}

%X iCOM iSTR

%%

"=<"			BEGIN(iCOM); comment_nest++;
<iCOM>[^*/]*	; /* Ignore any tokens inside except other comments */
<iCOM>"=<"		comment_nest++;
<iCOM>"=>"		if (--comment_nest == 0) BEGIN 0;
<iCOM>[=>]		; /* Already decreased nest so nothing to do */

==.*			;
[ \n\r\t]+		;

"void"			return VOID;
"integer"		return INTEGER;
"string"		return STRING;
"public"		return PUBLIC;
"number"		return NUMBER;
"const"			return CONST;
"if"			return IF;
"then"			return THEN;
"else"			return ELSE;
"while"			return WHILE;
"do"			return DO;
"for"			return FOR;
"in"			return IN;
"step"			return STEP;
"upto"			return UPTO;
"downto"		return DOWNTO;
"break"			return BREAK;
"continue"		return CONTINUE;

.				yyerror("Unknown character.");
%%

void yyerror (char *s) {
	fprintf(stderr, "%s\n", s);
}

char *getyytext() { return yytext; }