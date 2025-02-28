#include <iostream>
#include "Point.hpp"

void testPoint(Point const a, Point const b, Point const c, Point const p)
{
	if (bsp(a, b, c, p))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point is outside the triangle." << std::endl;
}

int main(void)
{
	// Triangle vertices
	Point a = Point(-1, 4);
	Point b = Point(-1, 0);
	Point c = Point(5, 2);
	// Test points
	Point in = Point(2, 2);
	Point out = Point(0, 0);
	Point edge = Point(-1, 2);
	Point corner = Point(5, 2);
	// BSP tests
	testPoint(a, b, c, in); // Point is inside the triangle. (true)
	testPoint(a, b, c, out); // Point is outside the triangle. (false)
	testPoint(a, b, c, edge); // Point is on the edge of the triangle. (false)
	testPoint(a, b, c, corner); // Point is on the corner of the triangle. (false)

	return 0;
}
