#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    // devolve true se conseguiu calcular; em erro escreve "Error" em stderr
    bool evaluate(const std::string& expr, long& out) const;

private:
    static bool applyOp(long a, long b, char op, long& out);
};

#endif
