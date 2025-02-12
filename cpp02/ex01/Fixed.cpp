#include "Fixed.hpp"
#include <cmath>  // Needed for roundf

// ----------------- Constructors / Destructor ------------------

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    // Copy the internal integer value
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other.getRawBits(); 
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// ----------------- New Constructors ------------------

Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    // Convert intValue to fixed-point by shifting bits to the left
    // Example: 42 -> 42 << 8
    this->_value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    // Convert floatValue to fixed-point
    // Multiply by 2^fractionalBits, then round to nearest int
    this->_value = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

// ----------------- Getter / Setter ------------------

int Fixed::getRawBits(void) const {
    // Uncomment if you want to see logs
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    // Uncomment if you want to see logs
    // std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

// ----------------- Conversions ------------------

float Fixed::toFloat(void) const {
    // Divide by 2^fractionalBits to get back to float
    return static_cast<float>(this->_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    // Shift right by fractional bits to get integer
    return this->_value >> _fractionalBits;
}

// ----------------- Insertion Operator ------------------

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
