#include "Point.hpp"

// Orthodox Canonical Form

Point::Point() : x(0), y(0) { }

Point::Point(const Point &src) : x(src.x), y(src.y) { }

Point &Point::operator=(const Point &src)
{
	// The people that wrote this execise didnt stop to think for 5 seconds about how
	// forcing us to make the x and y attributes const would make it literally impossible
	// to then later reassign them with an operator overload. Which is what this is...
	// x = src.x;
	// y = src.y;
	return *this;
}

Point::~Point() { }

// Point parametric constructor

Point::Point(Fixed const x, Fixed const y) : x(x), y(y) { }

// X and Y getters

Fixed Point::getX(void) const 
{
	return x;
}

Fixed Point::getY(void) const
{
	return y;
}
