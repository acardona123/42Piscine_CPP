/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:23:43 by acardona          #+#    #+#             */
/*   Updated: 2024/01/12 20:44:14 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T> void iter(T *array, unsigned int size, void (*f)(T &))
{
	for (unsigned int i = 0; i < size; ++i)
		(*f)(array[i]);

}

#endif