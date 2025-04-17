#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <stack>
#include <limits>

// Colors
#define RED       "\x1b[31m ✗ "
#define GREEN     "\x1b[32m ✓ "
#define YELLOW    "\x1b[33m ⚠ "
#define BLUE      "\x1b[34m > "
#define MAGENTA   "\x1b[35m ⌫ "
#define CYAN      "\x1b[36m"
// Styles
#define BOLD      "\x1b[1m"
#define UNDERLINE "\x1b[4m\t\t"
// Format reset
#define RESET     "\x1b[0m"

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
		//OCF
		MutantStack();
		MutantStack(const MutantStack &src);
		MutantStack &operator=(const MutantStack &src);
		~MutantStack();

		// Members
		
};

#include "MutantStack.tpp"
