/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:36:39 by acardona          #+#    #+#             */
/*   Updated: 2023/09/11 21:20:55 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// ===== Canonical class elements =====

Cat::Cat( void ) : Animal( "Cat" )
{
	std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat ( Cat const & model ) : Animal( model )
{
	std::cout << "[Cat] Copy constructor called for " << model.type << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "[Cat] Default destructor for " << this->type << std::endl;
}

Cat & Cat::operator=(Cat const & model )
{
	this->type = model.type;
	return (*this); 
}

// ---- End: Canonical class elements ----



// ==== Member functions ====

void Cat::makeSound( void ) const
{
	std::cout << "Miaou!" << std::endl;
}

// ---- Member functions ----
