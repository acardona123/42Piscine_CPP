/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:37:03 by acardona          #+#    #+#             */
/*   Updated: 2024/01/25 18:24:46 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void )
{	
}

Span::Span (unsigned int N) : _sizeMax(N), _size(0)
{
}

Span::Span (Span & model) : _sizeMax(model.getSizeMax()), _size(model.getSize())
{
	for (unsigned int n = 0; n < _size; n++)
		_values.push_back(model[n]);
}

Span::~Span()
{
}

Span &Span::operator=(Span & model)
{
	if (this == &model)
		return (*this);
	_sizeMax = model.getSizeMax();
	_size = model.getSize();
	_values = model._values;
	return (*this);
}


// ==== getters ====

unsigned int Span::getSize( void ) const
{
	return (_size);
}

unsigned int Span::getSizeMax( void ) const
{
	return (_sizeMax);
}

int Span::operator[](unsigned int idx)  throw (std::out_of_range)
{
	if (idx >= _size)
		throw(std::out_of_range("index ot of the span bounds"));
	return (_values.at(idx));
}

int Span::operator[](unsigned int idx) const throw (std::out_of_range)
{
	if (idx >= _size)
		throw(std::out_of_range("index ot of the span bounds"));
	return (_values.at(idx));
}



// ==== setters ====

void Span::addNumber(int n) throw(exceptionSpanFull)
{
	if (_size == _sizeMax)
		throw(Span::exceptionSpanFull());
	++_size;
	_values.push_back(n);
}



static long int _abs(long int a)
{
	return (a < 0 ? -a : a);
}

unsigned int	Span::shortestSpan( void ) throw(exceptionSpanTooShort)
{
	if (_size <= 1)
		throw (exceptionSpanTooShort());
	std::vector<int> diffs(_values.size());
	
	std::adjacent_difference(_values.begin(), _values.end(), diffs.begin());
	diffs[0] = diffs[1];
	std::transform(diffs.begin(), diffs.end(), diffs.begin(), _abs);
	// return (*min_element(diffs.begin(), diffs.end()));	
	return (static_cast<unsigned int>(*min_element(diffs.begin(), diffs.end())));	
}

unsigned int	Span::longestSpan( void ) throw(exceptionSpanTooShort)
{
	if (_size <= 1)
		throw (exceptionSpanTooShort());
	std::vector<int> diffs(_values.size());
	
	std::adjacent_difference(_values.begin(), _values.end(), diffs.begin());
	diffs[0] = diffs[1];
	std::transform(diffs.begin(), diffs.end(), diffs.begin(), _abs);
	// return (*min_element(diffs.begin(), diffs.end()));	
	return (static_cast<unsigned int>(*max_element(diffs.begin(), diffs.end())));	
}

std::ostream &operator<<(std::ostream &o, Span const & rhs)
{
	std::cout << "{";
	for (unsigned int n = 0; n < rhs.getSize() - 1 ; n++)

		std::cout << rhs[n] << ", ";
	if (rhs.getSize() >= 1)
		std::cout << rhs[rhs.getSize() - 1];
	std::cout << "} (" << rhs.getSize() << "/" <<rhs.getSizeMax() << ")";
	return (o);
}