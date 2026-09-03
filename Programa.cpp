//
// Created by S861321135 on 03/09/2026.
//

#include "Programa.h"

#include <format>
#include <fstream>
#include <iostream>
#include <random>

#include "Jogo.h"

bool Programa::solicitarPalavraOcultar() {
    auto limparTela = []() {
        // Limpa a tela
        std::cout << "\033[2J\033[1;1H";
    };

    std::cout << "Jogador que adivinha deve se afastar para não ver a palavra\n";
    std::cout << "Informe a palavra para ocultar(Fim-de-arquivo finaliza): ";

    std::cin >> m_palavra;
    if (std::cin.eof()) {
        return false;
    }
    limparTela();
    return true;
}

bool Programa::sortearPalavraOcultar(std::mt19937 &gen) {
    lerArquivoPalavras();
    if (m_palavras.empty()) {
        std::cerr << "Nenhuma palavra disponível para sortear." << std::endl;
        return false;
    }

    std::uniform_int_distribution<std::size_t> dis(0, m_palavras.size() - 1);
    auto it = m_palavras.begin();
    std::advance(it, dis(gen));
    m_palavra = *it;
    return true;
}

void Programa::tratarErroEntrada() {
    std::cin.clear(); // Limpa o estado de falha
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Programa::executar() {
    Jogo jogo;

    std::random_device rd;
    std::mt19937 gen(rd());
    do {
        OpcaoMenu opcao = exibirMenu();
        bool palavraEscolhida = true;
        switch (opcao) {
            case OpcaoMenu::JOGADOR_VS_JOGADOR:
                palavraEscolhida = solicitarPalavraOcultar();
                break;
            case OpcaoMenu::JOGADOR_VS_COMPUTADOR:
                palavraEscolhida = sortearPalavraOcultar(gen);
                break;
            case OpcaoMenu::SAIR:
                std::cout << "Saindo do programa." << std::endl;
                return 0;
            case OpcaoMenu::FALHA:
                std::cout << "Entrada inválida. Por favor, digite uma opção válida." << std::endl;
                continue;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
                continue;
        }

        if (!palavraEscolhida) {
            std::cout << "Nenhuma palavra escolhida. Saindo do programa." << std::endl;
            break;
        }

        jogo.iniciaJogo(m_palavra);
        do {
            std::cout << "Palavra: " << jogo.gerarPalavraCamuflada() << std::endl;
            std::cout << "Informe uma letra: ";
            char letra;
            std::cin >> letra;
            if (std::cin.eof()) {
                break;
            }
            if (std::cin.fail()) {
                tratarErroEntrada(); // Ignora a entrada inválida
                std::cout << "Entrada inválida. Por favor, digite uma letra válida." << std::endl;
                continue;
            }
            if (jogo.verificaAposta(letra)) {
                std::cout << "Acertou!" << std::endl;
            } else {
                std::cout << "Errou!" << std::endl;
                jogo.exibirPartesCorpo();
                if (jogo.fimJogo()) {
                    std::cout << "Fim de jogo! A palavra era: " << m_palavra << std::endl;
                    break;
                }
            }
        } while (!jogo.verificarPalavraCerta());
        if (jogo.verificarPalavraCerta()) {
            std::cout << "Parabéns! Você acertou a palavra: " << m_palavra << std::endl;
        } else {
            std::cout << "Você foi enforcado!" << std::endl;
        }
    } while (true);

    return 0;
}

OpcaoMenu Programa::exibirMenu() {
    int opcao{};
    std::cout << "Menu do Programa" << std::endl;
    std::cout << std::format("{}. Jogador vs Jogador", static_cast<int>(OpcaoMenu::JOGADOR_VS_JOGADOR)) <<
            std::endl;
    std::cout << std::format("{}. Jogador vs Computador", static_cast<int>(OpcaoMenu::JOGADOR_VS_COMPUTADOR)) <<
            std::endl;
    std::cout << std::format("{}. Sair", static_cast<int>(OpcaoMenu::SAIR)) << std::endl;
    std::cout << "Escolha uma opção: ";

    // Se o usuário pressionar Ctrl+D (EOF) no Linux ou Ctrl+Z no Windows, limpamos os bits de estado da stream
    if (std::cin.eof()) {
        std::cin.clear();
    }
    std::cin >> opcao;
    if (std::cin.fail()) {
        tratarErroEntrada();
        return OpcaoMenu::FALHA;
    }
    return static_cast<OpcaoMenu>(opcao);
}

void Programa::lerArquivoPalavras() {
    std::ifstream arquivo(m_arquivoPalavras);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de palavras: " << m_arquivoPalavras << std::endl;
        return;
    }
    std::string linha;
    while (std::getline(arquivo, linha)) {
        m_palavras.insert(linha);
    }
}
