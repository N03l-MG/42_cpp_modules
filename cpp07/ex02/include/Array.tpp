/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:36:04 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/14 16:14:16 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Array.hpp"

// Construction and Destruction
template <class T>
Array<T>::Array() : array(NULL), length(0)
{
	std::cout << BOLD GREEN "Default Array Constructed." RESET << std::endl;
}

template <class T>
Array<T>::Array(size_t n) : array(new T[n]), length(n)
{
	std::cout << BOLD GREEN "Array of size " << length << " constructed." RESET << std::endl;
}

template <class T>
Array<T>::Array(Array &src) : array(NULL), length(0)
{
	std::cout << BOLD GREEN "Copy Array Constructed." RESET << std::endl;
	*this = src;
}

template <class T>
Array<T>::~Array()
{
	if (array)
		delete[] array;
	std::cout << BOLD MAGENTA "Array destroyed." RESET << std::endl;
}

// Operator Overloads
template <class T>
Array<T> &Array<T>::operator=(Array &src)
{
	if (this != &src) {
		if (array)
			delete[] array;
		length = src.length;
		array = new T[length];
		for (size_t i = 0; i < length; i++)
			array[i] = src.array[i];
	}
	return *this;
}

template <class T>
T &Array<T>::operator[](size_t index)
{
	if (index >= length)
		throw OutOfBoundsException();
	return array[index];
}

// Methods
template <class T>
size_t Array<T>::size() const
{
	return length;
}

// Exception Class Method Override
template <class T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return RED "Index out of bounds!" RESET;
}
