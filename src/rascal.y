%{
    #include <stdio.h>
    int yylex();
%}

%token PROGRAM PROCEDURE FUNCTION VAR
%token BEGIN_T END_T INTEGER BOOLEAN TRUE FALSE WHILE DO
%token IF THEN ELSE READ WRITE AND OR NOT DIV
%token LPAREN RPAREN SEMICOLON IGUAL DIFERENTE MENOR MENORIGUAL
%token MAIOR MAIORIGUAL MAIS MENOS VEZES ATRIB COLON VIRGULA PONTO
%token ID NUM

%%

programa:
        PROGRAM ID PONTO
        ;

%%

void yyerror(const char *s) {
    printf("Erro sintático: %s\n", s);
}

int main() {
    return yyparse();
}
