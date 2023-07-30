/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexcardona <alexcardona@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:58:24 by alexcardona       #+#    #+#             */
/*   Updated: 2023/07/29 17:58:26 by alexcardona      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++)
	{
		std::string test (av[i]);
		for (std::string::size_type j = 0; j < test.size(); j++)
			std::cout << static_cast <unsigned char> (std::toupper(test[j]));
	}
std::cout << std::endl;
	return 0;
}