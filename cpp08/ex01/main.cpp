/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:35:34 by acardona          #+#    #+#             */
/*   Updated: 2024/02/10 19:14:52 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <random>
#include <time.h>

int main( void )
{
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
		std::cout << "longest: " << SpanDerman.longestSpan() << std::endl;

		//////////////////////////////

		std::cout << std::endl << "=== Tests with range ===" << std::endl;

		Span SpanIsh(SpanDerman);
		std::vector<int> rangeRoger = {-1, -200, -12};
		std::vector<int>::iterator it_start = rangeRoger.begin();
		try //more elements in the range than the Span can contain
		{
			std::vector<int>::iterator it_end = rangeRoger.end();
			SpanIsh.addNumber<std::vector<int>>(it_start, it_end);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		rangeRoger.pop_back();
		try //range iterator not ordered properly (end before start) 
		{
			std::vector<int>::iterator it_end = rangeRoger.end();
			SpanIsh.addNumber<std::vector<int>>(it_end, it_start);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try //successful addition of the range elements to the list 
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
		std::cout << "longest: " << SpanIsh.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << "=== Tests with a lot of numbers ===" << std::endl;


		unsigned int	spanSize = 5000;
		Span spanAcotta(spanSize + 2);

		srand(time(NULL));
		for (unsigned int i = 0; i < spanSize; ++i)
		{
			spanAcotta.addNumber(rand() % 10000);
		}
		// spanAcotta.addNumber(-10000);
		// spanAcotta.addNumber(20000);
		std::cout << "The span is : " << spanAcotta << std::endl;
		std::cout << "shortest: " << spanAcotta.shortestSpan() << std::endl;
		std::cout << "longest: " << spanAcotta.longestSpan() << std::endl;
	}
	return (0);
}