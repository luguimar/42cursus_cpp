
#include "Point.hpp"
#include <iostream>

// Default constructor -> (0,0)
Point::Point() : _x(0), _y(0) {
    // std::cout << "Point default constructor called\n";
}

// Custom constructor -> (x, y)
Point::Point(const float x, const float y) : _x(x), _y(y) {
    // std::cout << "Point float constructor called\n";
}

// Copy constructor
Point::Point(const Point& other) : _x(other._x), _y(other._y) {
    // std::cout << "Point copy constructor called\n";
}

// Copy assignment operator
Point& Point::operator=(const Point& other) {
    // std::cout << "Point copy assignment operator called\n";
    // _x and _y are const, so we can't assign them here
    // This effectively does nothing
    (void)other;
    return *this;
}

Point::~Point() {
    // std::cout << "Point destructor called\n";
}

// Getters
Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }
