%{

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "string.h"
#include "simbol_table.h"
#include "generador_codigo"
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
%token <cadena> ENTERO
%token <cadena> DECIMAL
%token <cadena> BOOLEANO
%token <cadena> STRING
%token <cadena> COMPLEJO
%token <cadena> T_ENTERO 
%token <cadena> T_DECIMAL 
%token <cadena> T_BOOLEANO
%token <cadena> T_STRING
%token <cadena> T_COMPLEJO

%token VOID MAIN FOR WHILE IF ELIF DEFINE ID_MACRO
%token ASIGNADOR SUMA RESTA MULTIPLICACION DIVISION AUMENTAR 
%token DISMINUIR MAYOR MENOR IGUAL DIFERENTE ELSE 

%start programa

%type <cadena> iniciafor
%type <cadena> condicional
%type <cadena> condicion
%type <cadena> cambvalor
%type <cadena> indis
%type <cadena> cambvariable
%type <cadena> cambiarvalor
%type <cadena> tipoopr
%type <cadena> opcomplemento
%type <cadena> opcomun
%type <cadena> oprcom
%type <cadena> aritmetico
%type <cadena> asignarvalor
%type <cadena> tipodato
%type <cadena> crearvariable
%type <cadena> valor
%type <cadena> linea
%type <cadena> lineacodigo
%type <cadena> lineascodigo


%%
/***********************
 * Reglas Gramaticales *
 ***********************/

programa:       principal macro
                | principal;

principal:		VOID MAIN '(' VOID ')' '{' lineascodigo '}';

/* produccion para generar macros */
macro:			DEFINE ID_MACRO valor macro | DEFINE ID_MACRO valor;

lineascodigo:   lineacodigo                       { $$ = $1; }
                | /* vacio */                     { $$ = ""; };

lineacodigo:    lineacodigo linea                 { $$ = $2; }
                | linea                           { $$ = $1; };

linea:          crearvariable ';'                 { escribir_linea (concat($1,";\n")); $$ = concat($1,";"); }
                | cambiarvalor ';'                { $$ = concat($1,";\n"); } 
                | buclecondicion                  { $$ = ""; };

valor:          ENTERO      { $$ = $1; }
                | DECIMAL   { $$ = $1; }
                | BOOLEANO  { $$ = $1; }
                | STRING    { $$ = $1; }
                | COMPLEJO  { $$ = $1; };

/* produccion para crear una variable */
crearvariable:    tipodato CONSTANTE                {
                                                      if (buscar_elemento($2)==0){
                                                        insertar($2,$1);
                                                        $$ = asignacion_variable ($1,$2,"");
                                                      }
                                                      else {
                                                        printf("Aviso[linea %d]: variable %s previamente definida\n", linea, $2);
                                                      } 
                                                    };/* crear variable */ 
                  | tipodato CONSTANTE asignarvalor {
                                                      if (buscar_elemento($2)==0){
                                                        insertar($2,$1);
                                                      }
                                                      else {
                                                        printf("Aviso[linea %d]: variable %s previamente definida\n", linea, $2);
                                                      }
                                                      $$ = asignacion_variable ($1,$2,$3);
                                                    }; /* crear variable asignandole un dato */

tipodato:         T_ENTERO      { $$=$1; }
                  | T_DECIMAL   { $$=$1; }
                  | T_BOOLEANO  { $$=$1; }
                  | T_STRING    { $$=$1; }
                  | T_COMPLEJO  { $$=$1; };

/* produccion para asignar algun objeto a una variable Asignador '=' */
asignarvalor:     ASIGNADOR aritmetico      { $$ = concat(" = ",$2); }
                  | ASIGNADOR valor         { $$ = concat(" = ",$2); }
                  | ASIGNADOR CONSTANTE     {
                                              if (check_Variable($2)!=0){
                                                $$ = concat(" = ",$2);
                                              }
                                              else $$ = "";
                                            };

aritmetico:       opcomun                   { $$ = $1; }
                  | opcomun opcomplemento  { $$ = concat($1,$2); };

/* operaciones aritmeticas: suma, resta, multiplicacion, division*/
opcomun:          valor tipoopr valor             { $$ = concatenar_operacion($1,$3,$2);}
                  | valor tipoopr CONSTANTE       {
                                                    if (check_Variable($3)!=0){
                                                      $$ = concatenar_operacion($1,$3,$2);
                                                    }
                                                    else $$ = "";
                                                  }
                  | CONSTANTE tipoopr valor       {
                                                    if (check_Variable($1)!=0){
                                                      $$ = concatenar_operacion($1,$3,$2);
                                                    }
                                                    else $$ = "";
                                                  }
                  | CONSTANTE tipoopr CONSTANTE   {
                                                    if (check_Variable($1)!=0 && check_Variable($3)!=0){
                                                      $$ = concatenar_operacion($1,$3,$2);
                                                    }
                                                    else $$ = "";
                                                  };

opcomplemento:    opcomplemento oprcom      { $$ = concat($1,$2); } 
                  | oprcom                  { $$ = $1; };

oprcom:           tipoopr valor             { $$ = concat($1,$2); }
                  | tipoopr CONSTANTE       {
                                              if (check_Variable($2)!=0){
                                                $$ = concat($1,$2);
                                              }
                                              else $$ = "";
                                            };

tipoopr:          SUMA                { $$ = " + "; }
                  | RESTA             { $$ = " - "; }
                  | MULTIPLICACION    { $$ = " * "; }
                  | DIVISION          { $$ = " / "; };

cambiarvalor:	    CONSTANTE ASIGNADOR cambvalor   { $$ = asignacion_variable($1," = ",$3);};

cambvariable:     CONSTANTE indis     { $$ = concat($1,$2); };

indis:            AUMENTAR            { $$ = "++"; } 
                  | DISMINUIR         { $$ = "--"; };

cambvalor:        valor               { $$ = $1; }
                  | aritmetico        { $$ = $1; }
                  | CONSTANTE         { 
                                        if (check_Variable($1)!=0){
                                          $$ = $1;
                                        }
                                        else $$ = "";
                                      };

buclecondicion:   condicionif 
                  | buclefor 
                  | buclewhile;

condicionif:      condicionsi
                  | condicionsi condicionno 
                  | condicionsi condicionessino condicionno;

condicionsi:      IF '(' condicion ')' '[' lineascodigo ']'    {
                                                                escribir_if($3);
                                                                escribir_cuerpo($6);
                                                              };

condicion:        valor condicional valor             { $$ = concatenar_operacion($1,$3,$2); }
                  | valor condicional CONSTANTE       {
                                                        if (check_Variable($3)!=0){
                                                          $$ = concatenar_operacion($1,$3,$2);
                                                        }
                                                        else $$ = "";
                                                      }
                  | CONSTANTE condicional valor       {
                                                        if (check_Variable($1)!=0){
                                                          $$ = concatenar_operacion($1,$3,$2);
                                                        }
                                                        else $$ = "";
                                                      }
                  | CONSTANTE condicional CONSTANTE   {
                                                        if (check_Variable($1)!=0 && check_Variable($3)!=0){
                                                          $$ = concatenar_operacion($1,$3,$2);
                                                        }
                                                        else $$ = "";
                                                      };

/* operadores logicos */
condicional:      MAYOR           { $$ = " > "; }
                  | MENOR         { $$ = " < "; }
                  | IGUAL         { $$ = " == "; }
                  | DIFERENTE     { $$ = " != "; };

/* else */
condicionno:      ELSE '[' lineascodigo ']'   {
                                                escribir_else();
                                                escribir_cuerpo($3);
                                              };

/* uno o varios elif */
condicionessino:  condicionessino condicionsino 
                  | condicionsino;

/* elif */
condicionsino:    ELIF '(' condicion ')' '[' lineascodigo ']'  {
                                                                  escribir_elif($3);
                                                                  escribir_cuerpo($6);
                                                                };

/* ciclo for */
buclefor:         FOR '(' iniciafor ';' condicion 
                  ';' cambvariable ')' '[' lineascodigo ']' {
                                                              escribir_for($3,$5,$7);
                                                              escribir_cuerpo($10);

};					

/* variable inicial del for */
iniciafor:        tipodato CONSTANTE asignarvalor     { 
														 if (buscar_elemento($2)==0){
															insertar($2,$1);
														}
                                                        char * temporal = concat($1,$2);
                                                        temporal = concat(temporal,$3);
                                                        $$ = temporal;
                                                      };

/* ciclo while */
buclewhile:       WHILE '(' condicion ')' '[' lineascodigo ']'  {
                                                                  escribir_while($3);
                                                                  escribir_cuerpo($6);
                                                                };

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

int insertar (char * constante, char * tipo){
  if (strcmp(tipo,"int ")==0)
    ins_inicio_lista(constante, 1, 0);
  else if (strcmp(tipo,"double ")==0)
    ins_inicio_lista(constante, 2, 0);
  else if (strcmp(tipo,"bool ")==0)
    ins_inicio_lista(constante, 3, 0);
  else if (strcmp(tipo,"string ")==0)
    ins_inicio_lista(constante, 4, 0);
  else if (strcmp(tipo,"float ")==0)
    ins_inicio_lista(constante, 5, 0);
  return 0;
}
