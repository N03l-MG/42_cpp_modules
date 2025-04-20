#include "RPN.hpp"

// Orthodox Canonical Form
// (default constructor, param constructor, copy constructor, assignment operator override, destructor)
RPN::RPN() : expression("0")
{
	tokens = ParseExpression();
	std::cout << BOLD GREEN "Default RPN instance constructed." RESET << std::endl;
}

RPN::RPN(std::string input) : expression(input)
{
	tokens = ParseExpression();
	std::cout << BOLD GREEN "RPN instance constructed." RESET << std::endl;
}

RPN::RPN(const RPN &src) : expression(src.expression), tokens(src.tokens)
{
	*this = src;
	std::cout << BOLD GREEN "RPN instance copy-constructed." RESET << std::endl;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src) {
		this->expression = src.expression;
		this->tokens = src.tokens;
	}
	return *this;
}

RPN::~RPN()
{
	std::cout << BOLD MAGENTA "RPN instance destroyed." RESET << std::endl;
}

// Member Functions
std::stack<char> RPN::ParseExpression()
{
	std::stack<char> tokens;
    std::string validChars = "0123456789+-/*";

	if (expression.empty())
		throw InvalidExpressionException();

	bool space = false;
	for (size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];
		
		if (space && c != ' ') // Force "digit, space, digit ..." format
			throw InvalidExpressionException();
		if (!space) {
			if (validChars.find(c) == std::string::npos)
				throw InvalidExpressionException();
			if (std::string("+-*/").find(c) != std::string::npos) {
				if (tokens.size() < 2)
					throw InvalidExpressionException();
			}
			tokens.push(c);
		}
		space = !space;
	}

	return tokens;
}

void RPN::EvaluateExpression()
{
	std::cout << BLUE "Evaluating Expression: " BOLD RESET << expression << RESET << std::endl;
	std::stack<char> temp = tokens;
	std::stack<char> reversed;
	std::stack<int> numbers;

	while (!temp.empty()) // Reverse tokens
	{
		reversed.push(temp.top());
		temp.pop(); // Trick to iterate through stack
	}
	while (!reversed.empty())
	{
		char token = reversed.top();
		reversed.pop();
		
		if (isdigit(token)) {
			numbers.push(token - '0'); // Convert to integter
			continue;
		}
		// Pick the next two values
		int b = numbers.top();
		numbers.pop();
		int a = numbers.top();
		numbers.pop();
		// Calculate result
		switch (token) {
			case '+':
				numbers.push(a + b);
				break;
			case '-':
				numbers.push(a - b);
				break;
			case '*':
				numbers.push(a * b);
				break;
			case '/':
				if (b == 0)
					throw DivisionByZeroException();
				numbers.push(a / b);
				break;
		}
	}
	if (numbers.size() != 1) // Must be only the resulting number left
		throw NotResolvableException();

	std::cout << BLUE "Result: " RESET BOLD << numbers.top() << RESET << std::endl;
}

// Exception Class Method Overrides
const char *RPN::InvalidArgsException::what() const throw()
{
	return RED "Error: " BOLD "Invalid arguments! Please use \"./RPN [expression]\"" RESET;
}

const char *RPN::InvalidExpressionException::what() const throw()
{
	return RED "Error: " BOLD "Invalid expression!" RESET;
}

const char *RPN::NotResolvableException::what() const throw()
{
	return YELLOW "Error: " BOLD "Expression not resolvable!" RESET;
}

const char *RPN::DivisionByZeroException::what() const throw()
{
	return YELLOW "Error: " BOLD "Division by zero!" RESET;
}
