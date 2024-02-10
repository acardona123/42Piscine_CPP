/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:23:10 by acardona          #+#    #+#             */
/*   Updated: 2024/02/10 18:39:50 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <iterator>
# include <algorithm>
# include <exception>

# define 	WANT_ITERATOR //

# ifdef WANT_ITERATOR

class ExceptionNotFound : public std::exception
{
	public:
		virtual const char* what() const throw() { return ("Value not found"); };
};

template <typename T>typename T::const_iterator easyfind(T const & int_container, int const to_find)
{
	typename T::const_iterator	i = std::find(int_container.begin(), int_container.end(), to_find);

	if (i == int_container.end())
	{
		throw (ExceptionNotFound());
	}
	return (i);	
}

template <typename T>typename T::iterator easyfind(T & int_container, int const to_find)
{
	typename T::iterator	i = std::find(int_container.begin(), int_container.end(), to_find);

	if (i == int_container.end())
	{
		throw (ExceptionNotFound());
	}
	return (i);	
}

# else

template <typename T> bool easyfind(T & int_container, int to_find)
{
	if (std::find(int_container.begin(), int_container.end(), to_find) == int_container.end())
	{
		return (false);
	}
	return (true);	
}

# endif

#endif