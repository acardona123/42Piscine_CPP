/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:07:55 by acardona          #+#    #+#             */
/*   Updated: 2023/09/14 14:02:38 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include <iostream>

#include "main.hpp"
#include "colors.hpp"

#include "AMateria.hpp"

class Ice : public AMateria
{
	public :
		Ice( void );
		Ice( Ice const & model );
		~Ice( void );
		Ice & operator=(Ice const & model);
	
		Ice	*clone( void )const;
		void use(ICharacter& target);

};

#endif