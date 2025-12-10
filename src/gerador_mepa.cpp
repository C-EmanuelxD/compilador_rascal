#include "gerador_mepa.h"
#include "ast.h"
#include <fstream>

GeradorMepa::GeradorMepa() {
    nivelAtual = 0;
    deslocamentoAtual = 0;
    contadorRotulos = 0;
    entrarEscopo();
}

void GeradorMepa::emit(std::string cmd, std::string arg) {
    if (arg.empty())
        instrucoes.push_back("\t" + cmd);
    else
        instrucoes.push_back("\t" + cmd + " " + arg);
}

void GeradorMepa::emitLabel(std::string label) {
    instrucoes.push_back(label + ":\tNADA");
}

std::string GeradorMepa::novoRotulo() {
    return "R" + std::to_string(++contadorRotulos);
}

std::string GeradorMepa::novoRotuloProc() {
    return "P" + std::to_string(++contadorRotulos);
}

void GeradorMepa::entrarEscopo() {
    tabelaSimbolos.push_back(std::map < std::string, VarMepa > ());
}

void GeradorMepa::sairEscopo(int nVarsLocais) {
    if (nVarsLocais > 0) {
        emit("DMEM", std::to_string(nVarsLocais));
    }
    tabelaSimbolos.pop_back();
}

VarMepa * GeradorMepa::buscar(std::string nome) {
    for (auto it = tabelaSimbolos.rbegin(); it != tabelaSimbolos.rend(); ++it) {
        if (it -> find(nome) != it -> end()) {
            return & (( * it)[nome]);
        }
    }
    return nullptr;
}

void GeradorMepa::salvarEmArquivo(std::string nomeArquivo) {
    std::ofstream arq(nomeArquivo);
    if (!arq.is_open()) {
        std::cerr << "Erro ao criar arquivo de saida MEPA." << std::endl;
        return;
    }
    for (const auto & linha: instrucoes) {
        arq << linha << std::endl;
    }
    arq.close();
}

void GeradorMepa::visit(Programa & no) {
    emit("INPP");

    int qtdGlobais = 0;
    if (!no.variaveis_globais.empty()) {
        for (auto
            var: no.variaveis_globais) {
            var -> accept( * this);
            qtdGlobais +=
                var -> nomes.size();
        }
    }

    if (!no.subrotinas_globais.empty()) {
        std::string rotuloMain = novoRotulo();
        emit("DSVS", rotuloMain);

        for (auto sub: no.subrotinas_globais) {
            sub -> accept( * this);
        }

        emitLabel(rotuloMain);
    }

    if (no.bloco_principal) {
        no.bloco_principal -> accept( * this);
    }

    if (qtdGlobais > 0) {
        emit("DMEM", std::to_string(qtdGlobais));
    }

    emit("PARA");
    emit("FIM");
}

void GeradorMepa::visit(DeclararVar & no) {
    emit("AMEM", std::to_string(no.nomes.size()));

    for (const auto & nome: no.nomes) {
        VarMepa v;
        v.nivel = nivelAtual;
        v.deslocamento = deslocamentoAtual++;
        tabelaSimbolos.back()[nome] = v;
    }
}

void GeradorMepa::visit(ExprValorInteiro & no) {
    emit("CRCT", std::to_string(no.value));
}

void GeradorMepa::visit(ExprValorBool & no) {
    emit("CRCT", no.value ? "1" : "0");
}

void GeradorMepa::visit(ExprComVariavel & no) {
    VarMepa * v = buscar(no.nome);
    if (v) {
        emit("CRVL", std::to_string(v -> nivel) + "," + std::to_string(v -> deslocamento));
    }
}

void GeradorMepa::visit(ExprBinaria & no) {
    no.expr1 -> accept( * this);
    no.expr2 -> accept( * this);

    switch (no.op) {
    case OP_ADD:
        emit("SOMA");
        break;
    case OP_SUB:
        emit("SUBT");
        break;
    case OP_MUL:
        emit("MULT");
        break;
    case OP_DIV:
        emit("DIVI");
        break;

    case OP_AND:
        emit("CONJ");
        break;
    case OP_OR:
        emit("DISJ");
        break;

    case OP_IGUAL:
        emit("CMIG");
        break;
    case OP_DIFERENTE:
        emit("CMDG");
        break;
    case OP_MENOR:
        emit("CMME");
        break;
    case OP_MENOR_IGUAL:
        emit("CMEG");
        break;
    case OP_MAIOR:
        emit("CMMA");
        break;
    case OP_MAIOR_IGUAL:
        emit("CMAG");
        break;
    }
}

void GeradorMepa::visit(ExprUnaria & no) {
    no.expressao -> accept( * this);
    if (no.op == OP_SUB) emit("INVR");
    else if (no.op == OP_NOT) emit("NEGA");
}

void GeradorMepa::visit(ExprChamadaFunc & no) {
    emit("AMEM", "1");

    for (auto arg: no.argumentos) {
        arg -> accept( * this);
    }

    VarMepa * func = buscar(no.name);
    if (func) {
        emit("CHPR", func -> rotulo + "," + std::to_string(nivelAtual));
    }
}

void GeradorMepa::visit(CmdBeginEnd & no) {
    for (auto cmd: no.comandos) {
        if (cmd) cmd -> accept( * this);
    }
}

void GeradorMepa::visit(CmdAtribuicao & no) {
    no.expressao -> accept( * this);

    VarMepa * v = buscar(no.variavel);
    if (v) {
        emit("ARMZ", std::to_string(v -> nivel) + "," + std::to_string(v -> deslocamento));
    }
}

void GeradorMepa::visit(CmdIf & no) {
    std::string rotElse = novoRotulo();
    std::string rotFim = novoRotulo();

    no.condicao -> accept( * this);
    emit("DSVF", rotElse);

    no.CmdThen -> accept( * this);
    emit("DSVS", rotFim);

    emitLabel(rotElse);
    if (no.CmdElse) {
        no.CmdElse -> accept( * this);
    }

    emitLabel(rotFim);
}

void GeradorMepa::visit(CmdWhile & no) {
    std::string rotInicio = novoRotulo();
    std::string rotFim = novoRotulo();

    emitLabel(rotInicio);
    no.condicao -> accept( * this);
    emit("DSVF", rotFim);

    no.corpo -> accept( * this);
    emit("DSVS", rotInicio);

    emitLabel(rotFim);
}

void GeradorMepa::visit(CmdRead & no) {
    for (const auto & nome: no.nome_variaveis) {
        emit("LEIT");
        VarMepa * v = buscar(nome);
        if (v) {
            emit("ARMZ", std::to_string(v -> nivel) + "," + std::to_string(v -> deslocamento));
        }
    }
}

void GeradorMepa::visit(CmdWrite & no) {
    for (auto expr: no.expressoes) {
        expr -> accept( * this);
        emit("IMPR");
    }
}

void GeradorMepa::visit(CmdChamadaProc & no) {
    for (auto arg: no.argumentos) {
        arg -> accept( * this);
    }
    VarMepa * proc = buscar(no.nome);
    if (proc) {
        emit("CHPR", proc -> rotulo + "," + std::to_string(nivelAtual));
    }
}

void GeradorMepa::visit(DeclararProcedimento & no) {
    std::string rotulo = novoRotuloProc();
    std::string rotuloFim = novoRotulo();

    VarMepa procInfo;
    procInfo.nivel = nivelAtual;
    procInfo.rotulo = rotulo;
    tabelaSimbolos.back()[no.nome] = procInfo;

    emit("DSVS", rotuloFim);
    emitLabel(rotulo);

    emit("ENPR", std::to_string(nivelAtual + 1));

    int backupDeslocamento = deslocamentoAtual;
    nivelAtual++;
    deslocamentoAtual = 0;
    entrarEscopo();

    int qtdParams = 0;
    for (auto p: no.parametros) qtdParams += p -> nomes.size();

    int offsetParam = -4 - qtdParams;

    for (auto decl: no.parametros) {
        for (const auto & nome: decl -> nomes) {
            VarMepa v;
            v.nivel = nivelAtual;
            v.deslocamento = offsetParam++;
            tabelaSimbolos.back()[nome] = v;
        }
    }

    int varsLocais = 0;
    for (auto local: no.variaveis_locais) {
        local -> accept( * this);
        varsLocais += local -> nomes.size();
    }

    if (no.corpo) no.corpo -> accept( * this);

    emit("RTPR", std::to_string(nivelAtual) + "," + std::to_string(qtdParams));

    sairEscopo(varsLocais);
    nivelAtual--;
    deslocamentoAtual = backupDeslocamento;

    emitLabel(rotuloFim);
}

void GeradorMepa::visit(DeclararFuncao & no) {
    std::string rotulo = novoRotuloProc();
    std::string rotuloFim = novoRotulo();

    VarMepa funcInfo;
    funcInfo.nivel = nivelAtual;
    funcInfo.rotulo = rotulo;
    tabelaSimbolos.back()[no.nome] = funcInfo;

    emit("DSVS", rotuloFim);
    emitLabel(rotulo);
    emit("ENPR", std::to_string(nivelAtual + 1));

    int backupDeslocamento = deslocamentoAtual;
    nivelAtual++;
    deslocamentoAtual = 0;
    entrarEscopo();

    int qtdParams = 0;
    for (auto p: no.parametros) qtdParams += p -> nomes.size();

    int offsetParam = -4 - qtdParams;
    for (auto decl: no.parametros) {
        for (const auto & nome: decl -> nomes) {
            VarMepa v;
            v.nivel = nivelAtual;
            v.deslocamento = offsetParam++;
            tabelaSimbolos.back()[nome] = v;
        }
    }

    VarMepa retVar;
    retVar.nivel = nivelAtual;
    retVar.deslocamento = -4 - qtdParams - 1;
    tabelaSimbolos.back()[no.nome] = retVar;

    int varsLocais = 0;
    for (auto local: no.variaveis_locais) {
        local -> accept( * this);
        varsLocais += local -> nomes.size();
    }

    if (no.corpo) no.corpo -> accept( * this);

    emit("RTPR", std::to_string(nivelAtual) + "," + std::to_string(qtdParams));

    sairEscopo(varsLocais);
    nivelAtual--;
    deslocamentoAtual = backupDeslocamento;

    emitLabel(rotuloFim);
}