/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:01:32 by acardona          #+#    #+#             */
/*   Updated: 2023/08/25 16:39:34 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// =========== Canonical elements =====================

ScavTrap::ScavTrap( void ):ClapTrap()
{
	this->_HitPoints = INIT_SCAVTRAP_HIT;
	this->_EnergyPoints = INIT_SCAVTRAP_ENERGY;
	this->_AttackDamage = INIT_SCAVTRAP_ATT;
	this->_Mode = NORMAL;
	std::cout << "[ScavTrap] Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	this->_HitPoints = INIT_SCAVTRAP_HIT;
	this->_EnergyPoints = INIT_SCAVTRAP_ENERGY;
	this->_AttackDamage = INIT_SCAVTRAP_ATT;
	this->_Mode = NORMAL;
	std::cout << "[ScavTrap] Param constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & elem ) : ClapTrap(elem)
{
	this->_Mode = elem._Mode;
	std::cout << "[ScavTrap] Copy constructor called for " << this->_Name << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "[ScavTrap] Destructor called for " << this->_Name << std::endl;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & elem)
{
	ClapTrap::operator=(elem);
	this->_Mode = elem._Mode;
	return (*this);
}

// =========== End: Canonical elements =====================


void ScavTrap::guardGate( void )
{
	this->_Mode = GUARD_GATE;
	std::cout << "ScavTrap " << this->_Name << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::showStatus( void )
{
	this->ClapTrap::showStatus();
	std::cout << " - Mode: ";
	if (this->_Mode == NORMAL)
		std::cout << "normal";
	else
		std::cout << "Gate keeper";
	std::cout << std::endl;
}
