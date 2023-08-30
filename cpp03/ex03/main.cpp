/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:30:34 by acardona          #+#    #+#             */
/*   Updated: 2023/08/30 17:05:56 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap first("theFirst");
	first.showStatus();
	first.whoAmI();
	std::cout << std::endl;

	
	DiamondTrap second(first);
	second.showStatus();
	second.whoAmI();
	std::cout << std::endl;
	
	return (0);
}