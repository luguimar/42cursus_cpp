#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _value;                         // The fixed-point value
    static const int    _fractionalBits = 8;            // Number of fractional bits

public:
    // Orthodox Canonical Form
    Fixed();                               // Default constructor
    Fixed(const Fixed& other);             // Copy constructor
    Fixed& operator=(const Fixed& other);  // Copy assignment operator
    ~Fixed();                              // Destructor

    // Constructors for int and float
    Fixed(const int intValue);             // Constructor: int to fixed-point
    Fixed(const float floatValue);         // Constructor: float to fixed-point

    // Getter and Setter
    int   getRawBits(void) const;
    void  setRawBits(int const raw);

    // Conversions
    float toFloat(void) const;
    int   toInt(void) const;

    // Comparison operators
    bool operator<(const Fixed& other) const;
    bool operator>(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment/Decrement operators
    Fixed& operator++();       // Pre-increment
    Fixed operator++(int);     // Post-increment
    Fixed& operator--();       // Pre-decrement
    Fixed operator--(int);     // Post-decrement
};

// Overload of the insertion operator for output streams
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

