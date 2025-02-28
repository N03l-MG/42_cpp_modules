#include <cmath>
#include "Point.hpp"

Fixed AbsFixed(Fixed const value)
{
	if (value.getRawBits() < 0)
        return Fixed(-value.getRawBits());
    return value;
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	// Area formula from triangle vertex coords: (1/2) |x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)|
	Fixed areaABP = Fixed(0.5f) * AbsFixed(a.getX() * (b.getY() - p.getY()) + b.getX() * (p.getY() - a.getY()) + p.getX() * (a.getY() - b.getY()));
	Fixed areaBCP = Fixed(0.5f) * AbsFixed(b.getX() * (c.getY() - p.getY()) + c.getX() * (p.getY() - b.getY()) + p.getX() * (b.getY() - c.getY()));
	Fixed areaCAP = Fixed(0.5f) * AbsFixed(c.getX() * (a.getY() - p.getY()) + a.getX() * (p.getY() - c.getY()) + p.getX() * (c.getY() - a.getY()));
	Fixed areaABC = Fixed(0.5f) * AbsFixed(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
	// If any all the areas exist and sum to the total area, the point must be inside the triangle.
	// Otherwise it must be outside or on an edge/corner.
	if (areaABP != 0 && areaBCP != 0 && areaCAP != 0 && (areaABP + areaBCP + areaCAP == areaABC))
		return true;
	return false;
}
