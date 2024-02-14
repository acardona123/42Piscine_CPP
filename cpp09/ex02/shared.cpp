/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:23:57 by acardona          #+#    #+#             */
/*   Updated: 2024/02/13 20:00:50 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.hpp"

successStatus	getIntFromInput(std::string ValueInput, unsigned int &destConvertion)
{
	if (ValueInput.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Error : " << ValueInput << ": Incorrect format" << std::endl;
		return FAILURE;
	}
	unsigned int	n (std::atoi(ValueInput.c_str()));
	std::string		str_conv = static_cast<const std::ostringstream&>((std::ostringstream() << std::dec << n)).str();
	if (str_conv != ValueInput)
	{
		std::cout << "Error : " << ValueInput << ": wrong format or overflow" << std::endl;
		return FAILURE;
	}
	destConvertion = n;
	return (SUCCESS);
}
