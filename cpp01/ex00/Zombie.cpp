/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:56:29 by alexcardona       #+#    #+#             */
/*   Updated: 2023/08/29 18:14:14 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


//============== construcor / destructor ==============

Zombie::Zombie( std::string new_name ) : name(new_name)
{
	std::cout << "[Zombie] Param constructor called for " << new_name << std::endl;
	return ;
}

Zombie::Zombie( void )
{
	std::cout << "[Zombie] Default constructor called" << std::endl;
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << "[Zombie] Default destructor called for " << this->name << std::endl;
}

//============== End : construcor / destructor ==============



//============== End : Zombie actions ==============

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//============== End : Zombie actions ==============
