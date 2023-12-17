/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:34:06 by acardona          #+#    #+#             */
/*   Updated: 2023/09/18 16:01:23 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// ==== Canonical elements ====

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm( target + "_shrubbery", SHRUBBERYCREATIONFORM_SIGN, SHRUBBERYCREATIONFORM_EXEC ), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & model ) : AForm(model), _target(model.getTarget()) 
{
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & model )
{
	if (this == &model)
		return (*this);
	AForm::operator=(model);
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
		throw(AForm::FormNotSignedException());
	if (!this->checkExecGrade(executor))
		throw(AForm::GradeTooLowException());
	try
	{
		std::ofstream outFile((this->_target + "_shrubbery").c_str());
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
