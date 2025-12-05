#include "printer.h"
#include "ast.h"

const char* OperacaoToChar(TipoOperacao op){
    switch(op){
        case OP_ADD: return "+";
        case OP_SUB: return "-";
        case OP_MUL: return "*";
        case OP_DIV: return "div";
        case OP_AND: return "and";
        case OP_OR: return "or";
        case OP_NOT: return "not";
        case OP_IGUAL: return "=";
        case OP_DIFERENTE: return "<>"; 
        case OP_MENOR: return "<";
        case OP_MENOR_IGUAL: return "<=";
        case OP_MAIOR: return ">";
        case OP_MAIOR_IGUAL: return ">=";
        default: return "?";
    }
}

std::string TipoToString(RascalType tipo){
    switch (tipo){
        case TP_INT: return "integer";
        case TP_BOOL: return "boolean";
        default: return "desconhecido";
    }
}

void PrintVisitor::visit(ExprValorBool& no) {
    printIndent();
    std::cout << "Bool: " << (no.value ? "true" : "false") << std::endl;
}

void PrintVisitor::visit(ExprValorInteiro& no) {
    printIndent();
    std::cout << "Int: " << no.value << std::endl;
}

void PrintVisitor::visit(ExprComVariavel& no) {
    printIndent();
    std::cout << "VarLoad: " << no.nome << std::endl;
}

void PrintVisitor::visit(ExprBinaria& no) {
    printIndent();
    std::cout << "BinOp (" << OperacaoToChar(no.op) << ")" << std::endl;
    
    nivel++;
    no.expr1->accept(*this);
    no.expr2->accept(*this);
    nivel--;
}

void PrintVisitor::visit(ExprUnaria& no) {
    printIndent();
    std::cout << "UnOp (" << OperacaoToChar(no.op) << ")" << std::endl;
    
    nivel++;
    no.expressao->accept(*this);
    nivel--;
}

void PrintVisitor::visit(ExprChamadaFunc& no) {
    printIndent();
    std::cout << "ChamadaFuncao: " << no.name << std::endl;

    nivel++;
    for (auto arg : no.argumentos) {
        arg->accept(*this);
    }
    nivel--;
}

void PrintVisitor::visit(CmdBeginEnd& no) {
    printIndent();
    std::cout << "Bloco (Begin/End)" << std::endl;

    nivel++;
    for (auto cmd : no.comandos) {
        cmd->accept(*this);
    }
    nivel--;
}

void PrintVisitor::visit(CmdAtribuicao& no) {
    printIndent();
    std::cout << "Atribuicao (:=)" << std::endl;

    nivel++;
    printIndent(); 
    std::cout << "Var: " << no.variavel << std::endl;
    
    printIndent(); 
    std::cout << "Expr:" << std::endl;
    nivel++;
    no.expressao->accept(*this);
    nivel--;
    nivel--;
}

void PrintVisitor::visit(CmdIf& no) {
    printIndent();
    std::cout << "If" << std::endl;

    nivel++; 
    

    printIndent(); std::cout << "Condicao:" << std::endl;
    nivel++;
    no.condicao->accept(*this);
    nivel--;


    printIndent(); std::cout << "Then:" << std::endl;
    nivel++;
    no.CmdThen->accept(*this);
    nivel--;


    if (no.CmdElse != nullptr) {
        printIndent(); std::cout << "Else:" << std::endl;
        nivel++;
        no.CmdElse->accept(*this);
        nivel--;
    }

    nivel--;
}

void PrintVisitor::visit(CmdWhile& no) {
    printIndent();
    std::cout << "While" << std::endl;

    nivel++;
    
    printIndent(); std::cout << "Condicao:" << std::endl;
    nivel++;
    no.condicao->accept(*this);
    nivel--;

    printIndent(); std::cout << "Do:" << std::endl;
    nivel++;
    no.corpo->accept(*this);
    nivel--;

    nivel--;
}

void PrintVisitor::visit(CmdRead& no) {
    printIndent();
    std::cout << "Read ( ";

    for (const auto& var : no.nome_variaveis) {
        std::cout << var << " ";
    }
    std::cout << ")" << std::endl;
}

void PrintVisitor::visit(CmdWrite& no) {
    printIndent();
    std::cout << "Write" << std::endl;

    nivel++;
    for (auto expr : no.expressoes) {
        expr->accept(*this);
    }
    nivel--;
}

void PrintVisitor::visit(CmdChamadaProc& no) {
    printIndent();
    std::cout << "ChamadaProcedimento: " << no.nome << std::endl;

    nivel++;
    for (auto arg : no.argumentos) {
        arg->accept(*this);
    }
    nivel--;
}

void PrintVisitor::visit(DeclararVar& no) {
    printIndent();
    std::cout << "Declarar Var: ";

    for (size_t i = 0; i < no.nomes.size(); i++) {
        std::cout << no.nomes[i];
        if (i < no.nomes.size() - 1) std::cout << ", ";
    }
    std::cout << " : " << TipoToString(no.tipo) << std::endl;
}

void PrintVisitor::visit(DeclararProcedimento& no) {
    printIndent();
    std::cout << "Declarar Procedimento: " << no.nome << std::endl;

    nivel++;
    

    if (!no.parametros.empty()) {
        printIndent(); std::cout << "Parametros:" << std::endl;
        nivel++;
        for (auto p : no.parametros) p->accept(*this);
        nivel--;
    }


    if (!no.variaveis_locais.empty()) {
        printIndent(); std::cout << "Locais:" << std::endl;
        nivel++;
        for (auto v : no.variaveis_locais) v->accept(*this);
        nivel--;
    }


    if (no.corpo) {
        printIndent(); std::cout << "Corpo:" << std::endl;
        nivel++;
        no.corpo->accept(*this);
        nivel--;
    }

    nivel--;
}

void PrintVisitor::visit(DeclararFuncao& no) {
    printIndent();
    std::cout << "Declarar Funcao: " << no.nome 
              << " (Retorno: " << TipoToString(no.tipo_retorno) << ")" << std::endl;

    nivel++;
    

    if (!no.parametros.empty()) {
        printIndent(); std::cout << "Parametros:" << std::endl;
        nivel++;
        for (auto p : no.parametros) p->accept(*this);
        nivel--;
    }


    if (!no.variaveis_locais.empty()) {
        printIndent(); std::cout << "Locais:" << std::endl;
        nivel++;
        for (auto v : no.variaveis_locais) v->accept(*this);
        nivel--;
    }


    if (no.corpo) {
        printIndent(); std::cout << "Corpo:" << std::endl;
        nivel++;
        no.corpo->accept(*this);
        nivel--;
    }

    nivel--;
}

// --- PROGRAMA (RAIZ) ---

void PrintVisitor::visit(Programa& no) {
    std::cout << "========== AST RASCAL ============" << std::endl;
    std::cout << "Programa: " << no.nome_prog << std::endl;

    nivel++;

    // 1. Variáveis Globais
    if (!no.variaveis_globais.empty()) {
        printIndent(); std::cout << "Variaveis globais" << std::endl;
        nivel++;
        for (auto v : no.variaveis_globais) v->accept(*this);
        nivel--;
    }

    if (!no.subrotinas_globais.empty()) {
        printIndent(); std::cout << "Subrotinas" << std::endl;
        nivel++;
        for (auto s : no.subrotinas_globais) {
            //Usa polimorfismo pra saber que tipo de subrotina é
            s->accept(*this); 
        }
        nivel--;
    }


    if (no.bloco_principal) {
        printIndent(); std::cout << "Bloco principal" << std::endl;
        nivel++;
        no.bloco_principal->accept(*this);
        nivel--;
    }

    nivel--;
    std::cout << "================================" << std::endl;
}