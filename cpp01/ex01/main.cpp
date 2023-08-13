/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:10:06 by acardona          #+#    #+#             */
/*   Updated: 2023/08/14 00:29:32 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static int _one_loop(void)
{
	std::cout << "Enter parameters :" << std::endl << "- number of zombies : ";
	int			nb_zomb;
	while (!(std::cin >> nb_zomb))
	{
		std::cout << "  Invalid input. Please enter a numeric value : ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	std::string name("");
	std::cout << "- name : ";
	getline(std::cin, name);;
	while (name.empty())
	{
		std::cout << "  Invalid input. A name cannot be empty. Please enter a name : ";
		getline(std::cin, name);
	}
	std::cout << "=> results :" << std::endl;

	Zombie	*horde;
	horde = zombieHorde(nb_zomb, name);
	if (!horde)
		return 1;
	for (int i = 0; i < nb_zomb; i++)
	{
		std::cout << i << ": " << horde[i].get_name() << std::endl;
		horde[i].announce();
		std::cout << std::endl;
	}
	std::cout << "All displayed !" << std::endl;
	delete [] horde;
	std::cout << std::endl;
	return (0);
}

int	main(void)
{
	while (1)
	{
		_one_loop();
		std::string other_sim;
		std::cout << std::endl << "CONTINUE ANOTHER TEST ? (y/n)";
		std::cin >> other_sim;
		if (other_sim.compare("y") && other_sim.compare("Y") && other_sim.compare("yes") && other_sim.compare("YES"))
		{
			std::cout << "Simulation ended successfully" << std::endl;
			return 0;
		}
		std::cout << std::endl;
	}
	return (0);
}