/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:15:41 by acardona          #+#    #+#             */
/*   Updated: 2023/09/14 23:12:20 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ==== Canonical elements ====

AForm::AForm( void ) : _name(""), _grade_signature(0), _grade_execution(0)
{
	throw (AForm::GradeTooLowException());
}

AForm::AForm( std::string name, int grade_signature, int grade_execution, bool is_signed ) : _name(name), _grade_signature(grade_signature), _grade_execution(grade_execution), _signed(is_signed)
{
	if (grade_signature < HIGHEST_GRADE || grade_execution < HIGHEST_GRADE)
		throw(AForm::GradeTooHighException());
	if (grade_signature > LOWEST_GRADE || grade_execution > LOWEST_GRADE)
		throw(AForm::GradeTooLowException());
}
AForm::AForm(AForm const & model) : _name(model.getName()), _grade_signature(model.getGradeSignature()), _grade_execution(model.getGradeExecution()), _signed(model.getSigned())
{
}

AForm::~AForm( void )
{
}

AForm & AForm::operator=(AForm const & model)
{
	if (this == & model)
		return (*this);
	this->_signed = model.getSigned();
	return (*this);
}

// ---- End: Canonical elements ----


// ==== Accessors ====

std::string	AForm::getName( void ) const
{
	return (this->_name);
}

bool		AForm::getSigned( void ) const
{
	return (this->_signed);
}

int			AForm::getGradeSignature( void ) const
{
	return (this->_grade_signature);
}

int			AForm::getGradeExecution( void ) const
{
	return (this->_grade_execution);
}

// ---- End: Accessors ----



// ==== mumber functions ====

void	AForm::beSigned( Bureaucrat const & Bob)
{
	if (Bob.getGrade() > this->_grade_signature)
		throw(AForm::GradeTooLowException());
	if (this->getSigned())
		std::cout << "* Signed again *" << std::endl;
	else
		std::cout << "* Signed *" << std::endl;
	this->_signed = true;
}

bool	AForm::checkExecGrade( Bureaucrat const & executor) const
{
	return (executor.getGrade() <= this->_grade_execution);
}

// ---- End: mumber functions ----



// ==== streams redirections ====

std::ostream & operator<<(std::ostream & o, AForm const & elem)
{
	std::cout << elem.getName() << ", grade signature : " << elem.getGradeSignature() << ", grade execution: " << elem.getGradeExecution() << ", signed: " << (elem.getSigned() ? "yes" : "no") << ".";
	return (o);
}

// ---- End: streams redirections ----



// ==== Exceptions ====

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

// ---- End: Exceptions ----
