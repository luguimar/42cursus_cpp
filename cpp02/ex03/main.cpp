#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

// Declare the function (so we can call it in main)
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    // Define the triangle's vertices
    Point A(0.0f, 0.0f);
    Point B(10.0f, 0.0f);
    Point C(5.0f, 5.0f);

    // Test some points
    Point inside(5.0f, 1.0f);
    Point edge(5.0f, 0.0f);
    Point outside(11.0f, 2.0f);

    std::cout << std::boolalpha; // print bool as true/false

    std::cout << "Point inside (5,1):   " << bsp(A,B,C, inside) << std::endl;
    std::cout << "Point on edge (5,0):  " << bsp(A,B,C, edge) << std::endl;
    std::cout << "Point outside(11,2):  " << bsp(A,B,C, outside) << std::endl;

    return 0;
}

