/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:17:22 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 18:37:38 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "colors.hpp"
#define CONSTRUCTOR_COLOR CBLUE
#define DESTRUCTOR_COLOR CYELLOW

#include "Aanimal.hpp"
#include "Brain.hpp"

class Dog : public Aanimal
{
	public:
		Dog ( void );
		Dog (std::string ideas[BRAIN_SIZE]);
		Dog ( Dog const & model);
		~Dog ( void );
		Dog & operator=(Dog const & model);
		void makeSound( void ) const;
		Brain	*getBrain( void ) const;
	private:
		Brain	*_brain;
};

#endif