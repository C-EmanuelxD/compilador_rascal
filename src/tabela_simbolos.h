#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "ast.h"

enum CategoriaSimbolo {
    CAT_VAR,
    CAT_PARAM,
    CAT_PROC,
    CAT_FUNC,
    CAT_PROG
};

struct Simbolo {
    std::string nome;
    CategoriaSimbolo categoria;
    RascalType tipo;
    
    // Para funções e procedimentos: assinatura dos parâmetros
    std::vector<RascalType> tiposParametros; 

    Simbolo() {}
    Simbolo(std::string n, CategoriaSimbolo c, RascalType t) 
        : nome(n), categoria(c), tipo(t) {}
};

class TabelaSimbolos {
private:
    // Pilha de escopos. Cada escopo é um mapa de string -> Simbolo
    std::vector<std::map<std::string, Simbolo>> escopos;

public:
    TabelaSimbolos() {
        // Começa com o escopo global
        entrarEscopo();
    }

    void entrarEscopo() {
        escopos.push_back(std::map<std::string, Simbolo>());
    }

    void sairEscopo() {
        if (escopos.size() > 1) {
            escopos.pop_back();
        }
    }

    // Tenta inserir um símbolo no escopo ATUAL. Retorna false se já existir.
    bool inserir(Simbolo s) {
        auto& escopoAtual = escopos.back();
        if (escopoAtual.find(s.nome) != escopoAtual.end()) {
            return false; // Já declarado neste escopo
        }
        escopoAtual[s.nome] = s;
        return true;
    }

    // Busca do escopo atual para o global (pilha de cima para baixo)
    Simbolo* buscar(std::string nome) {
        for (auto it = escopos.rbegin(); it != escopos.rend(); ++it) {
            if (it->find(nome) != it->end()) {
                return &((*it)[nome]);
            }
        }
        return nullptr;
    }
};

#endif