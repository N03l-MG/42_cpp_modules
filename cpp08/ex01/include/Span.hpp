#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <vector>
#include <limits>

// Colors
#define RED       "\x1b[31m ✗ " // Error or exception
#define GREEN     "\x1b[32m 🛠 " // Construction
#define YELLOW    "\x1b[33m ⚠ " // Warning
#define BLUE      "\x1b[34m 🛈 " // Info or log
#define MAGENTA   "\x1b[35m 🗑 " // Destruction
# define CYAN      "\x1b[36m"
// Styles
# define BOLD      "\x1b[1m"
# define UNDERLINE "\x1b[4m\t\t"
// Format reset
# define RESET     "\x1b[0m"

class Span
{
	private:
		std::vector<int> numVec;
		size_t maxSize;
	public:
		// OCF
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span();

		// Members
		void addNumber(int num);
		size_t shortestSpan();
		size_t longestSpan();
		void printVector();

		// Exceptions
		class VectorFullException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return BOLD RED "Vector is already full!" RESET;
				}
		};

		class VectorTooSmallException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return BOLD RED "Vector too small!" RESET;
				}
		};
};
