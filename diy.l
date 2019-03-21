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
<iCOM>[^=>]*	; /* Ignore any tokens inside except other comments */
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

[a-z][a-z0-9_]*|[A-Z][A-Z0-9_]*		yylval.s = dupstr(yytext); return ID;

([1-9][0-9]*|0) {
	errno = 0; yylval.i = strtol(yytext, NULL, 10);
	if (errno == ERANGE) yyerror("Decimal integer overflow.");
	return INT;
}

(0[0-9]+) {
	errno = 0; yylval.i = strtol(yytext, NULL, 8);
	if (errno == ERANGE) yyerror("Octal integer overflow.");
	return INT;
}

(0b[0-1]+) {
	errno = 0; yylval.i = strtol(yytext, NULL, 2);
	if (errno == ERANGE) yyerror("Binary integer overflow.");
	return INT;
}

.									yyerror("Unknown character.");
%%

void yyerror (char *s) {
	fprintf(stderr, "%s\n", s);
}

char *getyytext() { return yytext; }