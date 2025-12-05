#include "ast.h"

void PrintarArvoreIdentacao(int nivel){
    for(int i=0; i < nivel; i++){
        std::cout << "  " << std::endl;
    }
}

// Converte a operação em um caractere representativo
char OperacaoToChar(TipoOperacao op){
    switch(op){
        case OP_ADD: return '+';
        case OP_SUB: return '-';
        case OP_MUL: return '*';
        case OP_DIV: return 'div';
        case OP_AND: return 'and';
        case OP_OR: return 'or';
        case OP_NOT: return 'not';
        case OP_IGUAL: return '=';
        case OP_DIFERENTE: return '<>'; 
        case OP_MENOR: return '<';
        case OP_MENOR_IGUAL: return '<=';
        case OP_MAIOR: return '>';
        case OP_MAIOR_IGUAL: return '>=';
        default: return '?'; //caso de erro, caractere não existe 
    }
}

std::string TipoToString(RascalType tipo){
    switch (tipo){
        case TP_INT: return "integer";
        case TP_BOOL: return "boolean";
        default: return "desconhecido";
    }
}

void ExprValorInteiro::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << " (ExprValorInteiro) Int: "<< value << std::endl;
}

void ExprValorBool::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(ExprValorBool) Bool: " << (value ? "true" : false) << std::endl;
}

void ExprComVariavel::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(ExprComVariavel) Var: " << nome << std::endl;
}

void ExprBinaria::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(ExprBinaria) OperacaoBinaria (" << OperacaoToChar(op) << ")" << std::endl;

    expr1->print(nivel+1);
    expr2->print(nivel+1);
}

void ExprUnaria::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(ExprUnaria) OperacaoUnaria (" << OperacaoToChar(op) << ")" << std::endl;

    expressao->print(nivel+1);
}

void ExprChamadaFunc::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(ExprChamadaFunc) ChamadaFuncao: " << name << std::endl;

    for(Expressao* expr : argumentos){
        expr->print(nivel+1);
    }

}

void CmdBeginEnd::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(CmdBeginEnd) ComandoBeginEnd" << std::endl;

    for(Comando* comand : comandos){
        comand->print(nivel+1);
    }
}

void CmdAtribuicao::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(CmdAtribuicao) ComandoAtribuicao: " << variavel << std::endl;
    expressao->print(nivel+1);
}

void CmdIf::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(CmdIf) If" << std::endl;
    condicao->print(nivel+1);
    PrintarArvoreIdentacao(nivel);
    std::cout << "(CmdIf) Then:" << std::endl;
    CmdThen->print(nivel+1);

    if(CmdElse != nullptr){
        PrintarArvoreIdentacao(nivel);
        std::cout << "(CmdIf) Else:" << std::endl;
        CmdElse->print(nivel + 1);
    }
}

void CmdWhile::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(CmdWhile) While: " << std::endl;
    condicao->print(nivel+1);
    PrintarArvoreIdentacao(nivel);
    std::cout << "(CmdWhile) Do:" << std::endl;
    corpo->print(nivel+1);
}

void CmdChamadaProc::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(CmdChamadaProc) ChamadaProcedimento: " << nome << std::endl;

    for(Expressao* expr : argumentos){
        expr->print(nivel+1);
    }
}

void CmdRead::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(CmdRead) Read" << std::endl;

    for(const std::string& var_name : nome_variaveis){
        PrintarArvoreIdentacao(nivel+1);
        std::cout << "Var: " << var_name << std::endl;
    }
}

void CmdWrite::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(CmdWrite) Write" << std::endl;

    for(Expressao* expr : expressoes){
        expr->print(nivel+1);
    }
}

void DeclararVar::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(DeclararVar) DeclaracaoVariavel. Tipo: " << TipoToString(tipo) << std::endl;
    for(const std::string& var_name : nomes){
        std::cout << "Var: " << var_name << std::endl;
    }
}

void DeclararSubrotina::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(DeclararSubrotina) DeclaracaoSubrotina. Nome: " << nome << std::endl;
    if (!parametros.empty()) {
        PrintarArvoreIdentacao(nivel + 1);
        std::cout << "Parametros:" << std::endl;
        for (auto p : parametros) {
            p->print(nivel + 2); // Os parâmetros são filhos, então +2
        }
    }
    if (!variaveis_locais.empty()) {
        PrintarArvoreIdentacao(nivel + 1);
        std::cout << "Variaveis Locais:" << std::endl;
        for (auto v : variaveis_locais) {
            v->print(nivel + 2);
        }
    }

    if (corpo != nullptr) {
        PrintarArvoreIdentacao(nivel + 1);
        std::cout << "Corpo:" << std::endl;
        corpo->print(nivel + 2);
    }
}

void DeclararProcedimento::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(DeclararProcedimento) DeclaracaoProcedimento. Nome: " << nome << std::endl;

    if (!parametros.empty()) {
        PrintarArvoreIdentacao(nivel + 1);
        std::cout << "Parametros:" << std::endl;
        for (auto p : parametros) {
            p->print(nivel + 2); // Os parâmetros são filhos, então +2
        }
    }

    if (!variaveis_locais.empty()) {
        PrintarArvoreIdentacao(nivel + 1);
        std::cout << "Variaveis Locais:" << std::endl;
        for (auto v : variaveis_locais) {
            v->print(nivel + 2);
        }
    }

    if (corpo != nullptr) {
        PrintarArvoreIdentacao(nivel + 1);
        std::cout << "Corpo:" << std::endl;
        corpo->print(nivel + 2);
    }
    
}

void DeclararFuncao::print(int nivel) const{
    PrintarArvoreIdentacao(nivel);
    std::cout << "(DeclararFunc) DeclaracaoFuncao. Nome: " << nome << std::endl;
    std::cout << "(DeclararFunc) Retorno: " << TipoToString(tipo_retorno) << std::endl;


    if (!parametros.empty()) {
        PrintarArvoreIdentacao(nivel + 1);
        std::cout << "Parametros:" << std::endl;
        for (auto p : parametros) {
            p->print(nivel + 2); // Os parâmetros são filhos, então +2
        }
    }

    if (!variaveis_locais.empty()) {
        PrintarArvoreIdentacao(nivel + 1);
        std::cout << "Variaveis Locais:" << std::endl;
        for (auto v : variaveis_locais) {
            v->print(nivel + 2);
        }
    }

    if (corpo != nullptr) {
        PrintarArvoreIdentacao(nivel + 1);
        std::cout << "Corpo:" << std::endl;
        corpo->print(nivel + 2);
    }
}

void Programa::print(int nivel) const{
    std::cout << "Programa: " << nome_prog << std::endl;

    if (!variaveis_globais.empty()) {
        std::cout << "  Var globais: " << std::endl;
        for (auto v : variaveis_globais) v->print(nivel + 2);
    }

    if (!subrotinas_globais.empty()) {
        std::cout << "  subrotinas globais: " << std::endl;
        for (auto s : subrotinas_globais) s->print(nivel + 2);
    }

    std::cout << "  bloco principal:" << std::endl;
    if (bloco_principal) {
        bloco_principal->print(nivel + 2);
    }
}