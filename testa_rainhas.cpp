// Copyright 2024 Breno
#define CATCH_CONFIG_MAIN
#include "./catch.hpp"
#include "./rainhas.hpp"

TEST_CASE("Tabuleiro - válido e solução", "[rainhas]") {
    REQUIRE(checa_tabuleiro("tabuleiro1.txt") == 1);
}
