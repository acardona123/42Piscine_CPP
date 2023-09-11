/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:58:40 by acardona          #+#    #+#             */
/*   Updated: 2023/09/11 17:21:51 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// ==== Canonical elemtents ==== 

Cure::Cure( void ) : AMateria( "cure")
{
	std::cout << CBLUE << "   [Cure] Default constructor called" << CBLACK << std::endl;
}

Cure::Cure( Cure const & model) : AMateria(model)
{
	std::cout << CBLUE << "   [Cure] Copy constructor called" << CBLACK << std::endl;
}

Cure::~Cure( void )
{
	std::cout << CYELLOW << "   [Cure] Default destructor called" << CBLACK << std::endl;
}

Cure & Cure::operator=(Cure const & model)
{
	(void) model;
	//nothing to assign (the subject indicates that the type shouldn't be copied
	return (*this);
}

// ---- End: Canonical elemtents ---- End: 



// ==== Member functions ====

Cure	*Cure::clone( void )const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

// ---- Member functions ----
