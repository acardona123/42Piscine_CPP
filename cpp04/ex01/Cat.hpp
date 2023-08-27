/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:37:19 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 16:45:30 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "colors.hpp"
#define CONSTRUCTOR_COLOR CBLUE
#define DESTRUCTOR_COLOR CYELLOW

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat ( void );
		Cat (std::string ideas[BRAIN_SIZE]);
		Cat ( Cat const & model);
		~Cat ( void );
		Cat & operator=(Cat const & model);
		void makeSound( void ) const;
		Brain	*getBrain( void ) const;
	private:
		Brain	*_brain;
};

#endif