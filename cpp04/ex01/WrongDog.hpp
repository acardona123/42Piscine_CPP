/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:17:22 by acardona          #+#    #+#             */
/*   Updated: 2023/08/26 17:01:54 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public:
		WrongDog ( void );
		WrongDog ( WrongDog const & model);
		~WrongDog ( void );
		WrongDog & operator=(WrongDog const & model);
		void makeSound( void ) const;
};

#endif