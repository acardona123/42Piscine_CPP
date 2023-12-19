/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:34:06 by acardona          #+#    #+#             */
/*   Updated: 2023/12/18 21:19:48 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// ==== Canonical elements ====

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form( "presidential pardon", PRESIDENCIALPARDONFORM_SIGN, PRESIDENCIALPARDONFORM_EXEC ), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & model ) : Form(model), _target(model.getTarget()) 
{
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & model )
{
	if (this == &model)
		return (*this);
	Form::operator=(model);
	this->_target = model.getTarget();
	return (*this);
}

// ---- End: Canonical elements ----



// ==== Members functions ====

std::string PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (!this->getSigned())
		throw(Form::FormNotSignedException());
	if (!this->checkExecGrade(executor))
		throw(Form::GradeTooLowException());
	try
	{
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	}
	catch (std::exception & e)
	{
		throw ;
	}
}

// ---- Members functions ----





std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & elem)
{
	std::cout << static_cast<const Form&>(elem) << " Target: " << elem.getTarget() << "." << std::endl;
	return (o);
}