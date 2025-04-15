#pragma once

#include <iostream>
#include <string>
#include <cstdint>

struct Data
{
	int integer;
	float float_val;
	char chr;
	std::string str;
};

class Serializer
{
	private:
		Serializer() = delete;
		Serializer(const Serializer &other) = delete;
		Serializer	&operator=(const Serializer &other) = delete;
		~Serializer() = delete;
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};
