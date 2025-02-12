#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _value;                          // Stores the fixed-point number
    static const int    _fractionalBits = 8;             // Always 8 fractional bits

public:
    // Constructors & Destructor
    Fixed();                                  // Default constructor
    Fixed(const Fixed& other);               // Copy constructor
    Fixed& operator=(const Fixed& other);    // Copy assignment operator
    ~Fixed();                                // Destructor

    // Getter & Setter
    int  getRawBits(void) const;             // Returns the raw fixed-point value
    void setRawBits(int const raw);          // Sets the raw fixed-point value
};

#endif
