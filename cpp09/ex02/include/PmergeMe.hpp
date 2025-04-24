#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <limits.h>
#include <algorithm>
#include <iomanip>
#include <ctime>

// Colors
#define RED       "\x1b[31m ✗ " // Error or exception
#define GREEN     "\x1b[32m 🛠 " // Construction
#define YELLOW    "\x1b[33m ⚠ " // Warning
#define BLUE      "\x1b[34m 🛈 " // Info or log
#define MAGENTA   "\x1b[35m 🗑 " // Destruction
#define CYAN      "\x1b[36m"
// Styles
#define BOLD      "\x1b[1m"
#define UNDERLINE "\x1b[4m\t\t"
// Format reset
#define RESET     "\x1b[0m"

template<typename Container>
class PmergeMe
{
	static_assert(std::is_same<Container, std::vector<int>>::value ||
		std::is_same<Container, std::deque<int>>::value,
		"PmergeMe only works with std::vector<int> or std::deque<int>");

	private:
		Container unsorted;
		Container sorted;
	public:
		//OCF
		PmergeMe();
		PmergeMe(Container const &input);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

	// Member Methods
	private:
		constexpr size_t Jacobsthal(size_t n) noexcept;
		Container MergeInsertionSort();
		void CheckResult();
	public:
		void SortAndPrint();

		//Exceptions
		class InvalidArgsException : public std::exception
		{
			public: const char *what() const throw();
		};

		class InvalidInputException : public std::exception
		{
			public: const char* what() const throw();
		};
};

// Explicit instantiancion for supported types
template class PmergeMe<std::vector<int>>;
template class PmergeMe<std::deque<int>>;

// Orthodox Canonical Form
// (default constructor, param constructor, copy constructor, assignment operator override, destructor)
template<typename Container>
PmergeMe<Container>::PmergeMe()
{
	std::cout << BOLD GREEN "Default PmergeMe instance constructed." RESET << std::endl;
}

template<typename Container>
PmergeMe<Container>::PmergeMe(Container const &input) : unsorted(input)
{
	std::cout << BOLD GREEN "PmergeMe instance constructed." RESET << std::endl;
}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &src) : unsorted(src.unsorted), sorted(src.sorted)
{
	std::cout << BOLD GREEN "PmergeMe instance copy-constructed." RESET << std::endl;
}

template<typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &src)
{
	if (this != &src) {
		this->unsorted = src.unsorted;
		this->sorted = src.sorted;
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
constexpr size_t PmergeMe<Container>::Jacobsthal(size_t n) noexcept
{
	// J(0) = 0, J(1) = 1, J(n) = J(n‑1) + 2*J(n‑2)
	size_t a = 0, b = 1;
	for (std::size_t i = 0; i < n; ++i) {
		std::size_t next = b + 2 * a;
		a = b;
		b = next;
	}
	return a;
}

template<typename Container>
Container PmergeMe<Container>::MergeInsertionSort()
{
	if (unsorted.size() <= 1) return unsorted; // Quick single element/empty check.
	Container temp = unsorted;
	std::vector<std::pair<int,int>> pairs;

	///ONE: Compare pairs of elements in two halves of the container, keep odd element if present.
	for (std::size_t i = 0; i + 1 < temp.size(); i += 2)
	{
		if (temp[i] > temp[i+1]) std::swap(temp[i], temp[i+1]);
		pairs.emplace_back(temp[i], temp[i+1]);
	}
	int extra = (temp.size() & 1) ? temp.back() : -1;

	///TWO: Sort each pair by by the bigger element and split into Maxima and Minima
	Container minima, maxima;
	std::sort(pairs.begin(), pairs.end(), [](auto const& a, auto const& b) {
		return a.second < b.second;
	});
	for (auto const& p : pairs)
	{
		minima.push_back(p.first);
		maxima.push_back(p.second);
	}

	///THREE: Insert minima into maxima using binary search in the order of Jacobsthal indices.
	Container result;
	if (!pairs.empty()) {
		result.push_back(minima[0]);
		result.push_back(maxima[0]);
	}
	for (std::size_t k = 1; k < minima.size(); ++k)
	{
		std::size_t window = Jacobsthal(static_cast<int>(k + 2)) - 1;
		auto window_end = result.begin() + std::min(window, result.size());
		auto it_small = std::upper_bound(result.begin(), window_end, minima[k]);
		it_small = result.insert(it_small, minima[k]);
		window_end = result.begin() + std::min(window + 1, result.size());
		auto it_big = std::upper_bound(result.begin(), window_end, maxima[k]);
		result.insert(it_big, maxima[k]);
	}

	///FOUR: Re-insert extra element if it exists.
	if (extra != -1) {
		auto it = std::upper_bound(result.begin(), result.end(), extra);
		result.insert(it, extra);
	}

	return result;
}

template<typename Container>
void PmergeMe<Container>::CheckResult()
{
	// Check 1: Size should be the same (no numbers got removed or added)
	if (sorted.size() != unsorted.size()) {
		std::cout << RED "Failure: Size mismatch!" RESET << std::endl;
		return;
	}
	// Check 2: Result should be sorted (ensure it actually works lol)
	if (!std::is_sorted(sorted.begin(), sorted.end())) {
		std::cout << RED "Failure: Result is not sorted!" RESET << std::endl;
		return;
	}
	std::cout << BLUE "Success: All checks passed!" RESET << std::endl;
}

template<typename Container>
void PmergeMe<Container>::SortAndPrint()
{
	if (unsorted.size() == 0) {
		std::cout << YELLOW "Wanring: " BOLD "Empty container." RESET << std::endl;
		return;
	}
	// Time the sorting
	clock_t start = clock();
	sorted = MergeInsertionSort();
	clock_t end = clock();
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	// Print sorted sequence
	std::cout << BLUE "Sorted " << (std::is_same<Container, std::vector<int>>::value ? "Vector" : "Deque")
			<< ": " RESET << std::endl;
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

// Independent function protorypes
std::vector<int> ParseToVector(char **argv);
std::deque<int> ParseToDeque(char **argv);
