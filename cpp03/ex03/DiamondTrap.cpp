/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:29:58 by acardona          #+#    #+#             */
/*   Updated: 2023/08/30 17:08:43 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// ==== Canonical elements ====

DiamondTrap::DiamondTrap( void ) : ClapTrap( "unknown"), FragTrap("unknown"), ScavTrap("unknown")
{
	_Name = "unknown";
	// this->_HitPoints = INIT_FRAGTRAP_HIT;
	// this->_EnergyPoints = INIT_SCAVTRAP_ENERGY;
	// this->_AttackDamage = INIT_FRAGTRAP_ATTACK;
	this->_HitPoints = FragTrap::_HitPoints;
	this->_EnergyPoints = ScavTrap::_EnergyPoints;
	this->_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "[DiamondTrap] Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_name" ), FragTrap( name ), ScavTrap( name )
{
	_Name = name;
	// this->_HitPoints = INIT_FRAGTRAP_HIT;
	// this->_EnergyPoints = INIT_SCAVTRAP_ENERGY;
	// this->_AttackDamage = INIT_FRAGTRAP_ATTACK;
	this->_HitPoints = FragTrap::_HitPoints;
	this->_EnergyPoints = ScavTrap::_EnergyPoints;
	this->_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "[DiamondTrap] Param constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & model) : ClapTrap(model), FragTrap(model), ScavTrap(model)
{
	this->_Name = model._Name;
	std::cout << "[DiamondTrap] Copy constructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & model)
{
	if (this == &model)
		return (*this);
	FragTrap::operator= (model);
	this->_Name = model._Name;
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "[DiamondTrap] Destructor called for " << this->_Name << "(alias " << this->ScavTrap::_Name << ")" << std::endl;
}

// ---- End: Canonical elements ----



// ==== Member functions ====

void 	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}


void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: \"" << this->_Name << "\" and ClapTrap name: \"" << this->ClapTrap::_Name << "\"" << std::endl;
}

// ---- End: Member functions ----