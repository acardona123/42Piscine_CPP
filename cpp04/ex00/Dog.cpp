/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:26:28 by acardona          #+#    #+#             */
/*   Updated: 2023/09/11 21:23:52 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// ===== Canonical class elements =====

Dog::Dog( void ) : Animal( "Dog" )
{
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog ( Dog const & model) : Animal( model )
{
	std::cout << "[Dog] Copy constructor called for " << model.type << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "[Dog] Default destructor for " << this->type << std::endl;
}

Dog & Dog::operator=(Dog const & model )
{
	this->type = model.type;
	return (*this); 
}

// ---- End: Canonical class elements ----



// ==== Member functions ====

void Dog::makeSound( void ) const
{
	std::cout << "Waf!" << std::endl;
}

// ---- Member functions ----
