/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:59:20 by kixik             #+#    #+#             */
/*   Updated: 2025/04/09 17:33:26 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cmath>

class ScalarConverter
{
	public:
		// OFC
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();
		// Memeber methods
		static void convert(const std::string &literal);
		static void printChar(char c);
		static void printInt(int i);
		static void printFloat(float f);
		static void printDouble(double d);
		static void printCharImpossible();
		static void printIntImpossible();
		static void printFloatImpossible();
		static void printDoubleImpossible();
};
