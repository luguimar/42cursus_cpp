#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) { std::cerr << "Error" << std::endl; return 1; }
    RPN r;
    long result = 0;
    if (!r.evaluate(argv[1], result)) return 1;
    std::cout << result << std::endl;
    return 0;
}
