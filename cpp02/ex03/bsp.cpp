#include "Point.hpp"

static Fixed area2(Point const &p1, Point const &p2, Point const &p3)
{
    // Cross product approach, but we won't do the /2 part 
    // because we only compare sums of these areas.
    // area2 = absolute value of cross product
    Fixed x1 = p1.getX();
    Fixed y1 = p1.getY();
    Fixed x2 = p2.getX();
    Fixed y2 = p2.getY();
    Fixed x3 = p3.getX();
    Fixed y3 = p3.getY();

    // cross = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1)
    Fixed cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    // For strictly inside checks, we need absolute value
    if (cross < Fixed(0))
        cross = cross * Fixed(-1);
    return cross;  // 2 * actual area
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // 1) area of the main triangle
    Fixed areaABC = area2(a, b, c);

    // 2) area of sub-triangles
    Fixed areaPAB = area2(point, a, b);
    Fixed areaPBC = area2(point, b, c);
    Fixed areaPCA = area2(point, c, a);

    // If sum of sub-areas is the same as total area => 
    // point is either inside or on the edge. 
    // We want strictly inside => none of the sub-areas can be 0.
    if ( (areaPAB + areaPBC + areaPCA) == areaABC
         && areaPAB != Fixed(0)
         && areaPBC != Fixed(0)
         && areaPCA != Fixed(0) ) {
        return true;
    }
    return false;
}
