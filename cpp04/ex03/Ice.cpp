/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:13:30 by acardona          #+#    #+#             */
/*   Updated: 2023/09/11 17:22:20 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// ==== Canonical elemtents ==== 

Ice::Ice( void ) : AMateria( "ice")
{
	std::cout << CBLUE << "   [Ice] Default constructor called" << CBLACK << std::endl;
}

Ice::Ice( Ice const & model) : AMateria(model)
{
	std::cout << CBLUE << "   [Ice] Copy constructor called" << CBLACK << std::endl;
}

Ice::~Ice( void )
{
	std::cout << CYELLOW << "   [Ice] Default destructor called" << CBLACK << std::endl;
}

Ice & Ice::operator=(Ice const & model)
{
	//nothing to assign (the subject indicates that the type shouldn't be copied
	(void) model;
	return (*this);
}

// ---- End: Canonical elemtents ---- End: 



// ==== Member functions ====

Ice	*Ice::clone( void )const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

// ---- Member functions ----

