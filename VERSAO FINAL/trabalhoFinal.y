%{

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


#define GetCurrentDir getcwd

extern  FILE *yyin;
void yyerror(const char * s);

extern int yylex();
extern int yyparse();

char *auxTermo = NULL;
char outfileName[] = "input_code.txt";
extern int lineCounter;

struct listIds *codeList = NULL;
struct listIds *simbTab = NULL;
int cont = 1, auxIds = 1, lines = 1, cont2 = 3, labels = 0;

char *fileName = "output.j";
FILE *file;


%}

%union{
    int ival;
    float fval;
    int bval;
    char * idval;
    char * aopval;

    struct listIds{
		int num;
        char *nome;
        struct listIds *prox;
    };
    struct valorar *a;

    struct listIds *id;
    
	struct {
		int **trueList, **falseList;
	} bexpr_type;
	struct {
		int **nextList;
	} stmt_type;
	int sType;

}

/* Declaração dos tokens... */

%token <ival> T_INT
%token <fval> T_REAL
%token <bval> T_BOOL
%token IF_WORD THEN_WORD ELSE_WORD 
%token PROGRAM_WORD
%token WHILE_WORD DO_WORD FOR_WORD
%token BEGIN_WORD END_WORD
%token VAR_WORD
%token ARRAY_WORD OF_WORD
%token <ival> INT
%token <fval> FLOAT
%token <bval> BOOL
%token <idval> IDENTIFIER
%token <aopval> OPAD
%token <aopval> OPMUL 
%token <aopval> RELATIONAL 
%token SEMI_COLON PONTO_PONTO VIRGULA DOIS_PONTOS
%token ATRIBUICAO
%token RIGHT_BRACKET LEFT_BRACKET
%token COLCHETES_FECHA COLCHETES_ABRE
%token READ_WORD PRINT_WORD
%token ASPAS 

%type <sType> tipoSimples
%type <id> listaIds
%type <idval> variavel
%type <ival> intlit
%type <fval> floatlit
%type <bval> boollit
%type <a> literal
%type <a> fator
%type <aopval> termo
%type <aopval> opmul 

%start programa

%%

programa:   {generateHeader();}
         PROGRAM_WORD IDENTIFIER SEMI_COLON corpo  {printf("Programa\n");}
        ;


corpo: declaracoes comandoComposto       {printf("corpo\n");}
     ;
     
comandoComposto: BEGIN_WORD   {printf("comando composto\n");}
                 listaDeComandos
                 END_WORD    { generateFooter();}
               ;

declaracoes: declaracoesaux declaracaoDeVariavel SEMI_COLON
           | vazio               {printf("declaracoes\n");}
           ;

declaracoesaux: declaracoes
              ;

//string str($2);
declaracaoDeVariavel: VAR_WORD listaIds DOIS_PONTOS tipo {printf("Declaracao de Variavel");}
;


listaDeComandos: listaComandosaux comando SEMI_COLON
               | vazio                       {printf("lista de comandos\n");}
               ;
listaComandosaux: listaDeComandos
                ;

comando: atribuicao                                      {printf("comando\n");}
       | condicional                                     {printf("comando\n");}
       | comandoComposto                                 {printf("comando\n");}
       | comandoFor                                      {printf("comando\n");}
       | comandoWhile                                    {printf("comando\n");}
       | print                                           {printf("comando\n");}
       | read                                            {printf("comando\n");}
       ;

listaIds: IDENTIFIER                         {printf("IDENTIFIER");}
        | listaIds VIRGULA IDENTIFIER        {printf("IDENTIFIER");}
        ;

atribuicao: variavel ATRIBUICAO fator
            |variavel  ATRIBUICAO  expressaoSimples            { printf("atribuicao\n");}
          ;

condicional: IF_WORD expressao THEN_WORD comando condicionalAUX {printf("condicional\n");}
           ;

condicionalAUX: ELSE_WORD comando SEMI_COLON                                  {printf("condicionalAUX\n");}
              | SEMI_COLON 
              ;

comandoWhile: DO_WORD listaDeComandos WHILE_WORD LEFT_BRACKET expressao RIGHT_BRACKET SEMI_COLON   {printf("comando While\n");}
            ;

comandoFor: FOR_WORD LEFT_BRACKET atribuicao SEMI_COLON expressaoSimples RELATIONAL expressaoSimples SEMI_COLON expressaoSimples SEMI_COLON RIGHT_BRACKET  listaDeComandos SEMI_COLON  {printf("comando For\n");}
          ;

expressao: expressaoSimples                              {printf("expressao\n");}
         | expressao RELATIONAL expressao  {printf("expressao\n");}
         ;


expressaoSimples: expressaoSimples OPAD termo       {printf("EXP SIMPLES \n");}
                | termo                             {printf("EXP SIMPLES \n");}
                ;

literal: intlit                                       {printf("Atribuido int\n");}
       | floatlit                                     {printf("Atribuido float\n");}
       | boollit                                      {printf("Atribuido bool\n");}
       ;


intlit: INT {$$ = $1;}
      ;

floatlit: FLOAT {$$ = $1;}
        ;

boollit: BOOL {$$ = $1;}
       ;


fator: variavel                                    {printf("VARIAVEL \n");}

     | literal                                      {printf("literal \n");$$ = $1;}
     | LEFT_BRACKET expressao RIGHT_BRACKET         {printf("expressao \n");}
    ;

seletor: seletoraux COLCHETES_ABRE expressao  COLCHETES_FECHA
       | vazio               {printf("vazio \n");}
       ;

seletoraux: seletor
          ;

termo: termo opmul fator {printf("TERMO\n"); }
    | fator              {printf("TERMO - FATOR\n");} 
    ;

opmul: OPMUL   {$$ = $1;}
    ;

agregadoAux: COLCHETES_ABRE lit COLCHETES_FECHA   {printf("agregado Aux \n");}
    ;

lit: lit VIRGULA literal
   | literal
   ;

tipo: tipoAgregado  {printf("TIPO \n");}
    |tipoSimples   {printf("TIPO \n");}
    ;

tipoAgregado: ARRAY_WORD agregadoAux OF_WORD tipo  {printf("TIPO AGREGADO\n");}
    ;

tipoSimples: T_INT {$$=T_INT;printf("TIPO INT\n");}
    | T_REAL       {$$=T_REAL;printf("TIPO REAL\n");}
    | T_BOOL       {$$=T_BOOL;printf("TIPO BOOL\n");}
    ;

variavel: IDENTIFIER seletor {printf("Variavel\n");$$ = $1;}
        ;



vazio: {printf("Vazio\n");}
    ;



print: PRINT_WORD LEFT_BRACKET ASPAS idd ASPAS RIGHT_BRACKET
    ;

idd: idd IDENTIFIER
   | IDENTIFIER
   | idd variavel
   | variavel
   | expressao
   | idd expressao
   ;

read: READ_WORD LEFT_BRACKET IDENTIFIER RIGHT_BRACKET  {printf("read\n");}
    ;

%%



int main(int argv, char * argc[]) {
	FILE *myfile;
    file = fopen("output.j","w+");
	if(argv == 1) 
	{
		myfile = fopen("input_code.txt", "r");
	}
	if (!myfile) {
		printf("I can't open input code file!\n");
		char cCurrentPath[200];
		 if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
		     {
		     return -1;
		     }
		printf("%s\n",cCurrentPath);  
				getchar();

		return -1;

	}
	yyin = myfile;
	yyparse();
}

void yyerror(const char* s) {
	fprintf(stderr, "Erro de análise (sintática, Linha: %d): %s\n", lineCounter, s);
	exit(1);
}

void generateHeader()
{   
    fprintf(file,".source %s\n",outfileName);
	fprintf(file,".class public test\n.super java/lang/Object\n\n"); //code for defining class
	
    fprintf(file,".method public <init>()V \n");
	fprintf(file,"aload_0\n");
	fprintf(file,"invokenonvirtual java/lang/Object/<init>()V\n");
	fprintf(file,"return\n");
	fprintf(file,".end method\n\n");

	fprintf(file,".method public static main([Ljava/lang/String;)V\n");
	fprintf(file,".limit locals 100\n.limit stack 100\n");

	/* generate temporal vars for syso*/
	defineVar("1syso_int_var",T_INT);
	defineVar("1syso_float_var",T_REAL);
    printLine();
}

void generateFooter()
{
	fprintf(file,"\nreturn\n");
	fprintf(file,".end method\n");
}
 
void defineVar(char *id, int type){
    if(type == T_INT){
        fprintf(file, "iconst_0\nistore %i\n", cont);
    }else if(type == T_BOOL){
        fprintf(file, "iconst_0\nistore %i\n", cont);
    }else if(type == T_REAL){
        fprintf(file, "fconst_0\nfstore %i\n", cont);
    }
    cont++;
}

void printLine(){
    fprintf(file, ".line %i\n", lines);
    lines++;
}

void printSimb(){
    struct listIds *p;
    p = simbTab;
    while(p != NULL){
        printf("%i- %s\n",p->num, p->nome);
        p=p->prox;
    }
}

int findVar(char *nome){
    struct listIds *p;
    p = simbTab;
    while(p!=NULL){
        if(strcmp(p->nome, nome)==0){
            return p->num;
        }
        p = p->prox;
    }
    return -1;
}

void printnoj(int var){
    fprintf(file, "istore %i\n", var);
    fprintf(file, "getstatic      java/lang/System/out Ljava/io/PrintStream;");
    fprintf(file, "iload %i", var);
    fprintf(file, "invokevirtual java/io/PrintStream/println(I)V");

}
