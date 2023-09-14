/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:02:02 by acardona          #+#    #+#             */
/*   Updated: 2023/09/14 15:09:32 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// ==== Canonical elements ====

Character::Character( void ) : _Name("Undefined")
{
	std::cout << CBLUE << "   [Character] Default constructor called" << CBLACK << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		(this->_inventory)[i] = NULL;
}

Character::Character( std::string name ) : _Name(name)
{
	std::cout << CBLUE << "   [Character] Param constructor called for " << name << CBLACK << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		(this->_inventory)[i] = NULL;
}

Character::Character( Character const & model ) : _Name(model.getName())
{
	std::cout << CBLUE << "   [Character] Copy constructor called for " << this->getName() << CBLACK << std::endl;
	for (unsigned int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (!model.getMateria(i))
			this->_inventory[i] = NULL;
		else
		 	(this->_inventory)[i] = model.getMateria(i)->clone();
			
	}
}

Character::~Character ( void )
{
	std::cout << CYELLOW << "   [Character] Default destructor called for " << this->getName() << CBLACK << std::endl;
	for (unsigned int i = 0; i < INVENTORY_SIZE; i++)
		if (_inventory[i])
		{
			for (int j = i + 1; j < INVENTORY_SIZE; j++)
				if (_inventory[j] == _inventory[i])
					_inventory[j] = NULL;
			delete(_inventory[i]);
		}
}

Character & Character::operator=( Character const & model )
{
	std::cout << "[Character] Copy operator called for " << this->getName() << std::endl;
	if (this == &model)
		return (*this);	
	this->_Name = model.getName();
	for (unsigned int i = 0; i < INVENTORY_SIZE; i++)
	{
		if ((this->_inventory)[i])
			delete ((this->_inventory)[i]);
		if (model.getMateria(i))
			(this->_inventory)[i] = model.getMateria(i)->clone();
		else
			(this->_inventory)[i] = NULL;
	}
	return (*this);
}

// ----End: Canonical elements ----



// ==== Accessors ====

std::string const & Character::getName() const
{
	return (this->_Name);	
}

AMateria * Character::getMateria(unsigned int idx) const
{
	if (idx >= INVENTORY_SIZE)
		return (NULL);
	return (this->_inventory[idx]);
}

// ---- End: Accessors ----



// ==== Mumber functions ====

void Character::equip(AMateria* m)
{
	unsigned int	i(0);

	if (!m)
		return ;
	while (i < INVENTORY_SIZE && this->_inventory[i])
		i++;
	if (i == INVENTORY_SIZE)
	{
		if (COMMENTARY_ON)
			std::cout << CPURPLE << this->_Name << ": inventory full, impossible to equipe " << m->getType() << CBLACK << std::endl;
		return ;
	}
	this->_inventory[i] = m;
	if (COMMENTARY_ON)
		std::cout << CPURPLE << this->_Name << ": " << m->getType() << " equiped at slot " << i << CBLACK << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= INVENTORY_SIZE || idx < 0)
	{
		if (COMMENTARY_ON)
			std::cout << CPURPLE << "Character unequip: wrong inventory index" << CBLACK << std::endl;
		return ;
	}
	if (COMMENTARY_ON)
	{
		if (this->_inventory[idx])
			std::cout << CPURPLE << this->_Name << ": unequiped " << this->_inventory[idx]->getType() << " from slot #" << idx << CBLACK << std::endl;
		else
		 	std::cout << CPURPLE << this->_Name << "'s inventory slot #" << idx << " is already empty" << CBLACK << std::endl;
	}
	(this->_inventory)[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= INVENTORY_SIZE || idx < 0)
	{
		if (COMMENTARY_ON)
			std::cout << CPURPLE << "Character use: wrong inventory index" << CBLACK << std::endl;
		return ;
	}
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << this->_Name << ": no materia to use in slot #" << idx << std::endl;
}

// ---- End: Mumber functions ----
