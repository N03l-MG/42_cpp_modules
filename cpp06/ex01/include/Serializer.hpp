#pragma once

#include <iostream>
#include <string>
#include <cstdint>

struct Data
{
	int ival;
	float fval;
	char c;
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
