/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:24:50 by acardona          #+#    #+#             */
/*   Updated: 2024/02/14 22:11:20 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_deque.hpp"
#include "sort_vector.hpp"
#include "shared.hpp"
#include <ctime>

double	sortAndMeasureExecutionTime(std::string ContainerName,
			sortAlgo sort, char **toSort, int elementCount);

int main(int ac, char **arg)
{
	if (ac < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	char	**toSort = arg + 1;
	int		elementCount = ac - 1;

	sortAlgo	algoContainer1 = sortVector;
	std::string	nameContainer1 = "std::vector";
	double		executionTimeContainer1;

	sortAlgo 	algoContainer2 = sortDeque;
	std::string	nameContainer2 = "std::deque";
	double		executionTimeContainer2;

	algoContainer1(toSort, true);
	executionTimeContainer1 = sortAndMeasureExecutionTime(nameContainer1, algoContainer1, toSort, elementCount);
	executionTimeContainer2 = sortAndMeasureExecutionTime(nameContainer2, algoContainer2, toSort, elementCount);


	return (0);
}

double	sortAndMeasureExecutionTime(std::string containerName,
			sortAlgo sort, char **toSort, int elementCount)
{
	clock_t			start, end;
	successStatus	sortedSuccessfully;

	start = clock();
	sortedSuccessfully = (*sort)(toSort, false);
	end = clock();

	if (sortedSuccessfully == SUCCESS)
		std::cout << "Time to process a range of " << elementCount
			<< " elements with " << containerName << " : " << std::setprecision(5)
			<< (double(end - start) / double(CLOCKS_PER_SEC)) * 1e6 << "us" << std::endl;
	return (double(end - start) / double(CLOCKS_PER_SEC));
}


