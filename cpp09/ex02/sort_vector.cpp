/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sort_vector.cpp									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: acardona <acardona@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/28 23:31:52 by acardona		  #+#	#+#			 */
/*   Updated: 2024/02/13 21:57:24 by acardona		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

# include "sort_vector.hpp"

successStatus	sortVector(char **args, bool verbose)
{
	vectorUnsigned toSort;

	if (GetvaluesToSort(args, toSort) == FAILURE)
		return (FAILURE);
	if (verbose)
		std::cout << "\e[1mBefore :\e[0m ", displayVector(toSort);
	MergeInsertVector(toSort);
	if (verbose)
		std::cout << "\e[1mAfter :\e[0m ", displayVector(toSort);
	return (SUCCESS);
}

successStatus	GetvaluesToSort(char **inputElements, vectorUnsigned &dest )
{
	unsigned int 	argIndex = 0;
	unsigned int	NewIntValue;

	while (inputElements[argIndex])
	{
		if (getIntFromInput(inputElements[argIndex], NewIntValue) == FAILURE)
			return (FAILURE);
		dest.push_back(NewIntValue);
		++argIndex;
	}
	return (SUCCESS);
}

void MergeInsertVector(vectorUnsigned &toSort)
{
	t_unpaired unpairedElement; 

	if (toSort.size() <= 1)
		return ;

	vectorPairs toSortPaired = pairElements<unsigned int>(toSort, unpairedElement);
	if (VERBOSE_STEP_BY_STEP_VECTOR)
		std::cout << "Paired: ", displayPairsVector(toSortPaired),
			std::cout << "  unpaired elem ? "
			<< ((unpairedElement.isUnpaired == ONE_UNPAIRED_ELEMENT) ?
				"one unpaired":"No unpaired") <<  " -> "
			<< unpairedElement.unpairedValue << std::endl;

	sortElementsInPairs(toSortPaired);
	if (VERBOSE_STEP_BY_STEP_VECTOR)
		std::cout << "Inside of the pairs paired: ",
			displayPairsVector(toSortPaired);

	mergeSortPairs(toSortPaired, toSortPaired.begin(), toSortPaired.end());
	if (VERBOSE_STEP_BY_STEP_VECTOR)
		std::cout << "Sorted pairs: ",
			displayPairsVector(toSortPaired);

	toSort = extractMax(toSortPaired);
	if (VERBOSE_STEP_BY_STEP_VECTOR)
		std::cout << "Extract max: ", displayVector(toSort);

	insertFirstMin(toSortPaired, toSort);
	if (VERBOSE_STEP_BY_STEP_VECTOR)
		std::cout << "Insert first min: ", displayVector(toSort),
			std::cout << " -> ", displayPairsVector(toSortPaired);

	insertMins(toSortPaired, toSort, unpairedElement);
	if (VERBOSE_STEP_BY_STEP_VECTOR)
		std::cout << "Insert min: ", displayVector(toSort);
}

void	sortElementsInPairs(vectorPairs & paired)
{
	for (vectorPairs::iterator it = paired.begin(); it != paired.end(); ++it)
	{
		if ((*it).first < (*it).second)
			std::swap((*it).first,(*it).second);
	}
}

void	mergeSortPairs(vectorPairs & toSort, vectorPairs::iterator itStart, vectorPairs::iterator itEnd)
{
	unsigned int subSize = std::distance(itStart, itEnd);
	if ( subSize < 2)
		return;
	mergeSortPairs(toSort, itStart, itStart + subSize / 2);
	mergeSortPairs(toSort, itStart + subSize / 2, itEnd);
	vectorPairs sortedSubSectionLeft;
	vectorPairs sortedSubSectionRight;
	sortedSubSectionLeft.assign(itStart, itStart + subSize / 2);
	sortedSubSectionRight.assign(itStart + subSize / 2, itEnd);
	unsigned int	indexInSubvector = 0;
	while (!sortedSubSectionLeft.empty() && !sortedSubSectionRight.empty())
	{
		if (sortedSubSectionLeft.front().first <= sortedSubSectionRight.front().first)
		{
			*(itStart + indexInSubvector) = sortedSubSectionLeft.front();
			sortedSubSectionLeft.erase(sortedSubSectionLeft.begin());
		}
		else
		{
			*(itStart + indexInSubvector) = sortedSubSectionRight.front();
			sortedSubSectionRight.erase(sortedSubSectionRight.begin());
		}
		++indexInSubvector;
	}
	if (!sortedSubSectionLeft.empty())
	{
		std::copy(sortedSubSectionLeft.begin(), sortedSubSectionLeft.end(), itStart + indexInSubvector);
	}
	else
	{
		std::copy(sortedSubSectionRight.begin(), sortedSubSectionRight.end(), itStart + indexInSubvector);
	}
}

vectorUnsigned	extractMax(vectorPairs & sortedPairs)
{
	vectorUnsigned maximums;
	for (vectorPairs::iterator it = sortedPairs.begin(); it != sortedPairs.end(); ++it)
	{
		maximums.push_back(it->first);
	}
	return maximums;
}

void	insertFirstMin(vectorPairs & sortedPairs, vectorUnsigned & sortedValues)
{
	sortedValues.insert(sortedValues.begin(), sortedPairs.begin()->second);
	sortedPairs.erase(sortedPairs.begin());
}

void	insertMins(vectorPairs & sortedPairs, vectorUnsigned & sortedValues,
			t_unpaired & unpairedElement)
{
	static const long unsigned int jacobsthalValues[] = {
		2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
		2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
		1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
		178956970, 357913942, 715827882, 1431655766, 2863311530, 5726623062,
		11453246122, 22906492246, 45812984490, 91625968982, 183251937962,
		366503875926, 733007751850, 1466015503702, 2932031007402, 5864062014806,
		11728124029610, 23456248059222, 46912496118442, 93824992236886, 187649984473770,
		375299968947542, 750599937895082, 1501199875790165, 3002399751580331,
		6004799503160661, 12009599006321322, 24019198012642644, 48038396025285288,
		96076792050570576, 192153584101141152, 384307168202282304, 768614336404564608,
		1537228672809129216, 3074457345618258432, 6148914691236516864, 0};
	
	unsigned long int			pairsIndex = 0;
	unsigned int				jacobsthalGroupIndex = 0;

	while (pairsIndex + jacobsthalValues[jacobsthalGroupIndex] + 1 < sortedPairs.size())
	{

		insertJacobsthalGroup(
			sortedPairs.begin() + pairsIndex, 
			jacobsthalValues[jacobsthalGroupIndex],
			sortedValues);
		pairsIndex += jacobsthalValues[jacobsthalGroupIndex];
		++jacobsthalGroupIndex;
	}
	if (unpairedElement.isUnpaired == ONE_UNPAIRED_ELEMENT)
	{
		sortedValues.insert(
				std::upper_bound(sortedValues.begin(),
					sortedValues.end(), unpairedElement.unpairedValue),
				unpairedElement.unpairedValue);
	}
	if (pairsIndex != sortedPairs.size())
	{
		insertJacobsthalGroup(
			sortedPairs.begin() + pairsIndex,
			sortedPairs.size() - pairsIndex,
			sortedValues);
	}
}

void	insertJacobsthalGroup(
			vectorPairs::iterator pairsIndexGroupStart,
			unsigned long int groupSize,
			vectorUnsigned & sortedValues)
{
		unsigned long int	inGroupIndex = groupSize - 1;
		while (1)
		{
			sortedValues.insert(
				std::upper_bound(sortedValues.begin(), sortedValues.end(),
					(pairsIndexGroupStart + inGroupIndex)->second),
					(pairsIndexGroupStart + inGroupIndex)->second);
			if (!inGroupIndex)
				return ;
			--inGroupIndex;
		}
}



void	displayVector(vectorUnsigned const toDisplay)
{
	if (!toDisplay.empty())
	{
		std::cout << "{";
		for (vectorUnsigned::const_iterator it = toDisplay.begin(); it != toDisplay.end() - 1; ++it)
		{
			std::cout << *it << ", ";
		}
		std::cout << *(toDisplay.end() - 1) << "}" << std::endl;
	}
	else
	{
		std::cout << "Empty vector" << std::endl;
	}
}

void	displayPairsVector(vectorPairs const toDisplay)
{
	if (!toDisplay.empty())
	{
		std::cout << "{";
		for (vectorPairs::const_iterator it = toDisplay.begin(); it != toDisplay.end() - 1; ++it)
		{
			std::cout << "(" << it->first << ", " << it->second << "), ";
		}
		std::cout << "(" << (toDisplay.end() - 1)->first << ", " << (toDisplay.end() - 1)->second << ")" << "}" << std::endl;
	}
	else
	{
		std::cout << "Empty vector" << std::endl;
	}
}