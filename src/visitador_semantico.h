#ifndef SEMANTIC_VISITOR_H
#define SEMANTIC_VISITOR_H

#include "visitor.h"
#include "tabela_simbolos.h"
#include <iostream>
#include <string>

class SemanticVisitor : public Visitor {
private:
    TabelaSimbolos ts;
    bool temErro;


    std::string nomeFuncaoAtual;
    bool encontrouRetorno; 

    void erro(const std::string& msg) {
        std::cerr << "ERRO SEMANTICO: " << msg << std::endl;
        temErro = true;
    }

public:
    SemanticVisitor() : temErro(false), nomeFuncaoAtual(""), encontrouRetorno(false) {}
    
    bool houveErro() const { return temErro; }

    // Expressões
    void visit(ExprValorInteiro& node) override;
    void visit(ExprValorBool& node) override;
    void visit(ExprComVariavel& node) override;
    void visit(ExprBinaria& node) override;
    void visit(ExprUnaria& node) override;
    void visit(ExprChamadaFunc& node) override;

    // Comandos
    void visit(CmdBeginEnd& node) override;
    void visit(CmdAtribuicao& node) override;
    void visit(CmdIf& node) override;
    void visit(CmdWhile& node) override;
    void visit(CmdChamadaProc& node) override;
    void visit(CmdRead& node) override;
    void visit(CmdWrite& node) override;

    // Declarações e Programa
    void visit(DeclararVar& node) override;
    void visit(DeclararProcedimento& node) override;
    void visit(DeclararFuncao& node) override;
    void visit(Programa& node) override;
};

#endif