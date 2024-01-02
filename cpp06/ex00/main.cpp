/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:16:43 by acardona          #+#    #+#             */
/*   Updated: 2024/01/02 23:24:38 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error:" << std::endl << "wrong number or arguments, expects one" << std::endl;
		return 1;
	}

	std::string str(av[1]);
	ScalarConverter::convert(str);
	return (0);
}