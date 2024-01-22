/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:35:34 by acardona          #+#    #+#             */
/*   Updated: 2024/01/21 00:54:18 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main( void )
{
	unsigned int	SpanMaxSize = 7;
	Span SpanDerman(SpanMaxSize);

	SpanDerman.addNumber(120);
	SpanDerman.addNumber(42);
	SpanDerman.addNumber(0);
	SpanDerman.addNumber(12);
	try
	{
		SpanDerman.addNumber(0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "The span is : " << SpanDerman << std::endl;
	std::cout << "shortest: " << SpanDerman.shortestSpan() << std::endl;
	std::cout << "longuest: " << SpanDerman.longestSpan() << std::endl;


	std::cout << std::endl << "=== Tests with range ===" << std::endl;
	Span SpanIsh(SpanDerman);
	std::vector<int> rangeRoger = {-1, -200, -12};
	try
	{
		std::vector<int>::iterator it_start = rangeRoger.begin();
		std::vector<int>::iterator it_end = rangeRoger.end();
		SpanIsh.addNumber<std::vector<int>>(it_start, it_end);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	rangeRoger.pop_back();
	try
	{
		std::vector<int>::iterator it_start = rangeRoger.begin();
		std::vector<int>::iterator it_end = rangeRoger.end();
		SpanIsh.addNumber<std::vector<int>>(it_end, it_start);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::iterator it_start = rangeRoger.begin();
		std::vector<int>::iterator it_end = rangeRoger.end();
		SpanIsh.addNumber<std::vector<int>>(it_start, it_end);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "The span is : " << SpanIsh << std::endl;
	
	std::cout << "shortest: " << SpanIsh.shortestSpan() << std::endl;
	std::cout << "longuest: " << SpanIsh.longestSpan() << std::endl;

	return (0);
}