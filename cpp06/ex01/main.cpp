#include "Serializer.hpp"
#include "TextFormat.hpp"

int	main()
{
	Data ogData;
	Data *resultData;


	ogData.ival = 42;
	ogData.fval = 42.42f;
	ogData.str = "Hello, world!";
	ogData.c = '*';

	resultData = Serializer::deserialize(Serializer::serialize(&ogData));

	std::cout << BLUE "Original data:\t" << &ogData << RESET << std::endl;
	std::cout << BLUE "New data:\t" << resultData << RESET << std::endl;
	return 0;
}
