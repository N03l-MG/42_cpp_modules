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

bool BitcoinExchange::ValidLine(std::string line)
{
	std::regex dateFormat("\\d{4}-(?:0[1-9]|1[0-2])-(?:0[1-9]|[12]\\d|3[01])");
	std::regex lineFormat("^([0-9]{4}-[0-9]{2}-[0-9]{2}) \\| ([0-9]*\\.?[0-9]+)$");
	std::smatch matches;

	if (!std::regex_match(line, matches, lineFormat)) {
		std::cout << YELLOW "Error:" BOLD " bad input => " << line << RESET << std::endl;
		return false;
	}
	std::string date = matches[1];
	std::string value = matches[2];
	if (!std::regex_match(date, dateFormat)) {
		std::cout << YELLOW "Error:" BOLD " bad date format => " << date << RESET << std::endl;
		return false;
	}
	try {
		float val = std::stof(value);
		if (val < 0) {
			std::cout << YELLOW "Error:" BOLD " not a positive number." RESET << std::endl;
			return false;
		}
		if (val > 1000) {
			std::cout << YELLOW "Error:" BOLD " too large a number." RESET << std::endl;
			return false;
		}
	} catch (std::exception &e) {
		std::cout << YELLOW "Error:" BOLD " invalid value => " << value << RESET << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::BTCExchange()
{
	if (inputFile.empty())
		throw InvalidFileException();
	std::ifstream inFile(inputFile);
	if (!inFile)
		throw InvalidFileException();

	std::string line;
	std::getline(inFile, line); // Skip title line
	while (std::getline(inFile, line))
	{
		if (!ValidLine(line))
			continue;
		std::cout << line << std::endl;
	}
}
