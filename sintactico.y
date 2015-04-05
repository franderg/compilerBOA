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



programa:       principal macro
                | principal;

principal:		VOID MAIN '(' VOID ')' '{' lineascodigo '}';

/* produccion para generar macros */
macro:			DEFINE ID_MACRO valor macro | DEFINE ID_MACRO valor;

lineascodigo:   lineacodigo 
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
                  | tipodato CONSTANTE asignarvalor {ins_inicio_lista($2, $1, 0);}; /* crear variable asignandole un dato */

tipodato:         T_ENTERO      {$$=1;}
                  | T_DECIMAL   {$$=2;}
                  | T_BOOLEANO  {$$=3;}
                  | T_STRING    {$$=4;}
                  | T_COMPLEJO  {$$=5;};

/* produccion para asignar algun objeto a una variable Asignador '=' */
asignarvalor:     ASIGNADOR opasignar 
                  | ASIGNADOR valor 
                  | ASIGNADOR CONSTANTE;

/* asigna una operacion, el retorno de un metodo o modifica una variable*/
opasignar:		    aritmetico 
                  | invocarmetodo;

aritmetico:		opcomun | opcomun opcomplemento;

/* operaciones aritmeticas: suma, resta, multiplicacion, division*/
opcomun:          valor tipoopr valor /* */
                  | valor tipoopr CONSTANTE 
                  | CONSTANTE tipoopr valor 
                  | CONSTANTE tipoopr CONSTANTE;

opcomplemento:	opcomplemento oprcom | oprcom;

oprcom:			 tipoopr valor | tipoopr CONSTANTE;

tipoopr:		SUMA | RESTA | MULTIPLICACION | DIVISION;

cambiarvalor:	CONSTANTE ASIGNADOR cambvalor;

cambvariable: CONSTANTE indis;

indis:      AUMENTAR | DISMINUIR;

cambvalor:		valor | opasignar | CONSTANTE;

buclecondicion:   condicionif 
                  | buclefor 
                  | buclewhile;

condicionif:      condicionsi
                  | condicionsi condicionno 
                  | condicionsi condicionessino condicionno;

condicionsi:      IF '(' condicion ')' '[' lineascodigo']';

condicion:        valor condicional valor 
                  | valor condicional CONSTANTE 
                  | CONSTANTE condicional valor 
                  | CONSTANTE condicional CONSTANTE;

/* operadores logicos */
condicional:      MAYOR | MENOR | IGUAL | MAYORIGUAL | MENORIGUAL | DIFERENTE;

/* else */
condicionno:      ELSE '[' lineascodigo ']';

/* uno o varios elif */
condicionessino:  condicionessino condicionsino 
                  | condicionsino;

/* elif */
condicionsino:    ELIF '(' condicion ')' '[' lineascodigo ']';

/* ciclo for */
buclefor:         FOR '(' iniciafor ';' condicion ';' cambvariable ')' '[' lineascodigo ']';					

/* variable inicial del for */
iniciafor:        tipodato CONSTANTE asignarvalor;

/* ciclo while */
buclewhile:       WHILE '(' condicion ')' '[' lineascodigo ']';

%%

/**********************
 * Codigo C Adicional *
 **********************/

int check_Variable (char * constante){
  if (obtener_tipo_elemento(constante)==-1){ /* si la constante no esta en la tabla de simbolos */
    printf("La variable %s no esta declarada",constante);
    return 0;
  }
  else{
    /* */
    return 1;
  }
}




