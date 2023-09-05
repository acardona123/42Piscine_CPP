/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:16:48 by acardona          #+#    #+#             */
/*   Updated: 2023/09/03 15:37:07 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_pointPos = 8;

//------------- Canonical form elements ----------------

Fixed::Fixed( void ) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed	( int const n )
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = n << this->_pointPos;
}

Fixed::Fixed	( float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(f * (1 << this->_pointPos));
}

Fixed::Fixed( Fixed const & source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	& Fixed::operator=( Fixed const & source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = source.getRawBits();
	return (*this);
}

//------------- END: Canonical form elements ----------------


//------------- Operators ----------------

std::ostream & operator<<(std::ostream & o, Fixed & n)
{
	std::cout << n.toFloat();
	return o;
}

std::ostream & operator<<(std::ostream & o, Fixed const & n)
{
	std::cout << n.toFloat();
	return o;
}

//------------- End: Operators ----------------


//------------- setters and getters ----------------

int		Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

//------------- END: setters and getters ----------------

//------------- Conversion ----------------

float	Fixed::toFloat( void ) const
{
	return (float)(this->_rawBits) / (1 << this->_pointPos);
}

int	Fixed::toInt( void ) const
{
	return  this->_rawBits >> this->_pointPos;
}

//------------- End: Conversion ----------------