#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    std::cout << "----------------------------------------" << std::endl;
    PmergeMe sorter;
    (void)argc; // evitar warning
    (void)argv; // evitar warning
    
    int i = 19;
    std::vector<int> test;
    test = sorter.jacobsthalOrder(i);
    std::cout << "Jacobsthal order for " << i << " elements: ";
    for (size_t j = 0; j < test.size(); ++j) {
        std::cout << test[j] << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    i = 0;
    while (i < 30) {
        std::cout << "J(" << i << ") = " << sorter.jacobsthal(i) << std::endl;
        std::cout << "Last J <= " << i << " is " << sorter.lastJacobsthal(i) << std::endl;
        i++;
    }
}
