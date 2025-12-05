#ifndef VISITOR_H
#define VISITOR_H

class ExprValorInteiro;
class ExprValorBool;
class ExprComVariavel;
class ExprBinaria;
class ExprUnaria;
class ExprChamadaFunc;
class CmdBeginEnd;
class CmdAtribuicao;
class CmdIf;
class CmdWhile;
class CmdRead;
class CmdWrite;
class CmdChamadaProc;
class DeclararVar;
class DeclararProcedimento;
class DeclararFuncao;
class Programa;

//Interface visitor para visitar cada um dos nós concretos da árvore.
class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(ExprValorInteiro& no) = 0;
    virtual void visit(ExprValorBool& no) = 0;
    virtual void visit(ExprComVariavel& no) = 0;
    virtual void visit(ExprBinaria& no) = 0;
    virtual void visit(ExprUnaria& no) = 0;
    virtual void visit(ExprChamadaFunc& no) = 0;

    virtual void visit(CmdBeginEnd& no) = 0;
    virtual void visit(CmdAtribuicao& no) = 0;
    virtual void visit(CmdIf& no) = 0;
    virtual void visit(CmdWhile& no) = 0;
    virtual void visit(CmdRead& no) = 0;
    virtual void visit(CmdWrite& no) = 0;
    virtual void visit(CmdChamadaProc& no) = 0;

    virtual void visit(DeclararVar& no) = 0;
    virtual void visit(DeclararProcedimento& no) = 0;
    virtual void visit(DeclararFuncao& no) = 0;
    
    virtual void visit(Programa& no) = 0;
};

#endif