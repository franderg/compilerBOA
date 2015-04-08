%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "semantico.tab.h"
	int linea = 1;
	int erroresSemanticos = 0;
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
"int"					{return T_ENTERO;}
"decimal"				{return T_DECIMAL;}
"bool"					{return T_BOOLEANO;}
"string"				{return T_STRING;}
"float"				{return T_COMPLEJO;}
"define"				{return DEFINE;}
[A-Z]+				{return ID_MACRO;}
"+"						{yylval.entero = 9; return SUMA;}
"-"						{yylval.entero = 8; return RESTA;}
"*"						{yylval.entero = 7; return MULTIPLICACION;}
"/"						{yylval.entero = 6; return DIVISION;}
"--"					{yylval.entero = 5; return DISMINUIR;}
"++"					{yylval.entero = 4; return AUMENTAR;}
"="						{return ASIGNADOR;}
"<"						{yylval.entero = 99;return MENOR;}
">"						{yylval.entero = 88;return MAYOR;}
"=="					{yylval.entero = 77;return IGUAL;}
"!="					{yylval.entero = 66;return DIFERENTE;}
"if"					{return IF;}
"else"					{return ELSE;}
"else if"				{return ELIF;}
"while"					{return WHILE;}
"for"					{return FOR;}
{booleano}				{yylval.entero = 3; return BOOLEANO;}
{numero}+				{yylval.entero = 1; return ENTERO;}
{numero}+"."{numero}	{yylval.entero = 2; return DECIMAL;}
{numero}+"."{numero}+				{yylval.entero = 5; return COMPLEJO;}
"\""({caracter}|" "|{numero})*"\""	{yylval.entero = 4; return STRING;}
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

void generarSalida (char * cadena) {
	FILE *fp;
    fp = fopen("SalidaSemantico", "wt");
    fputs(cadena, fp);
    fclose(fp);
}

int main(int argc,char **argv)
{
	if (argc>1){
		yyin=fopen(argv[1],"rt");
		if(!yyparse()) { generarSalida("error"); }
	}
	else{
		yyin=fopen("entrada.txt","rt");
		if(!yyparse()) { generarSalida("error"); }
	}
	if (erroresSemanticos==0) {
		generarSalida("1");
	}
	else {
		generarSalida("error");
	}
	fclose(yyin);
}






