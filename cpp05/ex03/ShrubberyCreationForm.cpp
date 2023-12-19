/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:34:06 by acardona          #+#    #+#             */
/*   Updated: 2023/12/18 21:20:22 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// ==== Canonical elements ====

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form( "shrubbery creation", SHRUBBERYCREATIONFORM_SIGN, SHRUBBERYCREATIONFORM_EXEC ), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & model ) : Form(model), _target(model.getTarget()) 
{
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & model )
{
	if (this == &model)
		return (*this);
	Form::operator=(model);
	this->_target = model.getTarget();
	return (*this);
}

// ---- End: Canonical elements ----



// ==== Members functions ====

std::string ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (!this->getSigned())
		throw(Form::FormNotSignedException());
	if (!this->checkExecGrade(executor))
		throw(Form::GradeTooLowException());
	try
	{
		std::ofstream outFile((this->_target).c_str());
		if (!outFile)
			throw(std::bad_exception());
		outFile << std::endl << \
		"        _-_ " << std::endl << \
		"     /~~   ~~\\ " << std::endl << \
		"  /~~         ~~\\ " << std::endl << \
		" {               } " << std::endl << \
		"  \\  _-     -_  / " << std::endl << \
		"    ~  \\ //  ~ " << std::endl << \
		" _- -   | | _- _ " << std::endl << \
		"   _ -  | |   -_ " << std::endl << \
		"       // \\\\";
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	}
	catch (std::exception & e)
	{
		throw ;
	}
}

// ---- Members functions ----


std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & elem)
{
	std::cout << static_cast<const Form&>(elem) << " Target: " << elem.getTarget() << "." << std::endl;
	return (o);
}
