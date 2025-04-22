#pragma once

#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <algorithm>
#include <fstream>
#include <regex>

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

class BitcoinExchange
{
	private:
		std::string databaseFile;
		std::string inputFile;
		std::map<std::string, float> exchangeData;
	public:
		//OCF
		BitcoinExchange();
		BitcoinExchange(std::string database, std::string input);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

	// Memeber Methods
	private:
		std::map<std::string, float> ParseDatabase();
		bool ValidLine(std::string line);
	public:
		void BTCExchange();

		// Exceptions
		class InvalidArgsException : public std::exception
		{
			public: const char *what() const throw();
		};

		class BadDatabaseException : public std::exception
		{
			public: const char *what() const throw();
		};

		class InvalidFileException : public std::exception
		{
			public: const char *what() const throw();
		};
};
