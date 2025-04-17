#include <iostream>
#include <string>
#include "Array.hpp"
#include "Array.tpp"

int main()
{
	// Straight up copy of friend's test main, will change lol
	std::cout << CYAN UNDERLINE "Empty Array:" RESET << std::endl;
	{
		Array<int>	a;

		try {
			a[0] = 42;
		} catch (const Array<int>::OutOfBoundsException &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << CYAN UNDERLINE "Array of size 20:" RESET << std::endl;
	{
		Array<int>	b(20);

		for (int i = 0; i < 20; i++)
			b[i] = i;
		for (int i = 0; i < 20; i++)
			std::cout << b[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << CYAN UNDERLINE "Copy array:" RESET << std::endl;
	{
		Array<int>	c(10);
		Array<int>	d(10);

		for (int i = 0; i < 10; i++)
			c[i] = i;
		
		d = c;
		Array<int>	e(c);
		c[9] = -42;

		for (int i = 5; i < 10; i++)
			d[i] = 42;
		for (int i = 0; i < 10; i++)
			std::cout << "C:  " << c[i] << "\tD:  " << d[i] << "\tE:  " << e[i] << std::endl;
	}
	return 0;
}
