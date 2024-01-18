/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:01:15 by acardona          #+#    #+#             */
/*   Updated: 2024/01/15 20:36:20 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template <typename T> class Array 
{
	public:
		Array<T>( void ) throw (std::bad_alloc): _size(0) {
			_content = new T [0];
		}
		Array<T>( unsigned int size ) throw (std::bad_alloc): _size(size) {
			_content = new T [size];
			_size = size;
		}
		Array<T>( Array & model ) throw (std::bad_alloc): _size(model.size()) {
			_content = new T [model.size()];
		}
		~Array<T>( void ) {
			delete[] _content;
		}
		unsigned int size ( void ) {
			return (_size);
		}
		T & operator[](unsigned int index) throw (std::out_of_range){
			if (index >= _size)
				throw (std::out_of_range("index out of bounds"));
			return (_content[index]);
		}
	private:
		T				*_content;
		unsigned int	_size;
};



#endif