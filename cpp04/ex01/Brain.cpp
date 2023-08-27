/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:46:35 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 16:46:57 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// ==== Canonical form ====

Brain::Brain( void )
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Brain] Default constructor called" << CBLACK << std::endl;
	for (int i = 0; i < BRAIN_SIZE; i++)
		this->setIdea(i, "");
}

Brain::Brain( std::string ideas[BRAIN_SIZE] )
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Brain] Param constructor called" << CBLACK << std::endl;
	for (int i = 0; i < BRAIN_SIZE; i++)
		this->setIdea(i, ideas[i]);
}

Brain::Brain( Brain const & model)
{
	std::cout << CONSTRUCTOR_COLOR <<  "[Brain] Copy constructor called" << CBLACK << std::endl;
	for (int i = 0; i < BRAIN_SIZE; i++)
		this->setIdea(i, model.getIdea(i));
}

Brain::~Brain( void )
{
	std::cout << DESTRUCTOR_COLOR <<  "[Brain] Default destructor called" << CBLACK << std::endl;
}

Brain & Brain::operator=(Brain const & model)
{
	for (int i = 0; i < BRAIN_SIZE; i++)
		this->setIdea(i, model.getIdea(i));
	return (*this);
}

// ---- End: Canonical form ----


// ==== Mumber functions ====

void	Brain::setIdea(int index, std::string newIdea)
{
	if (index < 0 || index >= BRAIN_SIZE)
	{
		std::cout << "setIdea error: " << index << " isn't a valid index for an idea. It must be positive and strictly inferior to " << BRAIN_SIZE << std::endl;
	}
	else
		this->ideas[index] = newIdea;
}

void	Brain::setIdeas(std::string newIdeas[BRAIN_SIZE])
{
	for (int i = 0; i < BRAIN_SIZE; )
		this->setIdea(i, newIdeas[i]);
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= BRAIN_SIZE)
	{
		std::cout << "getidea error: " <<  index << " isn't a valid index for an idea. It must be positive and strictly inferior to " << BRAIN_SIZE << std::endl;
		return ("");
	}
	else
		return (this->ideas[index]);
}

// ---- End: Mumber functions ----
