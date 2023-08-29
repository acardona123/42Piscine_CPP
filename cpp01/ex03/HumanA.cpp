/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:39:02 by acardona          #+#    #+#             */
/*   Updated: 2023/08/29 18:37:34 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon & new_weapon) : name(new_name), weapon(new_weapon)
{
	std::cout << "[HumanA] Param constructor called for " << new_name << std::endl;
	return ;
}

HumanA::~HumanA( void )
{
	std::cout << "[HumanA] Default destructor called for " << this->name << std::endl;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}