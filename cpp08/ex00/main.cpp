/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:12 by acardona          #+#    #+#             */
/*   Updated: 2024/02/10 18:38:57 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <queue>

#ifdef WANT_ITERATOR

int main( void )
{
	{ //vector
		std::cout << "=== VECTOR (sequential container) ===" << std::endl;
		std::vector<int> vec;

		vec.push_back(0);
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		for (int i = -2; i < 7; ++i)
		{
			std::cout << "i = " << i << ":" << std::endl << "  "; 
			try
			{
				std::cout << *easyfind<std::vector<int>>(vec, i) << " found" <<  std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	std::cout << std::endl << std::endl; 
	{ //list
		std::cout << "=== LIST (sequential container) ===" << std::endl;
		std::list<int> lst;

		lst.push_back(0);
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		for (int i = -2; i < 7; ++i)
		{
			std::cout << "i = " << i << ":" << std::endl << "  "; 
			try
			{
				std::cout << *easyfind<std::list<int>>(lst, i) << " found" <<  std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	// { 
	// //impossible for container adaptator (can only access the first and/or last element) / associative containers (no real order so no notion of "fist element") :
	// 	std::cout << "=== QUEUE (container adaptor) ===" << std::endl;
	// 	std::queue<int> qu;

	// 	qu.push(0);
	// 	qu.push(1);
	// 	qu.push(2);
	// 	qu.push(3);
	// 	qu.push(4);
	// 	for (int i = -2; i < 7; ++i)
	// 	{
	// 		std::cout << "i = " << i << ":" << std::endl << "  "; 
	// 		try
	// 		{
	// 			std::cout << easyfind<std::queue<int>>(qu, i) << " found" <<  std::endl;
	// 		}
	// 		catch (std::exception &e)
	// 		{
	// 			std::cout << e.what() << std::endl;
	// 		}
	// 	}
	// }
	return (0);
}

#else

int main( void )
{
	{ //vector
		std::cout << "=== VECTOR (sequential container) ===" << std::endl;
		std::vector<int> vec;

		vec.push_back(0);
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		for (int i = -2; i < 7; ++i)
		{
			std::cout << "i = " << i << ":" << std::endl << "  "; 
			if (easyfind<std::vector<int>>(vec, i))
				std::cout << " found" <<  std::endl;
			else
				std::cout << "not found" << std::endl;
		}
	}
	std::cout << std::endl << std::endl; 
	{ //list
		std::cout << "=== LIST (sequential container) ===" << std::endl;
		std::list<int> lst;

		lst.push_back(0);
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		for (int i = -2; i < 7; ++i)
		{
			std::cout << "i = " << i << ":" << std::endl << "  "; 
			if (easyfind<std::list<int>>(lst, i))
				std::cout << " found" <<  std::endl;
			else
				std::cout << "not found" << std::endl;
		}
	}
	// { 
	// //impossible for container adaptator (can only access the first and/or last element) / associative containers (no real order so no notion of "fist element") :
	// 	std::cout << "=== QUEUE (container adaptor) ===" << std::endl;
	// 	std::queue<int> qu;

	// 	qu.push(0);
	// 	qu.push(1);
	// 	qu.push(2);
	// 	qu.push(3);
	// 	qu.push(4);
	// 	for (int i = -2; i < 7; ++i)
	// 	{
	// 		std::cout << "i = " << i << ":" << std::endl << "  "; 
	// 		if (easyfind<std::queue<int>>(qu, i))
	// 			std::cout << " found" <<  std::endl;
	// 		else
	// 			std::cout << "not found" << std::endl;
	// 	}
	// }
	return (0);
}

#endif