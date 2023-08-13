/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexcardona <alexcardona@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:55:03 by alexcardona       #+#    #+#             */
/*   Updated: 2023/08/01 16:15:52 by alexcardona      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	Zombie	z0("First");
	Zombie	*pz1;
	
	std::cout << "manual display : ";
	z0.announce();
	
	pz1 = newZombie("Second");
	std::cout << "manual display : ";
	pz1->announce();
	delete pz1;

	randomChump("Third");
	
	
	return (0);
}