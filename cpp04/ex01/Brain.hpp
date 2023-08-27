/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:47:11 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 16:45:03 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#include "colors.hpp"
#define CONSTRUCTOR_COLOR CBLUE
#define DESTRUCTOR_COLOR CYELLOW

#define BRAIN_SIZE 100

class Brain
{
	public:
		Brain( void );
		Brain( std::string ideas[BRAIN_SIZE] );
		Brain( Brain const & model);
		~Brain( void );
		Brain & operator=(Brain const & model);
		
		std::string ideas[BRAIN_SIZE];
		
		void		setIdea(int index, std::string newIdea);
		void		setIdeas(std::string newIdeas[BRAIN_SIZE]);
		std::string getIdea(int index) const;
};


#endif