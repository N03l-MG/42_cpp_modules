#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(b);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	// extra tests
	std::cout << std::endl;
	std::cout << Fixed::min(b, a) << std::endl;
	std::cout << a + b << std::endl;
	std::cout << c - a << std::endl;
	std::cout << a * b << std::endl;
	std::cout << c / a << std::endl;
	if (a > b)
		std::cout << "a is grater" << std::endl;
	else if (a < b)
		std::cout << "b is grater" << std::endl;
	if (c != b)
		std::cout << "c is not equal to b" << std::endl;
	else if (c == b)
		std::cout << "c is equal to b" << std::endl;

	return 0;
}
