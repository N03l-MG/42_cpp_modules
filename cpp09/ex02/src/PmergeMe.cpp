#include "PmergeMe.hpp"

// Orthodox Canonical Form
// (default constructor, param constructor, copy constructor, assignment operator override, destructor)
template<typename Container>
PmergeMe<Container>::PmergeMe()
{
	jacobsthalSeries = GenerateJacobsthal();
	std::cout << BOLD GREEN "Default PmergeMe instance constructed." RESET << std::endl;
}

template<typename Container>
PmergeMe<Container>::PmergeMe(Container const &input) : unsorted(input)
{
	jacobsthalSeries = GenerateJacobsthal();
	std::cout << BOLD GREEN "PmergeMe instance constructed." RESET << std::endl;
}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &src) : unsorted(src.unsorted), sorted(src.sorted),
					jacobsthalSeries(src.jacobsthalSeries)
{
	std::cout << BOLD GREEN "PmergeMe instance copy-constructed." RESET << std::endl;
}

template<typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &src)
{
	if (this != &src) {
		this->unsorted = src.unsorted;
		this->sorted = src.sorted;
		this->jacobsthalSeries = src.jacobsthalSeries;
	}
	return *this;
}

template<typename Container>
PmergeMe<Container>::~PmergeMe()
{
	std::cout << BOLD MAGENTA "PmergeMe instance destroyed." RESET << std::endl;
}

// Member Functions
template<typename Container>
std::vector<int> PmergeMe<Container>::GenerateJacobsthal()
{
	std::vector<int> sequence;

	sequence.push_back(0);
	sequence.push_back(1);
	for (size_t i = 2; i < 30; ++i)
	{
		int next = sequence.back() + 2 * *std::next(sequence.rbegin());
		sequence.push_back(next);
	}
	return sequence;
}

template<typename Container>
Container PmergeMe<Container>::Sort()
{
	size_t size = unsorted.size();
	if (size <= 1) return unsorted;

	// Step 1: Create pairs and sort them
	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i < size - 1; i += 2)
	{
		int first = unsorted[i];
		int second = unsorted[i + 1];
		if (first > second)
			pairs.push_back(std::make_pair(first, second));
		else
			pairs.push_back(std::make_pair(second, first));
	}
	// Handle remainder if exists
	int extraElement = -1;
	if (size % 2)
		extraElement = unsorted[size - 1];

	// Step 2: Sort pairs by their larger elements
	std::sort(pairs.begin(), pairs.end());

	// Step 3: Create main chain with larger elements
	Container result;
	for (const auto& pair : pairs)
		result.push_back(pair.first);

	// Step 4: Insert smaller elements using binary search
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		int element = pairs[i].second;
		auto insertPos = std::lower_bound(result.begin(), result.end(), element);
		result.insert(insertPos, element);
	}
	// Insert remainder if it exists
	if (extraElement != -1) {
		auto insertPos = std::lower_bound(result.begin(), result.end(), extraElement);
		result.insert(insertPos, extraElement);
	}

	return result;
}

template<typename Container>
void PmergeMe<Container>::CheckResult()
{
	// Check 1: Size should be the same
	if (sorted.size() != unsorted.size()) {
		std::cout << RED "Failure: Size mismatch!" RESET << std::endl;
		return;
	}
	// Check 2: Result should be sorted
	if (!std::is_sorted(sorted.begin(), sorted.end())) {
		std::cout << RED "Failure: Result is not sorted!" RESET << std::endl;
		return;
	}
	std::cout << BLUE "Success: All checks passed!" RESET << std::endl;
}

template<typename Container>
void PmergeMe<Container>::SortAndPrint()
{
	// Print original sequence (TESTING ONLY)
	// std::cout << BLUE "Unsorted: " RESET;
	// for (const auto& num : unsorted)
	// 	std::cout << num << " ";
	// std::cout << std::endl;

	// Time the sorting
	clock_t start = clock();
	sorted = Sort();
	clock_t end = clock();
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	// Print sorted sequence
	std::cout << BLUE "Sorted:" RESET << std::endl;
	for (const auto &num : sorted)
		std::cout << num << " ";
	std::cout << std::endl;
	std::cout << BLUE "Time to process a range of " BOLD << unsorted.size() 
			<< " elements with std::" << (std::is_same<Container, std::vector<int>>::value ? "vector" : "deque")
			<< ": " << RESET BOLD << time << " μs" RESET << std::endl;
	CheckResult();
}

// Exception Class Method Overrides
template<typename Container>
const char *PmergeMe<Container>::InvalidArgsException::what() const throw()
{
	return RED "Error: " BOLD "Invalid arguments! Please use \"./PmergeMe [unsorted positive integers]\"" RESET;
}

template<typename Container>
const char *PmergeMe<Container>::InvalidInputException::what() const throw()
{
	return RED "Error: " BOLD "Invalid character or value in input!" RESET;
}
