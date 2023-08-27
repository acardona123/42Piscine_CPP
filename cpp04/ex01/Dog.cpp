/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:26:28 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 16:46:51 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// ===== Canonical class elements =====

Dog::Dog( void ) : Animal( "Dog" )
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Dog] Default constructor called" << CBLACK << std::endl;
	this->_brain = NULL;
}

Dog::Dog( std::string ideas[BRAIN_SIZE] ) : Animal( "Dog" )
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Dog] Param constructor called" << CBLACK << std::endl;
	this->_brain = new Brain(ideas);
	if (!this->_brain)
	{
		std::cout << "Memory allocation fail" << std::endl;
		return ;
	}
}

Dog::Dog ( Dog const & model) : Animal( model.type )
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Dog] Copy constructor called for " << model.type << CBLACK << std::endl;
	this->_brain = new Brain(model._brain->ideas);
	if (!this->_brain)
	{
		std::cout << "Memory allocation fail" << std::endl;
		return ;
	}
	
}

Dog::~Dog( void )
{
	if (this->_brain)
		delete this->_brain;
	std::cout << DESTRUCTOR_COLOR <<  "[Dog] Default destructor for " << this->type << CBLACK << std::endl;
}

Dog & Dog::operator=(Dog const & model )
{
	if (this == &model)
		return (*this);
	this->type = model.type;
	if (!model._brain && this->_brain)
	{
		delete this->_brain;
		this->_brain = NULL;
	}
	else if (model._brain)
	{
		if (!this->_brain)
			this->_brain = new Brain(model._brain->ideas);
		else
			*this->_brain = *model._brain;
	}
	return (*this); 
}

// ---- End: Canonical class elements ----



// ==== Member functions ====

void Dog::makeSound( void ) const
{
	if (!this->_brain)
		std::cout << "Waf!" << std::endl;
	else
		std::cout << "Waf! (which means : \"" << this->_brain->getIdea(rand() % BRAIN_SIZE) << "\")" << std::endl;
}

Brain	*Dog::getBrain( void ) const
{
	return (this->_brain);
}

// ---- Member functions ----
