//
// Created by S861321135 on 03/09/2026.
//

#ifndef JOGO_FORCA_PROGRAMA_H
#define JOGO_FORCA_PROGRAMA_H
#include <optional>
#include <random>
#include <set>
#include <string>

enum class OpcaoMenu {
    JOGADOR_VS_JOGADOR = 1,
    JOGADOR_VS_COMPUTADOR = 2,
    SAIR = 3,
    FALHA = -1,
};

class Programa {
public:
    bool solicitarPalavraOcultar();

    bool sortearPalavraOcultar(std::mt19937 &gen);

    void tratarErroEntrada();

    int executar();

    OpcaoMenu exibirMenu();

private:
    void lerArquivoPalavras();

    std::string m_palavra{};
    constexpr static const char *m_arquivoPalavras{"palavras.txt"};
    std::set<std::string> m_palavras;
};

#endif //JOGO_FORCA_PROGRAMA_H
