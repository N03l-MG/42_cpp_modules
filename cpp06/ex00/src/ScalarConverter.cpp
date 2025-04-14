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
	if (literal.empty()) return INVALID;
	else if	(isChar(literal))	return CHAR;
	else if	(isInt(literal))	return INT;
	else if	(isFloat(literal))	return FLOAT;
	else if	(isDouble(literal))	return DOUBLE;
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
	size_t start = 0;

	if (literal[0] == '-' || literal[0] == '+')
		start = 1;
	if (literal.length() == start)
		return false;
	for (size_t i = start; i < literal.length(); i++)
		if (!isdigit(literal[i]))
			return false;	
	try {
		std::stoi(literal);
	} catch (std::out_of_range &e) {
		return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	std::string specials[] = {"nanf", "+inff", "-inff"};

	for (size_t i = 0; i < sizeof(specials) / sizeof(std::string); i++)
		if (literal == specials[i])
			return true;    
	size_t start = 0;
	if (literal[0] == '-' || literal[0] == '+')
		start = 1;
	if (literal.length() <= start + 1)
		return false;
	bool hasDecimal = false;
	bool hasDigit = false;
	for (size_t i = start; i < literal.length() - 1; i++) {
		if (literal[i] == '.') {
			if (hasDecimal) return false;
			hasDecimal = true;
		}
		else if (isdigit(literal[i]))
			hasDigit = true;
		else
			return false;
	}
	if (!hasDigit || literal[literal.length() - 1] != 'f')
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
	std::string specials[] = {"nan", "+inf", "-inf"};

	for (size_t i = 0; i < sizeof(specials) / sizeof(std::string); i++)
		if (literal == specials[i])
			return true;
	size_t start = 0;
	if (literal[0] == '-' || literal[0] == '+')
		start = 1;
	if (literal.length() <= start)
		return false;
	bool hasDecimal = false;
	bool hasDigit = false;
	for (size_t i = start; i < literal.length(); i++) {
		if (literal[i] == '.') {
			if (hasDecimal) return false;
			hasDecimal = true;
		}
		else if (isdigit(literal[i]))
			hasDigit = true;
		else
			return false;
	}
	if (!hasDigit)
		return false;
	try {
		std::stod(literal);
	} catch (std::out_of_range &e) {
		return false;
	}
	return true;
}

void ScalarConverter::printChar(const std::string &literal)
{
	char c = (literal.length() == 3) ? literal[1] : literal[0];

	std::cout << BLUE "Type: char" RESET << std::endl;
	std::cout << BLUE "Conversions:" RESET << std::endl;
	if (!isprint(c))
		std::cout << "char:\t" << YELLOW "Non-displayable" RESET << std::endl;
	else
		std::cout << "char:\t'" << c << "'" << std::endl;
	std::cout << "int:\t" << static_cast<int>(c) << std::endl;
	std::cout << "float:\t" << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::printInt(const std::string &literal)
{
	int i;

	std::cout << BLUE "Type: int" RESET << std::endl;
	try {
		i = std::stoi(literal);
	} catch (std::out_of_range &e) {
		std::cout << RED "Number out of range." RESET << std::endl;
		return;
	} catch (std::exception &e) {
		std::cout << RED "Invalid int." RESET << std::endl;
		return;
	}
	std::cout << BLUE "Conversions:" RESET << std::endl;
	if (i >= 0 && i <= 127)
		std::cout << "char:\t" << (isprint(i) ? "'" + std::string(1, static_cast<char>(i)) + "'"
					: YELLOW "Non-displayable" RESET) << std::endl;
	else
		std::cout << "char:\t" << YELLOW "Impossible" RESET << std::endl;
	std::cout << "int:\t" << i << std::endl;
	if (i > std::numeric_limits<float>::max() || i < std::numeric_limits<float>::lowest())
		std::cout << "float:\t" << YELLOW "Impossible" RESET << std::endl;
	else
		std::cout << "float:\t" << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(i) << std::endl;
}

void ScalarConverter::printFloat(const std::string &literal)
{
    float f;

    std::cout << BLUE "Type: float" RESET << std::endl;
    try {
        f = std::stof(literal);
    } catch (std::exception &e) {
        std::cout << RED "Invalid float." RESET << std::endl;
        return;
    }
    std::cout << BLUE "Conversions:" RESET << std::endl;
    
    if (literal.compare("-inff") == 0 || literal.compare("+inff") == 0 || 
        literal.compare("nanf") == 0 || f > std::numeric_limits<int>::max() || 
        f < std::numeric_limits<int>::min()) {
        std::cout << "char:\t" << YELLOW "impossible" RESET << std::endl;
        std::cout << "int:\t" << YELLOW "impossible" RESET << std::endl;
        std::cout << "float:\t" << f << "f" << std::endl;
        std::cout << "double:\t" << static_cast<double>(f) << std::endl;
        return;
    }
    if (f >= 0 && f <= 127)
        std::cout << "char:\t" << (isprint(static_cast<int>(f)) ? 
            "'" + std::string(1, static_cast<char>(f)) + "'" : 
            YELLOW "Non-displayable" RESET) << std::endl;
    else
        std::cout << "char:\t" << YELLOW "impossible" RESET << std::endl;
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
        std::cout << RED "Invalid double." RESET << std::endl;
        return;
    }
    std::cout << BLUE "Conversions:" RESET << std::endl;
    if (literal.compare("-inf") == 0 || literal.compare("+inf") == 0 || 
        literal.compare("nan") == 0 || d > std::numeric_limits<int>::max() || 
        d < std::numeric_limits<int>::min()) {
        std::cout << "char:\t" << YELLOW "impossible" RESET << std::endl;
        std::cout << "int:\t" << YELLOW "impossible" RESET << std::endl;
        std::cout << "float:\t" << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double:\t" << d << std::endl;
        return;
    }
    if (d >= 0 && d <= 127)
        std::cout << "char:\t" << (isprint(static_cast<int>(d)) ? 
            "'" + std::string(1, static_cast<char>(d)) + "'" : 
            YELLOW "Non-displayable" RESET) << std::endl;
    else
        std::cout << "char:\t" << YELLOW "impossible" RESET << std::endl;
    std::cout << "int:\t" << static_cast<int>(d) << std::endl;
    std::cout << "float:\t" << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double:\t" << d << std::endl;
}
