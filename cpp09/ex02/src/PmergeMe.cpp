#include "PmergeMe.hpp"

// Independent Parsing Functions
std::vector<int> ParseToVector(char **argv)
{
	std::vector<int> numbers;
	int i = 1;
	
	while (argv[i])
	{
		char *endptr;
		long num = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0')
			throw PmergeMe<std::vector<int>>::InvalidInputException();
		if (num < 0 || num > INT_MAX)
			throw PmergeMe<std::vector<int>>::InvalidInputException();
		numbers.push_back(static_cast<int>(num));
		i++;
	}
	if (numbers.empty())
		throw PmergeMe<std::vector<int>>::InvalidArgsException();

	return numbers;
}

std::deque<int> ParseToDeque(char **argv)
{
	std::deque<int> numbers;
	int i = 1;
	
	while (argv[i])
	{
		char *endptr;
		long num = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0')
			throw PmergeMe<std::deque<int>>::InvalidInputException();
		if (num < 0 || num > INT_MAX)
			throw PmergeMe<std::deque<int>>::InvalidInputException();
		numbers.push_back(static_cast<int>(num));
		i++;
	}
	if (numbers.empty())
		throw PmergeMe<std::deque<int>>::InvalidArgsException();

	return numbers;
}
