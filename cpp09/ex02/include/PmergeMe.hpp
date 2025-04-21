#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

// Colors
#define RED       "\x1b[31m ✗ "
#define GREEN     "\x1b[32m 🛠 "
#define YELLOW    "\x1b[33m ⚠ "
#define BLUE      "\x1b[34m 🛈 "
#define MAGENTA   "\x1b[35m 🗑 "
#define CYAN      "\x1b[36m"
// Styles
#define BOLD      "\x1b[1m"
#define UNDERLINE "\x1b[4m\t\t"
// Format reset
#define RESET     "\x1b[0m"

class PmergeMe
{
	private: ///FIXME: Make this generic so it can be Vector OR Deque!
		std::vector<int> unsorted;
		std::vector<int> sorted;
		std::list<int> jacobsthalSeries;
	public:
		//OCF
		PmergeMe();
		PmergeMe(std::vector<int> unsorted);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		// Members
		

		//Exceptions
		class InvalidNumberException : public std::exception
		{
			public: virtual const char* what() const throw();
		};
		
		class DuplicateNumberException : public std::exception
		{
			public: virtual const char* what() const throw();
		};
};
