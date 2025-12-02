%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    extern int yylex();
    extern int yylineno;
    extern char* yytext;

    void yyerror(const char *s);
%}

 %define parse.error verbose

%token T_PROGRAM T_BEGIN T_END T_VAR T_PROCEDURE T_FUNCTION
%token T_IF T_THEN T_ELSE T_WHILE T_DO
%token T_OR T_AND T_NOT T_DIV
%token T_READ T_WRITE
%token T_TRUE T_FALSE
%token T_INTEGER T_BOOLEAN

%token T_SEMICOLON T_COLON T_PONTO T_VIRGULA
%token T_LPAREN T_RPAREN
%token T_ATRIB 
%token T_IGUAL T_DIFERENTE T_MENOR T_MENORIGUAL T_MAIOR T_MAIORIGUAL
%token T_MAIS T_MENOS T_VEZES

%union{
    int ival;
    char *sval;
}
%token <ival> T_NUM
%token <sval> T_ID     

%nonassoc LOWER_THAN_ELSE
%nonassoc T_ELSE

/* Simbolo inicial */
%start programa

%%
    programa : T_PROGRAM T_ID T_SEMICOLON bloco T_PONTO;

    bloco : declaracao_var_vazio declaracao_subrotina_vazio comando_composto;

    /* tratar o caso de var ou function nao existir*/
    declaracao_var_vazio :   | secao_declaracao_variaveis;
    declaracao_subrotina_vazio :   | secao_declaracao_subrotinas;

    /*
        <seção_declaração_variáveis> ::=
        'var' <declaração_variáveis> ';' { <declaração_variáveis> ';' }
        <declaração_variáveis> ::=
        <lista_identificadores> ':' <tipo>
        <lista_identificadores> ::=
        <identificador> { ',' <identificador> }
        <tipo> ::=
        'boolean' | 'integer'

        o bloco abaixo faz isso
    */
    secao_declaracao_variaveis : T_VAR repeticao_declaracao;
    repeticao_declaracao : declaracao_vars T_SEMICOLON | repeticao_declaracao declaracao_vars T_SEMICOLON;
    declaracao_vars: lista_identificadores T_COLON tipo;
    lista_identificadores: T_ID | lista_identificadores T_VIRGULA T_ID;
    tipo : T_BOOLEAN | T_INTEGER;


    secao_declaracao_subrotinas : declaracao_subrotina T_SEMICOLON | secao_declaracao_subrotinas declaracao_subrotina T_SEMICOLON;
    declaracao_subrotina : procedimento | funcao;

    procedimento : T_PROCEDURE T_ID parametros_gerais_subrotina T_SEMICOLON bloco_subrotina;
    funcao : T_FUNCTION T_ID parametros_gerais_subrotina T_COLON tipo T_SEMICOLON bloco_subrotina;

    parametros_gerais_subrotina :   | T_LPAREN lista_parametros  T_RPAREN;
    lista_parametros : secao_parametros | lista_parametros T_SEMICOLON secao_parametros;
    secao_parametros : lista_identificadores T_COLON tipo;

    bloco_subrotina : declaracao_var_vazio comando_composto;


    comando_composto : T_BEGIN lista_comandos T_END;

    lista_comandos : comando | lista_comandos T_SEMICOLON comando;

    comando : atribuicao | chamada_procedimento | condicional | repeticao | leitura | escrita | comando_composto |  ;

    atribuicao : T_ID T_ATRIB expressao;

    expressao: expressao_simples | expressao_simples relacao expressao_simples;

    relacao: T_IGUAL 
    | T_DIFERENTE 
    | T_MENOR 
    | T_MENORIGUAL 
    | T_MAIOR 
    | T_MAIORIGUAL;

    expressao_simples: termo 
    | T_MAIS termo 
    | T_MENOS termo 
    | expressao_simples T_MAIS termo 
    | expressao_simples T_MENOS termo 
    | expressao_simples T_OR termo;

    termo: fator 
    | termo T_VEZES fator 
    | termo T_DIV fator 
    | termo T_AND fator;

    fator: T_ID 
    | T_ID T_LPAREN lista_expressoes_vazio T_RPAREN 
    | T_NUM 
    | T_TRUE 
    | T_FALSE 
    | T_LPAREN expressao T_RPAREN 
    | T_NOT fator;

    chamada_procedimento: T_ID T_LPAREN lista_expressoes_vazio T_RPAREN;
    
    condicional : T_IF expressao T_THEN comando %prec LOWER_THAN_ELSE | T_IF expressao T_THEN comando T_ELSE comando;

    repeticao : T_WHILE expressao T_DO comando;

    leitura: T_READ T_LPAREN lista_identificadores T_RPAREN;

    escrita : T_WRITE T_LPAREN lista_expressoes_vazio T_RPAREN;

    lista_expressoes_vazio :   | lista_expressoes;
    lista_expressoes: expressao | lista_expressoes T_VIRGULA expressao;
    
%%


void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe na linha %d: %s. Token encontrado: '%s'\n", yylineno, s, yytext);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Uso: %s <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    extern FILE *yyin;
    yyin = fopen(argv[1], "r");

    if (!yyin) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    yyparse();

    printf("Execucao concluida com sucesso!");

    fclose(yyin);
    return 0;
}