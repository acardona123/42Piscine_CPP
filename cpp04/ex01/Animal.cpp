/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:35:29 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 18:22:30 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// ===== Canonical class elements =====

Animal::Animal( void )
{
	this->type = "Unknown_animal_type";
	std::cout << CONSTRUCTOR_COLOR <<  "[Animal] Default constructor called" << CBLACK << std::endl;
}

Animal::Animal( std::string type ) : type(type)
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Animal] Param constructor called for " << type << CBLACK << std::endl;
}

Animal::Animal ( Animal const & model) : type(model.type)
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Animal] Copy constructor called for " << model.type << CBLACK << std::endl;
}

Animal::~Animal( void )
{
	std::cout << DESTRUCTOR_COLOR <<  "[Animal] Default destructor for " << this->type << CBLACK << std::endl;
}

Animal & Animal::operator=(Animal const & model )
{
	this->type = model.type;
	return (*this); 
}

// ---- End: Canonical class elements ----



// ==== Mumber functions ====

std::string		Animal::getType( void ) const
{
	return (this->type);
}

void Animal::makeSound( void ) const
{
	std::cout << " * undefined noise... I'm not sure about what it is but I definitly hear an animal! *" << std::endl;
}

// ---- End: Mumber functions ----
