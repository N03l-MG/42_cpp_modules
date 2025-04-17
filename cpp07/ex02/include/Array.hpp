#pragma once

#include <iostream>
#include <exception>
#include <string>

// ~~ Debug Text Formatting ~~ //
// Colors
# define RED       "\x1b[31m ✗ " // Error or exception
# define GREEN     "\x1b[32m 🛠 " // Construction
# define YELLOW    "\x1b[33m ⚠ " // Warning
# define BLUE      "\x1b[34m 🛈 " // Info or log
# define MAGENTA   "\x1b[35m 🗑 " // Destruction
# define CYAN      "\x1b[36m" // Title or important info
// Styles
# define BOLD      "\x1b[1m" // Construction, destruction, names and errors
# define UNDERLINE "\x1b[4m\t\t" // Titles
// Format reset
# define RESET     "\x1b[0m" // Reset back to plain white text

// ~~ Template Class Definition ~~ //
template <typename T>
class Array
{
	private:
		T *array;
		size_t length;
	public:
		// Construction and Destruction
		Array();
		Array(size_t n);
		Array(Array &src);
		~Array();

		// Operator Overloads
		Array<T> &operator=(Array &src);
		T &operator[](size_t index);

		// Methods 
		size_t size() const;

		// Exception Class Method Override
		class OutOfBoundsException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
