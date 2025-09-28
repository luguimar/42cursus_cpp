#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cctype>

RPN::RPN() {}
RPN::RPN(const RPN& ) {}
RPN& RPN::operator=(const RPN& ) { return *this; }
RPN::~RPN() {}

bool RPN::applyOp(long a, long b, char op, long& out) {
    switch (op) {
        case '+': out = a + b; return true;
        case '-': out = a - b; return true;
        case '*': out = a * b; return true;
        case '/':
            if (b == 0) return false;
            out = a / b; return true;
        default: return false;
    }
}

bool RPN::evaluate(const std::string& expr, long& out) const {
    std::stack<long> st;
    for (std::size_t i = 0; i < expr.size();) {
        if (std::isspace(static_cast<unsigned char>(expr[i]))) { ++i; continue; }
        if (std::isdigit(static_cast<unsigned char>(expr[i]))) {
            // números de um dígito (regra do enunciado)
            long v = expr[i] - '0';
            st.push(v);
            ++i;
        } else {
            char c = expr[i];
            if (c=='+'||c=='-'||c=='*'||c=='/') {
                if (st.size() < 2) { std::cerr << "Error" << std::endl; return false; }
                long b = st.top(); st.pop();
                long a = st.top(); st.pop();
                long r;
                if (!applyOp(a,b,c,r)) { std::cerr << "Error" << std::endl; return false; }
                st.push(r);
                ++i;
            } else {
                std::cerr << "Error" << std::endl;
                return false;
            }
        }
    }
    if (st.size() != 1) { std::cerr << "Error" << std::endl; return false; }
    out = st.top();
    return true;
}
