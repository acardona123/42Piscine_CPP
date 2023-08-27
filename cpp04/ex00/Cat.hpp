/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:37:19 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 12:03:52 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat ( void );
		Cat ( Cat const & model);
		~Cat ( void );
		Cat & operator=(Cat const & model);
		void makeSound( void ) const;
};

#endif