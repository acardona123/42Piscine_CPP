/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:56:29 by alexcardona       #+#    #+#             */
/*   Updated: 2023/08/01 17:22:12 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


//============== construcor / destructor ==============

Zombie::Zombie( std::string new_name ) : name(new_name)
{
	return ;
}

Zombie::Zombie( void )
{
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << this->name << ": destroyed" << std::endl;
}

//============== End : construcor / destructor ==============



//============== End : Zombie actions ==============

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//============== End : Zombie actions ==============

void Zombie::set_name(std::string new_name)
{
	this->name = new_name;
}

std::string Zombie::get_name( void ) const
{
	return (this->name);
}