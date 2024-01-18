/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:55:06 by acardona          #+#    #+#             */
/*   Updated: 2024/01/12 20:20:48 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

template<typename T> void swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T> T & min(T & a, T & b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T> T const & min(T const & a, T & b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T> T const & min(T & a, T const & b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T> T const & min(T const & a, T const & b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T> T & max(T & a, T & b)
{
	if (a > b)
		return (a);
	return (b);
}

template<typename T> T const & max(T const & a, T & b)
{
	if (a > b)
		return (a);
	return (b);
}

template<typename T> T const & max(T & a, T const & b)
{
	if (a > b)
		return (a);
	return (b);
}

template<typename T> T const & max(T const & a, T const & b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif