%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "sintactico.tab.h"
	int linea = 1;
%}

%option noyywrap
%option yylineno

ignora " "|\t|\n
numero [0-9]
caracter [a-zA-Z]
booleano "true"|"false"

%%

(ignora)*				/* */
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
"int"					{yylval.cadena = "int "; return T_ENTERO;}
"decimal"				{yylval.cadena = "double "; return T_DECIMAL;}
"bool"					{yylval.cadena = "bool "; return T_BOOLEANO;}
"string"				{yylval.cadena = "string "; return T_STRING;}
"float"				{yylval.cadena = "float "; return T_COMPLEJO;}
"define"				{return DEFINE;}
[A-Z]+				{return ID_MACRO;}
"+"						{return SUMA;}
"-"						{return RESTA;}
"*"						{return MULTIPLICACION;}
"/"						{return DIVISION;}
"--"					{return DISMINUIR;}
"++"					{return AUMENTAR;}
"="						{return ASIGNADOR;}
"<"						{return MENOR;}
">"						{return MAYOR;}
"=="					{return IGUAL;}
"!="					{return DIFERENTE;}
"if"					{return IF;}
"else"					{return ELSE;}
"else if"				{return ELIF;}
"while"					{return WHILE;}
"for"					{return FOR;}
{booleano}				{yylval.cadena = strdup(yytext); return BOOLEANO;}
{numero}+				{yylval.cadena = strdup(yytext); return ENTERO;}
{numero}+"."{numero}	{yylval.cadena = strdup(yytext); return DECIMAL;}
{numero}+"."{numero}{numero}+	{yylval.cadena = strdup(yytext); return COMPLEJO;}
"\""({caracter}|" "|{numero})*"\""	{yylval.cadena = strdup(yytext); return STRING;}
{caracter}({caracter}|{numero})*	{yylval.cadena = strdup(yytext); return CONSTANTE;}
"\n" 					{ linea++; }
[\t\r\f]				/* */
" "						/* */
"/*"(.)+"*/"			/* */
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
	//visualizacion();
	print_code();
	fclose(yyin);
}
