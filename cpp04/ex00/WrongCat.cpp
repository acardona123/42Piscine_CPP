/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:36:39 by acardona          #+#    #+#             */
/*   Updated: 2023/08/26 16:44:22 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// ===== Canonical class elements =====

WrongCat::WrongCat( void ) : WrongAnimal( "WrongCat" )
{
	std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat ( WrongCat const & model) : WrongAnimal( model.type )
{
	std::cout << "[WrongCat] Copy constructor called for " << model.type << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "[WrongCat] Default destructor for " << this->type << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & model )
{
	this->type = model.type;
	return (*this); 
}

// ---- End: Canonical class elements ----



// ==== Member functions ====

void WrongCat::makeSound( void ) const
{
	std::cout << "Waf!" << std::endl;
}

// ---- Member functions ----
