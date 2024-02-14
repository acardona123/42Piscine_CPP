/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 00:57:50 by acardona          #+#    #+#             */
/*   Updated: 2024/02/14 22:31:29 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchanger.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Wrong number of arguments, only expects the input file's name" << std::endl;
		return (1);
	}

	char 		*inputFileName (av[1]);
	char	dataFileName[] = "data.csv";

	//open the input file first (to avoid unecessary calculation on the database if the input can't be opened)
	std::ifstream inputStream;
	inputStream.open(inputFileName, std::ios_base::in);
	if (!inputStream)
	{
		std::cout << "Error: Can't open the input file " << inputFileName << std::endl;
		return (1);
	}


	//builds the database containing all the conversion rates
								// std::cout << "\e[103mBuild the database\e[0m" << std::endl;//
	BitcoinExchanger	theAccountant;
	try
	{
		BitcoinExchanger theAccountant1(dataFileName);
		theAccountant = theAccountant1;
	}
	catch (std::exception &e)
	{

		(void)e;
		return (1);
	}
	
	//tries to convert all the input file values
							// std::cout << "\e[103mconverts the input file\e[0m" << std::endl;//
	std::string inputLine;

	getline(inputStream, inputLine);
	if (inputStream.bad() || inputLine != "date | value")
		return (std::cout << "Error: Wrong infile header" << std::endl, 1);
	while (!inputStream.eof())
	{
		
		getline(inputStream, inputLine);
		if (inputStream.bad())
			return (std::cout << "Error: getline error" << std::endl, 1);
										// std::cout << "- {" << inputLine << "}" << std::endl << " ";//
		if (inputLine.empty())
			std::cout << std:: endl;
		else
			theAccountant.getChangeRate(inputLine);		
	}
	
	return 0;
}
