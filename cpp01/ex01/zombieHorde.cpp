/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:56:42 by acardona          #+#    #+#             */
/*   Updated: 2023/08/01 17:59:04 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*horde;

	if (N <= 0)
	{
		std::cout << "The number of zombies must be > 0" << std::endl;
		return NULL;
	}
	horde = new Zombie[N];
	if (horde == NULL)
	{
		std::cout << "Allocation failure" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N;  i++)
		horde[i].set_name(name); 
	return (horde);
}
