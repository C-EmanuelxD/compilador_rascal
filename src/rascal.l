%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../include/tokens.h"
    char lexema[100];

    #define T_ERRO 999

%}

%option noyywrap yylineno

IGNORE      [ \t\r\n]+
ID          [a-zA-Z][a-zA-Z0-9_]*
NUM         [0-9]+

%%

"program"   { strcpy(lexema, yytext);return T_PROGRAM; }
"true"      { strcpy(lexema, yytext);return T_TRUE; }
"false"     { strcpy(lexema, yytext);return T_FALSE; }
"begin"     { strcpy(lexema, yytext);return T_BEGIN_T; }
"if"        { strcpy(lexema, yytext);return T_IF; }
"write"     { strcpy(lexema, yytext);return T_WRITE; }
"procedure" { strcpy(lexema, yytext);return T_PROCEDURE; }
"end"       { strcpy(lexema, yytext);return T_END_T; }
"then"      { strcpy(lexema, yytext);return T_THEN; }
"and"       { strcpy(lexema, yytext);return T_AND; }
"function"  { strcpy(lexema, yytext);return T_FUNCTION; }
"integer"   { strcpy(lexema, yytext);return T_INTEGER; }
"while"     { strcpy(lexema, yytext);return T_WHILE; }
"else"      { strcpy(lexema, yytext);return T_ELSE; }
"or"        { strcpy(lexema, yytext);return T_OR; }
"var"       { strcpy(lexema, yytext);return T_VAR; }
"boolean"   { strcpy(lexema, yytext);return T_BOOLEAN; }
"do"        { strcpy(lexema, yytext);return T_DO; }
"read"      { strcpy(lexema, yytext);return T_READ; }
"not"       { strcpy(lexema, yytext);return T_NOT; }
"div"       { strcpy(lexema, yytext);return T_DIV; }


"("         { strcpy(lexema, yytext);return T_LPAREN; }
")"         { strcpy(lexema, yytext);return T_RPAREN; }
";"         { strcpy(lexema, yytext);return T_SEMICOLON; }
"="         { strcpy(lexema, yytext);return T_IGUAL; }
"<>"        { strcpy(lexema, yytext);return T_DIFERENTE; }
"<="        { strcpy(lexema, yytext);return T_MENORIGUAL; }
"<"         { strcpy(lexema, yytext);return T_MENOR; }
">="        { strcpy(lexema, yytext);return T_MAIORIGUAL; }
">"         { strcpy(lexema, yytext);return T_MAIOR; }
"+"         { strcpy(lexema, yytext);return T_MAIS; }
"-"         { strcpy(lexema, yytext);return T_MENOS; }
"*"         { strcpy(lexema, yytext);return T_VEZES; }
":="        { strcpy(lexema, yytext);return T_ATRIB; }
":"         { strcpy(lexema, yytext);return T_COLON; }
","         { strcpy(lexema, yytext);return T_VIRGULA; }
"."         { strcpy(lexema, yytext);return T_PONTO; }

{IGNORE}    {;}
{ID}        {strcpy(lexema, yytext); return T_ID; }
{NUM}       { return T_NUM; }

.           { printf("Caractere inválido na linha %d: '%s'\n", yylineno, yytext); return T_ERRO;}

%%

int main (int argc, char *argv[]) {
    int tok;
    
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo_fonte>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    printf("--- Analisando o arquivo: %s ---\n", argv[1]);
    
    while ((tok = yylex()) != 0) {
        if (tok != T_ERRO) { 
            
            // 1. Calcula o índice do array, subtraindo o valor inicial (T_PROGRAM)
            int indice = tok - T_PROGRAM; 

            // 2. Imprime a STRING (o nome do token)
            printf("Tipo: %s\t(Lexema: '%s', Linha: %d)\n", 
                token_names[indice], lexema, yylineno);
            }
    }

    printf("--- Análise Léxica Concluída ---\n");
    fclose(yyin);
    return 0;
}