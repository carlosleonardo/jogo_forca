//
// Created by S861321135 on 30/07/2026.
//

#include "Jogo.h"

#include <algorithm>
#include <iostream>
#include <ostream>

Jogo::Jogo() {
}

bool Jogo::verificaAposta(char letra) {
    return std::ranges::any_of(m_palavraEscondida, [&](char c) { return c == letra; });
}

void Jogo::iniciaJogo(const std::string &palavra) {
    m_palavraEscondida = palavra;
    m_tentativas = 0;
}
