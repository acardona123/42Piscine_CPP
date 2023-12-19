/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:05:20 by acardona          #+#    #+#             */
/*   Updated: 2023/12/19 15:46:34 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
	Form		*new_form;
	Intern		futurBoss;
	Bureaucrat	currentBoss("Macron", 1);

	std::cout << "==== wrong name ====" << std::endl;
	new_form = futurBoss.makeForm("toto", "superTarget");

	std::cout << std::endl << "==== shrubbery creation ====" << std::endl;
	new_form = futurBoss.makeForm("shrubbery creation", "superTarget");
	std::cout << "new form:" << std::endl << *new_form << std::endl;
	currentBoss.signForm(new_form);
	currentBoss.executeForm(new_form);
	delete new_form;

	std::cout << std::endl << "==== Robotomy request ====" << std::endl;
	new_form = futurBoss.makeForm("robotomy request", "superTarget");
	std::cout << "new form:" << std::endl << *new_form << std::endl;
	currentBoss.signForm(new_form);
	currentBoss.executeForm(new_form);
	delete new_form;

	std::cout << std::endl << "==== Presidential pardon ====" << std::endl;
	new_form = futurBoss.makeForm("presidential pardon", "superTarget");
	std::cout << "new form:" << std::endl << *new_form << std::endl;
	currentBoss.signForm(new_form);
	currentBoss.executeForm(new_form);
	delete new_form;

	return (0);
}
