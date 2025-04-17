#include <iostream>
#include <string>
#include "iter.hpp"

int main()
{
	const int intArray[] = {1, 2, 3, 4, 5};
	std::string strArray[] = {"Hello", "World", "!"};

	std::cout << "Integer array:" << std::endl;
	iter(intArray, 5, print<int>);

	std::cout << "String array:" << std::endl;
	iter(strArray, 3, print);

	return 0;
}
