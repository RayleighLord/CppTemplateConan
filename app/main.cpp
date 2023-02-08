#include <iostream>

#include "math_lib.h"

int main(int, char **) {
    mathlib::print_hello();
    std::cout << "5! = " << mathlib::factorial(5) << std::endl;
    std::cout << "2 + 3 = " << mathlib::add(2, 3) << std::endl;
    return 0;
}
