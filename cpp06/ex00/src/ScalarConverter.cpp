#include "ScalarConverter.hpp"
#include "TextFormat.hpp"

// No OCF because class is not instantiable

// Member methods
void ScalarConverter::convert(const std::string &literal)
{
	switch(get_type(literal))
	{
		case CHAR:
			printChar(literal);
			break;
		case INT:
			printInt(literal);
			break;
		case FLOAT:
			printFloat(literal);
			break;
		case DOUBLE:
			printDouble(literal);
			break;
		default:
			std::cout << RED "Invalid type!" RESET << std::endl;
			break;
	}
}

ScalarConverter::type ScalarConverter::get_type(const std::string &literal)
{
	if		(isChar(literal))	return CHAR;
	else if	(isInt(literal))	return INT;
	else if	(isFloat(literal))	return FLOAT; // TODO: check +inff, -inff, nanf
	else if	(isDouble(literal))	return DOUBLE; // TODO: check +inf, -inf, nan
	else return INVALID;
}

bool ScalarConverter::isChar(const std::string &literal)
{
	if ((literal.length() == 1 && !isdigit(literal[0]))
		|| (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\''))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string &literal)
{
	if (literal.length() == 0)
		return false;
	if (literal[0] == '-' || literal[0] == '+') {
		if (literal.length() == 1)
			return false;
	}
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	try {
		std::stoi(literal);
	} catch (std::out_of_range &e) {
		return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	if (literal.length() == 0)
		return false;
	if (literal[0] == '-' || literal[0] == '+') {
		if (literal.length() == 1)
			return false;
	}
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f')
			return false;
	}
	if (literal[literal.length() - 1] != 'f')
		return false;
	try {
		std::stof(literal);
	} catch (std::out_of_range &e) {
		return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	if (literal.length() == 0)
		return false;
	if (literal[0] == '-' || literal[0] == '+') {
		if (literal.length() == 1)
			return false;
	}
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]) && literal[i] != '.')
			return false;
	}
	try {
		std::stod(literal);
	} catch (std::out_of_range &e) {
		return false;
	}
	return true;
}

void ScalarConverter::printChar(const std::string &literal)
{
	std::cout << BLUE "Type: char" RESET << std::endl;
	if ((literal.length() == 3 && !isprint(literal[1]))
		|| (literal.length() == 1 && !isprint(literal[0])))
		std::cout << YELLOW "Non-displayable." RESET << std::endl;
	std::cout << BLUE "Conversions:" RESET << std::endl;
	std::cout << "char:\t" << (isprint(literal[0]) ? "'" + std::string(1, literal[0]) + "'"
				: YELLOW "Non-displayable" RESET) << std::endl;
	std::cout << "int:\t" << static_cast<int>(literal[0]) << std::endl;
	std::cout << "float:\t" << static_cast<float>(literal[0]) << "f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(literal[0]) << std::endl;
}

void ScalarConverter::printInt(const std::string &literal)
{
	int i;
	std::cout << BLUE "Type: int" RESET << std::endl;
	try {
		i = std::stoi(literal);
	} catch (std::out_of_range &e) {
		std::cout << YELLOW "Number out of range." RESET << std::endl;
		return;
	}
	std::cout << BLUE "Conversions:" RESET << std::endl;
	std::cout << "char:\t" << (isprint(i) ? "'" + std::string(1, static_cast<char>(i)) + "'"
				: YELLOW "Non-displayable" RESET) << std::endl;
	std::cout << "int:\t" << i << std::endl;
	std::cout << "float:\t" << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(i) << std::endl;
}

void ScalarConverter::printFloat(const std::string &literal)
{
	float f;
	std::cout << BLUE "Type: float" RESET << std::endl;
	try {
		f = std::stof(literal);
	} catch (std::exception &e) { // TODO: catch ".f"
		std::cout << YELLOW "Invalid float." RESET << std::endl;
		return;
	}
	std::cout << BLUE "Conversions:" RESET << std::endl;
	std::cout << "char:\t" << (isprint(f) ? "'" + std::string(1, static_cast<char>(f)) + "'"
				: YELLOW "Non-displayable" RESET) << std::endl;
	std::cout << "int:\t" << static_cast<int>(f) << std::endl;
	std::cout << "float:\t" << f << "f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printDouble(const std::string &literal)
{
	double d;
	std::cout << BLUE "Type: double" RESET << std::endl;
	try {
		d = std::stod(literal);
	} catch (std::exception &e) {
		std::cout << YELLOW "Invalid double." RESET << std::endl;
		return;
	}
	std::cout << BLUE "Conversions:" RESET << std::endl;
	std::cout << "char:\t" << (isprint(d) ? "'" + std::string(1, static_cast<char>(d)) + "'"
				: YELLOW "Non-displayable" RESET) << std::endl;
	std::cout << "int:\t" << static_cast<int>(d) << std::endl;
	std::cout << "float:\t" << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double:\t" << d << std::endl;
}
