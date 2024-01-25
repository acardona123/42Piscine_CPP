/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:36:08 by acardona          #+#    #+#             */
/*   Updated: 2024/01/25 18:24:42 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <iostream>

class Span
{
	public:
		Span( unsigned int N);
		Span( Span & model);
		Span &operator=(Span &model);
		~Span( void );

		//getters
		unsigned int	getSize( void ) const;
		unsigned int	getSizeMax( void ) const;
		int operator[]( unsigned int i) throw (std::out_of_range);
		int operator[]( unsigned int i) const throw (std::out_of_range);

		//setters
		class exceptionSpanFull : public std::exception
		{
			public:
				virtual const char *what( void ) const throw() { return ("Span: exception: the span is full"); }
		};
		class exceptionWrongIterator : public std::exception
		{
			public:
				virtual const char *what( void ) const throw() { return ("Span: exception: given iterators are not ordered properly"); }
		};
		class exceptionRageTooWide : public std::exception
		{
			public:
				virtual const char *what( void ) const throw() { return ("Span: exception: the given iterators describe a range bigger than the Span remaining capacity"); }
		};
		void addNumber(int n) throw(exceptionSpanFull);
		template<typename T>
			void addNumber(typename T::iterator &it_start, typename T::iterator &it_end) throw(exceptionSpanFull, exceptionWrongIterator, exceptionRageTooWide);

		class exceptionSpanTooShort : public std::exception
		{
			public:
				virtual const char *what( void ) const throw() { return ("Span: exception: the span is empty or only contains one element"); }
		};
		unsigned int shortestSpan( void ) throw(exceptionSpanTooShort);
		unsigned int longestSpan( void ) throw(exceptionSpanTooShort);

	private:
		Span( void );
		unsigned int		_sizeMax;
		unsigned int		_size;
		std::vector<int>	_values;


};

template<typename T>
	void Span::addNumber(typename T::iterator &it_start, typename T::iterator &it_end) throw(exceptionSpanFull, exceptionWrongIterator, exceptionRageTooWide)
{
	if (_size == _sizeMax)
		throw (exceptionSpanFull());
	if (it_start > it_end)
		throw (exceptionWrongIterator());
	if (std::distance(it_start, it_end) > _sizeMax - _size)
		throw (exceptionRageTooWide());
	while (it_start != it_end)
	{
		++_size;
		_values.push_back(*it_start);
		++it_start;
	}
}

std::ostream &operator<<(std::ostream &o, Span const & rhs);

#endif