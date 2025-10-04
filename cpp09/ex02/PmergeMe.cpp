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

int PmergeMe::jacobsthal(int n) const {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1;
    for (int k = 2; k <= n; ++k) {
        int c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

int PmergeMe::lastJacobsthal(int size) const {
    int i = 0;
    while (jacobsthal(i) <= size) {
        i++;
    }
    return jacobsthal(i - 1);
}

int PmergeMe::inVectorFindIndiceOf(const std::vector<int>& v, int value) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == value) {
            return i;
        }
    }
    return -1; // Not found
}

std::vector<int> PmergeMe::jacobsthalOrder(int size) {
    std::vector<int> order;
    int last = lastJacobsthal(size);
    order.push_back(last);
    while (last < size) {
        order.push_back(size--);
    }
    int prevLast = last;
    if (last == 1) return order;
    last = lastJacobsthal(last - 1);
    order.insert(order.begin(), last);
    int i = 1;
    while (last < size && last != 0) {
        if (i == 1) size--;
        order.insert(order.begin() + PmergeMe::inVectorFindIndiceOf(order, prevLast) + i, size--);
        i++;
        if (last == size) {
            prevLast = last;
            last = lastJacobsthal(last - 1);
            if (last != 0)
                order.insert(order.begin(), last);
            i = 1;
        }
    }
    return order;
}

int PmergeMe::binarySearchInsertPosition(const std::vector<int>& a, int value) {
    std::size_t lo = 0, hi = a.size();
    while (lo < hi) {
        std::size_t mid = lo + (hi - lo) / 2;
        if (a[mid] < value) lo = mid + 1;
        else                hi = mid;
    }
    return static_cast<int>(lo);
}

int PmergeMe::binarySearchInsertPosition(const std::deque<int>& a, int value) {
    std::size_t lo = 0, hi = a.size();
    while (lo < hi) {
        std::size_t mid = lo + (hi - lo) / 2;
        if (a[mid] < value) lo = mid + 1;
        else                hi = mid;
    }
    return static_cast<int>(lo);
}

int PmergeMe::findElementPair(const std::vector<std::pair<int,int> >& pairs, int element) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first == element) {
            return pairs[i].second;
        }
    }
    return -1; // Not found
}

int PmergeMe::findElementPair(const std::deque<std::pair<int,int> >& pairs, int element) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first == element) {
            return pairs[i].second;
        }
    }
    return -1; // Not found
}

void PmergeMe::mergeInsertSortVec(std::vector<int>& v) {
    std::vector<std::pair<int,int> > pairs;
    std::vector<int> mainChain;
    std::vector<int> pendingElements;
    int i = 0;
    for(; i + 1 < static_cast<int>(v.size()); i += 2) {
        if (v[i] < v[i + 1]) {
            pairs.push_back(std::make_pair(v[i], v[i + 1]));
            mainChain.push_back(v[i + 1]);
            pendingElements.push_back(v[i]);
        } else {
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
            mainChain.push_back(v[i]);
            pendingElements.push_back(v[i + 1]);
        }
    }
    if (i < static_cast<int>(v.size())) {
        pairs.push_back(std::make_pair(v[i], -1)); // Handle odd element
    }
    if (mainChain.size() > 1) {
        mergeInsertSortVec(mainChain);
    }
    std::vector<int> order = jacobsthalOrder(pendingElements.size());
    for (size_t j = 0; j < order.size(); ++j) {
        int element = pendingElements[order[j] - 1];
        int elementPair = findElementPair(pairs, element);
        if (elementPair != -1) {
            int pos = binarySearchInsertPosition(mainChain, elementPair);
            while (pos > 0 && element < mainChain[pos - 1]) {
                pos--;
            }
            mainChain.insert(mainChain.begin() + pos, element);
        } else {
            int pos = binarySearchInsertPosition(mainChain, element);
            mainChain.insert(mainChain.begin() + pos, element);
        }
    }
    v = mainChain; // Copy sorted mainChain back to v
}

void PmergeMe::mergeInsertSortDeq(std::deque<int>& d) {
    std::deque<std::pair<int,int> > pairs;
    std::deque<int> mainChain;
    std::deque<int> pendingElements;
    int i = 0;
    for(; i + 1 < static_cast<int>(d.size()); i += 2) {
        if (d[i] < d[i + 1]) {
            pairs.push_back(std::make_pair(d[i], d[i + 1]));
            mainChain.push_back(d[i + 1]);
            pendingElements.push_back(d[i]);
        } else {
            pairs.push_back(std::make_pair(d[i + 1], d[i]));
            mainChain.push_back(d[i]);
            pendingElements.push_back(d[i + 1]);
        }
    }
    if (i < static_cast<int>(d.size())) {
        pairs.push_back(std::make_pair(d[i], -1)); // Handle odd element
    }
    if (mainChain.size() > 1) {
        mergeInsertSortDeq(mainChain);
    }
    std::vector<int> order = jacobsthalOrder(pendingElements.size());
    for (size_t j = 0; j < order.size(); ++j) {
        int element = pendingElements[order[j] - 1];
        int elementPair = findElementPair(pairs, element);
        if (elementPair != -1) {
            int pos = binarySearchInsertPosition(mainChain, elementPair);
            while (pos > 0 && element < mainChain[pos - 1]) {
                pos--;
            }
            mainChain.insert(mainChain.begin() + pos, element);
        } else {
            int pos = binarySearchInsertPosition(mainChain, element);
            mainChain.insert(mainChain.begin() + pos, element);
        }
    }
    d = mainChain; // Copy sorted mainChain back to d
}

void PmergeMe::printContainer(const std::vector<int>& v) const {
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printContainer(const std::deque<int>& d) const {
    for (size_t i = 0; i < d.size(); ++i) {
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;
}
