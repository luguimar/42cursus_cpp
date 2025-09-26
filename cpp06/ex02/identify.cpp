#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int r = std::rand() % 3;
    if (r == 0) return new A();
    if (r == 1) return new B();
    return new C();
}


void identify(Base* p) {
    if (dynamic_cast<A*>(p)) { std::cout << "A\n"; return; }
    if (dynamic_cast<B*>(p)) { std::cout << "B\n"; return; }
    if (dynamic_cast<C*>(p)) { std::cout << "C\n"; return; }
    std::cout << "Unknown\n";
}


void identify(Base& p) {
    // No <typeinfo> header; catch all exceptions from failed reference casts.
    try { (void)dynamic_cast<A&>(p); std::cout << "A\n"; return; } catch (...) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B\n"; return; } catch (...) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C\n"; return; } catch (...) {}
    std::cout << "Unknown\n";
}
