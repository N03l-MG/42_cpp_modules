#include "Serializer.hpp"
#include "TextFormat.hpp"

int	main()
{
	Data og_data;
	Data *result_data;


	og_data.integer = 42;
	og_data.float_val = 42.42f;
	og_data.str = "This is the test string!";
	og_data.chr = 'c';

	result_data = Serializer::deserialize(Serializer::serialize(&og_data));

	std::cout << BLUE "OG data:\t" << &og_data << RESET << std::endl;
	std::cout << BLUE "New data:\t" << result_data << RESET << std::endl;
	return 0;
}
