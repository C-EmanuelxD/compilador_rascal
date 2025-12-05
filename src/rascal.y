%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <vector>
    #include <string>
    #include "ast.h"

    extern Programa* root;

    extern int yylex();
    extern int yylineno;
    extern char* yytext;

    void yyerror(const char *s);

    Programa* root = nullptr;
%}

%code requires {
    #include "ast.h"
    #include <vector>
    #include <string>

    // Estrutura auxiliar para transportar os dados do bloco (Vars + Subs + Corpo)
    struct BlocoData {
        std::vector<DeclararVar*>* vars;
        std::vector<DeclararSubrotina*>* subs;
        CmdBeginEnd* corpo;
    };
}

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

    Programa* ptr_programa;
    Comando* ptr_comando;
    CmdBeginEnd* ptr_bloco_cmd;
    Expressao* ptr_expr;
    DeclararVar* ptr_decl_var;
    DeclararSubrotina* ptr_decl_sub;
    RascalType type_val;
    BlocoData* ptr_dados_bloco;
    std::vector<std::string>* vec_str;
    std::vector<DeclararVar*>* vec_decl_var;
    std::vector<DeclararSubrotina*>* vec_decl_sub;
    std::vector<Comando*>* vec_cmd;
    std::vector<Expressao*>* vec_expr;
}
%token <ival> T_NUM
%token <sval> T_ID     

%nonassoc LOWER_THAN_ELSE
%nonassoc T_ELSE

%type <ptr_programa> programa
%type <ptr_dados_bloco> bloco bloco_subrotina
%type <ptr_bloco_cmd> comando_composto
%type <ptr_comando> comando atribuicao condicional repeticao leitura escrita chamada_procedimento

%type <ptr_expr> expressao expressao_simples termo fator
%type <ival> relacao

%type <vec_decl_var> secao_declaracao_variaveis declaracao_var_vazio repeticao_declaracao 
%type <ptr_decl_var> declaracao_vars
%type <vec_str> lista_identificadores
%type <type_val> tipo

// Sub-rotinas
%type <vec_decl_sub> secao_declaracao_subrotinas declaracao_subrotina_vazio
%type <ptr_decl_sub> declaracao_subrotina procedimento funcao

// Parametros
%type <vec_decl_var> parametros_gerais_subrotina lista_parametros
%type <ptr_decl_var> secao_parametros

// Listas de Comandos e Expressões
%type <vec_cmd> lista_comandos
%type <vec_expr> lista_expressoes lista_expressoes_vazio

/* Simbolo inicial */
%start programa

%%
    programa : T_PROGRAM T_ID T_SEMICOLON bloco T_PONTO{
        root = new Programa($2);
        
        
        if ($4->vars) root->variaveis_globais = *($4->vars);
        if ($4->subs) root->subrotinas_globais = *($4->subs);
        root->bloco_principal = $4->corpo;

        delete $4;
        free($2);
    };

    bloco : declaracao_var_vazio declaracao_subrotina_vazio comando_composto{
        $$ = new BlocoData();
        $$->vars = $1;
        $$->subs = $2;
        $$->corpo = $3;
    };

    /* tratar o caso de var ou function nao existir*/
    declaracao_var_vazio :  {$$ = new std::vector<DeclararVar*>();} | secao_declaracao_variaveis {$$ = $1;};
    declaracao_subrotina_vazio :  { $$ = new std::vector<DeclararSubrotina*>(); } | secao_declaracao_subrotinas { $$ = $1; };

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
    secao_declaracao_variaveis : T_VAR repeticao_declaracao { $$ = $2; };

    repeticao_declaracao : declaracao_vars T_SEMICOLON{
        { 
            $$ = new std::vector<DeclararVar*>();
            $$->push_back($1);
        }
    } | repeticao_declaracao declaracao_vars T_SEMICOLON{
        {
            $$ = $1;
            $$->push_back($2);
        };
    };

    declaracao_vars: lista_identificadores T_COLON tipo{
        $$ = new DeclararVar(*$1, $3);
        delete $1;
    };;

    lista_identificadores
        : T_ID {
            $$ = new std::vector<std::string>();
            $$->push_back(std::string($1));
            free($1);
        }
        | lista_identificadores T_VIRGULA T_ID {
            $$ = $1;
            $$->push_back(std::string($3));
            free($3);
        };

    tipo 
        : T_BOOLEAN { $$ = TP_BOOL; }
        | T_INTEGER { $$ = TP_INT; };


    secao_declaracao_subrotinas 
        : declaracao_subrotina T_SEMICOLON {
            $$ = new std::vector<DeclararSubrotina*>();
            $$->push_back($1);
        }
        | secao_declaracao_subrotinas declaracao_subrotina T_SEMICOLON {
            $$ = $1;
            $$->push_back($2);
        };
    declaracao_subrotina : procedimento { $$ = $1; } | funcao { $$ = $1; };

    procedimento : T_PROCEDURE T_ID parametros_gerais_subrotina T_SEMICOLON bloco_subrotina {

        DeclararProcedimento* proc = new DeclararProcedimento($2);

        if ($3) proc->parametros = *($3);
        
    
        if ($5->vars) proc->variaveis_locais = *($5->vars);
        proc->corpo = $5->corpo;

        $$ = proc;
        free($2);
        delete $3; delete $5;
    };

    funcao : T_FUNCTION T_ID parametros_gerais_subrotina T_COLON tipo T_SEMICOLON bloco_subrotina {
        // Cria funcao com tipo de retorno
        DeclararFuncao* func = new DeclararFuncao($2, $5);
        
        if ($3) func->parametros = *($3);
        
        if ($7->vars) func->variaveis_locais = *($7->vars);
        func->corpo = $7->corpo;

        $$ = func;
        free($2);
        delete $3; delete $7;
    };

    parametros_gerais_subrotina 
        : { $$ = new std::vector<DeclararVar*>(); }
        | T_LPAREN lista_parametros T_RPAREN { $$ = $2; };
    lista_parametros 
        : secao_parametros {
            $$ = new std::vector<DeclararVar*>();
            $$->push_back($1);
        }
        | lista_parametros T_SEMICOLON secao_parametros {
            $$ = $1;
            $$->push_back($3);
        };
    secao_parametros : lista_identificadores T_COLON tipo {
        $$ = new DeclararVar(*$1, $3);
        delete $1;
    };

    bloco_subrotina : declaracao_var_vazio comando_composto {
        $$ = new BlocoData();
        $$->vars = $1;
        $$->subs = nullptr; // Não permitido no Rascal
        $$->corpo = $2;
    };


    comando_composto : T_BEGIN lista_comandos T_END {
        $$ = new CmdBeginEnd();
        $$->comandos = *($2);
        delete $2;
    };

    lista_comandos 
        : comando {
            $$ = new std::vector<Comando*>();
            if ($1 != nullptr) $$->push_back($1);
        }
        | lista_comandos T_SEMICOLON comando {
            $$ = $1;
            if ($3 != nullptr) $$->push_back($3);
        };

    comando 
        : atribuicao { $$ = $1; }
        | chamada_procedimento { $$ = $1; }
        | condicional { $$ = $1; }
        | repeticao { $$ = $1; }
        | leitura { $$ = $1; }
        | escrita { $$ = $1; }
        | comando_composto { $$ = $1; }
        | /* vazio */ { $$ = nullptr; };

    atribuicao : T_ID T_ATRIB expressao {
        $$ = new CmdAtribuicao($1, $3);
        free($1);
    };

    expressao: expressao_simples { $$ = $1; }
             | expressao_simples relacao expressao_simples {
                 $$ = new ExprBinaria($1, (TipoOperacao)$2, $3);
             };

    relacao
        : T_IGUAL { $$ = OP_IGUAL; }
        | T_DIFERENTE { $$ = OP_DIFERENTE; }
        | T_MENOR { $$ = OP_MENOR; }
        | T_MENORIGUAL { $$ = OP_MENOR_IGUAL; }
        | T_MAIOR { $$ = OP_MAIOR; }
        | T_MAIORIGUAL { $$ = OP_MAIOR_IGUAL; };

    expressao_simples
        : termo { $$ = $1; }
        | T_MAIS termo { $$ = $2;}
        | T_MENOS termo { $$ = new ExprUnaria(OP_SUB, $2); }
        | expressao_simples T_MAIS termo { $$ = new ExprBinaria($1, OP_ADD, $3); }
        | expressao_simples T_MENOS termo { $$ = new ExprBinaria($1, OP_SUB, $3); }
        | expressao_simples T_OR termo { $$ = new ExprBinaria($1, OP_OR, $3); };

    termo
        : fator { $$ = $1; }
        | termo T_VEZES fator { $$ = new ExprBinaria($1, OP_MUL, $3); }
        | termo T_DIV fator { $$ = new ExprBinaria($1, OP_DIV, $3); }
        | termo T_AND fator { $$ = new ExprBinaria($1, OP_AND, $3); };

    fator
        : T_ID {
            $$ = new ExprComVariavel($1);
            free($1);
        }
        | T_ID T_LPAREN lista_expressoes_vazio T_RPAREN {
            $$ = new ExprChamadaFunc($1, *($3));
            free($1);
            delete $3;
        }
        | T_NUM { $$ = new ExprValorInteiro($1); }
        | T_TRUE { $$ = new ExprValorBool(true); }
        | T_FALSE { $$ = new ExprValorBool(false); }
        | T_LPAREN expressao T_RPAREN { $$ = $2; }
        | T_NOT fator { $$ = new ExprUnaria(OP_NOT, $2); };

    chamada_procedimento: T_ID T_LPAREN lista_expressoes_vazio T_RPAREN {
        $$ = new CmdChamadaProc($1, *($3));
        free($1);
        delete $3;
    };
    
    condicional 
        : T_IF expressao T_THEN comando %prec LOWER_THAN_ELSE {
            $$ = new CmdIf($2, $4, nullptr);
        }
        | T_IF expressao T_THEN comando T_ELSE comando {
            $$ = new CmdIf($2, $4, $6);
        };

    repeticao : T_WHILE expressao T_DO comando {
        $$ = new CmdWhile($2, $4);
    };

    leitura: T_READ T_LPAREN lista_identificadores T_RPAREN {
        $$ = new CmdRead(*$3);
        delete $3;
    };

    escrita : T_WRITE T_LPAREN lista_expressoes_vazio T_RPAREN {
        $$ = new CmdWrite(*$3);
        delete $3;
    };

    lista_expressoes_vazio 
        : /* vazio */ { $$ = new std::vector<Expressao*>(); }
        | lista_expressoes { $$ = $1; };

    lista_expressoes
        : expressao {
            $$ = new std::vector<Expressao*>();
            $$->push_back($1);
        }
        | lista_expressoes T_VIRGULA expressao {
            $$ = $1;
            $$->push_back($3);
        };
    
%%


void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe na linha %d: %s. Token encontrado: '%s'\n", yylineno, s, yytext);
}