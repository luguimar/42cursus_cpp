#include "Fixed.hpp"

int main(void) {

    Fixed a;             // Calls default constructor
    Fixed b(a);          // Calls copy constructor
    Fixed c;             // Calls default constructor again

    c = b;               // Calls copy assignment operator

    std::cout << a.getRawBits() << std::endl;  // getRawBits called on 'a'
    std::cout << b.getRawBits() << std::endl;  // getRawBits called on 'b'
    std::cout << c.getRawBits() << std::endl;  // getRawBits called on 'c'

    return 0;
}
