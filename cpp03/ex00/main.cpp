/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:06 by acardona          #+#    #+#             */
/*   Updated: 2023/08/25 16:17:21 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap first("theFirst");
	ClapTrap second("theSecond");

	std::cout << std::endl;
	first.showStatus();
	second.showStatus();
	std::cout << std::endl;

	first.attack("toto");
	first.takeDamage(5);
	first.beRepaired(2);
	std::cout << "=>" << std::endl;
	first.showStatus();
	std::cout << std::endl;
	
	first.beRepaired(10);
	first.attack("toto");
	std::cout << "=>" << std::endl;
	first.showStatus();
	std::cout << std::endl;
	
	first.takeDamage(20);
	first.beRepaired(2);	std::cout << "=>" << std::endl;
	first.showStatus();
	std::cout << std::endl;
	
	first.attack("Bob5->4");
	first.attack("Bob4->3");
	first.attack("Bob3->2");
	first.attack("Bob2->1");
	first.attack("Bob1->0");
	first.attack("Bob");
	first.attack("Bob");
	std::cout << std::endl;
	
	std::cout << "-------" << std::endl << "Copy tests :" << std::endl << std::endl;
	ClapTrap third(first);
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