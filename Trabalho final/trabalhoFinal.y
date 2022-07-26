%{

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define GetCurrentDir getcwd

extern  FILE *yyin;
void yyerror(const char * s);

extern int yylex();
extern int yyparse();

char outfileName[] = "input_code.txt";
extern int lineCounter;

char **codeList;
char *fileName = "output.j";
FILE *file;

void generateHeader();
void generateFooter();

%}

%union{
    int ival;
    float fval;
    int bval;
    char * idval;
    char * aopval;

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
%token INT FLOAT BOOL
%token <idval> IDENTIFIER
%token <aopval> OPAD
%token <aopval> OPMUL 
%token <aopval> RELATIONAL 
%token <aopval> BOOLEAN
%token T_NEWLINE T_QUIT
%token SEMI_COLON PONTO_PONTO VIRGULA DOIS_PONTOS
%token ATRIBUICAO EQUALS
%token RIGHT_BRACKET_CURLY LEFT_BRACKET_CURLY
%token RIGHT_BRACKET LEFT_BRACKET
%token COLCHETES_FECHA COLCHETES_ABRE

%start programa

%%

programa: PROGRAM_WORD IDENTIFIER SEMI_COLON corpo   {printf("Programa\n");}
        ;


corpo: declaracoes comandoComposto       {printf("corpo\n");}
     ;
     
comandoComposto: BEGIN_WORD   {generateFooter();printf("comando composto\n");}
                 listaDeComandos
                 END_WORD    {generateHeader();}
               ;

declaracoes: declaracaoDeVariavel SEMI_COLON               {printf("declaracoes\n");}
           | declaracoes declaracaoDeVariavel SEMI_COLON   {printf("declaracoes\n");}
           | vazio                                         {printf("declaracoes\n");}
           ;

declaracaoDeVariavel: VAR_WORD listaIds DOIS_PONTOS tipo   {printf("declaracao de variavel\n");}

listaDeComandos: comando SEMI_COLON                        {printf("lista de comandos\n");}
               | listaDeComandos comando SEMI_COLON        {printf("lista de comandos\n");}
               | vazio                                     {printf("lista de comandos\n");}
               ;

comando: atribuicao                                      {printf("comando\n");}
       | condicional                                     {printf("comando\n");}
       | comandoComposto                                 {printf("comando\n");}
       | comandoFor                                      {printf("comando\n");}
       | comandoWhile                                    {printf("comando\n");}
       ;

listaIds: IDENTIFIER                                     {printf("lista ids\n");}
        | listaIds VIRGULA IDENTIFIER                    {printf("lista ids\n");}
        ;

atribuicao: variavel ATRIBUICAO expressao                {printf("atribuicao\n");}
          ;

condicional: IF_WORD expressao THEN_WORD comando condicionalAUX {printf("condicional\n");}
           ;

condicionalAUX: ELSE_WORD comando                                   {printf("condicionalAUX\n");}
              | vazio                                        {printf("condicionalAUX\n");}
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

literal: INT                                       {printf("literal \n");}
       | FLOAT                                     {printf("literal \n");}
       | BOOL                                      {printf("literal \n");}
       ;

fator: variavel                                     {printf("VARIAVEL \n");}
     | literal                                      {printf("VARIAVEL \n");}
     | LEFT_BRACKET expressao RIGHT_BRACKET         {printf("VARIAVEL \n");}
     ;

seletor:                                                               {printf("TIPO \n");}
    | seletor  COLCHETES_ABRE expressao  COLCHETES_FECHA               {printf("TIPO \n");}
    | COLCHETES_ABRE expressao  COLCHETES_FECHA                        {printf("TIPO \n");}
    | vazio                                                            {printf("TIPO \n");}
    ;

termo: termo OPMUL fator {printf("TERMO\n");}
    | fator              {printf("TERMO - FATOR\n");}
    ;

agregadoAux: COLCHETES_ABRE literal PONTO_PONTO literal COLCHETES_FECHA   {printf("agregado Aux \n");}
    ;

tipo: tipoAgregado  {printf("TIPO \n");}
    |tipoSimples   {printf("TIPO \n");}
    ;

tipoAgregado: ARRAY_WORD agregadoAux OF_WORD tipo  {printf("TIPO AGREGADO\n");}
    ;

tipoSimples: T_INT {printf("TIPO INT\n");}
    | T_REAL       {printf("TIPO REAL\n");}
    | T_BOOL       {printf("TIPO BOOL\n");}
    ;

variavel: IDENTIFIER seletor {printf("Variavel\n");}
        ;



vazio: {printf("Vazio\n");}
    ;


%%

// int main() {
// 	yyin = stdin;

// 	do {
// 		yyparse();
// 	} while(!feof(yyin));

// 	return 0;
// }

// void yyerror(const char* s) {
// 	fprintf(stderr, "Erro de análise (sintática): %s\n", s);
// 	exit(1);
// }



int main(int argv, char * argc[]) {
	FILE *myfile;
	if(argv == 1) 
	{
		myfile = fopen("input_code.txt", "r");
		//outfileName = "input_code.txt";
	}
	// else 
	// {
	// 	myfile = fopen(argc[1], "r");
	// 	outfileName = string(argc[1]);
	// }
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
    file = fopen("output.j","a+");
    fprintf(file,".source %s","outfileName\n");
	fprintf(file,".class public test\n.super java/lang/Object\n\n"); //code for defining class
	
    fprintf(file,".method public <init>()V /n");
	fprintf(file,"aload_0 /n");
	fprintf(file,"invokenonvirtual java/lang/Object/<init>()V\n");
	fprintf(file,"return\n");
	fprintf(file,".end method\n\n");

	fprintf(file,".method public static main([Ljava/lang/String;)V/n");
	fprintf(file,".limit locals 100\n.limit stack 100\n");

	// /* generate temporal vars for syso*/
	// defineVar("1syso_int_var",INT);
	// defineVar("1syso_float_var",FLOAT);

	// /*generate line*/
	// writeCode(".line 1");
    // fclose(file);
}

void generateFooter()
{
    file = fopen("output.j","a+");
	fprintf(file,"\nreturn\n");
	fprintf(file,".end method\n");
}

//void writeCode(char * x)
//{
//	codeList.push_back(x);
//}
