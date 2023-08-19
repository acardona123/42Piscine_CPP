/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:17:14 by acardona          #+#    #+#             */
/*   Updated: 2023/08/14 19:11:21 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed	( void );
		Fixed	( Fixed const & source);
		~Fixed	( void );
		Fixed	& operator=( Fixed const & source);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int					_rawBits;
		static const int	_pointPos;
};



#endif