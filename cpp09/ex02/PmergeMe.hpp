#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        void processInput(int argc, char** argv);
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        void mergeInsertSortVec(std::vector<int>& v);
        void mergeInsertSortDeq(std::deque<int>& d);
        void printContainer(const std::vector<int>& v) const;
        void printContainer(const std::deque<int>& d) const;
        int jacobsthal(int n) const;
        int postJacobsthalIndex(int n, int size) const; 
};

#endif
