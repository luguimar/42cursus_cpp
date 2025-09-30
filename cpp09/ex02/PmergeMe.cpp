#include "PmergeMe.hpp"
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <stdexcept>

PmergeMe::PmergeMe() : vec(), deq() {}
PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), deq(other.deq) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::processInput(int argc, char** argv) {
    if (argc < 2) {
        throw std::invalid_argument("Error: No input numbers provided.");
    }

    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || num < 0) {
            throw std::invalid_argument("Error: Invalid number '" + std::string(argv[i]) + "'.");
        }
        vec.push_back(num);
        deq.push_back(num);
    }

    std::cout << "Before: ";
    printContainer(vec);

    clock_t startVec = clock();
    mergeInsertSortVec(vec);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000; // microseconds

    clock_t startDeq = clock();
    mergeInsertSortDeq(deq);
    clock_t endDeq = clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000; // microseconds

    std::cout << "After:  ";
    printContainer(vec);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}

int PmergeMe::postJacobsthalIndex(int n, int size) const {
    int j = 0;
    while (true) {
        int jVal = jacobsthal(j);
        if (jVal >= size) {
            return j - 1;
        }
        j++;
    }
}

int PmergeMe::jacobsthal(int n) const {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::mergeInsertSortVec(std::vector<int>& v) {
    int compCount = 0;
    if (v.size() <= 1) return;

    int i = 1;
    std::vector<std::pair<int, int> > pairs;
    while (i < static_cast<int>(v.size())) {
        if (v[i - 1] > v[i]) {
            pairs.push_back(std::make_pair(v[i], v[i - 1]));
        } else {
            pairs.push_back(std::make_pair(v[i - 1], v[i]));
        }
        compCount++;
        i += 2;
    }
    if (i == static_cast<int>(v.size())) {
        pairs.push_back(std::make_pair(v[i - 1], -1)); // Odd element out
    }
    std::vector<int> mainChain;
    for (size_t j = 0; j < pairs.size(); ++j) {
        mainChain.push_back(pairs[j].first);
    }
    mergeInsertSortVec(mainChain);
 
    
}


