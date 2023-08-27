/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:35:46 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 16:45:09 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#include "colors.hpp"
#define CONSTRUCTOR_COLOR CBLUE
#define DESTRUCTOR_COLOR CYELLOW

class Animal
{
	public:
		Animal( void );
		Animal ( std::string type);
		Animal (Animal const & model);
		virtual ~Animal( void );
		Animal & operator=(Animal const & model);
		
		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;
	protected:
		std::string	type;
		
};

#endif