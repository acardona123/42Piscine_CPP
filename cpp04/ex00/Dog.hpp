/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:17:22 by acardona          #+#    #+#             */
/*   Updated: 2023/08/26 16:58:25 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog ( void );
		Dog ( Dog const & model);
		~Dog ( void );
		Dog & operator=(Dog const & model);
		void makeSound( void ) const;
};

#endif