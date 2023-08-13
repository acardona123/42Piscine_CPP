/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:56:32 by alexcardona       #+#    #+#             */
/*   Updated: 2023/08/01 17:50:27 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <limits>

class Zombie
{
	public:
		Zombie( std::string new_name );
		Zombie( void );
		~Zombie( void );
		void		announce( void );
		void		set_name(std::string name);
		std::string	get_name( void ) const;
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif