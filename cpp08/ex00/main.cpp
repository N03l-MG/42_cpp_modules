#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <array>

int main()
{
	try {
		std::cout << CYAN UNDERLINE "Container Class tests:" RESET << std::endl;
	
		std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::cout << BLUE "Vector: ";
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << "\nFound: " << *easyfind(vec, 8) << RESET << std::endl;
		std::cout << std::endl;
	
		std::list<int> lst = {0, 1, 2, 3, -1};
		std::cout << BLUE "List: ";
		std::list<int>::iterator it = lst.begin();
		for (size_t i = 0; i < lst.size(); i++)
		{
			std::cout << *it << " ";
			std::advance(it, 1);
		}
		std::cout << "\nFound: " << *easyfind(lst, -1) << RESET << std::endl;
		std::cout << std::endl;

		std::cout << BLUE "Deque: ";
		std::deque<int> dque = {100, -10, 0, 235, -49, -10};
		for (size_t i = 0; i < dque.size(); i++)
			std::cout << dque[i] << " ";
		std::cout << "\nFound: " << *easyfind(dque, -10) << RESET << std::endl;
		std::cout << std::endl;

		std::cout << BLUE "Array-list: ";
		std::array<int, 3> arr = {64917, -7197, 10000};
		for (size_t i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << "\nFound: " << *easyfind(arr, 10000) << RESET << std::endl;
		std::cout << std::endl;

		std::cout << CYAN UNDERLINE "Not Found Exception test:" RESET << std::endl;
		std::cout << BLUE "Vector (again): ";
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << RESET << std::endl;
		easyfind(vec, 42);
	} catch (const NotFoundException &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return 0;
}
