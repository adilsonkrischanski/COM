%option noyywrap

%{
    #include "y.tab.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

    #define YY_DECL int yylex()

	int lineCounter = 1;

/* Linguagem: Pascal-like */


/* ========================================================================== */
/* =========================== Sessão DEFINIÇÔES ========================== */
/* ========================================================================== */

%}

DIGITO [0-9]
DIGITOS {DIGITO}+
NUMERO "-"?{DIGITOS}
FLOAT "-"?{DIGITOS}.{DIGITOS}("E"{DIGITOS}+)?
LETRA [a-zA-Z]
ID {LETRA}({LETRA}|{DIGITO})*
RELACIONAIS "="|"<>"|">"|">="|"<"|"<="
OP_AD "+"|"-"|"or"
OP_MUL "*"|"/"|"and"
BINARIO "true"|"false"



%%

"integer"    {return T_INT;}
"real"       {return T_REAL;}
"boolean"    {return T_BOOL;}
"if"         {return IF_WORD;}
"then"       {return THEN_WORD;}
"program"    {return PROGRAM_WORD;}
"else"       {return ELSE_WORD;}
"while"	     {return WHILE_WORD;}
"do"	     {return DO_WORD;}
"for"	     {return FOR_WORD;}
"begin"      {return BEGIN_WORD;}
"end"        {return END_WORD;}
"var"        {return VAR_WORD;}
"array"      {return ARRAY_WORD;}
"of"         {return OF_WORD;}
{OP_AD}      {yylval.aopval = strdup(yytext);return OPAD;}
{OP_MUL}     {yylval.aopval = strdup(yytext);return OPMUL;}
{NUMERO}      {yylval.ival = atoi(yytext);return INT;}
{FLOAT}       {yylval.fval = atof(yytext);return FLOAT;}
{ID}          {yylval.idval = strdup(yytext);return IDENTIFIER;}
{RELACIONAIS} {yylval.aopval = strdup(yytext);return RELATIONAL;}
{BINARIO}     {if(!strcmp(yytext,"true")){ yylval.bval = 1;} else { yylval.bval = 0;}return BOOL;}


";"  { return SEMI_COLON;}
":=" {return ATRIBUICAO;}
".." {return PONTO_PONTO;}
":"  {return DOIS_PONTOS;}
","  {return VIRGULA;}
"["  {return COLCHETES_ABRE;}
"]"  {return COLCHETES_FECHA;}
"("  {return LEFT_BRACKET;}
")"  {return RIGHT_BRACKET;}
\n	 {++lineCounter;}

[ \t]+      /* Lembre-se... espaços em branco não tem utilidade! */
. printf( "Erro Léxico: %s (Linha: %d,)\n", yytext, lineCounter );

    
%%
