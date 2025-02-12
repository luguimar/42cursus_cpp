#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    // Orthodox Canonical Form
    Point();                             // Default constructor (0,0)
    Point(const Point& other);          // Copy constructor
    Point& operator=(const Point& other); // Copy assignment operator
    ~Point();                           // Destructor

    // Custom constructor
    Point(const float x, const float y);

    // Getters
    Fixed getX() const;
    Fixed getY() const;
};

#endif
