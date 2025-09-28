#include <iostream>
#include <string>
#include "Array.hpp"

static void divider(const std::string &title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {
    divider("default constructor");
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;

    divider("size constructor");
    Array<std::string> b(3);
    std::cout << "b.size() = " << b.size() << std::endl;
    b[0] = "hello";
    b[1] = "42";
    b[2] = "porto";
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    divider("deep copy semantics");
    Array<std::string> c = b;  // copy ctor
    c[1] = "lisboa";
    std::cout << "b[1] = " << b[1] << " (should stay '42')" << std::endl;
    std::cout << "c[1] = " << c[1] << " (independent copy)" << std::endl;

    divider("assignment operator");
    Array<std::string> d;
    d = b;
    d[0] = "bye";
    std::cout << "b[0] = " << b[0] << " (should stay 'hello')" << std::endl;
    std::cout << "d[0] = " << d[0] << " (independent copy)" << std::endl;

    divider("const access");
    const Array<std::string> e = b;
    std::cout << "e[2] = " << e[2] << std::endl;

    divider("bounds checking");
    try {
        std::cout << b[3] << std::endl; // out of bounds
    } catch (const std::exception &ex) {
        std::cout << "Caught exception: " << ex.what() << std::endl;
    }
    try {
        Array<int> z(2);
        z[0] = 10;
        z[1] = 20;
        std::cout << "z[0] = " << z[0] << ", z[1] = " << z[1] << std::endl;
        std::cout << "Accessing z[2]..." << std::endl;
        std::cout << z[2] << std::endl; // out of bounds
    } catch (const std::exception &ex) {
        std::cout << "Caught exception: " << ex.what() << std::endl;
    }

    divider("value-initialization demo");
    Array<int> f(5);
    for (unsigned int i = 0; i < f.size(); ++i)
        std::cout << "f[" << i << "] = " << f[i] << std::endl; // should be 0

    return 0;
}
