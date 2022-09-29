#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "parta.h"

TEST_CASE("inflation(10.00, 1 year, 10%)") {
    int actual = inflation(1000, 1, 10.0);
    REQUIRE(actual == 1100);
}

TEST_CASE("inflation(10.00, 2 years, 10%)") {
    int actual = inflation(1000, 2, 10.0);
    REQUIRE(actual == 1210);
}

TEST_CASE("inflation(10.00, 9 years, 10%)") {
    int actual = inflation(1000, 9, 10.0);
    REQUIRE(actual == 2358);
}

TEST_CASE("inflation(10.50, 9 years, 10.5%)") {
    int actual = inflation(1050, 9, 10.5);
    REQUIRE(actual == 2579);
}

TEST_CASE("inflation(negative price)") {
    int actual = inflation(-100, 2, 10.0);
    REQUIRE(actual == -1);
}

TEST_CASE("inflation(negative year)") {
    int actual = inflation(100, -2, 10.0);
    REQUIRE(actual == -1);
}
TEST_CASE("inflation(negative rate)") {
    int actual = inflation(100, 2, -10.0);
    REQUIRE(actual == -1);
}
