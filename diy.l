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
<iCOM>[^=>]+	; /* Ignore any tokens inside except other comments */
<iCOM>"=<"		comment_nest++;
<iCOM>"=>"		if (--comment_nest == 0) BEGIN 0;

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

([1-9][0-9]*|0)	{
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

\"([^*"]|\*.)*\"								yylval.s = malloc(yyleng); *yylval.s = 0; REJECT; /* Allows concatenation */
\"												BEGIN iSTR;
<iSTR>["]{1}									BEGIN 0; return STRING;
<iSTR>[0-9A-Za-z\u00C0-\u00D5\u00D8-\u00f0]+	strcat(yylval.s, yytext); /* Best range I figured for ISO-LATIN-15 */
<iSTR>\\\"{1}									strcat(yylval.s, yytext); /* Allow slash */
<iSTR>"\n"|"\r"|"\t"							strcat(yylval.s, yytext); /* Allow LF, CR and HT */
<iSTR>\\\*[0-9a-fA-F]{1,2}						strcat(yylval.s, yytext); /* Allow hex digits */
<iSTR>\x0|"0"									strcat(yylval.s, yytext); /* NULL or ZERO */
<iSTR>.|\n										strcat(yylval.s, yytext); /* Absorb redundancies 	printf("%d.%lfe%d", yylval.i, yylval.fp, yylval.exp);*/

(([1-9][0-9]*|0){1}\.{1}[0-9]+(\e[0-9]+)*)	{
	errno = 0;

	char *parseFloat = strtok(yytext, ".");
	parseFloat = strtok(NULL, ".");

	char *parseExponential = strtok(parseFloat, "e");
	parseExponential = strtok(NULL, "e");

	yylval.i = strtol(yytext, NULL, 10);
	yylval.fp = strtol(parseFloat, NULL, 10);

	if( parseExponential != NULL )
		yylval.exp = strtol(parseExponential, NULL, 10);

	if (errno == ERANGE) yyerror("Real overflow.");
	return REAL;
}

.									yyerror("Unknown character.");
%%

void yyerror (char *s) {
	fprintf(stderr, "%s\n", s);
}

char *getyytext() { return yytext; }