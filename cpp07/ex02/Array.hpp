/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:01:15 by acardona          #+#    #+#             */
/*   Updated: 2024/01/21 22:11:13 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T> class Array 
{
	public:
		Array<T>( void ) throw (std::bad_alloc): _size(0) {
			_content = new T [0];
		}

		Array<T>( unsigned int size ) throw (std::bad_alloc): _size(size)
		{
			_content = new T [size];
		}

		Array<T>( Array & model ) throw (std::bad_alloc): _size(model.size()) {
			_content = new T [model.size()];
			for (unsigned int n = 0; n < _size; ++n)
				_content[n] = model[n];
		}

		~Array<T>( void ) { delete[] _content;}

		unsigned int size ( void ) const{ return (_size);}

		T & operator[](unsigned int index) const throw (std::out_of_range){
			if (index >= _size)
				throw (std::out_of_range("index out of bounds"));
			return (_content[index]);
		}

		T & operator=(T model) throw (std::out_of_range)
		{
			_swap(model);
			return (*this);
		}
		
	private:
		T				*_content;
		unsigned int	_size;

		void	_swap(T &rhs) {
			unsigned int	tmp_size = rhs._size;
			T				*tmp_content = rhs._content;
			rhs._content = _content;
			rhs._size = _size;
			_content = tmp_content;
			_size = tmp_size;
		}
};

template <typename T>std::ostream & operator<<(std::ostream & o, const Array<T> &array)
{
	std::cout << "{";
	if (array.size() > 1)
	{
		for (unsigned int n = 0; n < array.size() - 1; ++n)
			std::cout << array[n] << ", ";
		std::cout <<  array[array.size() - 1];
	}
	std::cout << "}";
	return (o);
}



#endif