#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>

// Colors and Formatting
# define RED       "\x1b[31m ✗ "
# define BOLD      "\x1b[1m"
// Format reset
# define RESET     "\x1b[0m"

// Exception class
class NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return BOLD "Entry not found!" RESET;
		}
};

// Easyfind template
template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator found = std::find(container.begin(), container.end(), n);
	if (found != container.end())
		return (found);
	throw NotFoundException();
}
