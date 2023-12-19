/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:05:20 by acardona          #+#    #+#             */
/*   Updated: 2023/12/18 18:42:24 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	try
	{
		Bureaucrat toto ("Toto", 0);
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" <<  e.what() << "\e[0m" << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Bureaucrat toto ("Toto", LOWEST_GRADE + 1);
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" <<  e.what() << "\e[0m" << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat toto ("Toto", 2);
		std::cout << toto << std::endl;
		toto.upgrade();
		std::cout << toto << std::endl;
		toto.upgrade();
		std::cout << toto << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" <<  e.what() << "\e[0m" << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Bureaucrat toto ("Toto", LOWEST_GRADE - 1);
		std::cout << toto << std::endl;
		toto.downgrade();
		std::cout << toto << std::endl;
		toto.downgrade();
		std::cout << toto << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "\e[31m" <<  e.what() << "\e[0m" << std::endl;
	}
	
	return (0);
}