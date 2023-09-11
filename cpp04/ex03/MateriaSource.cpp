/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:42:43 by acardona          #+#    #+#             */
/*   Updated: 2023/09/11 21:08:24 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// ==== Canonical elemets ====

MateriaSource::MateriaSource( void )
{
	std::cout << CBLUE << "   [MateriaSource] Default constructor called" << CBLACK << std::endl;
	for (int i = 0; i < MATERIA_MEMORY_SIZE; i++)
		this->_saved[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource const & model)
{
	std::cout << CBLUE << "   [MateriaSource] Copy constructor called" << CBLACK << std::endl;
	for (int i = 0; i < MATERIA_MEMORY_SIZE; i++)
	{
		if (model.getMateria(i))
			this->_saved[i] = model.getMateria(i)->clone();
		else
			this->_saved[i] = NULL;
	}
}

MateriaSource::~MateriaSource( void )
{
	std::cout << CYELLOW << "   [MateriaSource] Default destructor called (start)" << CBLACK << std::endl;
	for (int i = 0; i < MATERIA_MEMORY_SIZE; i++)
	{
		if (this->_saved[i])
			delete (this->_saved[i]);
	}
	std::cout << CYELLOW << "   [MateriaSource] Default destructor called (end)" << CBLACK << std::endl;
}

MateriaSource & MateriaSource::operator=( MateriaSource const & model )
{
	if (this == &model)
		return (*this);
	for (int i = 0; i < MATERIA_MEMORY_SIZE; i++)
	{
		if (this->_saved[i])
			delete (this->_saved[i]);
		if (model.getMateria(i))
			this->_saved[i] = model.getMateria(i)->clone();
		else
			this->_saved[i] = NULL;
	}
	return (*this);
}

// ---- End: Canonical elemets ----



// ==== Accessors ====

AMateria * MateriaSource::getMateria(unsigned int idx) const
{
	if (idx >= MATERIA_MEMORY_SIZE)
		return (NULL);
	return (this->_saved[idx]);
}

// ---- End: Accessors ----



// ==== Member functions ====

void MateriaSource::learnMateria(AMateria* model)
{
	int i(0);
	
	while (i < MATERIA_MEMORY_SIZE && this->_saved[i])
		i++;
	if (i == MATERIA_MEMORY_SIZE)
	{
		std::cout << "learnMateria: not enough memory to learn the materia " << model->getType() << std::endl;
		return ;
	}
	this->_saved[i] = model->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MATERIA_MEMORY_SIZE; i++)
	{
		if (this->_saved[i] && this->_saved[i]->getType() == type)
		{
			std::cout << "Materia generated based on " << type << " model" << std::endl;
			return (this->_saved[i]->clone());
		}
	}
	std::cout << "No model known for \"" << type << "\" type" << std::endl;

	return (NULL);
}


// ---- End: Member functions ----
