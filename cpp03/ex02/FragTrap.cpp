/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:01:32 by acardona          #+#    #+#             */
/*   Updated: 2023/08/25 16:51:29 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// =========== Canonical elements =====================

FragTrap::FragTrap( void ):ClapTrap()
{
	this->_HitPoints = INIT_FRAGTRAP_HIT;
	this->_EnergyPoints = INIT_FRAGTRAP_ENERGY;
	this->_AttackDamage = INIT_FRAGTRAP_ATTACK;
	std::cout << "[FragTrap] Default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->_HitPoints = INIT_FRAGTRAP_HIT;
	this->_EnergyPoints = INIT_FRAGTRAP_ENERGY;
	this->_AttackDamage = INIT_FRAGTRAP_ATTACK;
	std::cout << "[FragTrap] Param constructor called for " << name << std::endl;
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
	ClapTrap::operator=(elem);
	return (*this);
}

// =========== End: Canonical elements =====================


void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_Name << " says : \"Hey guys, does anybody want to high five me ?\"" << std::endl;
}
