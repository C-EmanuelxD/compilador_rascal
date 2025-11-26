%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "rascal.tab.h"

%}

%option noyywrap yylineno

ESPACO      [ \t\r\n]+
ID          [a-zA-Z][a-zA-Z0-9_]*
NUM         [0-9]+

%%

"program"   { return PROGRAM; }
"true"      { return TRUE; }
"false"     { return FALSE; }
"begin"     { return BEGIN_T; }
"if"        { return IF; }
"write"     { return WRITE; }
"procedure" { return PROCEDURE; }
"end"       { return END_T; }
"then"      { return THEN; }
"and"       { return AND; }
"function"  { return FUNCTION; }
"integer"   { return INTEGER; }
"while"     { return WHILE; }
"else"      { return ELSE; }
"or"        { return OR; }
"var"       { return VAR; }
"boolean"   { return BOOLEAN; }
"do"        { return DO; }
"read"      { return READ; }
"not"       { return NOT; }
"div"       { return DIV; }

"("         { return LPAREN; }
")"         { return RPAREN; }
";"         { return SEMICOLON; }
"="         { return IGUAL; }
"<>"        { return DIFERENTE; }
"<"         { return MENOR; }
"<="        { return MENORIGUAL; }
">"         { return MAIOR; }
">="        { return MAIORIGUAL; }
"+"         { return MAIS; }
"-"         { return MENOS; }
"*"         { return VEZES; }
":="        { return ATRIB; }
":"         { return COLON; }
","         { return VIRGULA; }
"."         { return PONTO; }

{ESPACO}    ;
{ID}        { return ID; }
{NUM}       { return NUM; }

.           { printf("Caractere inválido na linha %d: '%s'\n", yylineno, yytext); }

%%

