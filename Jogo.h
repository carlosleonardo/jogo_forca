//
// Created by S861321135 on 30/07/2026.
//

#ifndef JOGO_FORCA_JOGO_H
#define JOGO_FORCA_JOGO_H
#include <string>
#include <vector>


class Jogo {
public:
    Jogo();

    /**
     * Verifica se a letra apostada está presente na palavra.
     * @param letra A letra apostada pelo jogador.
     * @return true se a letra estiver na palavra, false caso contrário.
     */
    bool verificaAposta(char letra);

    /**
     * Inicia o jogo, preparando a palavra a ser adivinhada e o contador de tentativas
     */
    void iniciaJogo(const std::string &palavra);

    /**
     * Gera a palavra em formato de asteriscos, ocultando as letras ainda não acertadas.
     * @return A palavra em formato de asteriscos
     */
    [[nodiscard]] std::string gerarPalavraCamuflada() const;

    /**
     * Verifica se a palavra foi completamente acertada.
     * @return true se a palavra foi acertada, false caso contrário.
     */
    [[nodiscard]] bool verificarPalavraCerta() const;

    /**
     * Exibe progressivamente o corpo a medida que o jogador erra o palpite
     */
    void exibirPartesCorpo() const;

    /**
     * Verifica se foi alcançado o máximo de tentativas
     * @return false se não é fimm de jogo
     */
    [[nodiscard]] bool fimJogo() const;

private:
    constexpr static int MAX_TENTATIVAS = 6;

    static constexpr const char *ESTAGIOS[] = {
        R"( +---+
 |   |
     |
     |
     |
     |
=======)",
        R"( +---+
 |   |
 O   |
     |
     |
     |
=======)",
        R"( +---+
 |   |
 O   |
 |   |
     |
     |
=======)",
        R"( +---+
 |   |
 O   |
/|   |
     |
     |
=======)",
        R"( +---+
 |   |
 O   |
/|\  |
     |
     |
=======)",
        R"( +---+
 |   |
 O   |
/|\  |
/    |
     |
=======)",
        R"( +---+
 |   |
 O   |
/|\  |
/ \  |
     |
=======)"
    };
    int m_tentativasErrada{0};
    char m_letraApostada{0};
    std::string m_letrasCertas;
    std::string m_palavraEscondida;
};


#endif //JOGO_FORCA_JOGO_H
