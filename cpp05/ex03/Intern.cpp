/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:58:20 by acardona          #+#    #+#             */
/*   Updated: 2023/12/18 21:00:43 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//============ Caninocial ========

Intern::Intern(void)
{
}

Intern::Intern(Intern &model)
{
	(void)model;
}

Intern::~Intern(void)
{
}

Intern &Intern::operator=(Intern &model)
{
	(void)model;
	return (*this);
}

//============ End: caninocial ========


//============ Member functions ========


Form *Intern::_new_shrubbery_creation_new(std::string target)
{
	Form *newForm;

	try
	{
		newForm = new(ShrubberyCreationForm)(target);
	}
	catch (std::exception &e)
	{
		throw;
	}
	return (newForm);
}

Form *Intern::_new_robotomy_request_new(std::string target)
{
	Form *newForm;

	try
	{
		newForm = new(RobotomyRequestForm)(target);
	}
	catch (std::exception &e)
	{
		throw;
	}
	return (newForm);
}

Form *Intern::_new_presidiential_pardon_new(std::string target)
{
	Form *newForm;

	try
	{
		newForm = new(PresidentialPardonForm)(target);
	}
	catch (std::exception &e)
	{
		throw;
	}
	return (newForm);
}


Form *Intern::makeForm(std::string formName, std::string formTarget) const
{
	Form 						*newForm;
	static const std::string	formNamesList[3] = {"shrubbery creation",
									"robotomy request", "presidential pardon"};
	static formFunction			formFunctionsList[3] = {this->_new_shrubbery_creation_new,
									this->_new_robotomy_request_new,
									this->_new_presidiential_pardon_new};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNamesList[i])
		{
			try
			{
				newForm = formFunctionsList[i](formTarget);
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			if (newForm)
			{
				std::cout << "Intern creates " << formName << std::endl;
				return (newForm);
			}
		}
	}
	std::cout << "\"" << formName << "\" is a type of form that this poor intern doesn't know." << std::endl;
	return (NULL);
}

//============ End:member functions ========
