/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:07:55 by acardona          #+#    #+#             */
/*   Updated: 2023/09/07 19:15:45 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include <iostream>

#include "main.hpp"
#include "colors.hpp"

#include "AMateria.hpp"

class Cure : public AMateria
{
	public :
		Cure( void );
		Cure( Cure const & model );
		~Cure( void );
		Cure & operator=(Cure const & model);
	
		Cure	*clone( void )const;
		void use(ICharacter& target);

};

#endif