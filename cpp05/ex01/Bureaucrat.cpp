/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:04:08 by acardona          #+#    #+#             */
/*   Updated: 2023/09/14 23:13:32 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// ==== Canonical elements ====

Bureaucrat::Bureaucrat( void )
{
	throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < HIGHEST_GRADE)
		throw(Bureaucrat::GradeTooHighException());
	if (grade > LOWEST_GRADE)
		throw(Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat( Bureaucrat const & model) : _name(model.getName()), _grade(model.getGrade())
{
}

Bureaucrat::~Bureaucrat( void )
{
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &model)
{
	if (this == & model)
		return (*this);
	this->_grade = model.getGrade();
	return (*this);
}

// ---- End: Canonical elements ----



// ==== Accessors ====

std::string Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

// ---- End: Accessors ----


// ==== mumber functions ====

void	Bureaucrat::downGrade( void )
{
	if (this->_grade == LOWEST_GRADE)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade++;
}

void Bureaucrat::upGrade( void )
{
	if (this->_grade == HIGHEST_GRADE)
		throw(GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::signForm( Form & form )
{
	if (form.getSigned())
		std::cout << this->_name << " couldn't sign " << form.getName() << " because it's already signed." << std::endl;
	else if (form.getGradeSignature() < this->_grade)
		std::cout << this->_name << " couldn't sign " << form.getName() << " because it's grade is to low." << std::endl;
	else
		form.beSigned(*this);
}

// ---- End: mumber functions ----


// ==== Exceptions ====

const char * Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high\n");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

// ---- End: Exceptions ----


// ==== Stream overloading ====

std::ostream & operator<<(std::ostream & o, Bureaucrat const & elem)
{
	std::cout << elem.getName() << ", bureaucrat grade " << elem.getGrade() << ".";
	return (o);
}

// ---- End: Stream overloading ----
