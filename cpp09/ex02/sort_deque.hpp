/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_deque.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:36:06 by acardona          #+#    #+#             */
/*   Updated: 2024/02/15 19:55:27 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_DEQUE_HPP
#define SORT_DEQUE_HPP

#include "shared.hpp"

#include <deque>

#define VERBOSE_STEP_BY_STEP_DEQUE false

typedef std::deque<unsigned int> dequeUnsigned;
typedef std::deque< std::pair<unsigned int, unsigned int> > dequePairs;

void			displayDeque(dequeUnsigned const toDisplay);
void			displayPairsDeque(dequePairs const toDisplay);

template <typename T> std::deque< std::pair<T, T> > pairElements(std::deque<T> elementsToPair, unpaired &unpaired)
{
	unpaired.isUnpaired = elementsToPair.size() % 2 ? ONE_UNPAIRED_ELEMENT : NO_UNPAIRED_ELEMENT;
	unpaired.unpairedValue = unpaired.isUnpaired ? *(elementsToPair.end() -1) : 0;
	std::deque< std::pair<T, T> > pairedElements;
	for (unsigned int i = 0; i < elementsToPair.size() - elementsToPair.size() % 2; i += 2)
	{
		pairedElements.push_back(std::pair<T, T> (elementsToPair[i], elementsToPair[i + 1]));
	}
	return (pairedElements);
}

successStatus	sortDeque(char **args, bool verbose);

successStatus	GetvaluesToSort(char **inputElements, dequeUnsigned &dest );
successStatus	getIntFromInput(std::string ValueInput,
					unsigned int &destConvertion);

void			MergeInsertDeque(dequeUnsigned &toSort);
void			sortElementsInPairs(dequePairs & paired);
void			mergeSortPairs(dequePairs & toSort,
					dequePairs::iterator itStart, dequePairs::iterator itEnd);
dequeUnsigned	extractMax(dequePairs & sortedPairs);
void			insertFirstMin(dequePairs & sortedPairs,
					dequeUnsigned & sortedValues);
void			insertMins(dequePairs & sortedPairs, dequeUnsigned & sortedValues,
					t_unpaired & unpairedElement);
void			insertJacobsthalGroup(
					dequePairs::iterator pairsIndexGroupStart,
					unsigned long int groupSize,
					dequeUnsigned & sortedValues);

#endif