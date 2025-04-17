#include "Span.hpp"

int main()
{
	std::cout << CYAN UNDERLINE "Basic Test:" RESET << std::endl;
	{
		Span sp = Span(5);
		std::cout << std::endl;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printVector();
		std::cout << BLUE "Shortest Span:" RESET << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << BLUE "Longest Span:" RESET << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << CYAN UNDERLINE "Cannot Add Test:" RESET << std::endl;
	try {
		Span defSp; // Default has Max 0.
		std::cout << std::endl;
		defSp.addNumber(42);
	} catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; 
	}
	std::cout << std::endl;

	std::cout << CYAN UNDERLINE "Vector Too Small Test:" RESET << std::endl;
	try {
		Span smallSp = Span(2);
		std::cout << std::endl;
		smallSp.addNumber(42);
		smallSp.longestSpan();
		smallSp.shortestSpan(); // Won't even get here.
	} catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; 
	}

	return 0;
}
