/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStak.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:14:06 by acardona          #+#    #+#             */
/*   Updated: 2024/01/24 18:35:58 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <vector>
# include <algorithm>


//this would be the proper template in order to avoid the derivation of std::stack as recommended, but not compatible with the main (initialization of a std::stack with a MutantStack) 

// template <class T>
// 	class MutantStack
// {
// 	private:
// 		std::stack<T, std::deque<T>> _stack;

// 	public:
// 		MutantStack< T >( void ) {};
// 		MutantStack< T >( MutantStack & model) : _stack(model._stack) {}
// 		~MutantStack< T >( void ) {}
// 		MutantStack< T > & operator=(MutantStack model)
// 		{
// 			_stack = model._stack;
// 			return (*this);
// 		}

// 		void push( const T & value ) { _stack.push(value); }
// 		void pop() { _stack.pop(); }
// 		T & top() { return (_stack.top()); }
// 		const T & top() const { return (_stack.top()); }
// 		bool empty() const { return (_stack.empty()); }
// 		typename std::deque<T>::size_type size() const { return (_stack.size()); }
		
// 		class iterator : public std::iterator<
// 			std::bidirectional_iterator_tag,	//iterator_category
// 			T,									//difference_type
// 			std::ptrdiff_t,						//value_type
// 			T*,									//pointer
// 			T&									//reference
// 			> {

// 			private:
// 				T *_ptr;

// 			public:
// 				iterator( T *ptr) : _ptr(ptr) {}
// 				T &operator*() const { return (*_ptr);}
// 				T &operator->() const { return (_ptr);}
// 				iterator & operator++(){++_ptr; return (*this);}
// 				iterator operator++(int){iterator tmp(*this);++(*this); return (tmp);}
// 				iterator & operator--(){--_ptr; return (*this);}
// 				iterator operator--(int){iterator tmp(*this);--(*this); return (tmp);}
// 				bool operator==(iterator const & rhs) { return ( _ptr == rhs._ptr);}
// 				bool operator!=(iterator const & rhs) {return ( _ptr != rhs._ptr);}
// 		};
// 		iterator begin( void ) {return (iterator(&this->top() - this->size() + 1));}
// 		iterator end( void ) {return (iterator(&this->top() + 1));}
// };

template <class T>
	class MutantStack : public std::stack< T >
{
	public:
		MutantStack< T >( void ) {};
		MutantStack< T >( MutantStack & model) {
			std::stack< T >::operator=(model);
		}
		~MutantStack< T >( void ) {}
		MutantStack< T > & operator=(MutantStack model) {
			std::stack< T >::operator=(model);
			return (*this);
		}
		
		class iterator : public std::iterator<
			std::bidirectional_iterator_tag,	//iterator_category
			T,									// value_type,
			std::ptrdiff_t,						// difference_type,
			T*,									// pointer,
			T&									// reference
			>{

			private:
				T *_ptr;

			public:
				iterator ( void ) : _ptr(nullptr) {}
				iterator( T *ptr ) : _ptr(ptr) {}
				iterator (iterator const & model) : _ptr(model._ptr){}
				iterator & operator=(iterator const &model) { _ptr = model._ptr; }
				~iterator() {}
				T &operator*() const { return (*_ptr);}
				T &operator->() const { return (_ptr);}
				iterator & operator++(){
					++_ptr; return (*this);
				}
				iterator operator++(int){
					iterator tmp(*this);
					++(*this);
					return (tmp);
				}
				iterator & operator--(){
					--_ptr;
					return (*this);
				}
				iterator operator--(int){
					iterator tmp(*this);
					--(*this);
					return (tmp);
				}
				bool operator==(iterator const & rhs) { return ( _ptr == rhs._ptr);}
				bool operator!=(iterator const & rhs) {return ( _ptr != rhs._ptr);}
		};
		iterator begin( void ) {return (this->empty() ? iterator( ) : iterator(&this->top() - this->size() + 1));}
		iterator end( void ) {return (this->empty() ? iterator ( ) : iterator(&this->top() + 1));}
};

#endif