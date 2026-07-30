//
// Created by S861321135 on 30/07/2026.
//

#include "Jogo.h"

#include <algorithm>
#include <iostream>
#include <ostream>

Jogo::Jogo() = default;

bool Jogo::verificaAposta(const char letra) {
    m_letraApostada = letra;
    if (std::ranges::any_of(m_palavraEscondida, [&](const char c) { return c == letra; })) {
        m_letrasCertas += letra;
        return true;
    }
    return false;
}

void Jogo::iniciaJogo(const std::string &palavra) {
    m_palavraEscondida = palavra;
    m_tentativasErrada = 0;
}

std::string Jogo::gerarPalavra() const {
    std::string novaPalavra;
    for (const char c: m_palavraEscondida) {
        novaPalavra += (c == ' ') ? ' ' : (m_letrasCertas.find(c) != std::string::npos ? c : '*');
    }
    return novaPalavra;
}

bool Jogo::verificarPalavraCerta() const {
    return m_palavraEscondida == gerarPalavra();
}
