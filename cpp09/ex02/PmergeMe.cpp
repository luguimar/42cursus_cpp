#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <ctime>    // std::clock
#include <climits>  // INT_MAX
#include <cctype>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) { return *this; }
PmergeMe::~PmergeMe() {}

static bool parseIntStrict(const std::string& s, int& out) {
    if (s.empty()) return false;
    long sign = 1;
    std::size_t i = 0;
    if (s[0] == '+') { sign = 1; i = 1; }
    else if (s[0] == '-') return false; // só positivos
    if (i >= s.size()) return false;
    long acc = 0;
    for (; i < s.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
        acc = acc * 10 + (s[i]-'0');
        if (acc*sign > INT_MAX) return false;
    }
    out = static_cast<int>(acc*sign);
    return true;
}

bool PmergeMe::parseArgs(int argc, char** argv, std::vector<int>& out) const {
    out.clear();
    for (int i = 1; i < argc; ++i) {
        int v;
        if (!parseIntStrict(argv[i], v) || v <= 0) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        out.push_back(v);
    }
    if (out.empty()) { std::cerr << "Error" << std::endl; return false; }
    return true;
}

// Insertion sort de pares por first
template <typename PairCont>
void PmergeMe::insertionSortPairsByFirst(PairCont& pairs) {
    for (size_t i = 1; i < pairs.size(); ++i) {
        typename PairCont::value_type key = pairs[i];
        size_t j = i;
        while (j > 0 && pairs[j-1].first > key.first) {
            pairs[j] = pairs[j-1];
            --j;
        }
        pairs[j] = key;
    }
}

// Binary insert numa sequência (qualquer que tenha iteradores aleatórios ou pelo menos bidirecionais)
template <typename Seq>
typename Seq::iterator PmergeMe::binaryInsert(Seq& seq, int value) {
    typename Seq::iterator lo = seq.begin();
    typename Seq::iterator hi = seq.end();
    while (lo != hi) {
        typename Seq::iterator mid = lo;
        // avanço de metade (genérico sem std::advance com distância conhecida)
        size_t dist = 0; {
            typename Seq::iterator tmp = lo;
            while (tmp != hi) { ++dist; ++tmp; }
            dist /= 2;
        }
        for (size_t k = 0; k < dist; ++k) ++mid;
        if (*mid < value) lo = ++mid;
        else hi = mid;
    }
    return seq.insert(lo, value);
}

// Gera ordem Jacobsthal para indices [1..n-1] (0 é par mestre inicial)
static size_t jacob(size_t k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    size_t a = 0, b = 1, c = 0;
    for (size_t i = 2; i <= k; ++i) { c = b + 2*a; a = b; b = c; }
    return b;
}
std::vector<size_t> PmergeMe::jacobsthalIndices(size_t n) {
    // Vamos formar blocos de inserção segundo 1,3,5,11,... (Jacobsthal)
    // Geramos uma ordem que cobre [1..n-1]
    std::vector<size_t> order;
    if (n <= 1) return order;
    size_t k = 2;
    size_t prevJ = 1;
    while (true) {
        size_t Jk = jacob(k);
        if (Jk >= n) break;
        // inserir descendente (Jk .. prevJ+1)
        for (size_t idx = Jk; idx > prevJ; --idx) order.push_back(idx);
        prevJ = Jk;
        ++k;
    }
    // resto até n-1
    for (size_t idx = n - 1; idx > prevJ; --idx) order.push_back(idx);
    return order;
}

// Implementação Ford–Johnson para std::vector<int>
void PmergeMe::fordJohnson(std::vector<int>& a) {
    if (a.size() <= 1) return;
    // 1) formar pares (menor, maior)
    std::vector< std::pair<int,int> > pairs;
    pairs.reserve((a.size()+1)/2);
    size_t i = 0;
    for (; i + 1 < a.size(); i += 2) {
        int x = a[i], y = a[i+1];
        if (y < x) { int t=x; x=y; y=t; }
        pairs.push_back(std::make_pair(x,y));
    }
    int orphan = 0; bool hasOrphan = false;
    if (i < a.size()) { orphan = a[i]; hasOrphan = true; }

    // 2) ordenar pares pelos "maiores" como pares Mestre? Variante comum: ordenar por first (menor do par) para main chain com maiores
    // Versão clássica: ordenar pares pelos maiores (ou menores) de forma consistente. Aqui: ordenar pelos first e construir main com seconds.
    insertionSortPairsByFirst(pairs);

    // 3) construir cadeia principal com os segundos (maiores) dos pares
    std::vector<int> mainChain;
    mainChain.reserve(a.size());
    for (size_t k = 0; k < pairs.size(); ++k) mainChain.push_back(pairs[k].second);

    // 4) preparar pendentes (os menores de cada par), serão inseridos junto ao seu parceiro
    std::vector<int> pend;
    pend.reserve(pairs.size());
    for (size_t k = 0; k < pairs.size(); ++k) pend.push_back(pairs[k].first);

    // 5) inserir o primeiro pendente imediatamente (garantido)
    // insere antes do seu parceiro correspondente (garantindo posição correta)
    // Aqui inserimos o primeiro pendente na posição correta via busca limitada até ao parceiro
    if (!pend.empty()) {
        // parceiro é mainChain[0]; inserção até inclusive essa posição
        // Implementação simples: binaryInsert no prefixo [begin .. posPartner]
        int val = pend[0];
        // prefix binary insert
        std::vector<int>::iterator hi = mainChain.begin(); // aponta para partner
        // encontrar partner (o primeiro par)
        // partner = pairs[0].second que é mainChain[0]
        // inserir no prefixo [begin..hi]
        // custom binary no prefixo
        std::vector<int>::iterator lo = mainChain.begin();
        while (lo != hi) {
            std::vector<int>::iterator mid = lo;
            size_t dist = 0; {
                std::vector<int>::iterator tmp = lo;
                while (tmp != hi) { ++dist; ++tmp; }
                dist /= 2;
            }
            for (size_t k = 0; k < dist; ++k) ++mid;
            if (*mid < val) lo = ++mid;
            else hi = mid;
        }
        mainChain.insert(lo, val);
    }

    // 6) ordem Jacobsthal para restantes índices de pend (1..n-1)
    std::vector<size_t> order = jacobsthalIndices(pend.size());
    for (size_t t = 0; t < order.size(); ++t) {
        size_t idx = order[t];
        int val = pend[idx];
        // inserir no intervalo (até ao partner correspondente)
        // encontrar iterador para o parceiro (valor pairs[idx].second) em mainChain — como há duplicados possíveis, fazemos busca linear
        int partner = pairs[idx].second;
        std::vector<int>::iterator partnerPos = mainChain.begin();
        for (; partnerPos != mainChain.end(); ++partnerPos) {
            if (*partnerPos == partner) break;
        }
        if (partnerPos == mainChain.end()) {
            // fallback: inserir globalmente
            binaryInsert(mainChain, val);
        } else {
            // binary insert no prefixo [begin..partnerPos]
            std::vector<int>::iterator lo = mainChain.begin();
            std::vector<int>::iterator hi = partnerPos;
            while (lo != hi) {
                std::vector<int>::iterator mid = lo;
                size_t dist = 0; {
                    std::vector<int>::iterator tmp = lo;
                    while (tmp != hi) { ++dist; ++tmp; }
                    dist /= 2;
                }
                for (size_t k = 0; k < dist; ++k) ++mid;
                if (*mid < val) lo = ++mid;
                else hi = mid;
            }
            mainChain.insert(lo, val);
        }
    }

    // 7) inserir órfão (se existir) na posição correta global
    if (hasOrphan) {
        binaryInsert(mainChain, orphan);
    }

    a.swap(mainChain);
}

// Implementação Ford–Johnson para std::deque<int> (mesma lógica)
void PmergeMe::fordJohnson(std::deque<int>& a) {
    if (a.size() <= 1) return;
    std::vector< std::pair<int,int> > pairs;
    pairs.reserve((a.size()+1)/2);
    size_t i = 0;
    for (; i + 1 < a.size(); i += 2) {
        int x = a[i], y = a[i+1];
        if (y < x) { int t=x; x=y; y=t; }
        pairs.push_back(std::make_pair(x,y));
    }
    int orphan = 0; bool hasOrphan = false;
    if (i < a.size()) { orphan = a[i]; hasOrphan = true; }

    insertionSortPairsByFirst(pairs);

    std::deque<int> mainChain;
    for (size_t k = 0; k < pairs.size(); ++k) mainChain.push_back(pairs[k].second);

    std::deque<int> pend;
    for (size_t k = 0; k < pairs.size(); ++k) pend.push_back(pairs[k].first);

    if (!pend.empty()) {
        int val = pend[0];
        // insert before partner mainChain[0]
        std::deque<int>::iterator hi = mainChain.begin();
        std::deque<int>::iterator lo = mainChain.begin();
        while (lo != hi) { /* nunca entra, prefixo vazio */ }
        mainChain.insert(lo, val);
    }

    std::vector<size_t> order = jacobsthalIndices(pend.size());
    for (size_t t = 0; t < order.size(); ++t) {
        size_t idx = order[t];
        int val = pend[idx];
        int partner = pairs[idx].second;

        std::deque<int>::iterator partnerPos = mainChain.begin();
        for (; partnerPos != mainChain.end(); ++partnerPos) {
            if (*partnerPos == partner) break;
        }
        if (partnerPos == mainChain.end()) {
            // fallback global
            // binaryInsert manual
            std::deque<int>::iterator lo = mainChain.begin(), hi = mainChain.end();
            while (lo != hi) {
                // mid via distância
                std::deque<int>::iterator mid = lo;
                size_t dist = 0; { std::deque<int>::iterator tmp = lo; while (tmp != hi) { ++dist; ++tmp; } dist/=2; }
                for (size_t k = 0; k < dist; ++k) ++mid;
                if (*mid < val) { ++mid; lo = mid; }
                else hi = mid;
            }
            mainChain.insert(lo, val);
        } else {
            // prefixo até partner
            std::deque<int>::iterator lo = mainChain.begin();
            std::deque<int>::iterator hi = partnerPos;
            while (lo != hi) {
                std::deque<int>::iterator mid = lo;
                size_t dist = 0; { std::deque<int>::iterator tmp = lo; while (tmp != hi) { ++dist; ++tmp; } dist/=2; }
                for (size_t k = 0; k < dist; ++k) ++mid;
                if (*mid < val) { ++mid; lo = mid; }
                else hi = mid;
            }
            mainChain.insert(lo, val);
        }
    }

    if (hasOrphan) {
        std::deque<int>::iterator lo = mainChain.begin(), hi = mainChain.end();
        while (lo != hi) {
            std::deque<int>::iterator mid = lo;
            size_t dist = 0; { std::deque<int>::iterator tmp = lo; while (tmp != hi) { ++dist; ++tmp; } dist/=2; }
            for (size_t k = 0; k < dist; ++k) ++mid;
            if (*mid < orphan) { ++mid; lo = mid; }
            else hi = mid;
        }
        mainChain.insert(lo, orphan);
    }

    a.swap(mainChain);
}

bool PmergeMe::sortAndMeasure(const std::vector<int>& input,
                              std::vector<int>& sortedVec, long& usVec,
                              std::deque<int>& sortedDeq, long& usDeq) const {
    sortedVec = input;
    sortedDeq.assign(input.begin(), input.end());

    std::clock_t t0 = std::clock();
    fordJohnson(sortedVec);
    std::clock_t t1 = std::clock();

    std::clock_t t2 = std::clock();
    fordJohnson(sortedDeq);
    std::clock_t t3 = std::clock();

    usVec = static_cast<long>((t1 - t0) * 1000000.0 / CLOCKS_PER_SEC);
    usDeq = static_cast<long>((t3 - t2) * 1000000.0 / CLOCKS_PER_SEC);
    return true;
}
