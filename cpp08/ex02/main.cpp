#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << CYAN UNDERLINE "Basic Test:" RESET << std::endl;
	{
		MutantStack<int> mstack;
		std::cout << std::endl;

		mstack.push(5);
		mstack.push(17);
		std::cout << BLUE "Top of Mutuant Stack:" RESET << std::endl;
		std::cout << mstack.top() << std::endl;

		mstack.pop();
		std::cout << BLUE "Size of Mutuant Stack:" RESET << std::endl;
		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << BLUE "Content of Mutuant Stack:" RESET << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
		std::cout << BLUE "Normal Stack Copy Size:" RESET << std::endl;
		std::cout << s.size() << std::endl;
	}
	std::cout << std::endl;
	std::cout << CYAN UNDERLINE "Basic Test replacing with List:" RESET << std::endl;
	{
		std::list<int> mstack;
		std::cout << std::endl;

		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << BLUE "Top of List:" RESET << std::endl;
		std::cout << mstack.back() << std::endl;

		mstack.pop_back();
		std::cout << BLUE "Size of List:" RESET << std::endl;
		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << BLUE "Content of List:" RESET << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;
	std::cout << CYAN UNDERLINE "Indexing Operator Override Tests:" RESET << std::endl;
	{
		MutantStack<int> mutant;
		std::cout << std::endl;

		for (size_t i = 0; i < 10; i++)
			mutant.push(i);
		std::cout << BLUE "Size of Mutuant Stack:" RESET << std::endl;
		std::cout << mutant.size() << std::endl;
		std::cout << std::endl;

		std::cout << BLUE "Content of Mutuant Stack:" RESET << std::endl;
		for (size_t i = 0; i < mutant.size(); i++)
			std::cout << mutant[i] << std::endl;
	}

	return 0;
}
