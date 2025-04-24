#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::cout << CYAN UNDERLINE "Ford-Johnson (Merge-Insertion Sort) Algorithm:" RESET << std::endl;
	try {
		if (argc < 2)
			throw PmergeMe<std::vector<int>>::InvalidArgsException();
		PmergeMe<std::vector<int>> PmergeMyVector(ParseToVector(argv));
		PmergeMe<std::deque<int>> PmergeMyDeque(ParseToDeque(argv));
		std::cout << std::endl;
		PmergeMyVector.SortAndPrint();
		std::cout << std::endl;
		PmergeMyDeque.SortAndPrint();
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
