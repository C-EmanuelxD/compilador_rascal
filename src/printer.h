#ifndef PRINTER_H
#define PRINTER_H

#include "visitor.h"
#include <iostream>

class PrintVisitor : public Visitor {// Classe de print para mostrar os nós
    int nivel = 0; //Controlar identação pra mostrar os nós da arvore

    void printIndent() {
        for (int i = 0; i < nivel; ++i) std::cout << "  ";
    }

public:
    
    void visit(ExprValorInteiro& no) override;
    void visit(ExprValorBool& no) override;
    void visit(ExprComVariavel& no) override;
    void visit(ExprBinaria& no) override;
    void visit(ExprUnaria& no) override;
    void visit(ExprChamadaFunc& no) override;

    void visit(CmdBeginEnd& no) override;
    void visit(CmdAtribuicao& no) override;
    void visit(CmdIf& no) override;
    void visit(CmdWhile& no) override;
    void visit(CmdRead& no) override;
    void visit(CmdWrite& no) override;
    void visit(CmdChamadaProc& no) override;

    void visit(DeclararVar& no) override;
    void visit(DeclararProcedimento& no) override;
    void visit(DeclararFuncao& no) override;
    
    void visit(Programa& no) override;
};

#endif