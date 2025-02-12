#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;       // 0
    std::cout << ++a << std::endl;     // pre-increment
    std::cout << a << std::endl;       // check new value
    std::cout << a++ << std::endl;     // post-increment (print old, then increment)
    std::cout << a << std::endl;       // check new value
    std::cout << b << std::endl;       // should be 5.05 * 2 = 10.10(ish)
    std::cout << Fixed::max( a, b ) << std::endl; // Compare a and b
    std::cout << Fixed::min( a, b ) << std::endl; // Compare a and b

    return 0;
}

