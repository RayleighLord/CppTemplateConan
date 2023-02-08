#include <cblas.h>
#include <fmt/core.h>

#include <iostream>

#include "math_lib.h"

int main(int, char **) {
    mathlib::print_hello();
    std::cout << "5! = " << mathlib::factorial(5) << std::endl;
    std::cout << "2 + 3 = " << mathlib::add(2, 3) << std::endl;
    fmt::print("Hello, world!\n");

    int M = 2, N = 3, K = 4;
    float alpha = 1, beta = 0;
    float A[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    float B[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    float C[2][3] = {{0, 0, 0}, {0, 0, 0}};

    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K, alpha,
                (float *)A, K, (float *)B, N, beta, (float *)C, N);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
