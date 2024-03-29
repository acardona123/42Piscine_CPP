/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:45:00 by acardona          #+#    #+#             */
/*   Updated: 2024/02/12 17:31:04 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string new_name) : name(new_name), weapon(NULL)
{
	std::cout << "[HumanB] Param constructor called for " << new_name << std::endl;
	return ;
}

HumanB::~HumanB( void )
{
	std::cout << "[HumanB] Default destructor called for " << this->name << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->weapon = &new_weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks without any weapon" << std::endl;
}