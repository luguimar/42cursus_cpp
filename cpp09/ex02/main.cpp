#include "PmergeMe.hpp"
#include <iostream>

static void printSeqPrefix(const std::vector<int>& v, size_t maxn) {
    for (size_t i = 0; i < v.size() && i < maxn; ++i) {
        if (i) std::cout << ' ';
        std::cout << v[i];
    }
    if (v.size() > maxn) std::cout << " [...]";
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    PmergeMe p;
    std::vector<int> input;
    if (!p.parseArgs(argc, argv, input)) return 1;

    std::cout << "Before: ";
    printSeqPrefix(input, 20);

    std::vector<int> sortedV;
    std::deque<int>  sortedD;
    long usV = 0, usD = 0;
    if (!p.sortAndMeasure(input, sortedV, usV, sortedD, usD)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << "After: ";
    printSeqPrefix(sortedV, 20);

    std::cout << "Time to process a range of " << input.size()
              << " elements with std::vector : " << usV << " us" << std::endl;
    std::cout << "Time to process a range of " << input.size()
              << " elements with std::deque  : " << usD << " us" << std::endl;
    return 0;
}
