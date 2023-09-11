/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:32:08 by acardona          #+#    #+#             */
/*   Updated: 2023/09/08 19:58:28 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#include "colors.hpp"

#include "IChararcter.hpp"

class AMateria
{
	protected:
		std::string	_type;
	
	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & model);
		virtual	~AMateria( void );
		virtual AMateria & operator=( AMateria const & model);
	
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	private:
		AMateria( void );
};

#endif