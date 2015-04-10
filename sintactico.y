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
extern int erroresSimbolTable;
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
%token <cadena> FLOTANTE
%token <cadena> T_ENTERO 
%token <cadena> T_DECIMAL 
%token <cadena> T_BOOLEANO
%token <cadena> T_STRING
%token <cadena> T_FLOTANTE

%token VOID MAIN FOR WHILE IF ELIF DEFINE ID_MACRO
%token ASIGNADOR SUMA RESTA MULTIPLICACION DIVISION AUMENTAR 
%token DISMINUIR MAYOR MENOR IGUAL DIFERENTE ELSE 

%start programa

%type <cadena> lineascodigo
%type <cadena> lineacodigo
%type <cadena> linea
%type <cadena> valor
%type <cadena> crearvariable
%type <cadena> tipodato
%type <cadena> asignarvalor
%type <cadena> aritmetico
%type <cadena> opcomun
%type <cadena> opcomplemento
%type <cadena> oprcom
%type <cadena> tipoopr
%type <cadena> cambiarvalor
%type <cadena> cambvariable
%type <cadena> indis
%type <cadena> cambvalor
%type <cadena> buclecondicion
%type <cadena> condicionif
%type <cadena> condicionsi
%type <cadena> condicion
%type <cadena> condicional
%type <cadena> condicionno
%type <cadena> condicionessino
%type <cadena> condicionsino
%type <cadena> buclefor
%type <cadena> iniciafor
%type <cadena> buclewhile


%%
/***********************
 * Reglas Gramaticales *
 ***********************/

programa:       lineascodigo macro                { if (erroresSimbolTable==0) { /*print($1);*/ print_code($1); } };
                | lineascodigo                    { if (erroresSimbolTable==0) { /*print($1);*/ print_code($1); } };

/* produccion para generar macros */
macro:			DEFINE ID_MACRO valor macro | DEFINE ID_MACRO valor;

lineascodigo:   lineacodigo                       { $$ = $1; }
                | /* vacio */                     { $$ = ""; };

lineacodigo:    lineacodigo linea                 { $$ = concat($1,$2); }
                | linea                           { $$ = $1; };

linea:          crearvariable ';'                 { $$ = concat($1,";\n"); }
                | cambiarvalor ';'                { $$ = concat($1,";\n"); } 
                | buclecondicion                  { $$ = $1; };

valor:          ENTERO      { $$ = $1; }
                | DECIMAL   { $$ = $1; }
                | BOOLEANO  { $$ = $1; }
                | STRING    { $$ = $1; }
                | FLOTANTE  { $$ = $1; };

/* produccion para crear una variable */
crearvariable:    tipodato CONSTANTE                {
                                                      if (buscar_elemento($2)==0){ /* la variable no se encuentra en la tabla de simbolos */
                                                        insertar($2,$1); /* inserta la constante en la tabla de simbolos */
                                                        $$ = asignacion_variable ($1,$2,"");
                                                      }
                                                      else {
                                                        printf("Aviso[linea %d]: variable %s previamente definida\n", linea, $2);
                                                        erroresSimbolTable++;
                                                        $$ = "";
                                                      } 
                                                    };
                  | tipodato CONSTANTE asignarvalor {
                                                      if (buscar_elemento($2)==0){ /* la variable no se encuentra en la tabla de simbolos */
                                                        insertar($2,$1); /* inserta la constante en la tabla de simbolos */
                                                        $$ = asignacion_variable ($1,$2,$3);
                                                      }
                                                      else {
                                                        printf("Aviso[linea %d]: variable %s previamente definida\n", linea, $2);
                                                        erroresSimbolTable++;
                                                        $$ = "";
                                                      }
                                                      
                                                    }; /* crear variable asignandole un dato */

tipodato:         T_ENTERO      { $$=$1; }
                  | T_DECIMAL   { $$=$1; }
                  | T_BOOLEANO  { $$=$1; }
                  | T_STRING    { $$=$1; }
                  | T_FLOTANTE  { $$=$1; };

/* produccion para asignar algun objeto a una variable Asignador '=' */
asignarvalor:     ASIGNADOR aritmetico              { $$ = concat(" = ",$2); }
                  | ASIGNADOR valor                 { $$ = concat(" = ",$2); }
                  | ASIGNADOR CONSTANTE             {
                                                      if (check_Variable($2)!=0){ /* la variable se encuentra en la tabla de simbolos */
                                                        $$ = concat(" = ",$2);
                                                      }
                                                      else {
                                                        printf("Aviso[linea %d]: variable %s no se esta definida\n", linea, $2);
                                                        erroresSimbolTable++;
                                                        $$ = "";
                                                      }
                                                    };

aritmetico:       opcomun                           { $$ = $1; }
                  | opcomun opcomplemento           { $$ = concat($1,$2); };

/* operaciones aritmeticas: suma, resta, multiplicacion, division*/
opcomun:          valor tipoopr valor             { $$ = concatenar_operacion($1,$3,$2);}
                  | valor tipoopr CONSTANTE       {
                                                    if (check_Variable($3)!=0){ /* la variable se encuentra en la tabla de simbolos */
                                                      $$ = concatenar_operacion($1,$3,$2);
                                                    }
                                                    else {
                                                        printf("Aviso[linea %d]: variable %s no se esta definida\n", linea, $3);
                                                        erroresSimbolTable++;
                                                        $$ = "";
                                                    }
                                                  }
                  | CONSTANTE tipoopr valor       {
                                                    if (check_Variable($1)!=0){ /* la variable se encuentra en la tabla de simbolos */
                                                      $$ = concatenar_operacion($1,$3,$2);
                                                    }
                                                    else {
                                                        printf("Aviso[linea %d]: variable %s no se esta definida\n", linea, $1);
                                                        erroresSimbolTable++;
                                                        $$ = "";
                                                    }
                                                  }
                  | CONSTANTE tipoopr CONSTANTE   {
                                                    if (check_Variable($1)!=0){
                                                      if (check_Variable($3)!=0){
                                                        $$ = concatenar_operacion($1,$3,$2);
                                                      }
                                                      else {
                                                        printf("Aviso[linea %d]: variable %s no se esta definida\n", linea, $3);
                                                        erroresSimbolTable++;
                                                        $$ = "";
                                                      }
                                                    }
                                                    else {
                                                        printf("Aviso[linea %d]: variable %s no se esta definida\n", linea, $1);
                                                        erroresSimbolTable++;
                                                        $$ = "";
                                                    }
                                                  };

opcomplemento:    opcomplemento oprcom      { $$ = concat($1,$2); } 
                  | oprcom                  { $$ = $1; };

oprcom:           tipoopr valor             { $$ = concat($1,$2); }
                  | tipoopr CONSTANTE       {
                                              if (check_Variable($2)!=0){
                                                $$ = concat($1,$2);
                                              }
                                              else {
                                                printf("Aviso[linea %d]: variable %s no se esta definida\n", linea, $2);
                                                erroresSimbolTable++;
                                                $$ = "";
                                              }
                                            };

tipoopr:          SUMA                { $$ = " + "; }
                  | RESTA             { $$ = " - "; }
                  | MULTIPLICACION    { $$ = " * "; }
                  | DIVISION          { $$ = " / "; };

cambiarvalor:	    CONSTANTE ASIGNADOR cambvalor   { 
                                                    if (check_Variable($1)!=0){
                                                      $$ = asignacion_variable($1," = ",$3); /* NOTA: asignacion_variable funciona diferente */
                                                    }
                                                    else {
                                                      printf("Aviso[linea %d]: variable %s no se esta definida\n", linea, $1);
                                                      erroresSimbolTable++;
                                                      $$ = "";
                                                    }
                                                  };

cambvariable:     CONSTANTE indis     { $$ = concat($1,$2); };

indis:            AUMENTAR            { $$ = "++"; } 
                  | DISMINUIR         { $$ = "--"; };

cambvalor:        valor               { $$ = $1; }
                  | aritmetico        { $$ = $1; }
                  | CONSTANTE         { 
                                        if (check_Variable($1)!=0){
                                          $$ = $1;
                                        }
                                        else {
                                          printf("Aviso[linea %d]: variable %s no se esta definida\n", linea, $1);
                                          erroresSimbolTable++;
                                          $$ = "";
                                        }
                                      };

buclecondicion:   condicionif         { $$ = $1; }
                  | buclefor          { $$ = $1; }
                  | buclewhile        { $$ = $1; };

condicionif:      condicionsi                                   { $$ = $1; }
                  | condicionsi condicionno                     { $$ = concat($1,$2); }
                  | condicionsi condicionessino condicionno     { char * temporal = concat($1,$2); $$ = concat(temporal,$3); };

condicionsi:      IF '(' condicion ')' '[' lineascodigo ']'     {
                                                                  char * temporal = concat(escribir_if($3),"{\n");
                                                                  temporal = concat(temporal,$6);
                                                                  $$ = concat(temporal,"}\n");
                                                                };

condicion:        valor condicional valor                       { $$ = concatenar_operacion($1,$3,$2); }
                  | valor condicional CONSTANTE                 {
                                                                  if (check_Variable($3)!=0){
                                                                    $$ = concatenar_operacion($1,$3,$2);
                                                                  }
                                                                  else {
                                                                    printf("Aviso[linea %d]: variable %s no se esta definida\n", linea, $3);
                                                                    erroresSimbolTable++;
                                                                    $$ = "";
                                                                  }
                                                                }
                  | CONSTANTE condicional valor                 {
                                                                  if (check_Variable($1)!=0){
                                                                    $$ = concatenar_operacion($1,$3,$2);
                                                                  }
                                                                  else {
                                                                    printf("Aviso[linea %d]: variable %s no se esta definida\n", linea, $1);
                                                                    erroresSimbolTable++;
                                                                    $$ = "";
                                                                  }
                                                                }
                  | CONSTANTE condicional CONSTANTE             {
                                                                  if (check_Variable($1)!=0){
                                                                    if (check_Variable($3)!=0){
                                                                      $$ = concatenar_operacion($1,$3,$2);
                                                                    }
                                                                    else {
                                                                      printf("Aviso[linea %d]: variable %s no se esta definida\n", linea, $3);
                                                                      erroresSimbolTable++;
                                                                      $$ = "";
                                                                    }
                                                                  }
                                                                  else {
                                                                      printf("Aviso[linea %d]: variable %s no se esta definida\n", linea, $1);
                                                                      erroresSimbolTable++;
                                                                      $$ = "";
                                                                  }
                                                                };

/* operadores logicos */
condicional:      MAYOR           { $$ = " > "; }
                  | MENOR         { $$ = " < "; }
                  | IGUAL         { $$ = " == "; }
                  | DIFERENTE     { $$ = " != "; };

/* else */
condicionno:      ELSE '[' lineascodigo ']'                     {
                                                                  char * temporal = concat(escribir_else(),"{\n");
                                                                  temporal = concat(temporal,$3);
                                                                  $$ = concat(temporal,"}\n");
                                                                };

/* uno o varios elif */
condicionessino:  condicionessino condicionsino                 { $$ = concat ($1,$2); }
                  | condicionsino                               { $$ = $1; };

/* elif */
condicionsino:    ELIF '(' condicion ')' '[' lineascodigo ']'   {
                                                                  char * temporal = concat(escribir_elif($3),"{\n");
                                                                  temporal = concat(temporal,$6);
                                                                  $$ = concat(temporal,"}\n");
                                                                };

/* ciclo for */
buclefor:         FOR '(' iniciafor ';' condicion 
                  ';' cambvariable ')' '[' lineascodigo ']'     {
                                                                  char * temporal = concat(escribir_for($3,$5,$7),"{\n");
                                                                  temporal = concat(temporal,$10);
                                                                  $$ = concat(temporal,"}\n");
                                                                };					

/* variable inicial del for */
iniciafor:        tipodato CONSTANTE asignarvalor               { 
														                                      if (buscar_elemento($2)==0){ /* si el elemento no esta en la tabla */
                                                                    insertar($2,$1);
                                                                    $$ = asignacion_variable($1,$2,$3);
                                                                  }
                                                                  else {
                                                                      printf("Aviso[linea %d]: no se puede usar la variable %s porque ya esta previamente definida\n", linea, $2);
                                                                      erroresSimbolTable++;
                                                                      $$ = "";
                                                                  }
                                                                };

/* ciclo while */
buclewhile:       WHILE '(' condicion ')' '[' lineascodigo ']'  {
                                                                  char * temporal = concat(escribir_while($3),"{\n");
                                                                  temporal = concat(temporal,$6);
                                                                  $$ = concat(temporal,"}\n");
                                                                };

%%

/**********************
 * Codigo C Adicional *
 **********************/

int check_Variable (char * constante){
  if (obtener_tipo_elemento(constante)==-1) return 0;
  else return 1;
}

int insertar (char * constante, char * tipo){
  if (strcmp(tipo,"int ")==0)
    ins_inicio_lista(constante, 1, 0);
  else if (strcmp(tipo,"double ")==0)
    ins_inicio_lista(constante, 2, 0);
  else if (strcmp(tipo,"bool ")==0)
    ins_inicio_lista(constante, 3, 0);
  else if (strcmp(tipo,"String ")==0)
    ins_inicio_lista(constante, 4, 0);
  else if (strcmp(tipo,"float ")==0)
    ins_inicio_lista(constante, 5, 0);
  return 0;
}
