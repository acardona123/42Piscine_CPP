/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:35:46 by acardona          #+#    #+#             */
/*   Updated: 2023/08/26 16:59:31 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	public:
		WrongAnimal( void );
		WrongAnimal ( std::string type);
		WrongAnimal (WrongAnimal const & model);
		virtual ~WrongAnimal( void );
		WrongAnimal & operator=(WrongAnimal const & model);
		
		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;
	protected:
		std::string	type;
		
};

#endif