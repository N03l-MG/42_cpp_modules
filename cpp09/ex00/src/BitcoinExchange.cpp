#include "BitcoinExchange.hpp"

// Orthodox Canonical Form (default constructor, copy constructor, assignment operator override, destructor)
BitcoinExchange::BitcoinExchange() : databaseFile("data.csv"), inputFile("input.txt")
{
	exchangeData = ParseDatabase(databaseFile);
	std::cout << BOLD GREEN "Default BitcoinExchange instance constructed." RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string database, std::string input) : databaseFile(database), inputFile(input)
{
	exchangeData = ParseDatabase(databaseFile);
	std::cout << BOLD GREEN "BitcoinExchange instance constructed." RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : databaseFile(src.databaseFile), inputFile(src.inputFile)
{
	*this = src;
	std::cout << BOLD GREEN "BitcoinExchange instance copy-constructed." RESET << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src) {
		this->databaseFile = src.databaseFile;
		this->inputFile = src.inputFile;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << BOLD MAGENTA "BitcoinExchange instance destroyed." RESET << std::endl;
}

// Memeber Functions
std::map<std::string, int> BitcoinExchange::ParseDatabase(std::string database)
{
	std::ifstream db(database);
	if (!db)
		throw BadDatabaseException();

	std::string line;
	std::map<std::string, int> dbMap;

	std::getline(db, line); // Skip title line
	while (std::getline(db, line))
	{
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;
		std::string date = line.substr(0, commaPos);
		std::string value = line.substr(commaPos + 1);
		try {
			float rate = std::stof(value);
			dbMap[date] = rate;
		} catch (std::exception &e) {
			std::cout << YELLOW "Warning:" BOLD " Invalid value in database: " RESET
			<< value << std::endl;
			continue;
		}
	}
	return dbMap;
}

void BitcoinExchange::ValidateInput()
{
	if (inputFile.empty())
		throw InvalidFileException();
	
}

void BitcoinExchange::BTCExchange()
{
	ValidateInput();
	
}
