/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:55:03 by alexcardona       #+#    #+#             */
/*   Updated: 2023/08/29 18:17:21 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	Zombie	z0("First");
	Zombie	*pZ1;
	
	std::cout << "manual display : " << std::endl;
	z0.announce();
	std::cout << std::endl;
	
	pZ1 = newZombie("Second");
	if (pZ1)
	{
		std::cout << "manual display : ";
		pZ1->announce();
		delete pZ1;
	}
	else
		std::cout << "Allocation faillure" << std::endl;

	std::cout << std::endl << "Chump : " << std::endl;
	randomChump("Third");
	
	std::cout << std::endl;
	return (0);
}