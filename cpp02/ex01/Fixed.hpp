/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:17:14 by acardona          #+#    #+#             */
/*   Updated: 2023/08/16 17:41:53 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed	( void );
		Fixed	( Fixed const & source );
		Fixed	( int const n );
		Fixed	( float const f);
		~Fixed	( void );
		Fixed	& operator=( Fixed const & source);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
	private:
		int					_rawBits;
		static const int	_pointPos;
};

std::ostream & operator<<(std::ostream & o, Fixed & n);
std::ostream & operator<<(std::ostream & o, Fixed const & n);

#endif