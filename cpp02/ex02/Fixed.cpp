#include "Fixed.hpp"
#include <cmath>  // Needed for roundf

// ----------------- Constructors / Destructor ------------------

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// ----------------- Int / Float Constructors ------------------

Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = intValue << _fractionalBits; 
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

// ----------------- Getter / Setter ------------------

int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits member function called" << std::endl;
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

bool Fixed::operator>(const Fixed& other) const {
    return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const {
    return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const {
    return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const {
    return (this->_value <= other._value);
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
    // Multiply the two fixed values, then shift back by fractional bits
    // (long long used to avoid overflow with big numbers)
    long tmp = static_cast<long>(this->_value) * static_cast<long>(other._value);
    // Then shift back by fractionalBits to maintain correct scaling
    tmp = tmp >> _fractionalBits;
    Fixed result;
    result.setRawBits(static_cast<int>(tmp));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    // If other is 0, that's not handled => possibly crash as problem statement allows
    // Convert to long long to maintain precision, shift first, then divide
    long numerator = static_cast<long>(this->_value) << _fractionalBits;
    long denominator = static_cast<long>(other._value);
    long tmp = numerator / denominator;
    Fixed result;
    result.setRawBits(static_cast<int>(tmp));
    return result;
}

// ----------------- Increment/Decrement Operators ------------------
// The smallest increment is 1, which is 1/256 in real value (since fractionalBits=8).

// Pre-increment: ++a
Fixed& Fixed::operator++() {
    this->_value++;
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
    this->_value--;
    return *this;
}

// Post-decrement: a--
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_value--;
    return temp;
}

// ----------------- Min / Max ------------------

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b ? a : b);
}

// ----------------- Stream Operator ------------------

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

