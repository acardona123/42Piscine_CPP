/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:34:06 by acardona          #+#    #+#             */
/*   Updated: 2023/12/18 21:20:09 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// ==== Canonical elements ====

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form( "robotomy request", ROBOTOMYREQUESTCREATIONFORM_SIGN, ROBOTOMYREQUESTCREATIONFORM_EXEC ), _target(target)
{
	srand (time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & model ) : Form(model), _target(model.getTarget()) 
{
	srand (time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & model )
{
	if (this == &model)
		return (*this);
	Form::operator=(model);
	this->_target = model.getTarget();
	return (*this);
}

// ---- End: Canonical elements ----



// ==== Members functions ====

std::string RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (!this->getSigned())
		throw(Form::FormNotSignedException());
	if (!this->checkExecGrade(executor))
		throw(Form::GradeTooLowException());
	try
	{
		std::cout << "[drilling noise] RRRRRRRRrrrrRRRRRrrrrRRRrrrrRRrrrrRrr" << std::endl;
		if (rand() % 2)
			std::cout << this->_target << " has been robotomized" << std::endl;
		else
			std::cout << "The robotomy of " << this->_target << " failed" << std::endl;
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	}
	catch (std::exception & e)
	{
		throw ;
	}
}

// ---- Members functions ----


std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & elem)
{
	std::cout << static_cast<const Form&>(elem) << " Target: " << elem.getTarget() << "." << std::endl;
	return (o);
}
