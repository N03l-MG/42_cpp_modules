#include "RPN.hpp"

int main(int argc, char **argv)
{
	std::cout << CYAN UNDERLINE "RPN Calculator:" RESET << std::endl;
	try {
		if (argc != 2)
			throw RPN::InvalidArgsException();
		RPN rpn(argv[1]);
		std::cout << std::endl;
		rpn.EvaluateExpression();
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
