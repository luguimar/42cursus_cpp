#include "Fixed.hpp"

// ----------------- Constructors / Destructor ------------------

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    // Copy the internal integer value from the other object
    this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    // Check for self-assignment if you want to be thorough, 
    // but not always necessary. Then copy the internal value
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// ----------------- Getter / Setter ------------------

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}
