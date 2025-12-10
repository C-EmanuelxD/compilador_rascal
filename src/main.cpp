#include <iostream>
#include <cstdio>
#include <string>
#include "ast.h"
#include "printer.h"
#include "visitador_semantico.h"
#include "gerador_mepa.h" 
#include "rascal.tab.h"

extern FILE *yyin;
extern int yyparse();
extern Programa *root; 

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Uso incorreto." << std::endl;
        std::cerr << "Sintaxe: " << argv[0] << " <arquivo_entrada.rascal> [arquivo_saida.mep]" << std::endl;
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

    if (resultado == 0 && root != nullptr)
    {
        std::cout << "Sintaxe correta." << std::endl;

        // (Opcional) Imprimir AST para debug
        // std::cout << "\n>>> Imprimindo AST:" << std::endl;
        // PrintVisitor printer;
        // root->accept(printer);
        // std::cout << ">>> Fim da AST.\n" << std::endl;

        std::cout << "Iniciando Analise Semantica..." << std::endl;
        SemanticVisitor semantic;
        root->accept(semantic);

        if (semantic.houveErro())
        {
            std::cerr << "\nErros semanticos encontrados. Compilacao abortada." << std::endl;
            delete root;
            fclose(yyin);
            return 1;
        }
        else
        {
            std::cout << "Semantica correta." << std::endl;
            std::cout << "Gerando Codigo MEPA" << std::endl;
            std::string arquivoSaida = (argc >= 3) ? argv[2] : "saida.mep";

            GeradorMepa gerador;
            root->accept(gerador);
            gerador.salvarEmArquivo(arquivoSaida);

            std::cout << "Codigo gerado em '" << arquivoSaida << "'." << std::endl;
        }
        delete root;
    }
    else
    {
        std::cerr << "Erros de sintaxe detectados." << std::endl;
        fclose(yyin);
        return 1;
    }

    fclose(yyin);
    return 0;
}