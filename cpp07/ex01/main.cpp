/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:11:13 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/14 15:28:14 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
