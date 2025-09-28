#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <utility>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    // Lê argv -> sequência positiva (>=0 é permitido? Aqui exigido "positive"; vou exigir >0)
    // devolve false se algum erro (não-numérico/negativo/overflow)
    bool parseArgs(int argc, char** argv, std::vector<int>& out) const;

    // Executa Ford–Johnson no vector e no deque; devolve tempos em microssegundos
    bool sortAndMeasure(const std::vector<int>& input,
                        std::vector<int>& sortedVec, long& usVec,
                        std::deque<int>& sortedDeq, long& usDeq) const;

private:
    // Ford–Johnson para vector/deque
    static void fordJohnson(std::vector<int>& a);
    static void fordJohnson(std::deque<int>& a);

    // Helpers
    static std::vector<size_t> jacobsthalIndices(size_t n); // ordem de inserção
    template <typename PairCont>
    static void insertionSortPairsByFirst(PairCont& pairs);
    template <typename Seq>
    static typename Seq::iterator binaryInsert(Seq& seq, int value);
};

#endif
