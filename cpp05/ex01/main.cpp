/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:05:20 by acardona          #+#    #+#             */
/*   Updated: 2023/12/18 19:03:44 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{

	std::cout << "=== Invalid grades ====" << std::endl << std::endl;
	
	try
	{
		std::cout << "Form1 0 10" << std::endl;
		Form form ("Form1", 0, 10);
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" << e.what() << "\e[0m";
	}

	std::cout << std::endl;
	
	try
	{
		std::cout << "Form1 10 0" << std::endl;
		Form form ("Form1", 10, 0);
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" << e.what() << "\e[0m";
	}

	std::cout << std::endl;
	
	try
	{
		std::cout << "Form1 10 " << LOWEST_GRADE + 1 << std::endl;
		Form form ("Form1", 10, LOWEST_GRADE + 1);
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" << e.what() << "\e[0m";
	}

	try
	{
		std::cout << "Form1 " << LOWEST_GRADE + 1 << " 10" << std::endl;
		Form form ("Form1", LOWEST_GRADE + 1, 10);
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" << e.what() << "\e[0m";
	}

	std::cout << std::endl;


	std::cout << "--- End: Invalid grades ---=" << std::endl << std::endl;

	

	std::cout << "=== Valid grades ====" << std::endl << std::endl;
	
	try
	{
		std::cout << "- \e[0;4mBureaucrat::sign\e[0m" << std::endl << std::endl;
		Form form ("Form1", 10, 5);
		std::cout << form << std::endl << std::endl;
		
		Bureaucrat toto ("Toto", 11);
		std::cout << toto << std::endl;
		toto.signForm(form);
		std::cout << form << std::endl << std::endl;

		toto.upgrade();
		std::cout << toto << std::endl;
		toto.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" << e.what() << "\e[0m";
	}

	std::cout << std::endl;

	try
	{
		std::cout << "- \e[0;4mForm::beSigned\e[0m" << std::endl;
		Form form ("Form2", 10, 5);
		std::cout << form << std::endl;
		Bureaucrat toto ("Toto", 11);
		std::cout << toto << std::endl;
		form.beSigned(toto);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" << e.what() << "\e[0m";
	}

	std::cout << std::endl;

	try
	{
		Form form ("Form2", 10, 5);
		std::cout << form << std::endl;
		Bureaucrat toto ("Toto", 9);
		std::cout << toto << std::endl;
		form.beSigned(toto);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" << e.what() << "\e[0m";
	}
	

	std::cout << std::endl << "--- End: Valid grades ---" << std::endl;

	return (0);
}