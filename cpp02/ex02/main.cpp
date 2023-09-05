/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:11:17 by acardona          #+#    #+#             */
/*   Updated: 2023/09/03 15:45:41 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	my_tests(Fixed & a, Fixed & b);
void subject_tests( void );

int main( void )
{
	Fixed	a(32.5f);
	Fixed	b(1.25f);

	subject_tests();
	
	std::cout << std::endl;
	
	my_tests(a, b);
	
	return 0; 
	
}

void subject_tests( void )
{
	std::cout << "==== Subject tests ====" << std::endl;
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	std::cout << "==== End of subject tests ====" << std::endl << std::endl;
}

void	my_tests(Fixed & a, Fixed & b)
{
	std::cout << "==== My tests ====" << std::endl << std::endl << "Values used : a = " << a << " ; b = " << b << std:: endl << std::endl;

	
	Fixed	const ca = a;
	Fixed	const cb = b;

	Fixed c, d;

	c = d = a;
	std::cout << "c = d = a and a = " << a << "  ==>   c = " << c << " ; d = " << d << std::endl << std :: endl;
	
	std::cout << a << " < " << b << " : " << (a < b) * 1 << std::endl;
	std::cout << a << " < " << b << " : " << (ca < cb) * 1 << std::endl << std::endl;

	std::cout << a << " <= " << b << " : " << (a <= b) * 1 << std::endl;
	std::cout << a << " <= " << b << " : " << (ca <= cb) * 1 << std::endl << std::endl;
	
	std::cout << a << " > " << b << " : " << (a > b) * 1 << std::endl;
	std::cout << a << " > " << b << " : " << (ca > cb) * 1 << std::endl << std::endl;
	
	std::cout << a << " >= " << b << " : " << (a >= b) * 1 << std::endl;
	std::cout << a << " >= " << b << " : " << (ca >= cb) * 1 << std::endl << std::endl;
	
	std::cout << a << " == " << b << " : " << (a == b) * 1 << std::endl;
	std::cout << a << " == " << b << " : " << (ca == cb) * 1 << std::endl << std::endl;
	
	std::cout << a << " != " << b << " : " << (a != b) * 1 << std::endl;
	std::cout << a << " != " << b << " : " << (ca != cb) * 1 << std::endl << std::endl;
	
	std::cout << a << " + " << b << " : " << a + b << std::endl;
	std::cout << a << " + " << b << " : " << ca + cb << std::endl << std::endl;
	
	std::cout << a << " - " << b << " : " << a - b << std::endl;
	std::cout << a << " - " << b << " : " << ca - cb << std::endl << std::endl;
	
	std::cout << a << " * " << b << " : " << a * b << std::endl;
	std::cout << a << " * " << b << " : " << ca * cb << std::endl << std::endl;
	
	std::cout << a << " / " << b << " : " << a / b << std::endl;
	std::cout << a << " / " << b << " : " << ca / cb << std::endl << std::endl;
	
	std::cout << a << " + " << b << " : " << a + b << std::endl;
	std::cout << a << " + " << b << " : " << ca + cb << std::endl << std::endl;

	std::cout << "min(a, b) : " << Fixed::min(a, b) << std::endl;
	std::cout << "min(ca, cb) : " << Fixed::min(ca, cb) << std::endl;
	std::cout << "min(ca, b) : " << Fixed::min(ca, b) << std::endl << std::endl;
	std::cout << "max(a, b) : " << Fixed::max(a, b) << std::endl;
	std::cout << "max(ca, cb) : " << Fixed::max(ca, cb) << std::endl;
	std::cout << "max(a, cb) : " << Fixed::max(a, cb) << std::endl << std::endl;
	
	std::cout << "++" << a << " : " << ++a << " -> " << a << std::endl;
	std::cout << "--" << a << " : " << --a << " -> " << a << std::endl;
	std::cout << a << "++" << " : " << a++ << " -> " << a << std::endl;
	std::cout << a << "--" << " : " << a-- << " -> " << a << std::endl;

	std::cout << std::endl << "==== End of my tests ====" << std::endl << std::endl;
}