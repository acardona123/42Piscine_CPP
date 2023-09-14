/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:16:22 by acardona          #+#    #+#             */
/*   Updated: 2023/09/14 14:02:27 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

#include "colors.hpp"

#include "main.hpp"
#include "IChararcter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#define INVENTORY_SIZE	4

class Character : public ICharacter
{
	public:
		Character( Character const & model );
		Character( std::string name );
		~Character ( void );
		Character & operator=( Character const & model );
		
		std::string const & getName() const;
		AMateria * getMateria(unsigned int idx) const;
		
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		
	private:
		Character( void );
		AMateria	*_inventory[INVENTORY_SIZE];
		std::string	_Name;
	
};


#endif