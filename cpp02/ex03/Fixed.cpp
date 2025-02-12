#include "Fixed.hpp"
#include <cmath>

// ----------------- Constructors / Destructor ------------------

Fixed::Fixed() : _value(0) {
    // Default constructor
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    // Copy constructor
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    // Copy assignment operator
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    // Destructor
    // std::cout << "Destructor called" << std::endl;
}

// ----------------- Int / Float Constructors ------------------

Fixed::Fixed(const int intValue) {
    // Int constructor
    // std::cout << "Int constructor called" << std::endl;
    this->_value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    // Float constructor
    // std::cout << "Float constructor called" << std::endl;
    this->_value = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

// ----------------- Getter / Setter ------------------

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

// ----------------- Conversions ------------------

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_value >> _fractionalBits;
}

// ----------------- Comparison Operators ------------------

bool Fixed::operator<(const Fixed& other) const {
    return (this->_value < other._value);
}

bool Fixed::operator>(const Fixed& other) const {
    return (this->_value > other._value);
}

bool Fixed::operator<=(const Fixed& other) const {
    return (this->_value <= other._value);
}

bool Fixed::operator>=(const Fixed& other) const {
    return (this->_value >= other._value);
}

bool Fixed::operator==(const Fixed& other) const {
    return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const {
    return (this->_value != other._value);
}

// ----------------- Arithmetic Operators ------------------

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value + other._value);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value - other._value);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    // Multiply using 'long' to prevent overflow
    long tmp = static_cast<long>(this->_value) * static_cast<long>(other._value);
    // Adjust for fixed-point scaling
    tmp = tmp >> _fractionalBits;
    result.setRawBits(static_cast<int>(tmp));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    // Check for division by zero (allowed to crash per exercise specification)
    long numerator = static_cast<long>(this->_value) << _fractionalBits;
    long tmp = numerator / static_cast<long>(other._value);
    result.setRawBits(static_cast<int>(tmp));
    return result;
}

// ----------------- Increment/Decrement Operators ------------------

// Pre-increment: ++a
Fixed& Fixed::operator++() {
    ++(this->_value);
    return *this;
}

// Post-increment: a++
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_value++;
    return temp;
}

// Pre-decrement: --a
Fixed& Fixed::operator--() {
    --(this->_value);
    return *this;
}

// Post-decrement: a--
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_value--;
    return temp;
}

// ----------------- Stream Insertion Operator ------------------

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

