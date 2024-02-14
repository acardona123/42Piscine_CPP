/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_vector.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:34:12 by acardona          #+#    #+#             */
/*   Updated: 2024/02/14 21:55:11 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTVECTOR_HPP
#define SORTVECTOR_HPP

#include "shared.hpp"
#include <vector>

#define VERBOSE_STEP_BY_STEP false

typedef std::vector<unsigned int> vectorUnsigned;
typedef std::vector< std::pair<unsigned int, unsigned int> > vectorPairs;

void			displayVector(vectorUnsigned const toDisplay);
void			displayPairsVector(vectorPairs const toDisplay);

template <typename T> std::vector< std::pair<T, T> > pairElements(std::vector<T> elementsToPair, unpaired &unpaired)
{
	unpaired.isUnpaired = elementsToPair.size() % 2 ? ONE_UNPAIRED_ELEMENT : NO_UNPAIRED_ELEMENT;
	unpaired.unpairedValue = unpaired.isUnpaired ? *(elementsToPair.end() -1) : 0;
	std::vector< std::pair<T, T> > pairedElements;
	pairedElements.reserve(elementsToPair.size() / 2);
	for (unsigned int i = 0; i < elementsToPair.size() - elementsToPair.size() % 2; i += 2)
	{
		pairedElements.push_back(std::pair<T, T> (elementsToPair[i], elementsToPair[i + 1]));
	}
	return (pairedElements);
}

successStatus	sortVector(char **args, bool verbose);

successStatus	GetvaluesToSort(char **inputElements, vectorUnsigned &dest );
successStatus	getIntFromInput(std::string ValueInput,
					unsigned int &destConvertion);

void			MergeInsertVector(vectorUnsigned &toSort);
void			sortElementsInPairs(vectorPairs & paired);
void			mergeSortPairs(vectorPairs & toSort,
					vectorPairs::iterator itStart, vectorPairs::iterator itEnd);
vectorUnsigned	extractMax(vectorPairs & sortedPairs);
void			insertFirstMin(vectorPairs & sortedPairs,
					vectorUnsigned & sortedValues);
void			insertMins(vectorPairs & sortedPairs, vectorUnsigned & sortedValues,
					t_unpaired & unpairedElement);
void			insertJacobsthalGroup(
					vectorPairs::iterator pairsIndexGroupStart,
					unsigned long int groupSize,
					vectorUnsigned & sortedValues);
#endif