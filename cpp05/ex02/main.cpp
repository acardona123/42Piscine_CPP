/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:05:20 by acardona          #+#    #+#             */
/*   Updated: 2023/12/17 19:35:21 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void _testSchrubberyCreationForm(void);
static void _testRobotomyRequestForm(void);
static void _testPresidentialPardonForm(void);

int main( void )
{
	
	_testSchrubberyCreationForm();
	std::cout << std::endl << std::endl;
	_testRobotomyRequestForm();
	std::cout << std::endl << std::endl;
	_testPresidentialPardonForm();
	
	return (0);
}

static void _testSchrubberyCreationForm(void)
{
	try
	{
		std::cout << "== SchrubberyCreationForm ==" << std::endl << std::endl;
		ShrubberyCreationForm form ("Home");
		std::cout << "- Bureaucrat BigBoss : 1" << std::endl;
		Bureaucrat boss("BigBoss", 1);
		try
		{
			form.execute(boss);
		}
		catch (std::exception & e)
		{
			std::cout << "\e[31m" << e.what() << "\e[0m" << std::endl;
		}
		// form.beSigned(boss);
		boss.signForm(&form);
		boss.executeForm(&form);
		std::cout << "- Bureaucrat mediore: " << SHRUBBERYCREATIONFORM_EXEC + 1 << std::endl;
		Bureaucrat medium("Mediocre", SHRUBBERYCREATIONFORM_EXEC + 1);
		form.beSigned(medium);
		form.execute(medium);
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout << std::endl << "-- End: SchrubberyCreationForm --" << std::endl << std::endl;
}

static void _testRobotomyRequestForm(void)
{
	try
	{
		std::cout << "== RobotomyRequestForm ==" << std::endl << std::endl;
		RobotomyRequestForm form ("Home");
		std::cout << "- Bureaucrat 1" << std::endl;
		Bureaucrat boss("BigBoss", 1);
		try
		{
			form.execute(boss);
		}
		catch (std::exception & e)
		{
			std::cout << "\e[31m" << e.what() << "\e[0m" << std::endl;
		}
		form.beSigned(boss);
		form.execute(boss);
		form.execute(boss);
		form.execute(boss);
		form.execute(boss);
		form.execute(boss);
		form.execute(boss);
		std::cout << "- Bureaucrat " << ROBOTOMYREQUESTCREATIONFORM_EXEC + 1 << std::endl;
		Bureaucrat medium("Mediocre", ROBOTOMYREQUESTCREATIONFORM_EXEC + 1);
		form.beSigned(medium);
		form.execute(medium);
	}
	
	catch (std::exception & e)
	{
		std::cout << "\e[31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout << std::endl << "-- End: RobotomyRequestForm --" << std::endl << std::endl;
}

static void _testPresidentialPardonForm(void)
{
	try
	{
		std::cout << "== PresidentialPardonForm ==" << std::endl << std::endl;
		PresidentialPardonForm form ("Home");
		std::cout << "- Bureaucrat 1" << std::endl;
		Bureaucrat boss("BigBoss", 1);
		try
		{
			form.execute(boss);
		}
		catch (std::exception & e)
		{
			std::cout << "\e[31m" << e.what() << "\e[0m" << std::endl;
		}
		form.beSigned(boss);
		form.execute(boss);
		std::cout << "- Bureaucrat " << PRESIDENCIALPARDONFORM_EXEC + 1 << std::endl;
		Bureaucrat medium("Mediocre", PRESIDENCIALPARDONFORM_EXEC + 1);
		form.beSigned(medium);
		form.execute(medium);
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout << std::endl << "-- End: PresidentialPardonForm --" << std::endl << std::endl;

}