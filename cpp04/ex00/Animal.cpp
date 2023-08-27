/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:35:29 by acardona          #+#    #+#             */
/*   Updated: 2023/08/26 17:14:31 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// ===== Canonical class elements =====

Animal::Animal( void )
{
	this->type = "Unknown_animal_type";
	std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal( std::string type ) : type(type)
{
	std::cout << "[Animal] Param constructor called for " << type << std::endl;
}

Animal::Animal ( Animal const & model) : type(model.type)
{
	std::cout << "[Animal] Copy constructor called for " << model.type << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "[Animal] Default destructor for " << this->type << std::endl;
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
