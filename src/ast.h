#ifndef AST_H
#define AST_H

#include <iostream>
#include <vector>
#include <string>

class Visitor;

///Foi feito em toda classe concreta o comando accept para o visitor visitar os nós. Apenas as concretas tem o visitor.
//Usa o double dispatch do visitor.

//Tipos de dados
enum RascalType{
    TP_INT,
    TP_BOOL,
    TP_SEM_TIPO
};

// Enum feito para operadores, para auxiliar nas expressões binárias
enum TipoOperacao{
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, //Algebricos
    OP_AND, OP_OR, OP_NOT, //Logicos
    OP_IGUAL, OP_DIFERENTE, OP_MENOR, OP_MENOR_IGUAL, OP_MAIOR, OP_MAIOR_IGUAL //Comparação
};

//Função para imprimir as operações.
const char* OperacaoToChar(TipoOperacao op);

class No{
    public:
        virtual ~No() = default; //Destrutor, usado para liberar memoria do no e n ter memor leak

        virtual void accept(Visitor& v) = 0; //Força as subclasses do nó ou seja os galhos e folhas a implementarem a visita     
};

//Expressões retornam valor
class Expressao : public No {
    public:
        RascalType type = TP_SEM_TIPO;
};

//Executam ações nop programa
class Comando : public No{

};

//Definição de variavel e subrotina
class Declaracao : public No{

};

//Numeros inteiros
class ExprValorInteiro : public Expressao{
    public:
        int value;
        ExprValorInteiro(int v) : value(v) { type = TP_INT; }

        virtual void accept(Visitor& v) override;
};

//Valor Booleano
class ExprValorBool : public Expressao{
    public:
        bool value;
        ExprValorBool(bool valor) : value(valor) { type = TP_BOOL; };
        virtual void accept(Visitor& v) override;
};

//Expressõe com possiveis variaveis x+1, etc
class ExprComVariavel : public Expressao{
    public:
        std::string nome;
        ExprComVariavel(std::string h) : nome(h) {}
        virtual void accept(Visitor& v) override;
};

//Expressao binaria, guarda a primeira expressao, a segunda e o tipo de operação q vai ser aplicada.
class ExprBinaria : public Expressao{
    public:
        Expressao *expr1, *expr2;
        TipoOperacao op;
        ExprBinaria(Expressao* expr_1, TipoOperacao operador, Expressao* expr_2) : expr1(expr_1), op(operador), expr2(expr_2){

        };

        virtual void accept(Visitor& v) override;
};

class ExprUnaria : public Expressao{
    public:
        Expressao *expressao;
        TipoOperacao op;
        ExprUnaria(TipoOperacao operacao, Expressao* expr) : op(operacao), expressao(expr) {}

        virtual void accept(Visitor& v) override;
};


//Chamada de função com retorno de valor
class ExprChamadaFunc : public Expressao{
    public:
        std::string name;
        std::vector<Expressao*> argumentos;

        ExprChamadaFunc(std::string n, std::vector<Expressao*> arg) : name(n), argumentos(arg) {}

        virtual void accept(Visitor& v) override;
};

class CmdBeginEnd : public Comando{
    public:
        std::vector<Comando*> comandos;

        void addComando(Comando* cmd) {comandos.push_back(cmd);}

        virtual void accept(Visitor& v) override;
};

class CmdAtribuicao : public Comando{
    public:
        std::string variavel;
        Expressao* expressao;

        CmdAtribuicao(std::string var, Expressao* expr) : variavel(var), expressao(expr) {}

        virtual void accept(Visitor& v) override;
};

class CmdIf : public Comando {
    public:
        Expressao* condicao;
        Comando* CmdThen; //Aponta pra qualquer tipo comando, nao precisa do then completo
        Comando* CmdElse; //Aponta pra qualquer tipo comando, nao precisa do else completo, pode ser nulo

        //pode nao ter else
        CmdIf(Expressao *cond, Comando *t, Comando *e = nullptr) : condicao(cond), CmdThen(t), CmdElse(e) {

        };

        virtual void accept(Visitor& v) override;
};


class CmdWhile : public Comando {
    public:
        Expressao* condicao;
        Comando* corpo;

        CmdWhile(Expressao *c, Comando *corp) : condicao(c), corpo(corp) {}

        virtual void accept(Visitor& v) override;
};

//Chamada de procedimento é um comando pq nao retorna valor
class CmdChamadaProc : public Comando {
    public:
        std::string nome;
        std::vector<Expressao*> argumentos;

        CmdChamadaProc(std::string n, std::vector<Expressao*> l) : nome(n), argumentos(l) {}

        virtual void accept(Visitor& v) override; 
};

class CmdRead : public Comando {
    public:
        std::vector<std::string> nome_variaveis;

        CmdRead(std::vector<std::string> nome) : nome_variaveis(nome) {}

        virtual void accept(Visitor& v) override; 

};

class CmdWrite : public Comando {
    public:
        std::vector<Expressao*> expressoes;

        CmdWrite(std::vector<Expressao*> e) : expressoes(e) {}

        virtual void accept(Visitor& v) override; 
};

class DeclararVar : public Declaracao {
    public:
        std::vector<std::string> nomes;
        RascalType tipo;

        DeclararVar(std::vector<std::string> n, RascalType t) : tipo(t), nomes(n) {}

        virtual void accept(Visitor& v) override;
};


class DeclararSubrotina : public Declaracao {
    public:
        std::string nome;
        std::vector<DeclararVar*> parametros;
        std::vector<DeclararVar*> variaveis_locais;
        CmdBeginEnd* corpo;

        RascalType tipo_retorno;

        DeclararSubrotina(std::string n, RascalType t) : nome(n), corpo(nullptr), tipo_retorno(t) {}

};

class DeclararProcedimento : public  DeclararSubrotina{
    public:
        DeclararProcedimento(std::string n) : DeclararSubrotina(n, TP_SEM_TIPO) {}

        virtual void accept(Visitor& v) override;
};

class DeclararFuncao : public DeclararSubrotina{
    public:
        
        DeclararFuncao(std::string n, RascalType r) : DeclararSubrotina(n, r) {}
        virtual void accept(Visitor& v) override;
};


//Nó principal, sempre raiz
class Programa : public No {
    public:
        std::string nome_prog;
        std::vector<DeclararVar*> variaveis_globais;
        std::vector<DeclararSubrotina*> subrotinas_globais;
        CmdBeginEnd* bloco_principal;

        Programa(std::string n) : nome_prog(n), bloco_principal(nullptr) {}

        virtual void accept(Visitor& v) override;
};

#endif