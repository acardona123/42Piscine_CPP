/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:17:34 by acardona          #+#    #+#             */
/*   Updated: 2023/08/14 00:46:20 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex04.hpp"

bool	replace_in_one_line(std::ifstream *infile, std::ofstream *outfile, std::string toReplace, std::string replacement);

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error : Wrong number of arguments. Expected :" << std::endl << "<filename>  <string to replace>  <replacement string>" << std::endl;
		return (1);
	}
	
	std::ifstream inputFile(av[1]);
	if (!inputFile)
	{
		std::cout << "Error : the input file cannot be opened" << std::endl;
		return (1);
	}
	
	std::string outputName(av[1]);
	outputName.append(".replace");
	std::ofstream	outputFile(outputName.c_str());
	if (!outputFile)
	{
		std::cout << "Error : the output file cannot be opened" << std::endl;
		return (1);
	}
	
	std::string sToReplace(av[2]);
	std::string sReplacement(av[3]);

	while (!replace_in_one_line(&inputFile, &outputFile, sToReplace, sReplacement))
	{
		continue ;
	}
	std::cout << "Replacement done (\"" << sToReplace << "\" -> \"" << sReplacement << "\"), output saved in the file " << outputName << std::endl;
	return (0);
}

bool	replace_in_one_line(std::ifstream *infile, std::ofstream *outfile, std::string toReplace, std::string replacement)
{
	std::string	line("");
	std::size_t	pos(0);
	std::size_t	nextPos(0);
	bool		eofReached;
	
	eofReached = !getline(*infile, line);
	while (line[pos])
	{
		nextPos = line.find(toReplace, pos);
		if (nextPos == std::string::npos)
		{
			*outfile << line.substr(pos, line.length() - pos);
			break ;
		}
		*outfile << line.substr(pos, nextPos - pos) << replacement;
		pos = nextPos + toReplace.length();
	}
	if (!eofReached)
		*outfile << std::endl;
	return (eofReached);
}

/*tests :

make;
echo -e "this is a short text. it contains the kewyword "this".\nWe try to change this by THIS.\nis it doable ?\n" > test_input;
./sed_is_for_loosers test_input this THIS

*/