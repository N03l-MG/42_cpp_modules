#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::cout << CYAN UNDERLINE "Bitcoin Exchange:" RESET << std::endl;
	try {
		if (argc != 2)
			throw BitcoinExchange::InvalidArgsException();
		BitcoinExchange btc("data.csv", argv[1]);
		std::cout << std::endl;
		btc.BTCExchange();
		std::cout << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
