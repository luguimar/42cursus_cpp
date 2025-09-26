#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void);
void identify(Base* p);
void identify(Base& p);


int main() {
    Base* p = generate();
    std::cout << "identify(*ptr): ";
    identify(p);
    std::cout << "identify(&ref): ";
    identify(*p);
    delete p;
    return 0;
}
