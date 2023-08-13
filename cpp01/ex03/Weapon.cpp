/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:31:37 by acardona          #+#    #+#             */
/*   Updated: 2023/08/04 16:38:40 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon( void )
{
	return ;
}

void Weapon::setType( std::string new_type)
{
	this->type = new_type;
	return;
}

std::string Weapon::getType( void ) const
{
	return (this->type);
}