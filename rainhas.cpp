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

int checa_tabuleiro(const std::string file_name) {
    // Gera o tabuleiro a ser analisado
    std::vector<std::vector<int>> tabuleiro = tabuleiro_para_vetor(file_name);

    return 0;
}
