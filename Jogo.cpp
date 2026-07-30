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
    m_tentativasErrada++;
    return false;
}

void Jogo::iniciaJogo(const std::string &palavra) {
    m_palavraEscondida = palavra;
    m_tentativasErrada = 0;
    m_letraApostada = 0;
    m_letrasCertas.clear();
}

std::string Jogo::gerarPalavraCamuflada() const {
    std::string novaPalavra;
    for (const char c: m_palavraEscondida) {
        novaPalavra += (c == ' ') ? ' ' : (m_letrasCertas.find(c) != std::string::npos ? c : '*');
    }
    return novaPalavra;
}

bool Jogo::verificarPalavraCerta() const {
    return m_palavraEscondida == gerarPalavraCamuflada();
}

void Jogo::exibirPartesCorpo() const {
    std::cout << "Tentativas erradas: " << m_tentativasErrada << std::endl;
    for (int i = 0; i < m_tentativasErrada && i < MAX_TENTATIVAS; ++i) {
        std::cout << m_corpo[i] << std::endl;
    }
}

bool Jogo::fimJogo() const {
    return m_tentativasErrada == MAX_TENTATIVAS;
}
