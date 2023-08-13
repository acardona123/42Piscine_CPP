/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:14:59 by acardona          #+#    #+#             */
/*   Updated: 2023/08/04 16:51:28 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	public :
		HumanB ( std::string name);
		~HumanB ( void );
		std::string	name;
		Weapon		*weapon;
		void		setWeapon(Weapon &new_weapon);
		void		attack(void);
};

#endif