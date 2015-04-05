%{

/********************** 
 * Declaraciones en C *
 **********************/
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "string.h"
#include "simbol_table.h" 
extern int yylex(void);
extern char *yytext;
extern int linea;
extern FILE *yyin;
void yyerror(char *s);
int yystopparser = 0;


%}
%union{
        char *cadena;
        int entero;     
}
/*************************
  Declaraciones de Bison *
 *************************/
%token <cadena> CONSTANTE

%token VOID MAIN ENTERO DECIMAL BOOLEANO T_ENTERO T_DECIMAL T_BOOLEANO T_COMPLEJO ASIGNADOR SUMA RESTA MULTIPLICACION DIVISION AUMENTAR DISMINUIR MAYOR MENOR IGUAL MAYORIGUAL MENORIGUAL DIFERENTE ELSE FOR WHILE IF ELIF T_STRING COMPLEJO DEFINE ID_MACRO STRING

%start programa

%type <entero> tipodato

%%
/***********************
 * Reglas Gramaticales *
 ***********************/



programa:       principal macro {visualizacion();}
                | principal {visualizacion();}
                | error principal {visualizacion();};

principal:		VOID MAIN '(' VOID ')' '{' lineascodigo '}';

/* produccion para generar macros */
macro:			DEFINE ID_MACRO valor macro | DEFINE ID_MACRO valor;

lineascodigo:	  lineacodigo 
                | /* vacio */;

lineacodigo:    lineacodigo linea 
                | linea;

linea:          invocarmetodo ';'
                | crearvariable ';' 
                | cambiarvalor ';' 
                | buclecondicion;

invocarmetodo:	CONSTANTE '(' parametros ')';

parametros:		parametroenvio |;

parametroenvio:		parametroenvio ',' parenvio | parenvio;

parenvio:			valor | CONSTANTE;

valor:			ENTERO | DECIMAL | BOOLEANO | STRING | COMPLEJO;

/* produccion para crear una variable */
crearvariable:    tipodato CONSTANTE  {ins_inicio_lista($2, $1, 0);}  /* crear variable */ 
                  | tipodato CONSTANTE asignarvalor;  /* crear variable constante */

tipodato:         T_ENTERO      {$$=1;}
                  | T_DECIMAL   {$$=2;}
                  | T_BOOLEANO  {$$=3;}
                  | T_STRING    {$$=4;}
                  | T_COMPLEJO  {$$=5;};

asignarvalor:	ASIGNADOR opasignar | ASIGNADOR valor | ASIGNADOR CONSTANTE | error ASIGNADOR;

opasignar:		aritmetico | invocarmetodo| cambvariable;

aritmetico:		opcomun | opcomun opcomplemento;

opcomun:		valor tipoopr valor | valor tipoopr CONSTANTE | CONSTANTE tipoopr valor | CONSTANTE tipoopr CONSTANTE;

opcomplemento:	opcomplemento oprcom | oprcom;

oprcom:			 tipoopr valor | tipoopr CONSTANTE;

tipoopr:		SUMA | RESTA | MULTIPLICACION |DIVISION;

cambvariable:	CONSTANTE indis;

indis:			AUMENTAR | DISMINUIR;

cambiarvalor:	CONSTANTE ASIGNADOR cambvalor;

cambvalor:		valor | opasignar | CONSTANTE;

buclecondicion:	condicionif | buclefor | buclewhile;

condicionif:	condicionsi| condicionsi condicionno | condicionsi condicionessino condicionno;

condicionsi:	IF '(' condicion ')' '[' lineascodigo']';

condicion:		valor condicional valor | valor condicional CONSTANTE | CONSTANTE condicional valor | CONSTANTE condicional CONSTANTE;

condicionsino:	ELIF '(' condicion ')' '[' lineascodigo ']';

condicional:	MAYOR | MENOR | IGUAL | MAYORIGUAL | MENORIGUAL | DIFERENTE;

condicionno:	ELSE '[' lineascodigo ']';

condicionessino:	condicionessino condicionsino | condicionsino;

buclefor:		FOR '(' iniciafor ';' condicion ';' cambvariable ')' '[' lineascodigo ']';					

iniciafor:		tipodato CONSTANTE asignarvalor;

buclewhile:		WHILE '(' condicion ')' '[' lineascodigo ']';

%%
/**********************
 * Codigo C Adicional *
 **********************/


