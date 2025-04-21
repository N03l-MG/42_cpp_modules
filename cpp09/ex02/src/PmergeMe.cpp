#include "PmergeMe.hpp"
//#include "TextFormat.hpp"

// Orthodox Canonical Form (default constructor, param constructor, copy constructor, destructor)
PmergeMe::PmergeMe() // : default params
{
	std::cout << BOLD GREEN "Default PmergeMe instance constructed." RESET << std::endl;
}

PmergeMe::PmergeMe(std::vector<int> unsorted) // : param assignment (if possible)
{
	// code
	std::cout << BOLD GREEN "PmergeMe " /* << name (if possible) */ << " constructed." RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src) // : param getters
{
	// code
	*this = src;
	std::cout << BOLD GREEN "PmergeMe instance copy-constructed." RESET << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
		// code
	return *this;
}

PmergeMe::~PmergeMe()
{
	std::cout << BOLD MAGENTA "PmergeMe instance destroyed." RESET << std::endl;
}