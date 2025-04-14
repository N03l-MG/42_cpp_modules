#include <string>
#include <iostream>
#include "ScalarConverter.hpp"
#include "TextFormat.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << RED "Invalid Arguments! Usage: ./convert [literal]" RESET << std::endl;
		return 1;
	}
	try {
		ScalarConverter::convert(argv[1]);
	} catch (...) {
		return 1;
	}
	return 0;
}

// int	main()
// {
// 	std::string	tests[] = {"-42", "nan", "42.874f", "'p'", "&", "-inf", "-inff", "2147483647", "2147483648", "42.87434573567345063745038450357863078"};
// 	//	Program
// 	for (int i = 0; i < 10; i++)
// 	{
// 		std::cout << "-----------------------------------" << std::endl;
// 		ScalarConverter::convert(tests[i]);
// 		std::cout << "-----------------------------------" << std::endl;
// 	}
// 	return 0;
// }
