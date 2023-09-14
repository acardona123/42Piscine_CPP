/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:07:38 by acardona          #+#    #+#             */
/*   Updated: 2023/09/14 14:40:35 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// ==== Canonical elements ====

AMateria::AMateria( void ) : _type("unknown")
{
	std::cout << CBLUE << "   [AMateria] Default constructor called" << CBLACK << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
	std::cout << CBLUE << "   [AMateria] Param constructor called for " << type << CBLACK << std::endl;
}

AMateria::AMateria( AMateria const & model ) : _type(model.getType())
{
	std::cout << CBLUE << "   [AMateria] Copy constructor called" << CBLACK << std::endl;
}

AMateria::~AMateria( void )
{
	std::cout << CYELLOW << "   [AMateria] Default destructor called" << CBLACK << std::endl;
}

AMateria & AMateria::operator=( AMateria const & model)
{
	if (this != &model)
		this->_type = model._type;
	return (*this);
}

// ---- End: Canonical elements ----



// ==== Accessors ====

std::string const & AMateria::getType() const
{
	return (this->_type);
}

// ---- End: Accessors ----



// ==== Member functions ====

void AMateria::use(ICharacter &target)
{
	std::cout << "Undefined behavior of AMateria::use on " << target.getName() << std::endl;
}

// ---- End: Member functions ----
