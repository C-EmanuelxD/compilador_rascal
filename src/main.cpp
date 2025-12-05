#include <iostream>
#include <cstdio>
#include "ast.h"
#include "printer.h"
#include "visitador_semantico.h" // <--- 1. Inclua o cabeçalho do semântico
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

    std::cout << ">>> Iniciando Analise Sintatica..." << std::endl;

    int resultado = yyparse();

    if (resultado == 0)
    {
        std::cout << "Analise Sintatica concluida com SUCESSO!" << std::endl;

        if (root != nullptr)
        {
            // --- Impressão da AST (Opcional, mas útil para debug) ---
            std::cout << "\n>>> Imprimindo Arvore Sintatica Abstrata (AST):" << std::endl;
            PrintVisitor printer;
            root->accept(printer);
            std::cout << ">>> Fim da impressao.\n" << std::endl;

            // --- 2. Análise Semântica ---
            std::cout << ">>> Iniciando Analise Semantica..." << std::endl;
            
            SemanticVisitor semantic; // Instancia o visitador
            root->accept(semantic);   // Percorre a árvore verificando regras

            if (semantic.houveErro()) 
            {
                std::cerr << "\nFALHA: Ocorreram erros semanticos. Compilacao abortada." << std::endl;
                // Deletamos a árvore antes de sair para liberar memória
                delete root;
                fclose(yyin);
                return 1; // Retorna erro para o sistema operacional
            }
            else 
            {
                std::cout << "Analise Semantica concluida com SUCESSO!" << std::endl;
                
                // --- 3. Geração de Código (Próxima etapa) ---
                // Aqui entraria o GeradorDeCodigo mepa;
                // root->accept(mepa);
            }
            
            // Limpeza final de memória
            delete root;
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