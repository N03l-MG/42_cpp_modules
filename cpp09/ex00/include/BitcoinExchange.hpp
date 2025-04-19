#pragma once

#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <algorithm>
#include <fstream>

// Colors
#define RED       "\x1b[31m ✗ "
#define GREEN     "\x1b[32m ✓ "
#define YELLOW    "\x1b[33m ⚠ "
#define BLUE      "\x1b[34m > "
#define MAGENTA   "\x1b[35m ⌫ "
#define CYAN      "\x1b[36m"
// Styles
#define BOLD      "\x1b[1m"
#define UNDERLINE "\x1b[4m\t\t"
// Format reset
#define RESET     "\x1b[0m"

class BitcoinExchange
{
	private:
		std::string databaseFile;
		std::string inputFile;
		std::map<std::string, int> exchangeData;
	public:
		//OCF
		BitcoinExchange();
		BitcoinExchange(std::string database, std::string input);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		// Members
		std::map<std::string, int> ParseDatabase(std::string database);
		void ValidateInput();
		void BTCExchange();

		//Exceptions
		class InvalidArgsException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return RED "Error: " BOLD "Invalid arguments! Please use \"./btc [input file]\"" RESET;
				}
		};

		class BadDatabaseException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return RED "Error: " BOLD "Could not parse database!" RESET;
				}
		};

		class InvalidFileException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return RED "Error: " BOLD "Invalid input file!" RESET;
				}
		};
};
