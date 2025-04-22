#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <limits>
#include <algorithm>

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

class RPN
{
	private:
		std::string expression;
		std::stack<char> tokens;
	public:
		//OCF
		RPN();
		RPN(std::string input);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();

	// Members
	private:
		std::stack<char> ParseExpression();
	public:
		void EvaluateExpression();

		// Exceptions
		class InvalidArgsException : public std::exception
		{
			public: const char *what() const throw();
		};

		class InvalidExpressionException : public std::exception
		{
			public: const char *what() const throw();
		};

		class NotResolvableException : public std::exception
		{
			public: const char *what() const throw();
		};

		class DivisionByZeroException : public std::exception
		{
			public: virtual const char* what() const throw();
		};
};
