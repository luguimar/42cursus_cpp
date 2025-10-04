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
//    private:
        std::vector<int> vec;
        std::deque<int> deq;
        void mergeInsertSortVec(std::vector<int>& v);
        void mergeInsertSortDeq(std::deque<int>& d);
        void printContainer(const std::vector<int>& v) const;
        void printContainer(const std::deque<int>& d) const;
        int jacobsthal(int n) const;
        int lastJacobsthal(int size) const;
        int inVectorFindIndiceOf(const std::vector<int>& v, int value);
        std::vector<int> jacobsthalOrder(int size);
        int binarySearchInsertPosition(const std::vector<int>& a, int value);
        int binarySearchInsertPosition(const std::deque<int>& a, int value);
        int findElementPair(const std::vector<std::pair<int,int> >& pairs, int element);
        int findElementPair(const std::deque<std::pair<int,int> >& pairs, int element);
};

#endif
