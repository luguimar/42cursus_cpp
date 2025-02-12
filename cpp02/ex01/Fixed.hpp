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

    // New constructors
    Fixed(const int intValue);             // Converts int -> fixed-point
    Fixed(const float floatValue);         // Converts float -> fixed-point

    // Getters/Setters
    int   getRawBits(void) const;
    void  setRawBits(int const raw);

    // Conversions
    float toFloat(void) const;
    int   toInt(void) const;
};

// Overload of the insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
