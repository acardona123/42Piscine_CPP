/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:34:28 by acardona          #+#    #+#             */
/*   Updated: 2024/02/14 22:02:49 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED
# define SHARED


# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <iomanip>
# include <cstdlib>
# include <algorithm>

typedef enum e_successStatus
{
	SUCCESS = 0,
	FAILURE
}	successStatus;

typedef enum e_checkIfUnpairedElement
{
	NO_UNPAIRED_ELEMENT,
	ONE_UNPAIRED_ELEMENT
} checkIfUnpairedElement;

typedef struct unpaired
{
	checkIfUnpairedElement	isUnpaired;
	unsigned int			unpairedValue;
}	t_unpaired;

typedef successStatus (*sortAlgo)(char **arg, bool verbose);

successStatus	getIntFromInput(std::string ValueInput, unsigned int &destConvertion);

#endif