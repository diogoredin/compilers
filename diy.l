%option stack noyywrap yylineno 8bit

%{
#include <stdlib.h> 
#include <string.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"

void yyerror(char *s);
char *dupstr(const char *s);
%}

%X dCMT dSTR

%%

"--".*				;
[ \t\n]+			;

\=<					BEGIN(dCMT);
<dCMT>(.|\n)		;
<dCMT>=>			BEGIN(INITIAL);

\"				BEGIN dSTR;
<dSTR>\"		BEGIN 0; return STRING;
<dSTR>"*n"		strcat(yylval.s, "\n");
<dSTR>"*t"		strcat(yylval.s, "\t");
<dSTR>"*0"		strcat(yylval.s, "\0");
<dSTR>"*("		strcat(yylval.s, "{");
<dSTR>"*)"		strcat(yylval.s, "}");
<dSTR>\*[*'"]	strcat(yylval.s, yytext+1);
<dSTR>\*.		yyerror("Invalid escape sequence in string.");
<dSTR>.|\n		strcat(yylval.s, yytext);

"void"			return PRINT;
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

[0-9]+			yylval.i = strtol(yytext, 0, 10);		return INT;
[a-zA-Z_\b][a-zA-Z_\b0-9]* yylval.s = dupstr(yytext);	return ID;

.				yyerror("Unknown character.");
%%

void yyerror (char *s) {
	fprintf(stderr, "%s\n", s);
}

char *getyytext() { return yytext; }