#ifndef GERADOR_MEPA_H
#define GERADOR_MEPA_H

#include "visitor.h"
#include "ast.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

struct VarMepa {
    int nivel;
    int deslocamento;
    std::string rotulo;
};

class GeradorMepa : public Visitor {
private:
    std::vector<std::string> instrucoes;
    
    std::vector<std::map<std::string, VarMepa>> tabelaSimbolos;
    
    int nivelAtual;
    int deslocamentoAtual;
    int contadorRotulos;

    void emit(std::string cmd, std::string arg = "");
    void emitLabel(std::string label);
    std::string novoRotulo();
    
    void entrarEscopo();
    void sairEscopo(int nVarsLocais);
    VarMepa* buscar(std::string nome);

public:
    GeradorMepa();
    
    void salvarEmArquivo(std::string nomeArquivo);

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