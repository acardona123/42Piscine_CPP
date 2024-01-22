/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:55:06 by acardona          #+#    #+#             */
/*   Updated: 2024/01/22 16:11:58 by acardona         ###   ########.fr       */
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
	return (a < b ? a : b);
}

template<typename T> T const & min(T const & a, T const & b)
{
	return (a < b ? a : b);
}

template<typename T> T & max(T & a, T & b)
{
	return (a > b ? a : b);
}

template<typename T> T const & max(T const & a, T const & b)
{
	return (a > b ? a : b);
}

#endif