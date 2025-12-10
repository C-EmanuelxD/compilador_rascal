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
    

    std::vector<RascalType> tiposParametros; 

    Simbolo() {}
    Simbolo(std::string n, CategoriaSimbolo c, RascalType t) 
        : nome(n), categoria(c), tipo(t) {}
};

class TabelaSimbolos {
private:

    std::vector<std::map<std::string, Simbolo>> escopos;

public:
    TabelaSimbolos() {

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

    bool inserir(Simbolo s) {
        auto& escopoAtual = escopos.back();
        if (escopoAtual.find(s.nome) != escopoAtual.end()) {
            return false; 
        }
        escopoAtual[s.nome] = s;
        return true;
    }


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