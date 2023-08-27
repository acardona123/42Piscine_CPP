/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:35:29 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 18:36:34 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aanimal.hpp"

// ===== Canonical class elements =====

Aanimal::Aanimal( void )
{
	this->type = "Unknown_animal_type";
	std::cout << CONSTRUCTOR_COLOR <<  "[Aanimal] Default constructor called" << CBLACK << std::endl;
}

Aanimal::Aanimal( std::string type ) : type(type)
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Aanimal] Param constructor called for " << type << CBLACK << std::endl;
}

Aanimal::Aanimal ( Aanimal const & model) : type(model.type)
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Aanimal] Copy constructor called for " << model.type << CBLACK << std::endl;
}

Aanimal::~Aanimal( void )
{
	std::cout << DESTRUCTOR_COLOR <<  "[Aanimal] Default destructor for " << this->type << CBLACK << std::endl;
}

Aanimal & Aanimal::operator=(Aanimal const & model )
{
	this->type = model.type;
	return (*this); 
}

// ---- End: Canonical class elements ----



// ==== Mumber functions ====

std::string		Aanimal::getType( void ) const
{
	return (this->type);
}

// ---- End: Mumber functions ----
