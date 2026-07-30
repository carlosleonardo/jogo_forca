/**
 * Jogo da forca
 * Implementa o jogo usando caracteres para representar uma forca
 * Exibe um texto escondido usando '*' para esconder os caracteres
 * O jogador deve adivinhar a palavra definindo as letras certas
 *
 * @author Carlos Leonardo
 */

#include <iostream>

#include "Jogo.h"

int main() {
    setlocale(LC_ALL, ".UTF-8");
    std::cout << "Jogo da Forca!" << std::endl;

    Jogo jogo;
    do {
        std::cout << "Jogador que adivinha deve se afastar para não ver a palavra\n";
        std::cout << "Informe a palavra para ocultar(Fim-de-arquivo finaliza): ";
        std::string palavra;

        // Exibe asteriscos na entrada
        std::cin >> palavra;
        if (std::cin.eof()) {
            break;
        }
        // Limpa a tela
        std::cout << "\033[2J\033[1;1H";

        jogo.iniciaJogo(palavra);
        do {
            std::cout << "Palavra: " << jogo.gerarPalavra() << std::endl;
            std::cout << "Informe uma letra: ";
            char letra;
            std::cin >> letra;
            if (std::cin.eof()) {
                break;
            }
            if (jogo.verificaAposta(letra)) {
                std::cout << "Acertou!" << std::endl;
            } else {
                std::cout << "Errou!" << std::endl;
            }
        } while (!jogo.verificarPalavraCerta());
        std::cout << "Parabéns! Você acertou a palavra: " << jogo.gerarPalavra() << std::endl;
    } while (true);
    return 0;
}
