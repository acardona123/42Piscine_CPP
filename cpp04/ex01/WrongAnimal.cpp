/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:35:29 by acardona          #+#    #+#             */
/*   Updated: 2023/08/26 16:49:57 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// ===== Canonical class elements =====

WrongAnimal::WrongAnimal( void )
{
	this->type = "Unknown_WrongAnimal_type";
	std::cout << "[WrongAnimal] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type(type)
{
	std::cout << "[WrongAnimal] Param constructor called for " << type << std::endl;
}

WrongAnimal::WrongAnimal ( WrongAnimal const & model) : type(model.type)
{
	std::cout << "[WrongAnimal] Copy constructor called for " << model.type << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "[WrongAnimal] Default destructor for " << this->type << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & model )
{
	this->type = model.type;
	return (*this); 
}

// ---- End: Canonical class elements ----



// ==== Mumber functions ====

std::string		WrongAnimal::getType( void ) const
{
	return (this->type);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << " * undefined noise... I'm not sure about what it is but I definitly hear a WrongAnimal! *" << std::endl;
}

// ---- End: Mumber functions ----
