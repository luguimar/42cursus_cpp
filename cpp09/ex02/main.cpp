#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    std::cout << "----------------------------------------" << std::endl;
    PmergeMe sorter;
    (void)argc; // evitar warning
    (void)argv; // evitar warning
    for (int i = 1; i < 20; ++i) {
        std::cout << sorter.jacobsthal(i) << std::endl;
    }
}
