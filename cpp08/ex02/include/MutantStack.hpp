#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <stack>
#include <limits>

// Colors
#define RED       "\x1b[31m ✗ " // Error or exception
#define GREEN     "\x1b[32m 🛠 " // Construction
#define YELLOW    "\x1b[33m ⚠ " // Warning
#define BLUE      "\x1b[34m 🛈 " // Info or log
#define MAGENTA   "\x1b[35m 🗑 " // Destruction
#define CYAN      "\x1b[36m"
// Styles
#define BOLD      "\x1b[1m"
#define UNDERLINE "\x1b[4m\t\t"
// Format reset
#define RESET     "\x1b[0m"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		//OCF
		MutantStack();
		MutantStack(const MutantStack &src);
		MutantStack &operator=(const MutantStack &src);
		~MutantStack();

		// Iterator typedefs
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		// Members (iterator overrides)
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		// Extra [] operator override
		T &operator[](size_t index);
		const T &operator[](size_t index) const;
};

#include "MutantStack.tpp"
