/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:26 by acardona          #+#    #+#             */
/*   Updated: 2024/01/12 20:51:04 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>


void opposit(int &n)
{
	n *= -1;
}

template<typename T> void function_display(T & n)
{
	std::cout << n << std::endl;
}

int main( void )
{
	int 	*list_int;
	unsigned int size = 4;

	list_int = new int[size];
	for (unsigned int i = 0; i < size; ++i)
		list_int[i] = i;
	iter<int>(list_int, size, opposit);
	iter<int>(list_int, size, function_display<int>);
	delete[] list_int;
}
