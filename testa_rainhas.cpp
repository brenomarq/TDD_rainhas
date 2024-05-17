// Copyright 2024 Breno
#define CATCH_CONFIG_MAIN
#include "./catch.hpp"
#include "./rainhas.hpp"

TEST_CASE("Tabuleiro - válido e solução", "[rainhas]") {
    REQUIRE(checa_tabuleiro("tabuleiro1.txt") == 1);
    REQUIRE(checa_tabuleiro("tabuleiro2.txt") == 1);
}

TEST_CASE("Tabuleiro - válido, mas não é solução", "[rainhas]") {
    REQUIRE(checa_tabuleiro("tabuleiro3.txt") == 0);
    REQUIRE(checa_tabuleiro("tabuleiro4.txt") == 0);
}

TEST_CASE("Tabuleiro - inválido", "[rainhas]") {
    WHEN("Mais que 8 rainhas no tabuleiro") {
        REQUIRE(checa_tabuleiro("tabuleiro5.txt") == -1);
    }
}
