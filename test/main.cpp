#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "math_lib.h"

TEST_CASE("Testing operation functions", "[add, substract, multiply, divide]") {
    REQUIRE(mathlib::add(1, 2) == 3);
    REQUIRE(mathlib::add(2, 2) == 4);
    REQUIRE(mathlib::subtract(1, 2) == -1);
    REQUIRE(mathlib::subtract(2, 2) == 0);
    REQUIRE(mathlib::multiply(1, 2) == 2);
    REQUIRE(mathlib::multiply(2, 2) == 4);
    REQUIRE(mathlib::divide(1, 2) == 0);
    REQUIRE(mathlib::divide(2, 2) == 1);
}

TEST_CASE("Testing the factorial function", "[factorial]") {
    REQUIRE(mathlib::factorial(0) == 1);
    REQUIRE(mathlib::factorial(1) == 1);
    REQUIRE(mathlib::factorial(2) == 2);
    REQUIRE(mathlib::factorial(3) == 6);
    REQUIRE(mathlib::factorial(5) == 120);
    REQUIRE(mathlib::factorial(10) == 3628800);
}

TEST_CASE("Testing the fibonacci function", "[fibonacci]") {
    REQUIRE(mathlib::fibonacci(1) == 1);
    REQUIRE(mathlib::fibonacci(2) == 1);
    REQUIRE(mathlib::fibonacci(3) == 2);
    REQUIRE(mathlib::fibonacci(4) == 3);
    REQUIRE(mathlib::fibonacci(5) == 5);
    REQUIRE(mathlib::fibonacci(6) == 8);
}
