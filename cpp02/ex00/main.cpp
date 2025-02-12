#include "Fixed.hpp"

int main(void) {

    Fixed a;             // Calls default constructor
    Fixed b(a);          // Calls copy constructor
    Fixed c;             // Calls default constructor again

    c = b;               // Calls copy assignment operator

    std::cout << a.getRawBits() << std::endl;  // getRawBits called on 'a'
    std::cout << b.getRawBits() << std::endl;  // getRawBits called on 'b'
    std::cout << c.getRawBits() << std::endl;  // getRawBits called on 'c'
    c.setRawBits(42);     // setRawBits called on 'c'
    std::cout << c.getRawBits() << std::endl;  // getRawBits called on 'c'
    // Expected output:
    // Default constructor called
    // Copy constructor called
    // Default constructor called
    // Copy assignment operator called
    // getRawBits member function called
    // 0
    // getRawBits member function called
    // 0
    // getRawBits member function called
    // 0
    // setRawBits member function called
    // getRawBits member function called
    // 42
    // Destructor called
    // Destructor called
    // Destructor called
    return 0;
}
