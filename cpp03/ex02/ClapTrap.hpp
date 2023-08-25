/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:54 by acardona          #+#    #+#             */
/*   Updated: 2023/08/25 16:36:33 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

#define INIT_CLAPTRAP_HIT 10
#define INIT_CLAPTRAP_ENERGY 10
#define INIT_CLAPTRAP_ATTACK 0

class ClapTrap
{
	protected:
		ClapTrap( void );
		std::string		_Name;
		unsigned int	_HitPoints;
		unsigned int	_EnergyPoints;
		unsigned int	_AttackDamage;
		
	public:
		ClapTrap( std::string name);
		ClapTrap ( ClapTrap const & elem);
		~ClapTrap( void );
		ClapTrap & operator=(ClapTrap const & model);
		
		void 	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	showStatus( void );//
};

#endif