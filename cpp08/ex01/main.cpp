/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:35:34 by acardona          #+#    #+#             */
/*   Updated: 2024/02/12 19:52:33 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static void			_testFromSubject( void );
static void			_testRange( void );
static void			_testBigSize( void );
std::vector<int>	GenerateRandomVector(unsigned int Length);
static void			_displayVectorInt( std::vector<int> & vec);

int main( void )
{
	_testFromSubject();
	_testBigSize();
	_testRange();
	return (0);
}



static void	_testFromSubject( void )
{
	std::cout << std::endl << "=== Test from the subject ===" << std::endl;

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
}



static void	_testBigSize( void )
{
	std::cout << std::endl << "=== Test with a lot of numbers ===" << std::endl;


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




/*
==== Test range ====
*/

static void	_testRangeTooLong( void );
static void	_testRangeIteratorUnordered( void );
static void	_testRangeFunctionning( void );


static void	_testRange( void )
{
	std::cout << std::endl << "=== Tests with range ===" << std::endl;

	_testRangeTooLong();
	_testRangeIteratorUnordered();
	_testRangeFunctionning();
}

static void	_testRangeTooLong( void )
{
	std::cout << "- More elements in the range than the Span can contain" << std::endl;
	
	Span SpanIsh(2);
	std::vector<int> range(SpanIsh.getSizeMax() + 1);

	try
	{
		std::vector<int>::iterator it_start = range.begin();
		std::vector<int>::iterator it_end = range.end();
		SpanIsh.addNumber<std::vector<int> >(it_start, it_end);
		std::cout << " -> Success:" << SpanIsh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << " -> Failure:" << std::endl << "\t";
		std::cout << e.what() << std::endl;
	}
}

static void	_testRangeIteratorUnordered( void )
{
	std::cout << "- Range iterator not ordered properly (end before start)" << std::endl;

	Span spanAcotta(2);
	std::vector<int> range = GenerateRandomVector(2);
	try
	{
		std::vector<int>::iterator it_end = range.end();
		std::vector<int>::iterator it_start = range.begin();
		spanAcotta.addNumber<std::vector<int> >(it_end, it_start);
		std::cout << " -> Success:" << spanAcotta << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << " -> Failure:" << std::endl << "\t";
		std::cout << e.what() << std::endl;
	}
}

static void	_testRangeFunctionning( void )
{
	std::cout << "- Range functioning" << std::endl;

	Span spanAconda(10);
	spanAconda.addNumber(0);

	std::vector<int> rangeLinaJolie = GenerateRandomVector(5);
	std::cout << "  Range: ";
	_displayVectorInt(rangeLinaJolie);
	try
	{
		std::vector<int>::iterator it_end = rangeLinaJolie.end();
		std::vector<int>::iterator it_start = rangeLinaJolie.begin();
		spanAconda.addNumber<std::vector<int> >(it_start, it_end);
		spanAconda.addNumber(-1);
		std::cout << " -> Success:" << std::endl << spanAconda << std::endl;
		std::cout << "shortest: " << spanAconda.shortestSpan() << std::endl;
		std::cout << "longest: " << spanAconda.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << " -> Failure:" << std::endl << "\t";
		std::cout << e.what() << std::endl;
	}
}

std::vector<int>	GenerateRandomVector(unsigned int Length)
{
	std::vector<int> randomizedVector;

	for (unsigned int i = 0; i < Length; ++i)
	{
		randomizedVector.push_back(rand());
	}
	return (randomizedVector);
}

static void	_displayVectorInt( std::vector<int> & vec)
{
	std::cout << "{";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end() - 1; it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << *(--vec.end()) << "}" << std::endl;
}