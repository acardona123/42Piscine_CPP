/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:34:06 by acardona          #+#    #+#             */
/*   Updated: 2023/09/18 16:01:43 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// ==== Canonical elements ====

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm( target + "_RobotomyRequestForm", ROBOTOMYREQUESTCREATIONFORM_SIGN, ROBOTOMYREQUESTCREATIONFORM_EXEC ), _target(target)
{
	srand (time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & model ) : AForm(model), _target(model.getTarget()) 
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
	AForm::operator=(model);
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
		throw(AForm::FormNotSignedException());
	if (!this->checkExecGrade(executor))
		throw(AForm::GradeTooLowException());
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
