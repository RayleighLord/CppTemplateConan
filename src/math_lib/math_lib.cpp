#include "math_lib.h"

#include <iostream>

__MY_LIB_H__

namespace mathlib {
/**
 * @brief Adds two numbers `a` and `b`,
 *  $$a + b$$
 *
 * @param a
 * @param b
 * @return int The sum of `a` and `b`.
 */
int add(int a, int b) { return a + b; }

/**
 * @brief Subtracts two numbers `a` and `b`,
 *  $$a - b$$
 *
 * @param a
 * @param b
 * @return int The difference of `a` and `b`.
 */
int subtract(int a, int b) { return a - b; }

/**
 * @brief Multiplies two numbers `a` and `b`,
 *  $$a \cdot b$$
 *
 * @param a
 * @param b
 * @return int The product of `a` and `b`.
 */
int multiply(int a, int b) { return a * b; }

/**
 * @brief Divides two numbers `a` and `b`,
 *  $$a / b$$
 *
 * @param a
 * @param b
 * @return int The quotient of `a` and `b`.
 */
int divide(int a, int b) { return a / b; }

/**
 * @brief Prints "Hello, world!" to stdout.
 * $$a^2 + b^2 = c^2$$ is a code snippet.
 */
void print_hello() { std::cout << "Hello, world!\n"; }

/**
 * @brief Calculates the factorial of a number `n`.
 * $$n! = n \cdot (n - 1) \cdot (n - 2) \cdot \dots \cdot 1.$$
 * @param n
 * @return unsigned int The factorial of `n`.
 */
unsigned int factorial(unsigned int n) {
    return n <= 1 ? 1 : factorial(n - 1) * n;
}

/**
 * @brief Calculates the `n`th Fibonacci number.
 * $$F_n = F_{n - 1} + F_{n - 2}$$
 *
 * @param n
 * @return unsigned int The `n`th Fibonacci number.
 */
unsigned int fibonacci(unsigned int n) {
    return n < 2 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

}  // namespace mathlib
