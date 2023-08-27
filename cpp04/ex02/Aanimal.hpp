/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:35:46 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 18:36:23 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

#include "colors.hpp"
#define CONSTRUCTOR_COLOR CBLUE
#define DESTRUCTOR_COLOR CYELLOW

class Aanimal
{
	public:
		Aanimal( void );
		Aanimal ( std::string type);
		Aanimal (Aanimal const & model);
		virtual ~Aanimal( void );
		Aanimal & operator=(Aanimal const & model);
		
		std::string		getType( void ) const;
		virtual void	makeSound( void ) const = 0;
	protected:
		std::string	type;
		
};

#endif