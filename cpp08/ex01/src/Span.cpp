#include "Span.hpp"

// Orthodox Canonical Form (default constructor, param constructor, copy constructor, destructor)
Span::Span() : numVec(), maxSize(0)
{
	std::cout << BOLD GREEN "Default Span instance constructed." RESET << std::endl;
}

Span::Span(unsigned int N) : numVec(), maxSize(N)
{
	std::cout << BOLD GREEN "Span instance constructed." RESET << std::endl;
}

Span::Span(const Span &src) : numVec(src.numVec), maxSize(src.maxSize)
{
	std::cout << BOLD GREEN "Span instance copy-constructed." RESET << std::endl;
}

Span &Span::operator=(const Span &src)
{
	if (this != &src) {
		this->maxSize = src.maxSize;
		this->numVec = src.numVec;
	}
	return *this;
}

Span::~Span()
{
	std::cout << BOLD MAGENTA "Span instance destroyed." RESET << std::endl;
}

// Member Functions
void Span::addNumber(int num)
{
	if (numVec.size() >= maxSize)
		throw VectorFullException();
	numVec.push_back(num);
}

size_t Span::shortestSpan()
{
	if (numVec.size() < 2)
		throw VectorTooSmallException();
	std::vector<int> sorted = numVec;
	std::sort(sorted.begin(), sorted.end());
	size_t minSpan = std::numeric_limits<size_t>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		size_t span = std::abs(static_cast<long>(sorted[i]) - sorted[i-1]);
		minSpan = std::min(minSpan, span);
	}
	return minSpan;
}

size_t Span::longestSpan()
{
	if (numVec.size() < 2)
		throw VectorTooSmallException();
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> minmax = 
		std::minmax_element(numVec.begin(), numVec.end());
	return static_cast<size_t>(std::abs(static_cast<long>(*minmax.second) - *minmax.first));
}

void Span::printVector()
{
	std::cout << BLUE "Vector Content:" RESET << std::endl;
	for (size_t i = 0; i < numVec.size(); i++)
		std::cout << numVec[i] << " ";
	std::cout << std::endl;
}
