/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:47:28 by acardona          #+#    #+#             */
/*   Updated: 2023/09/08 19:31:26 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include <iostream>

#include "colors.hpp"

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define MATERIA_MEMORY_SIZE 4

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const & model);
		~MateriaSource( void );
		MateriaSource & operator=( MateriaSource const & model );

		AMateria* getMateria(unsigned int idx) const;

		void learnMateria(AMateria* model);
		AMateria* createMateria(std::string const & type);
	private:
		AMateria	*_saved[MATERIA_MEMORY_SIZE];
};

#endif