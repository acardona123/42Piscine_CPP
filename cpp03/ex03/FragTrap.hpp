/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:02:19 by acardona          #+#    #+#             */
/*   Updated: 2023/08/30 15:23:41 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#define INIT_FRAGTRAP_HIT 100
#define INIT_FRAGTRAP_ENERGY 100
#define INIT_FRAGTRAP_ATTACK 30

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap( std::string name );
		FragTrap( FragTrap const & model); 
		~FragTrap( void );
		FragTrap & operator=( FragTrap const & model);
		void	highFivesGuys(void);
	private:
		FragTrap( void );
};

#endif