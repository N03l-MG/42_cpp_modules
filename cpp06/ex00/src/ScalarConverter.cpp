/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:34:06 by kixik             #+#    #+#             */
/*   Updated: 2025/04/09 17:35:10 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "TextFormat.hpp"

// Orthodox Canonical Form
ScalarConverter::ScalarConverter()
{
	std::cout << BOLD GREEN "Scalar Converter instance constructed." RESET << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	std::cout << BOLD GREEN "Scalar Converter instance copy-constructed." RESET << std::endl;
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << BOLD MAGENTA "Scalar Converter instance destroyed." RESET << std::endl;
}
