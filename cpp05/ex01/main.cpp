/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:05:20 by acardona          #+#    #+#             */
/*   Updated: 2023/09/14 23:15:16 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
	try
	{
		std::cout << "Form1 0 10" << std::endl;
		Form form ("Form1", 0, 10);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		std::cout << "Form1 10 0" << std::endl;
		Form form ("Form1", 10, 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		std::cout << "Form1 10 " << LOWEST_GRADE + 1 << std::endl;
		Form form ("Form1", 10, LOWEST_GRADE + 1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		std::cout << "Form1 " << LOWEST_GRADE + 1 << " 10" << std::endl;
		Form form ("Form1", LOWEST_GRADE + 1, 10);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Form form ("Form1", 10, 20);
		std::cout << form << std::endl;
		Bureaucrat toto ("Toto", 11);
		std::cout << toto << std::endl;
		toto.signForm(form);
		std::cout << form << std::endl;
		toto.upGrade();
		std::cout << toto << std::endl;
		toto.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}

	std::cout << std::endl;

	try
	{
		Form form ("Form2", 10, 20);
		std::cout << form << std::endl;
		Bureaucrat toto ("Toto", 11);
		std::cout << toto << std::endl;
		form.beSigned(toto);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}

	std::cout << std::endl;

	try
	{
		Form form ("Form2", 10, 20);
		std::cout << form << std::endl;
		Bureaucrat toto ("Toto", 9);
		std::cout << toto << std::endl;
		form.beSigned(toto);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	
	return (0);
}