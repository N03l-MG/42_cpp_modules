#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cmath>

class ScalarConverter
{
	private:
		// OFC (redundant)
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &src) = delete;
		ScalarConverter &operator=(const ScalarConverter &src) = delete;
		~ScalarConverter() = delete;
		// Converter Types
		typedef enum e_type {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			INVALID
		} type;
	public:
		// Memeber methods
		static void convert(const std::string &literal);
		static type get_type(const std::string &literal);
		static bool isChar(const std::string &literal);
		static bool isInt(const std::string &literal);
		static bool isFloat(const std::string &literal);
		static bool isDouble(const std::string &literal);
		static void printChar(const std::string &literal);
		static void printInt(const std::string &literal);
		static void printFloat(const std::string &literal);
		static void printDouble(const std::string &literal);
};
