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

char *auxTermo;
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
declaracaoDeVariavel: VAR_WORD listaIds DOIS_PONTOS tipoSimples { 
    struct listIds *l;
    l = $2;
    codeList = NULL;
    while(l != NULL){
        if($4 == T_INT){
            defineVar(l->nome,T_INT);
        }else if ($4 == T_REAL){
            defineVar(l->nome,T_REAL);
        }else if ($4 == T_BOOL){
            defineVar(l->nome,T_BOOL);
        }
        l = l->prox;
    }

}
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
       ;

listaIds: IDENTIFIER                                     {
                struct listIds *p, *a;
                p = (malloc(sizeof(struct listIds)));
                a = (malloc(sizeof(struct listIds)));
                p->num = auxIds -1;
                p->nome = $1;
                p->prox = codeList;
                a->num = cont2;
                cont2++;
                a->nome = p->nome;
                a->prox = simbTab;
                simbTab = a;
                codeList = p;
                auxIds++;
    }
        | listaIds VIRGULA IDENTIFIER                    {
            struct listIds *p,*a;
                p = (malloc(sizeof(struct listIds)));
                a = (malloc(sizeof(struct listIds)));
                p->num = auxIds -1;
                p->nome = $3;
                p->prox = codeList;
                codeList = p;
                a->num = cont2;
                cont2++;
                a->nome = p->nome;
                a->prox = simbTab;
                simbTab = a;
                auxIds = 1;
                $$ = codeList;
    }
        ;

atribuicao: variavel ATRIBUICAO termo                {
    int a = findVar($1);
    if(a != -1){
        fprintf(file, "L_%i:\n", labels);
        fprintf(file, $3);
        fprintf(file, "istore %i\n", a);
        labels++;
    }
    printf("atribuicao\n");}
          ;

condicional: IF_WORD expressao THEN_WORD comando condicionalAUX {printf("condicional\n");}
           ;

condicionalAUX: ELSE_WORD comando SEMI_COLON                                  {printf("condicionalAUX\n");}
              | SEMI_COLON                                        {printf("condicionalAUX\n");}
              ;

comandoWhile: WHILE_WORD expressaoSimples RELATIONAL expressaoSimples DO_WORD comando       {printf("comando While\n");}
            ;

comandoFor: FOR_WORD LEFT_BRACKET atribuicao SEMI_COLON expressaoSimples RELATIONAL expressaoSimples SEMI_COLON atribuicao RIGHT_BRACKET listaDeComandos     {printf("comando For\n");}
          ;

expressao: expressaoSimples                              {printf("expressao\n");}
         | expressaoSimples RELATIONAL expressaoSimples  {printf("expressao\n");}
         ;

expressaoSimples: expressaoSimples OPAD termo       {printf("EXP SIMPLES \n");}
                | termo                             {printf("EXP SIMPLES \n");}
                ;

literal: intlit                                       {printf("Atribuido1\n");
        struct valorar *p;
        p=malloc(sizeof(struct valorar));
        p->valor = $1;
        p->tipo = strdup("INT");
        $$ = p;
        }
       | floatlit                                     {printf("Atribuido2\n");
        struct valorar *p;
        p=malloc(sizeof(struct valorar));
        p->valor = $1;
        p->tipo = strdup("FLOAT");
        $$ = p;
       }
       | boollit                                      {printf("Atribuido3\n");
        struct valorar *p;
        p=malloc(sizeof(struct valorar));
        p->valor = $1;
        p->tipo = strdup("BOOL");
        $$ = p;
       }
       ;


intlit: INT {$$ = $1;}
      ;

floatlit: FLOAT {$$ = $1;}
        ;

boollit: BOOL {$$ = $1;}
       ;


fator: variavel                                    {printf("VARIAVEL \n");
        int a = findVar($1);
        //printf("okk\n");
        if(a != -1){
            struct valorar *p;
            p=malloc(sizeof(struct valorar));
            p->valor = (float)a;
            p->tipo = strdup($1);
            $$ = p;
        }
    }
     | literal                                      {printf("VARIAVEL \n");printf("okk\n");$$ = $1;}
     | LEFT_BRACKET expressao RIGHT_BRACKET         {printf("VARIAVEL \n");}
    ;

seletor: seletoraux COLCHETES_ABRE expressao  COLCHETES_FECHA
       | vazio               {printf("TIPO \n");}
       ;

seletoraux: seletor
          ;

termo: termo opmul fator {printf("TERMO\n");
        if(strcmp($3->tipo, "INT")==0){
            auxTermo = strcat(auxTermo, toString(1, $3->valor));
        }else if(strcmp($3->tipo, "FLOAT")==0){
            auxTermo = strcat(auxTermo, toString(2, $3->valor));
        }else if(strcmp($3->tipo, "BOOL")==0){
            auxTermo = strcat(auxTermo, toString(1, $3->valor));
        }else{
            auxTermo = strcat(auxTermo, toString(3, $3->valor));
        }
        if(strcmp($2, "*")){
            auxTermo = strcat(auxTermo, "imul\n");
            $$ = auxTermo;
        }else if(strcmp($2, "/")){
            auxTermo = strcat(auxTermo, "imul\n");
            $$ = auxTermo;
        }
    }
    | fator              {printf("TERMO - FATOR\n");
        printf($1->tipo);
        if(strcmp($1->tipo, "INT")==0){
            auxTermo = strdup(toString(1, $1->valor));
        }else if(strcmp($1->tipo, "FLOAT")==0){
            auxTermo = strdup(toString(2, $1->valor));
        }else if(strcmp($1->tipo, "BOOL")==0){
            auxTermo = strdup(toString(1, $1->valor));
        }else{
            auxTermo = strdup(toString(3, $1->valor));
        }
}
    ;

opmul: OPMUL   {$$ = $1;}
    ;

agregadoAux: COLCHETES_ABRE literal PONTO_PONTO literal COLCHETES_FECHA   {printf("agregado Aux \n");}
    ;

// tipo: tipoAgregado  {printf("TIPO \n");}
//     |tipoSimples   {printf("TIPO \n");}
//     ;

// tipoAgregado: ARRAY_WORD agregadoAux OF_WORD tipo  {printf("TIPO AGREGADO\n");}
//     ;

tipoSimples: T_INT {$$=T_INT;printf("TIPO INT\n");}
    | T_REAL       {$$=T_REAL;printf("TIPO REAL\n");}
    | T_BOOL       {$$=T_BOOL;printf("TIPO BOOL\n");}
    ;

variavel: IDENTIFIER seletor {printf("Variavel\n");$$ = $1;}
        ;



vazio: {printf("Vazio\n");}
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
        printf("%s\n", p->nome);
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

char * toString(int i, float v){
    char *a;
    if(i == 1){
        sprintf(a, "%.0f", v);
        return strcat("ldc \n",a);
    }else if(i == 2){
        sprintf(a, "%f", v);
        return strcat("ldc \n",a);
    }else{
        sprintf(a, "%.0f", v);
        return strcat("ldc \n",a);
    }
}