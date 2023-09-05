/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:01:32 by acardona          #+#    #+#             */
/*   Updated: 2023/09/05 19:19:01 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// =========== Canonical elements =====================

FragTrap::FragTrap( void ):ClapTrap()
{
	std::cout << "[FragTrap] Default constructor called" << std::endl;
	this->_HitPoints = INIT_FRAGTRAP_HIT;
	this->_EnergyPoints = INIT_FRAGTRAP_ENERGY;
	this->_AttackDamage = INIT_FRAGTRAP_ATTACK;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "[FragTrap] Param constructor called for " << name << std::endl;
	this->_HitPoints = INIT_FRAGTRAP_HIT;
	this->_EnergyPoints = INIT_FRAGTRAP_ENERGY;
	this->_AttackDamage = INIT_FRAGTRAP_ATTACK;
}

FragTrap::FragTrap( FragTrap const & elem ) : ClapTrap(elem)
{
	std::cout << "[FragTrap] Copy constructor called for " << this->_Name << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "[FragTrap] Destructor called for " << this->_Name << std::endl;
}

FragTrap & FragTrap::operator=( FragTrap const & elem)
{
	if (this != &elem)
		ClapTrap::operator=(elem);
	return (*this);
}

// =========== End: Canonical elements =====================


void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_Name << " says : \"Hey guys, does anybody want to high five me ?\"" << std::endl;
}
