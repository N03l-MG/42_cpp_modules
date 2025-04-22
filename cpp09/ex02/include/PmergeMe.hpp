#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <iomanip>
#include <ctime>

// Colors
#define RED       "\x1b[31m ✗ "
#define GREEN     "\x1b[32m ✓ "
#define YELLOW    "\x1b[33m ⚠ "
#define BLUE      "\x1b[34m ◆ "
#define MAGENTA   "\x1b[35m ⌫ "
#define CYAN      "\x1b[36m"
// Styles
#define BOLD      "\x1b[1m"
#define UNDERLINE "\x1b[4m\t\t"
// Format reset
#define RESET     "\x1b[0m"

template<typename Container>
class PmergeMe
{
	static_assert(std::is_same<Container, std::vector<int>>::value ||
		std::is_same<Container, std::deque<int>>::value,
		"PmergeMe only works with std::vector<int> or std::deque<int>");

	private:
		Container unsorted;
		Container sorted;
		std::list<int> jacobsthalSeries;
	public:
		//OCF
		PmergeMe();
		PmergeMe(Container const &input);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

	// Member Methods
	private:
		std::list<int> GenerateJacobsthal();
		void CheckResult();
		Container Sort();
	public:
		void SortAndPrint();

		//Exceptions
		class InvalidArgsException : public std::exception
		{
			public: const char *what() const throw();
		};

		class InvalidNumberException : public std::exception
		{
			public: virtual const char* what() const throw();
		};
};

// Explicit instantiancion for supported types
template class PmergeMe<std::vector<int>>;
template class PmergeMe<std::deque<int>>;
