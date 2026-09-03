/**
 * Jogo da forca
 * Implementa o jogo usando caracteres para representar uma forca
 * Exibe um texto escondido usando '*' para esconder os caracteres
 * O jogador deve adivinhar a palavra definindo as letras certas
 * Também é possível jogar contra o computador, que sorteia uma palavra de um arquivo de palavras
 *
 * @author Carlos Leonardo
 */

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include "Jogo.h"
#include "Programa.h"

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    std::cout << "Jogo da Forca!" << std::endl;

    Programa programa;
    return programa.executar();
}
