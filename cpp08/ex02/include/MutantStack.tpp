#include "MutantStack.hpp"

// Orthodox Canonical Form
// (default constructor, copy constructor, assignment operator override, destructor)
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << BOLD GREEN "Default MutantStack instance constructed." RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src)
{
	std::cout << BOLD GREEN "MutantStack instance copy-constructed." RESET << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
	if (this != &src)
		std::stack<T>::operator=(src);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << BOLD MAGENTA "MutantStack instance destroyed." RESET << std::endl;
}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return std::stack<T>::c.end();
}

// Index [] operator overrides
template <typename T>
T& MutantStack<T>::operator[](size_t index)
{
    if (index >= this->size())
        throw std::out_of_range("Index out of bounds");
    return this->c[index];
}

template <typename T>
const T& MutantStack<T>::operator[](size_t index) const
{
    if (index >= this->size())
        throw std::out_of_range("Index out of bounds");
    return this->c[index];
}
