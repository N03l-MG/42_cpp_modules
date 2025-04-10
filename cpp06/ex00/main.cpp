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
	ScalarConverter::convert(argv[1]);
	return 0;
}
