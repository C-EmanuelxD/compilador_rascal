#include "visitador_semantico.h"

// --- FUNÇÃO AUXILIAR ---
std::string TypeToStr(RascalType t) {
    if (t == TP_INT) return "integer";
    if (t == TP_BOOL) return "boolean";
    return "void/sem_tipo";
}

// ==========================================================
//                   EXPRESSÕES
// ==========================================================

void SemanticVisitor::visit(ExprValorInteiro& node) {
    node.type = TP_INT;
}

void SemanticVisitor::visit(ExprValorBool& node) {
    node.type = TP_BOOL;
}

void SemanticVisitor::visit(ExprComVariavel& node) {
    Simbolo* s = ts.buscar(node.nome);
    if (!s) {
        erro("Variavel nao declarada: " + node.nome);
        node.type = TP_SEM_TIPO;
    } else {
        node.type = s->tipo;
    }
}

void SemanticVisitor::visit(ExprBinaria& node) {
    node.expr1->accept(*this);
    node.expr2->accept(*this);

    RascalType t1 = node.expr1->type;
    RascalType t2 = node.expr2->type;

    // Se um dos lados já tem erro, propaga o erro sem spammar mais mensagens
    if (t1 == TP_SEM_TIPO || t2 == TP_SEM_TIPO) {
        node.type = TP_SEM_TIPO;
        return;
    }

    switch (node.op) {
        case OP_ADD: case OP_SUB: case OP_MUL: case OP_DIV:
            if (t1 == TP_INT && t2 == TP_INT) {
                node.type = TP_INT;
            } else {
                erro("Operacao aritmetica (+, -, *, div) requer inteiros.");
                node.type = TP_SEM_TIPO;
            }
            break;

        case OP_AND: case OP_OR:
            if (t1 == TP_BOOL && t2 == TP_BOOL) {
                node.type = TP_BOOL;
            } else {
                erro("Operacao logica (and, or) requer booleanos.");
                node.type = TP_SEM_TIPO;
            }
            break;

        case OP_MAIOR: case OP_MENOR: case OP_MAIOR_IGUAL: case OP_MENOR_IGUAL:
            if (t1 == TP_INT && t2 == TP_INT) {
                node.type = TP_BOOL;
            } else {
                erro("Comparacao de magnitude (>, <, >=, <=) requer inteiros.");
                node.type = TP_SEM_TIPO;
            }
            break;

        case OP_IGUAL: case OP_DIFERENTE:
            if (t1 == t2) {
                node.type = TP_BOOL;
            } else {
                erro("Comparacao de igualdade/diferenca requer tipos iguais.");
                node.type = TP_SEM_TIPO;
            }
            break;
            
        default:
             node.type = TP_SEM_TIPO;
    }
}

void SemanticVisitor::visit(ExprUnaria& node) {
    node.expressao->accept(*this);
    RascalType t = node.expressao->type;

    if (t == TP_SEM_TIPO) {
        node.type = TP_SEM_TIPO;
        return;
    }

    if (node.op == OP_NOT) {
        if (t == TP_BOOL) node.type = TP_BOOL;
        else {
            erro("Operador 'not' requer expressao booleana.");
            node.type = TP_SEM_TIPO;
        }
    } else if (node.op == OP_SUB) { // Menos unário
        if (t == TP_INT) node.type = TP_INT;
        else {
            erro("Sinal de menos unario (-) requer expressao inteira.");
            node.type = TP_SEM_TIPO;
        }
    } else {
        node.type = t; // Caso seja apenas parenteses ou mais unário
    }
}

void SemanticVisitor::visit(ExprChamadaFunc& node) {
    Simbolo* s = ts.buscar(node.name);
    
    if (!s) {
        erro("Funcao nao declarada: " + node.name);
        node.type = TP_SEM_TIPO;
        return;
    }
    
    if (s->categoria != CAT_FUNC) {
        erro("Identificador '" + node.name + "' nao refere-se a uma funcao.");
        node.type = TP_SEM_TIPO;
        return;
    }

    // Verificar contagem de argumentos
    if (node.argumentos.size() != s->tiposParametros.size()) {
        erro("Numero incorreto de argumentos para funcao '" + node.name + "'. Esperado: " + 
             std::to_string(s->tiposParametros.size()) + ", Recebido: " + std::to_string(node.argumentos.size()));
        node.type = TP_SEM_TIPO; // Define erro para não cascatear
    } else {
        // Verificar tipos dos argumentos
        for (size_t i = 0; i < node.argumentos.size(); i++) {
            node.argumentos[i]->accept(*this);
            if (node.argumentos[i]->type != s->tiposParametros[i]) {
                erro("Tipo incompativel no argumento " + std::to_string(i+1) + " da chamada de '" + node.name + "'.");
            }
        }
        node.type = s->tipo; // O tipo da expressão é o retorno da função
    }
}

// ==========================================================
//                   COMANDOS
// ==========================================================

void SemanticVisitor::visit(CmdBeginEnd& node) {
    for (auto cmd : node.comandos) {
        if (cmd) cmd->accept(*this);
    }
}

void SemanticVisitor::visit(CmdAtribuicao& node) {
    node.expressao->accept(*this); // Calcula tipo da direita

    Simbolo* s = ts.buscar(node.variavel);
    
    if (!s) {
        erro("Variavel nao declarada na atribuicao: " + node.variavel);
        return;
    }
    
    // <--- LOGICA DE RETORNO: Verifica se estamos atribuindo ao nome da função atual
    if (!nomeFuncaoAtual.empty() && node.variavel == nomeFuncaoAtual) {
        encontrouRetorno = true;
    }
    
    // Regras de atribuição
    if (s->categoria != CAT_VAR && s->categoria != CAT_PARAM && s->categoria != CAT_FUNC) {
        erro("Nao e possivel atribuir valor ao identificador '" + node.variavel + "' (nao e variavel nem retorno de funcao).");
        return;
    }
    
    // Verificação de tipos
    if (node.expressao->type != TP_SEM_TIPO && s->tipo != node.expressao->type) {
        erro("Tipos incompativeis na atribuicao para '" + node.variavel + "'. Variavel e " + 
             TypeToStr(s->tipo) + ", mas expressao e " + TypeToStr(node.expressao->type));
    }
}

void SemanticVisitor::visit(CmdIf& node) {
    node.condicao->accept(*this);
    if (node.condicao->type != TP_BOOL && node.condicao->type != TP_SEM_TIPO) {
        erro("A condicao do comando IF deve resultar em um valor booleano.");
    }
    if (node.CmdThen) node.CmdThen->accept(*this);
    if (node.CmdElse) node.CmdElse->accept(*this);
}

void SemanticVisitor::visit(CmdWhile& node) {
    node.condicao->accept(*this);
    if (node.condicao->type != TP_BOOL && node.condicao->type != TP_SEM_TIPO) {
        erro("A condicao do comando WHILE deve resultar em um valor booleano.");
    }
    if (node.corpo) node.corpo->accept(*this);
}

void SemanticVisitor::visit(CmdChamadaProc& node) {
    Simbolo* s = ts.buscar(node.nome);
    if (!s) {
        erro("Procedimento nao declarado: " + node.nome);
        return;
    }
    if (s->categoria != CAT_PROC) {
        erro("Chamada invalida: '" + node.nome + "' nao e um procedimento.");
        return;
    }

    if (node.argumentos.size() != s->tiposParametros.size()) {
        erro("Numero incorreto de argumentos na chamada do procedimento '" + node.nome + "'.");
        return;
    }

    for (size_t i = 0; i < node.argumentos.size(); i++) {
        node.argumentos[i]->accept(*this);
        if (node.argumentos[i]->type != s->tiposParametros[i]) {
             erro("Tipo incompativel no argumento " + std::to_string(i+1) + " da chamada de '" + node.nome + "'.");
        }
    }
}

void SemanticVisitor::visit(CmdRead& node) {
    for (const auto& nomeVar : node.nome_variaveis) {
        Simbolo* s = ts.buscar(nomeVar);
        if (!s) {
            erro("Variavel '" + nomeVar + "' nao declarada no comando read.");
        } else if (s->categoria != CAT_VAR && s->categoria != CAT_PARAM) {
            erro("Identificador '" + nomeVar + "' no read deve ser uma variavel ou parametro.");
        }
    }
}

void SemanticVisitor::visit(CmdWrite& node) {
    for (auto expr : node.expressoes) {
        expr->accept(*this);
        // O write aceita int e bool, então apenas verificamos se a expressão é válida
        if (expr->type == TP_SEM_TIPO) {
            // O erro já foi reportado na expressão
        }
    }
}

// ==========================================================
//                   DECLARAÇÕES
// ==========================================================

void SemanticVisitor::visit(DeclararVar& node) {
    for (const auto& nome : node.nomes) {
        Simbolo s(nome, CAT_VAR, node.tipo);
        if (!ts.inserir(s)) {
            erro("Erro: Variavel '" + nome + "' ja declarada neste escopo.");
        }
    }
}

void SemanticVisitor::visit(DeclararProcedimento& node) {
    Simbolo sProc(node.nome, CAT_PROC, TP_SEM_TIPO);
    
    // Coleta tipos dos parâmetros para a assinatura
    for (auto decl : node.parametros) {
        for (size_t i=0; i < decl->nomes.size(); i++) {
            sProc.tiposParametros.push_back(decl->tipo);
        }
    }

    if (!ts.inserir(sProc)) {
        erro("Erro: Procedimento '" + node.nome + "' ja declarado.");
    }

    ts.entrarEscopo();

    // Inserir parâmetros no escopo local
    for (auto decl : node.parametros) {
        // Usa lógica manual para garantir que entrem como CAT_PARAM (opcional, mas bom para debug)
        for (const auto& nome : decl->nomes) {
            Simbolo s(nome, CAT_PARAM, decl->tipo);
            if (!ts.inserir(s)) erro("Parametro duplicado: " + nome);
        }
    }

    // Variáveis locais
    for (auto varLocal : node.variaveis_locais) {
        varLocal->accept(*this);
    }

    // Corpo
    if (node.corpo) node.corpo->accept(*this);

    ts.sairEscopo();
}

void SemanticVisitor::visit(DeclararFuncao& node) {
    Simbolo sFunc(node.nome, CAT_FUNC, node.tipo_retorno);
    
    // Assinatura
    for (auto decl : node.parametros) {
        for (size_t i=0; i < decl->nomes.size(); i++) {
            sFunc.tiposParametros.push_back(decl->tipo);
        }
    }

    if (!ts.inserir(sFunc)) {
        erro("Erro: Funcao '" + node.nome + "' ja declarada.");
    }

    ts.entrarEscopo();

    // <--- LOGICA DE RETORNO: Prepara contexto ---
    std::string contextoAnterior = nomeFuncaoAtual; 
    bool statusAnterior = encontrouRetorno;
    
    nomeFuncaoAtual = node.nome;
    encontrouRetorno = false; // Reset para a função atual

    // Parâmetros
    for (auto decl : node.parametros) {
        for (const auto& nome : decl->nomes) {
            Simbolo s(nome, CAT_PARAM, decl->tipo);
            if (!ts.inserir(s)) erro("Parametro duplicado: " + nome);
        }
    }

    // Variáveis locais
    for (auto varLocal : node.variaveis_locais) {
        varLocal->accept(*this);
    }

    // Corpo da função
    if (node.corpo) node.corpo->accept(*this);

    // <--- LOGICA DE RETORNO: Verifica se houve retorno ---
    if (!encontrouRetorno) {
        erro("A funcao '" + node.nome + "' nao possui retorno definido (faltou atribuicao '" + node.nome + " := ...').");
    }

    // Restaura contexto (caso existam funções aninhadas no futuro)
    nomeFuncaoAtual = contextoAnterior;
    encontrouRetorno = statusAnterior;

    ts.sairEscopo();
}


void SemanticVisitor::visit(Programa& node) {
    // Escopo Global
    ts.inserir(Simbolo(node.nome_prog, CAT_PROG, TP_SEM_TIPO));

    // Variáveis Globais
    for (auto var : node.variaveis_globais) {
        var->accept(*this);
    }

    // Subrotinas Globais
    for (auto sub : node.subrotinas_globais) {
        sub->accept(*this);
    }

    // Bloco Principal
    if (node.bloco_principal) {
        node.bloco_principal->accept(*this);
    }
}