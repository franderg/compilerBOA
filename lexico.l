%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "sintactico.tab.h"
	int linea = 1;
	int erroresSimbolTable = 0;
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
"string"				{yylval.cadena = "String "; return T_STRING;}
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
{booleano}							{yylval.cadena = strdup(yytext); return BOOLEANO;}
{numero}+							{yylval.cadena = strdup(yytext); return ENTERO;}
{numero}+"."{numero}				{yylval.cadena = strdup(yytext); return DECIMAL;}
{numero}+"."{numero}{numero}+		{yylval.cadena = strdup(yytext); return COMPLEJO;}
"\""({caracter}|" "|{numero})*"\""	{yylval.cadena = strdup(yytext); return STRING;}
{caracter}({caracter}|{numero})*	{yylval.cadena = strdup(yytext); return CONSTANTE;}
"\n" 								{ linea++; }
[\t\r\f]				/* */
" "						/* */
"/*"(.)+"*/"			/* */
.	{printf("Error en linea %d \n",yylineno);}

%%

void yyerror(char *s)
{
	printf("%s \n",s);
}

void AbrirSalida()
{
	FILE *archivo;
	char caracter;
 
	archivo = fopen("salida.java","r");
 
	if (archivo == NULL){ }
	else{
 	    while (feof(archivo) == 0)
	    {
			caracter = fgetc(archivo);
			if ((int)caracter!=-1){
				printf("%c",caracter);
			}
	    }
	}
	printf("\n");
    fclose(archivo);
}


int main(int argc,char **argv)
{
	if (argc>1){
		yyin=fopen(argv[1],"rt");
		
		char comb[30];
		char * line = "./semantico ";
		int i;
		for(i=0; i < strlen(line); ++i){
			comb[i] = line[i];
		}
		char * line2 = argv[1];
		int j;
		for(j=0; j < strlen(line2); ++j ){
			comb[i] = line2[j];
			++i;
		}
		comb[i] = '\0';
		
		system(comb);
	}
	else{
		yyin=fopen("entrada.txt","rt");
		system("./semantico");	
		
	}
	if(!yyparse()){ }
	else {
		if (SalidaSemantico()) {
			AbrirSalida();
		}
		else {
			system("rm salida.java");
		}
	}
	
	system("rm SalidaSemantico");
	//visualizacion();
	fclose(yyin);
}

int SalidaSemantico () {
	FILE *archivo;
	char caracter;
	archivo = fopen("SalidaSemantico","r");
	if (archivo == NULL){
		printf("\nError al ejecutar analisis semantico, asegurese de que el ejecutable semantico se encuentra en el directorio\n");
    }
    else{
	    while (feof(archivo) == 0)
	    {
			caracter = fgetc(archivo);
			if((int)caracter==49){
				return 1;
			}
	    }
	}
	fclose(archivo);
	return 0;
}
