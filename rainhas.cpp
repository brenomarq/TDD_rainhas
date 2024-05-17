// Copyright 2024 Breno
#include "./rainhas.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::vector<int>> tabuleiro_para_vetor(
    const std::string file_name
) {
    std::vector<std::vector<int>> tabuleiro;

    // Abre o arquivo
    std::ifstream file(file_name);

    // Transforma cada elemento em int e adiciona em um vetor de vetores
    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        for (char c : line) {
            row.push_back(c - '0');
        }
        tabuleiro.push_back(row);
    }

    file.close();

    return tabuleiro;
}

bool tem_oito_rainhas(std::vector<std::vector<int>> tabuleiro) {
    int quantidade_rainhas = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // Checa se há uma rainha
            if (tabuleiro[i][j] == 1) {
                ++quantidade_rainhas;
            }
        }
    }

    if (quantidade_rainhas != 8) {
        return false;
    } else {
        return true;
    }
}

bool formato_certo(std::vector<std::vector<int>> tabuleiro) {
    // Checa o número de linhas
    if (tabuleiro.size() == 8) {
        for (std::vector<int> linha : tabuleiro) {
            // Checa o número de colunas de cada linha
            if (linha.size() != 8) {
                return false;
            }
        }

        return true;
    }

    return false;
}

bool esta_atacando(int linha, int coluna, int i, int j) {
    return (i == linha || j == coluna || abs(i - linha) == abs(j - coluna));
}

bool caracter_invalido(std::vector<std::vector<int>> tabuleiro) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // Checa se há caracter inválido
            if (tabuleiro[i][j] > 1) {
                return true;
            }
        }
    }

    return false;
}

int checa_tabuleiro(const std::string file_name) {
    // Gera o tabuleiro a ser analisado
    std::vector<std::vector<int>> tabuleiro = tabuleiro_para_vetor(file_name);

    int result = 1;

    // Checa se o formato é 8 x 8
    if (!formato_certo(tabuleiro)) {
        return -1;
    }

    // Checa se há caracteres inválidos
    if (caracter_invalido(tabuleiro)) {
        return -1;
    }

    // Checa se há 8 rainhas
    if (!tem_oito_rainhas(tabuleiro)) {
        return -1;
    }

    // Itera pela posição de cada rainha no tabuleiro
    for (int linha = 0; linha < 8; ++linha) {
        for (int coluna = 0; coluna < 8; ++coluna) {
            // Confere se tem uma rainha na posição indicada
            if (tabuleiro[linha][coluna]) {
                for (int i = 0; i < 8; ++i) {
                    for (int j = 0; j < 8; ++j) {
                        // Ignora a posição da rainha analisada
                        if (i == linha && j == coluna) continue;

                        // Confere a coluna, a linha e as diagonais
                        if (tabuleiro[i][j] == 1 && esta_atacando(
                            linha, coluna, i, j)
                        ) {
                            result = 0;
                        }
                    }
                }
            }
        }
    }

    return result;
}
