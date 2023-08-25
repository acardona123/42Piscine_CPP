/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:30:34 by acardona          #+#    #+#             */
/*   Updated: 2023/08/25 16:16:21 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap first("theFirst");
	ScavTrap second("theSecond");

	std::cout << std::endl;
	first.showStatus();
	second.showStatus();
	std::cout << std::endl;

	first.attack("toto");
	first.takeDamage(5);
	first.beRepaired(2);
	first.guardGate();
	std::cout << "=>" << std::endl;
	first.showStatus();
	std::cout << std::endl;
	
	first.beRepaired(10);
	first.attack("toto");
	std::cout << "=>" << std::endl;
	first.showStatus();
	std::cout << std::endl;
	
	first.takeDamage(200);
	first.beRepaired(2);	std::cout << "=>" << std::endl;
	first.showStatus();
	std::cout << std::endl;
	
	first.attack("Bob1");
	first.attack("Bob2");
	first.attack("Bob3");
	first.attack("Bob4");
	first.attack("Bob5");
	first.attack("Bob6");
	first.attack("Bob7");
	std::cout << std::endl;
	
	std::cout << "-------" << std::endl << "Copy tests :" << std::endl << std::endl;
	ScavTrap third(first);
	first.showStatus();
	second.showStatus();
	third.showStatus();
	std::cout << std::endl;

	third = second;
	second.showStatus();

	std::cout << std::endl;

	std::cout << std::endl;
	return (0);
}