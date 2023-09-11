/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:26:28 by acardona          #+#    #+#             */
/*   Updated: 2023/08/26 16:44:37 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

// ===== Canonical class elements =====

WrongDog::WrongDog( void ) : WrongAnimal( "WrongDog" )
{
	std::cout << "[WrongDog] Default constructor called" << std::endl;
}

WrongDog::WrongDog ( WrongDog const & model) : WrongAnimal( model )
{
	std::cout << "[WrongDog] Copy constructor called for " << model.type << std::endl;
}

WrongDog::~WrongDog( void )
{
	std::cout << "[WrongDog] Default destructor for " << this->type << std::endl;
}

WrongDog & WrongDog::operator=(WrongDog const & model )
{
	this->type = model.type;
	return (*this); 
}

// ---- End: Canonical class elements ----



// ==== Member functions ====

void WrongDog::makeSound( void ) const
{
	std::cout << "Miaou!" << std::endl;
}

// ---- Member functions ----
