#include <iostream>
#include <cstdio>
#include "ast.h"
#include "printer.h"
#include "rascal.tab.h"

extern FILE *yyin;
extern int yyparse();
extern Programa *root;

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        std::cerr << "Erro: Nenhum arquivo de entrada fornecido." << std::endl;
        std::cerr << "Uso: " << argv[0] << " <arquivo_rascal>" << std::endl;
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin)
    {
        std::cerr << "Erro: Nao foi possivel abrir o arquivo '" << argv[1] << "'." << std::endl;
        return 1;
    }

    std::cout << "Iniciando Analise Sintatica..." << std::endl;

    int resultado = yyparse();

    if (resultado == 0)
    {
        std::cout << "Analise Sintatica concluida com SUCESSO!" << std::endl;

        if (root != nullptr)
        {
            std::cout << "\nImprimindo Arvore Sintatica Abstrata (AST):" << std::endl;

            PrintVisitor printer;
            root->accept(printer);

            std::cout << "\n>>> Fim da impressao." << std::endl;
        }
        else
        {
            std::cerr << "Aviso: O parser finalizou com sucesso, mas a root da AST eh nula." << std::endl;
        }
    }
    else
    {
        std::cerr << "FALHA: Ocorreram erros durante a analise sintatica." << std::endl;
    }

    fclose(yyin);

    return resultado;
}