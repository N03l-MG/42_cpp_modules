#include <iostream>
#include <string>
#include <random>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "TextFormat.hpp"

Base *generate(void)
{
	std::random_device rand; // Hardware-random generator
	std::mt19937 gen(rand()); // "Mersenne Twister" generator with generated seed
	std::uniform_int_distribution<> dis(0 ,2); // Range from 0 to 2
	switch (dis(gen)) // Generate a random number in said range and instantiate a class
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return nullptr;
	}
}

void identify(Base *p) // Pointer version
{
	if (!p)
		std::cout << YELLOW "Result is NULL." RESET << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << BLUE "Result is of type A." RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << BLUE "Result is of type B." RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << BLUE "Result is of type C." RESET << std::endl;
	else
		std::cout << YELLOW "Result is unknown." RESET << std::endl;
}

void identify(Base &p) // Reference version
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << BLUE "Result is of type A." RESET << std::endl;
		return;
	} catch (std::bad_cast &) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << BLUE "Result is of type B." RESET << std::endl;
		return;
	} catch (std::bad_cast &) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << BLUE "Result is of type C." RESET << std::endl;
		return;
	} catch (std::bad_cast &) {}
	std::cout << YELLOW "Result is unknown." RESET << std::endl;
}

int main()
{
	Base *base;
	// Generate and identify 15 times...
	for (size_t i = 0; i < 15; i++)
	{
		base = generate();
		std::cout << CYAN "By reference:" RESET << std::endl;
		identify(base);
		std::cout << CYAN "By pointer:" RESET << std::endl;
		identify(*base);
		std::cout << std::endl;
		if (base) // Free each one (they are allocated on the heap)
			delete base;
	}
	// Null tests
	// Cannot pass base itself or test null reference, that's wrong.
	std::cout << CYAN "By pointer (NULL):" RESET << std::endl;
	identify(nullptr);

	return 0;
}
