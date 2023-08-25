/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:02:19 by acardona          #+#    #+#             */
/*   Updated: 2023/08/25 16:39:50 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#define INIT_SCAVTRAP_HIT 100
#define INIT_SCAVTRAP_ENERGY 50
#define INIT_SCAVTRAP_ATT 20

typedef enum e_mode
{
	NORMAL,
	GUARD_GATE
}	t_mode;

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & model); 
		~ScavTrap( void );
		ScavTrap & operator=( ScavTrap const & model);
		void	guardGate();
		void	showStatus( void );//
	private:
		ScavTrap( void );
		t_mode	_Mode;
};

#endif