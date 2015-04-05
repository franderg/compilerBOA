/*****************
 * Codigo en C*
 ****************/

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "sintactico.tab.h"	

%}

%option noyywrap
%option yylineno

ignora " "|\t|\n
numero [0-9]
caracter [a-zA-Z]
booleano "true"|"false"

%%

(ignora)*				{;}
"(" 					{return('(');}
")"				 		{return(')');}
"," 					{return(',');}
"{"				 		{return('{');}
"}" 					{return('}');}
"[" 					{return('[');}
"]" 					{return(']');}
"." 					{return('.');}
";" 					{return(';');}
"void"					{return VOID;}
"main"					{return MAIN;}
"int"					{return T_ENTERO;}
"decimal"				{return T_DECIMAL;}
"bool"					{return T_BOOLEANO;}
"string"				{return T_STRING;}
"complex"				{return T_COMPLEJO;}
"define"				{return DEFINE;}
"id_macro"				{return ID_MACRO;}
"+"						{return SUMA;}
"-"						{return RESTA;}
"*"						{return MULTIPLICACION;}
"/"						{return DIVISION;}
"++"					{return AUMENTAR;}
"--"					{return DISMINUIR;}
"=>"					{return ASIGNADOR;}
"<"						{return MENOR;}
">"						{return MAYOR;}
">="					{return MAYORIGUAL;}
"<="					{return MENORIGUAL;}
"=="					{return IGUAL;}
"!="					{return DIFERENTE;}
"if"					{return IF;}
"else"					{return ELSE;}
"else if"				{return ELIF;}
"while"					{return WHILE;}
"for"					{return FOR;}
{booleano}				{return BOOLEANO;}
{numero}+				{return ENTERO;}
{numero}+"."{numero}	{return DECIMAL;}
{numero}+"+ j"{numero}+ {return COMPLEJO;}
{caracter}({caracter}|{numero})*	{return CONSTANTE;}
"\n" 					{}
[\t\r\f]				 {}
" "						 {}
.	{printf("Error en linea %d \n",yylineno);}

%%

void yyerror(char *s)
{
	printf("%s \n",s);
}


int main(int argc,char **argv)
{
	if (argc>1)
		yyin=fopen(argv[1],"rt");
	else
		yyin=fopen("entrada.txt","rt");		
		if(!yyparse())
			printf("Compilacion completa sin errores \n");
	
	fclose(yyin);
}
