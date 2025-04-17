#include "MutantStack.hpp"

// Orthodox Canonical Form
// (default constructor, copy constructor, assignment operator override, destructor)
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
	std::cout << BOLD GREEN "Default MutantStack instance constructed." RESET << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &src) : std::stack<T, Container>(src)
{
	std::cout << BOLD GREEN "MutantStack instance copy-constructed." RESET << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &src)
{
	if (this != &src)
		std::stack<T, Container>::operator=(src);
	return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
	std::cout << BOLD MAGENTA "MutantStack instance destroyed." RESET << std::endl;
}
