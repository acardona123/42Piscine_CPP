/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrapTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:48:32 by acardona          #+#    #+#             */
/*   Updated: 2023/08/30 16:52:08 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap
{
	public:
		DiamondTrap( std::string Name);
		DiamondTrap( DiamondTrap const & model );
		~DiamondTrap( void );
		DiamondTrap & operator=(DiamondTrap const & model);
		
		void 	attack(const std::string& target);
		void	whoAmI();
	private:
		DiamondTrap( void );
		std::string	_Name;
};

#endif