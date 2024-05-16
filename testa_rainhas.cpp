// Copyright 2024 Breno
#define CATCH_CONFIG_MAIN
#include "./catch.hpp"
#include "./rainhas.hpp"

TEST_CASE("Tabuleiro - válido e solução", "[rainhas]") {
    REQUIRE(checa_tabuleiro("tabuleiro1.txt") == 1);
    REQUIRE(checa_tabuleiro("tabuleiro2.txt") == 1);
}

TEST_CASE("Tabuleiro - válido, mas não é solução", "[rainhas]") {
    REQUIRE(checa_tabuleiro("Tabuleiro3.txt") == 0);
}
