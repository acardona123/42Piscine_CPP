/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:36:39 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 18:06:24 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// ===== Canonical class elements =====

Cat::Cat( void ) : Animal( "Cat" )
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Cat] Default constructor called" << CBLACK << std::endl;
	this->_brain = NULL;
}

Cat::Cat( std::string ideas[BRAIN_SIZE] ) : Animal( "Cat" )
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Cat] Param constructor called" << CBLACK << std::endl;
	this->_brain = new Brain(ideas);
	if (!this->_brain)
	{
		std::cout << "Memory allocation fail" << std::endl;
		return ;
	}
}

Cat::Cat ( Cat const & model) : Animal( model.type )
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Cat] Copy constructor called for " << model.type << CBLACK << std::endl;
	this->_brain = new Brain(model._brain->ideas);
	if (!this->_brain)
	{
		std::cout << "Memory allocation fail" << std::endl;
		return ;
	}
	
}

Cat::~Cat( void )
{
	if (this->_brain)
		delete this->_brain;
	std::cout << DESTRUCTOR_COLOR <<  "[Cat] Default destructor for " << this->type << CBLACK << std::endl;
}

Cat & Cat::operator=(Cat const & model )
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

void Cat::makeSound( void ) const
{
	if (!this->_brain)
		std::cout << "Miaou!" << std::endl;
	else
		std::cout << "Miaou! (which means : \"" << this->_brain->ideas[rand() % BRAIN_SIZE] << "\")" << std::endl;
}

Brain	*Cat::getBrain( void ) const
{
	return (this->_brain);
}

// ---- Member functions ----
