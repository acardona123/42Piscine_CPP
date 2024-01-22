/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:26 by acardona          #+#    #+#             */
/*   Updated: 2024/01/22 16:10:30 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>


void opposit(int &n)
{
	n *= -1;
}

template<typename T> void function_display(T & n)
{
	std::cout << n << std::endl;
}

int main( void )
{
	int 	*list_int;
	unsigned int size = 4;

	list_int = new int[size];
	for (unsigned int i = 0; i < size; ++i)
		list_int[i] = i;
	iter<int>(list_int, size, opposit);
	iter<int>(list_int, size, function_display<int>);
	delete[] list_int;
}


/*
//correction test

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  const int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}

*/