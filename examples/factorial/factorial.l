%{
/* factorial.l,v 1.0 2013/02/18 12:00:00 */
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "node.h"
#include "y.tab.h"

void yyerror(char *s);
char * octais();
int nested, newline, string_com;
char string[300];
char * buffer;
%}

DECIMAL 0|[1-9][0-9]*
DIG [0-9]+
OCTAL 0([0-9])+
BIN (0b|0B)(0|1)+
EXP [Ee][+-]?{DIG}
REAL {DIG}"."{DIG}({EXP})?
HEXA (0x|0X)[0-9a-fA-Z]+


%x COMMENTS STR

%%

"++"				newline = 0; return INC;
"--"				newline = 0; return DEC;
":="				newline = 0; return ATRIB;
"="					newline = 0; return EQ;
"<<"                 newline = 0; return SHIFT;
">="				newline = 0; return GE;
"<="				newline = 0; return LE;
"<>"				newline = 0; return NE;
"void"				newline = 0; return VOID;
"integer"			newline = 0; return INTEGER;
"string"			newline = 0; return STRING;
"public"			newline = 0; return PUBLIC;
"number"			newline = 0; return NUMBER;
"const"				newline = 0; return CONST;
"if"				newline = 0; return IF;
"then"				newline = 0; return THEN;
"else"				newline = 0; return ELSE;
"elif"              newline = 0; return ELIF;
"while"				newline = 0; return WHILE;
"do"				newline = 0; return DO;
"for"				newline = 0; return FOR;
"in"				newline = 0; return IN;
"step"				newline = 0; return STEP;
"upto"				newline = 0; return UPTO;
"downto"			newline = 0; return DOWNTO;
"break"				newline = 0; return BREAK;
"continue"			newline = 0; return CONTINUE;

"\n"			if(newline) {newline = 0; return ';';}

[ \t\r]+		;	/* ignore whitespace */

"==".*\n		newline = 0;	/*Comentarios linha*/

"=<"					{BEGIN COMMENTS;newline = 0; nested = 0; string_com = 0; /*Comentarios extensos*/}
<COMMENTS>"=<" 				{++nested;}
<COMMENTS>"=>"				{if(--nested <= 0 && string_com == 0) BEGIN INITIAL;}
<COMMENTS>\"				{if(string_com) --string_com; else ++string_com;}
<COMMENTS><<EOF>>			{ yyerror("LEX error: Comments reached of file"); yyterminate(); }
<COMMENTS>.|\n				;

[A-Za-z][A-Za-z0-9_]*		{ yylval.s = strdup(yytext); newline = 1; return IDENTIF; /* Identificador */}

\"						{ BEGIN STR; newline = 1; buffer = (char *) malloc(sizeof(char)); buffer[0] = '\0';}
<STR>\\n					{ buffer = (char *) realloc(buffer, sizeof(char) * (strlen(buffer) + 2)); strcat(buffer, "\n"); }
<STR>\\t					{ buffer = (char *) realloc(buffer, sizeof(char) * (strlen(buffer) + 2)); strcat(buffer, "\t"); }
<STR>\\r					{ buffer = (char *) realloc(buffer, sizeof(char) * (strlen(buffer) + 2)); strcat(buffer, "\r"); }
<STR>\\\"					{ buffer = (char *) realloc(buffer, sizeof(char) * (strlen(buffer) + 2)); strcat(buffer, "\""); }
<STR>([^"\\])|(\\[0-9a-fA-F][0-9a-fA-F]?)	{ buffer = (char *) realloc(buffer, sizeof(char) * (strlen(buffer) + strlen(yytext) + 1)); strcat(buffer, yytext); }
<STR>\"						{ BEGIN INITIAL; yytext[yyleng-1] = 0;
					  			buffer = (char *) realloc(buffer, sizeof(char) * (strlen(buffer) + strlen(yytext) + 1)); 
					 			strcat(buffer, yytext); yylval.s = strdup(buffer); return STRN;}
<STR><<EOF>>				{yyerror("LEX error: String reached end of file");	yyterminate();}
<STR>.						yyerror("LEX error: Unknown character");



{DECIMAL}					{ errno = 0; newline = 1; yylval.i = strtol(yytext, 0, 10); if(errno != ERANGE) return INT;   /* Literal - Decimal */  
						   		else{	
										sprintf(string, "LEX error: Number %s caused overflow", yytext);
										yyerror(string);  
								   }
							}

{OCTAL}						{ errno = 0; newline = 1; yylval.i = strtol(octais(), 0, 8); if(errno != ERANGE) return INT;   /* Literal - Octal */  
							   	else{
										sprintf(string, "LEX error: Number %s caused overflow", yytext);
										yyerror(string); 
								   }
							}

{HEXA}                     { errno = 0; newline = 1; yylval.i = strtol(yytext, 0, 16); if(errno != ERANGE) return INT;   /* Literal - Octal */  
                                else{
                                        sprintf(string, "LEX error: Number %s caused overflow", yytext);
                                        yyerror(string); 
                                   }
                            }                            

{BIN}						{ errno = 0; newline = 1; yylval.i = strtol(yytext, 0, 2); if(errno != ERANGE) return INT;   /* Literal - Binario */  
						   		else{
										sprintf(string, "LEX error: Number %s caused overflow", yytext);
										yyerror(string);  
								   }
							}

{REAL}						{ errno = 0; newline = 1; yylval.d = strtod(yytext, 0); if(errno != ERANGE) return NUM;   /* Literal - Real */
						   		else{
										sprintf(string, "LEX error: Number %s caused overflow", yytext);
										yyerror(string);  
								   }
							}

";"							newline = 0; return *yytext; /* Operadores/Delimitadores especiais*/
[)!]						newline = 1; return *yytext; /* Operadores/Delimitadores especiais*/

[-+*/%<>=|&~]				newline = 0; return *yytext; /* Operadores de expressoes */
[#\[\]{}(,]					newline = 0; return *yytext; /* Delimitadores e separadores */


.							yyerror("Unknown character");

%%
int yywrap(void) { return 1; }
char *getyytext() { return yytext; }

/*--------------overflow -- OCTAIS ---------------------------------------------*/
char *octais(){


    int carry_new, carry_old;
    int i,  size = 1;
    char *letras;

    carry_new = carry_old = 0;

    letras = (char *) malloc (sizeof(yytext));

    sscanf(yytext, "%s", letras);

    printf("%s\n", letras);

    size = strlen(letras) - 1;

    int num[size + 1];

    for (i = size; i >= 0; --i) num[i] = (letras[i]) - 48; /* converte para inteiro */

    for (i = size; i >= 0; --i)
    {
        printf("%d -- entra\n", num[i]);

        if (num[i] > 7)
        {

            carry_new = 1;

            if (num[i] == 9) num[i] = 1 + carry_old;

            else num[i] = 0 + carry_old;

            carry_old = 0;
        }
        if (carry_old == 1)
        {

            if (num[i] == 7)
            {

                carry_new = 1;
                num[i] = 0;

            }
            else num[i]++;

            carry_old = 0;
        }

        /* altera o valor de carry para a proxima iteracao */
        if (carry_new == 1)
        {

            carry_old = carry_new;
            carry_new = 0;

        }
        else carry_new = 0;

        printf("%d -- sai\n", num[i]);
    }

    for (i = size; i >= 0; --i)
    {
        letras[i] = num[i] + 48; /* converte para string */
    }

    printf("%s\n", letras);

    return letras;
}