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
%token <entero> ENTERO
%token <entero> DECIMAL
%token <entero> BOOLEANO
%token <entero> STRING
%token <entero> SUMA
%token <entero> RESTA
%token <entero> MULTIPLICACION
%token <entero> DIVISION
%token <entero> COMPLEJO
%token <entero> AUMENTAR
%token <entero> DISMINUIR
%token <entero> MAYOR
%token <entero> MENOR
%token <entero> IGUAL
%token <entero> DIFERENTE

%token VOID MAIN T_ENTERO T_DECIMAL T_BOOLEANO T_COMPLEJO ASIGNADOR DEFINE
%token ID_MACRO ELSE FOR WHILE IF ELIF T_STRING

%start programa

%type <entero> tipodato
%type <entero> valor
%type <entero> opasignar
%type <entero> aritmetico
%type <entero> tipoopr
%type <entero> opcomun
%type <entero> asignarvalor
%type <entero> cambiarvalor
%type <entero> cambvariable
%type <entero> indis
%type <entero> cambvalor
%type <entero> condicional
%type <entero> condicion

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

valor:		        ENTERO        {$$=$1;}
                  | DECIMAL     {$$=$1;}
                  | BOOLEANO    {$$=$1;}
                  | STRING      {$$=$1;}
                  | COMPLEJO    {$$=$1;};

/* produccion para crear una variable */
crearvariable:    tipodato CONSTANTE  {
                                        if (buscar_elemento($2)==0){
                                          ins_inicio_lista($2, $1, 0);
                                        }
                                        else {
                                          printf("Aviso[linea %d]: variable %s previamente definida\n", linea, $2);
                                        }
                                      }  /* crear variable */ 
                  | tipodato CONSTANTE asignarvalor {
                                                      if (buscar_elemento($2)==0){
                                                        ins_inicio_lista($2, $1, 0);
                                                      }
                                                      else {
                                                        printf("Aviso[linea %d]: variable %s previamente definida\n", linea, $2);
                                                      }
                                                      if($1!=$3){
                                                        printf("Error[linea %d]: se le asigna un tipo de dato diferente a la variable %s\n", linea, $2);
                                                      }
                                                    }; /* crear variable asignandole un dato */

tipodato:         T_ENTERO      {$$=1;}
                  | T_DECIMAL   {$$=2;}
                  | T_BOOLEANO  {$$=3;}
                  | T_STRING    {$$=4;}
                  | T_COMPLEJO  {$$=5;};

/* produccion para asignar algun objeto a una variable Asignador '=' */
asignarvalor:     ASIGNADOR opasignar       {$$=$2;}
                  | ASIGNADOR valor         {$$=$2;}
                  | ASIGNADOR CONSTANTE     {
                                              int operando1 = obtener_tipo_elemento($2);
                                              if (operando1!=-1){
                                                $$ = operando1;
                                              }
                                              else{
                                                printf("Error[linea %d]: la variable %s no esta definida o es de un tipo diferente\n", linea,$2);
                                                $$ = -1;
                                              }
                                            };

/* asigna una operacion, el retorno de un metodo o modifica una variable*/
opasignar:		    aritmetico                { $$ = $1; }; /////////////////// CAMBIAR

aritmetico:       opcomun                         { $$ = $1; }
                  | opcomun tipoopr aritmetico    { $$ = check_operacion_aritmetica($1,$3,$2); }
;

/* operaciones aritmeticas: suma, resta, multiplicacion, division*/
opcomun:          valor tipoopr valor             {$$ = check_operacion_aritmetica($1,$3,$2);}
                  | valor tipoopr CONSTANTE       {
                                                    if (check_Variable($3)!=0){
                                                      int tipo = obtener_tipo_elemento($3);
                                                      if (tipo!=-1){
                                                        $$ = check_operacion_aritmetica($1,tipo,$2);
                                                      }
                                                      else{
                                                        printf("Error[linea %d]: la variable %s es de un tipo diferente al valor que se le quiere asignar\n", linea,$3);
                                                        $$ = -1;
                                                      }
                                                    }
                                                    else $$ = -1;
                                                  }
                  | CONSTANTE tipoopr valor       {
                                                    if (check_Variable($1)!=0){
                                                      int tipo = obtener_tipo_elemento($1);
                                                      if (tipo!=-1){
                                                        $$ = check_operacion_aritmetica(tipo,$3,$2);
                                                      }
                                                      else{
                                                        printf("Error[linea %d]: la variable %s es de un tipo diferente al valor que se le quiere asignar\n", linea,$1);
                                                        $$ = -1;
                                                      }
                                                    }
                                                    else $$ = -1;
                                                  }
                  | CONSTANTE tipoopr CONSTANTE   {
                                                    int operando1 = obtener_tipo_elemento($1);
                                                    int operando2 = obtener_tipo_elemento($3);
                                                    if (operando1!=-1 && operando2!=-1){
                                                      if (operando1==operando2){
                                                        $$ = operando1;
                                                      }
                                                      else{
                                                        printf("Error[linea %d]: la variable %s es de un tipo diferente al de la variable %s\n", linea,$1,$3);
                                                        $$ = -1;
                                                      }
                                                    }
                                                    else $$ = -1;
                                                  };

tipoopr:          SUMA                {$$=$1;}
                  | RESTA             {$$=$1;}
                  | MULTIPLICACION    {$$=$1;}
                  | DIVISION          {$$=$1;};

cambiarvalor:	CONSTANTE ASIGNADOR cambvalor       {
                                                    if (check_Variable($1)!=0){
                                                      int tipo = obtener_tipo_elemento($1);
                                                      if (tipo==$3){
                                                        $$ = tipo;
                                                      }
                                                      else{
                                                        printf("Error[linea %d]: la variable %s es de un tipo diferente al valor que se le quiere asignar\n", linea,$1);
                                                        $$ = -1;
                                                      }
                                                    }
                                                    else $$ = -1;
                                                  };

cambvariable:     CONSTANTE indis     {
                                        if (check_Variable($1)!=0){
                                          int tipo = obtener_tipo_elemento($1);
                                          if (tipo==$2){
                                            if (tipo==1 || tipo==2)
                                            {
                                              $$ = tipo;
                                            }
                                            else{
                                              printf("Error[linea %d]: no se puede aplicar la operacion a la variable %s\n", linea,$1);
                                            }
                                          }
                                          else{
                                            printf("Error[linea %d]: la variable %s es de un tipo diferente al valor que se le quiere asignar", linea,$1);
                                            $$ = -1;
                                          }
                                        }
                                        else $$ = -1;
};

indis:            AUMENTAR            {$$ = $1;}
                  | DISMINUIR         {$$ = $1;};

cambvalor:        valor               {$$ = $1;} 
                  | opasignar         {$$ = $1;}
                  | CONSTANTE         {
                                        if (check_Variable($1)!=0){
                                          $$ = obtener_tipo_elemento($1);
                                        }
                                        else $$ = -1;
                                      };

buclecondicion:   condicionif 
                  | buclefor 
                  | buclewhile;

condicionif:      condicionsi
                  | condicionsi condicionno 
                  | condicionsi condicionessino condicionno;

condicionsi:      IF '(' condicion ')' '[' lineascodigo']';

condicion:        valor condicional valor             {check_operacion_logica($1,$3,$2);}
                  | valor condicional CONSTANTE       {
                                                        if (check_Variable($3)!=0){
                                                          int tipo = obtener_tipo_elemento($3);
                                                          if (tipo==$1){
                                                            $$ = check_operacion_logica($1,tipo,$2);
                                                          }
                                                          else{
                                                            printf("Error[linea %d]: la variable %s es de un tipo diferente al valor que se le quiere comparar\n", linea,$3);
                                                            $$ = -1;
                                                          }
                                                        }
                                                        else $$ = -1;
                                                      }
                  | CONSTANTE condicional valor       {
                                                        if (check_Variable($1)!=0){
                                                          int tipo = obtener_tipo_elemento($1);
                                                          if (tipo==$3){
                                                            $$ = check_operacion_logica(tipo,$1,$2);
                                                          }
                                                          else{
                                                            printf("Error[linea %d]: la variable %s es de un tipo diferente al valor con el que se le quiere comparar\n", linea,$1);
                                                            $$ = -1;
                                                          }
                                                        }
                                                        else $$ = -1;
                                                      }
                  | CONSTANTE condicional CONSTANTE   {
                                                        int operando1 = obtener_tipo_elemento($1);
                                                        int operando2 = obtener_tipo_elemento($3);
                                                        if (operando1!=-1 && operando2!=-1){
                                                          if (operando1==operando2){
                                                            $$ = check_operacion_logica($1,$3,$2);
                                                          }
                                                          else{
                                                            printf("Error[linea %d]: la variable %s es de un tipo diferente al de la variable %s\n", linea,$1,$3);
                                                            $$ = -1;
                                                          }
                                                        }
                                                        else $$ = -1;
                                                      };

/* operadores logicos */
condicional:      MAYOR               {$$ = $1;}
                  | MENOR             {$$ = $1;}
                  | IGUAL             {$$ = $1;}
                  | DIFERENTE         {$$ = $1;};

/* else */
condicionno:      ELSE '[' lineascodigo ']';

/* uno o varios elif */
condicionessino:  condicionessino condicionsino 
                  | condicionsino;

/* elif */
condicionsino:    ELIF '(' condicion ')' '[' lineascodigo ']'     {
                                                                    if ($3!=3){
                                                                      printf("Error[linea %d]: la condicion del ciclo elif no es de tipo booleano\n", linea);
                                                                    } 
                                                                  };

/* ciclo for */
buclefor:         FOR '(' iniciafor ';' 
                  condicion
                  ';' cambvariable ')' '[' lineascodigo ']' {
                                                              if ($5!=3){
                                                                printf("Error[linea %d]: la condicion del ciclo for no es de tipo booleano\n", linea);
                                                              } 
                                                            };					

/* variable inicial del for */
iniciafor:        tipodato CONSTANTE asignarvalor;

/* ciclo while */
buclewhile:       WHILE '(' 
                  condicion  
                  ')' '[' lineascodigo ']'      {
                                                  if ($3!=3){
                                                    printf("Error[linea %d]: la condicion del ciclo while no es de tipo booleano\n", linea);
                                                  } 
                                                };

%%

/**********************
 * Codigo C Adicional *
 **********************/

int check_Variable (char * constante){
  if (obtener_tipo_elemento(constante)==-1){ /* si la constante no esta en la tabla de simbolos */
    printf("Error[linea %d]: La variable %s no esta declarada\n", linea,constante);
    return 0;
  }
  else{
    /* */
    return 1;
  }
}

/**
 * @param operando1 tipo de dato (codigo definido en el archivo lex) del primer operando
 * @param operando2 tipo de dato (codigo definido en el archivo lex) del segundo operando
 * @param operador tipo del operador (codigo definido en el archivo lex) para los operandos
 * @return el tipo de dato resultante de la operacion, -1 en caso de error de tipos
 */
int check_operacion_aritmetica(int operando1, int operando2, int operador){
  if (operando1==-1 || operando2==-1){ /* si alguno de los dos operandos arrastra un error */
    return -1; /* continuar arrastrando el error */
  }
  if (operador==9){ /* si el operador es suma */

    /* si ambos son booleanos, hay un error */
    if (operando1==3 && operando2==3) { 
      printf("Error[linea %d]: no se pueden sumar datos de tipo booleanos\n", linea);
      return -1;
    }

    /* si ambos son del mismo tipo el resultado se mantiene del mismo tipo */
    else if (operando1==operando2) return operando1;
    
    /* si ambos son de tipos diferentes, hay un error */
    else if (operando1!=operando2) {
      printf("Error[linea %d]: no se pueden sumar datos de tipos diferentes\n", linea);
      return -1;
    }

  }
  else if (operador==8){ /* si el operador es resta */

    /* si ambos son booleanos, hay un error */
    if (operando1==3 && operando2==3) { 
      printf("Error[linea %d]: no se pueden restar datos de tipo booleanos\n", linea);
      return -1;
    }
    else if (operando1==4 && operando2==4) {
      printf("Error[linea %d]: no se pueden restar datos de tipo string\n", linea);
      return -1;
    }

    /* si ambos son del mismo tipo el resultado se mantiene del mismo tipo */
    else if (operando1==operando2) return operando1;
    
    /* si ambos son de tipos diferentes, hay un error */
    else if (operando1!=operando2) return -1;

  }

  else if (operador==7){ /* si el operador es multiplicacion */

    /* si ambos son booleanos, hay un error */
    if (operando1==3 && operando2==3) { 
      printf("Error[linea %d]: no se pueden multiplicar datos de tipo booleanos\n", linea);
      return -1;
    }
    else if (operando1==4 && operando2==4) {
      printf("Error[linea %d]: no se pueden multiplicar datos de tipo string\n", linea);
      return -1;
    }

    /* si ambos son del mismo tipo el resultado se mantiene del mismo tipo */
    else if (operando1==operando2) return operando1;
    
    /* si ambos son de tipos diferentes, hay un error */
    else if (operando1!=operando2) return -1;

  }

  else if (operador==8){ /* si el operador es division */

    /* si ambos son booleanos, hay un error */
    if (operando1==3 && operando2==3) { 
      printf("Error[linea %d]: no se pueden restar datos de tipo booleanos\n", linea);
      return -1;
    }
    else if (operando1==4 && operando2==4) {
      printf("Error[linea %d]: no se pueden restar datos de tipo string\n", linea);
      return -1;
    }

    /* si ambos son del mismo tipo el resultado se mantiene del mismo tipo */
    else if (operando1==operando2) return operando1;
    
    /* si ambos son de tipos diferentes, hay un error */
    else if (operando1!=operando2) return -1;

  }
}


int check_operacion_logica(int operando1, int operando2, int operador) {
  if (operando1==-1 || operando2==-1){ /* si alguno de los dos operandos arrastra un error */
    return -1; /* continuar arrastrando el error */
  }
  else if (operador == 77 || operador == 66){
    /* si ambos son booleanos, hay un error */
    if (operando1==3 && operando2==3) { 
      printf("Error[linea %d]: no se puede aplicar el operador logico a datos de tipo booleanos\n", linea);
      return -1;
    }
    else return 3;
  }
  else if (operador == 99 || operador == 88){
    /* si ambos son booleanos, hay un error */
    if (operando1==3 || operando2==3) { 
      printf("Error[linea %d]: no se puede aplicar el operador logico a datos de tipo booleanos\n", linea);
      return -1;
    }
    /* si ambos son string, hay un error */
    else if (operando1==4 || operando2==4) { 
      printf("Error[linea %d]: no se pueden aplicar los operadores logicos < o > a datos de tipo booleanos\n", linea);
      return -1;
    }
    else return 3;
  }
    
  }
