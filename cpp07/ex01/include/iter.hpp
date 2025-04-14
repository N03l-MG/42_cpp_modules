/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:01:32 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/14 15:27:44 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

template <typename T>
void iter(T *array, size_t length, void (*func)(T&))
{
	if (!array || !func) return;
	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}

template <typename T>
void iter(T *array, size_t length, void (*func)(const T&))
{
	if (!array || !func) return;
	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}

template <typename T>
void print(const T &elem)
{
	std::cout << elem << std::endl;
}
