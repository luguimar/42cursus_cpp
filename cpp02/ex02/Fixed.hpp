#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _value;                         // Fixed-point value
    static const int    _fractionalBits = 8;            // Number of fractional bits

public:
    // Orthodox Canonical Form
    Fixed();                                // Default constructor
    Fixed(const Fixed& other);              // Copy constructor
    Fixed& operator=(const Fixed& other);   // Copy assignment operator
    ~Fixed();                               // Destructor

    // Constructors for int and float
    Fixed(const int intValue);
    Fixed(const float floatValue);

    // Getter/Setter
    int   getRawBits(void) const;
    void  setRawBits(int const raw);

    // Conversions
    float toFloat(void) const;
    int   toInt(void) const;

    // ----------------- NEW OPERATORS -----------------
    // Comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment/Decrement operators
    // Pre-increment: ++a
    Fixed& operator++();       
    // Post-increment: a++
    Fixed operator++(int);     
    // Pre-decrement: --a
    Fixed& operator--();       
    // Post-decrement: a--
    Fixed operator--(int);     

    // ----------------- MIN / MAX -----------------
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Overload of the insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

