/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:26 by acardona          #+#    #+#             */
/*   Updated: 2023/09/05 19:16:57 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// =========== Canonical elements =====================

ClapTrap::ClapTrap( void )
{
	std::cout << "[ClapTrap] Default constructor called" << std::endl;
	_Name = "unknown";
	this->_HitPoints = INIT_CLAPTRAP_HIT;
	this->_EnergyPoints = INIT_CLAPTRAP_ENERGY;
	this->_AttackDamage = INIT_CLAPTRAP_ATTACK;
}

ClapTrap::ClapTrap( std::string name ) : _Name(name)
{
	std::cout << "[ClapTrap] Param constructor called for " << name << std::endl;
	this->_HitPoints = INIT_CLAPTRAP_HIT;
	this->_EnergyPoints = INIT_CLAPTRAP_ENERGY;
	this->_AttackDamage = INIT_CLAPTRAP_ATTACK;
}

ClapTrap::ClapTrap( ClapTrap const & elem )
{
	std::cout << "[ClapTrap] Copy constructor called for "<< elem._Name << std::endl;
	this->_Name = elem._Name;
	this->_HitPoints = elem._HitPoints;
	this->_EnergyPoints = elem._EnergyPoints;
	this->_AttackDamage = elem._AttackDamage;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "[ClapTrap] Destructor called for " << this->_Name << std::endl;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & elem)
{
	this->_Name = elem._Name;
	this->_EnergyPoints = elem._EnergyPoints;
	this->_HitPoints =	 elem._HitPoints;
	return (*this);
}

// =========== End: Canonical elements =====================


// =========== Methodes =====================


void	ClapTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints == 0)
	{	
		std::cout << "ClapTrap " << this->_Name << " tries to attack " << target << " but doesn't have enough energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
	this->_EnergyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_HitPoints)
	{
		std::cout << "ClapTrap " << this->_Name << " takes " << this->_HitPoints << " damage points and is completly broken!" << std::endl;
		this->_HitPoints = 0;
		return ;
	}
	this->_HitPoints -= amount;
	std::cout << "ClapTrap " << this->_Name << " takes " << amount << " damage points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	//security if adding amount points to HitPoints leads to a total amount of Hitpoints superior to 10 ? Undefined behavior
	//using one energypoint per _EnergyPoint recovered or per entiere reparation
	if (this->_EnergyPoints == 0)
		std::cout << "ClapTrap " << this->_Name << " tries to attack repaire itself but doesn't have enough energy" << std::endl;
	/*
	else if (this->_EnergyPoints < amount)
	{
		std::cout << "ClapTrap " << this->_Name << " tries to do a " << amount << " points reparation but its energy is limited. It then does the maximal " << this->_EnergyPoints << " Hit points reparation."<< std::endl;
		this->_HitPoints += this->_EnergyPoints;
		this->_EnergyPoints = 0;
	}
	*/
	else
	{
		std::cout << "ClapTrap " << this->_Name << " makes a " << amount << " Hit points reparation." << std::endl;
		this->_EnergyPoints -= 1; // amount
		this->_HitPoints += amount;
	}
}
// /*
void	ClapTrap::showStatus( void )
{
	std::cout << this->_Name << ":"<< std::endl;
	std::cout<< " - Hit points: " << this->_HitPoints << std::endl;
	std::cout <<" - Energy points: " << this->_EnergyPoints << std::endl ;
	std::cout << " - Attack damage: "<< this->_AttackDamage << std::endl;
}
//*/
