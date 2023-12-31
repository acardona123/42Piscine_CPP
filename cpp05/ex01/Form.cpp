/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:15:41 by acardona          #+#    #+#             */
/*   Updated: 2023/09/18 16:30:35 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// ==== Canonical elements ====

Form::Form( void ) : _name(""), _grade_signature(0), _grade_execution(0)
{
	throw (Form::GradeTooLowException());
}

Form::Form( std::string name, int grade_signature, int grade_execution ) : _name(name), _grade_signature(grade_signature), _grade_execution(grade_execution), _signed(false)
{
	if (grade_signature < HIGHEST_GRADE || grade_execution < HIGHEST_GRADE)
		throw(Form::GradeTooHighException());
	if (grade_signature > LOWEST_GRADE || grade_execution > LOWEST_GRADE)
		throw(Form::GradeTooLowException());
}
Form::Form(Form const & model) : _name(model.getName()), _grade_signature(model.getGradeSignature()), _grade_execution(model.getGradeExecution()), _signed(model.getSigned())
{
}

Form::~Form( void )
{
}

Form & Form::operator=(Form const & model)
{
	if (this == & model)
		return (*this);
	this->_signed = model.getSigned();
	return (*this);
}

// ---- End: Canonical elements ----


// ==== Accessors ====

std::string	Form::getName( void ) const
{
	return (this->_name);
}

bool		Form::getSigned( void ) const
{
	return (this->_signed);
}

int			Form::getGradeSignature( void ) const
{
	return (this->_grade_signature);
}

int			Form::getGradeExecution( void ) const
{
	return (this->_grade_execution);
}

// ---- End: Accessors ----



// ==== mumber functions ====

void	Form::beSigned( Bureaucrat const & Bob)
{
	if (Bob.getGrade() > this->_grade_signature)
		throw(Form::GradeTooLowException());
	if (this->getSigned() && COMMENTARY_ON)
		std::cout << "* Signed again *" << std::endl;
	else if (COMMENTARY_ON)
		std::cout << "* Signed *" << std::endl;
	this->_signed = true;
}

// ---- End: mumber functions ----



// ==== streams redirections ====

std::ostream & operator<<(std::ostream & o, Form const & elem)
{
	std::cout << elem.getName() << ", grade signature : " << elem.getGradeSignature() << ", grade execution: " << elem.getGradeExecution() << ", signed: " << (elem.getSigned() ? "yes" : "no") << ".";
	return (o);
}

// ---- End: streams redirections ----



// ==== Exceptions ====

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

// ---- End: Exceptions ----
