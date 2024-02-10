/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:12:50 by acardona          #+#    #+#             */
/*   Updated: 2024/02/10 18:29:21 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStak.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		std::cout << "=== Subject test: Default (deque) ===" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it (mstack.begin());
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::cout << "=== Subject tests: List ===" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::cout << "=== Very long one: Deque ===" << std::endl;
		int upperBound (3000);
		MutantStack<int> Huge;
		for (int i = 0; i < upperBound; ++i)
		{
			Huge.push(i);
		}
		Huge.push(25);
		for (MutantStack<int>::iterator it = Huge.begin(); it < Huge.end(); ++it)
		{
			if (*it != 0 && *it != *std::prev(it) + 1)
				std::cout << "\e[1;31m" << *it << "\e[0m; ";
			else
				std::cout << *it << "; ";
		}
		std::cout << std::endl;
	}
	return 0;
}