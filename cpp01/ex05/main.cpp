/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:23:49 by acardona          #+#    #+#             */
/*   Updated: 2023/08/13 18:29:34 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{
	std::string	level_input("");
	Harl	harl;

	while (true)
	{
		std::cout << "Please enter the level you want Harl to apply as a complain : ";
		std::cin >> level_input;
		harl.complain(level_input);
		std::cout << std::endl << "Harld would like to complain more, can he continue ? (y/n) ";
		std::cin >> level_input;
		if (level_input != "y")
			return (0);
		else
			std::cout << std::endl;		
	}
	return (0);
}