%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
%}

%option noyywrap yylineno

ESPACO      [ \t\r\n]+
LETRA       [a-zA-Z]
LOGICAL     (true|false)
ID          [a-zA-Z][a-zA-Z0-9_]*
NUM         [0-9]+

%%

{ESPACO}    {}
{LETRA}     {printf("Letra analisada: %s\n", yytext);}
{LOGICAL}   {printf("Identifcador lógico identificado: %s\n",yytext);}
{ID}        {printf("Identifcador analisado: %s\n",yytext);}
{NUM}       {printf("Valor numerico identificado: %s\n", yytext);}

%%

int main(){
    yylex();
    return 0;
}