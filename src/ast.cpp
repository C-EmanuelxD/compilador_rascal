#include "ast.h"
#include "visitor.h"

void acceptarArvoreIdentacao(int nivel){
    for(int i=0; i < nivel; i++){
        std::cout << "  " << std::endl;
    }
}



void ExprValorInteiro::accept(Visitor& v){
    v.visit(*this);
}

void ExprValorBool::accept(Visitor& v){
    v.visit(*this);
}

void ExprComVariavel::accept(Visitor& v){
    v.visit(*this);
}

void ExprBinaria::accept(Visitor& v){
    v.visit(*this);
}

void ExprUnaria::accept(Visitor& v){
    v.visit(*this);
}

void ExprChamadaFunc::accept(Visitor& v){
    v.visit(*this);
}

void CmdBeginEnd::accept(Visitor& v){
    v.visit(*this);
}

void CmdAtribuicao::accept(Visitor& v){
    v.visit(*this);
}

void CmdIf::accept(Visitor& v){
    v.visit(*this);
}

void CmdWhile::accept(Visitor& v){
    v.visit(*this);
}

void CmdChamadaProc::accept(Visitor& v){
    v.visit(*this);
}

void CmdRead::accept(Visitor& v){
    v.visit(*this);
}

void CmdWrite::accept(Visitor& v){
    v.visit(*this);
}

void DeclararVar::accept(Visitor& v){
    v.visit(*this);
}

void DeclararProcedimento::accept(Visitor& v){
    v.visit(*this);
}

void DeclararFuncao::accept(Visitor& v){
    v.visit(*this);
}

void Programa::accept(Visitor& v){
    v.visit(*this);
}