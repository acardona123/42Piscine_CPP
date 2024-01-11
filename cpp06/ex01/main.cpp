/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:11:54 by acardona          #+#    #+#             */
/*   Updated: 2024/01/11 15:47:07 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main ( void )
{
	Data toto = {};

	std::cout << "&toto = \t\t\t\t" << &toto << std::endl;
	std::cout << "deserialize(serialize(&toto)) = \t" << Serializer::deserialize(Serializer::serialize(&toto)) << std::endl; 
	return (0);
}
