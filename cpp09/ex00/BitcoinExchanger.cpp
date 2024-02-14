/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchanger.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:54:43 by acardona          #+#    #+#             */
/*   Updated: 2024/02/14 22:40:32 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchanger.hpp"

static bool _checkDateFormatOk(std::string const &date);
static bool	_checkAmountOk(float const f);
static int	_convertDigit(char c);



BitcoinExchanger::BitcoinExchanger( void )
{
}

BitcoinExchanger::BitcoinExchanger(BitcoinExchanger const & model) : _changeRatesDB(model._changeRatesDB)
{
}

BitcoinExchanger::BitcoinExchanger(char *dataFileName) throw (ExceptionConstructorFail)
{
	std::ifstream 	inFile ;
	std::string		line;
	char			separator;
	std::string		dataFileNameStr (dataFileName);

	if (dataFileNameStr.length() < 4 || dataFileNameStr.substr(dataFileNameStr.length() - 4, 4) != ".csv")
	{
		std::cout <<  "Error: " << dataFileNameStr << " is not a .csv file" << std::endl;
		throw (ExceptionConstructorFail());
	}		
	try
	{
		inFile.open(dataFileName, std::ios_base::in);
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << dataFileNameStr << ": " << e.what() << std::endl;
		throw (ExceptionConstructorFail());
	}

	//getting the separator
	getline(inFile, line);
	if (inFile.bad())
	{
		std::cout << "Error: getline failure" << std::endl;
		throw (ExceptionConstructorFail());
	}
	if (line.length() != 18 ||  line.substr(0, 4) != "date" || line.substr(5, 13) != "exchange_rate")
	{
		std::cout << "Error: " << dataFileNameStr << ": invalid header" << std::endl;
		throw(ExceptionConstructorFail());
	}
	separator = line.at(4);


	//adding the file data to the map
	while (!inFile.eof())
	{
		getline(inFile, line);
		if (inFile.bad())
		{
			std::cout << "Error: getline failure" << std::endl;
			throw (ExceptionConstructorFail());
		}
		if (!line.empty() && addChangeRate(line, separator))
			throw (ExceptionConstructorFail());
	}
}

BitcoinExchanger::~BitcoinExchanger( void )
{
}

BitcoinExchanger & BitcoinExchanger::operator=(BitcoinExchanger const & model)
{
	if (this != &model)
		_changeRatesDB = model._changeRatesDB;
	return (*this);
}

/**
 * @brief adds a conversion rate to the database
 * 
 * @param line 
 * @param separator character separating the date and the conversion rate in the csv file 
 * @return true if error
 * @return false if success
 */
bool	BitcoinExchanger::addChangeRate( std::string & line, char separator)
{
																						// std::cout << line << std::endl << " ";//

	std::istringstream dateAndRate ( line );
	std::string date;
	float		changeRate;

	for (unsigned int i = 0; i < 10; ++i)
	{
		if (dateAndRate.eof() && i != 9)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return (true);
		}
		date += dateAndRate.get();
	}
	if (!_checkDateFormatOk(date))
		return (true);
	if ( dateAndRate.get() != separator || !(dateAndRate >> changeRate) || !dateAndRate.eof())
	{
		std::cout << "Error: bad format" << std::endl;
		return (true);
	}
	_changeRatesDB.insert(std::make_pair(date, changeRate));
	return (false);
}

/**
 * @brief tries to display the conversion value associated to an input line and the database values
 * 
 * @param line 
 * @return true if Error, err msg displayed
 * @return false if success, conversion rate displayed
 */
bool	BitcoinExchanger::getChangeRate( std::string & line ) const
{
	std::istringstream dateAndAmount(line);
	std::string	date;
	std::string tmp;
	float		amount;
	std::map<std::string, float>::const_iterator it;

																							// std::cout << "date: {" << date << "}" << std::endl;//
	if (!(dateAndAmount >> date) || _checkDateFormatOk(date) == false)
		return (true);
	if (!(dateAndAmount >> tmp) || tmp != "|" || !(dateAndAmount >> amount) || !dateAndAmount.eof())
	{
		std::cout << "Error: wrong format" << std::endl;
		return (true);
	}
	if (!_checkAmountOk(amount))
		return (true);
	it = _changeRatesDB.find(date);
	if (it != _changeRatesDB.end())
	{
		std::cout << date << " => " << amount << " => " << amount * it->second << std::endl;
		return (true);
	}
	it = _changeRatesDB.lower_bound(date);
	if (it == _changeRatesDB.begin())
	{
		std::cout << "Error: " << date << " too early." << std::endl;
		return (true);
	}
	std::cout << date << " => " << amount << " => " << amount * (--it)->second << std::endl;
	return (false);
}

static bool _checkDateFormatOk(std::string const & date)
{			
																							// std::cout << "date _checkDateFormatOk: {" << date << "}" << std::endl;//
	if (date.length() != 10
		|| !(std::isdigit(date.at(0))
			&& std::isdigit(date.at(1))
			&& std::isdigit(date.at(2))
			&& std::isdigit(date.at(3))
			&& date.at(4) == '-'
			&& std::isdigit(date.at(5))
			&& std::isdigit(date.at(6))
			&& date.at(7) == '-'
			&& std::isdigit(date.at(8))
			&& std::isdigit(date.at(9))
		))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return (false);
	}
	int year (_convertDigit(date.at(0)) * 1000 + _convertDigit(date.at(1)) * 100 + _convertDigit(date.at(2)) * 10 + _convertDigit(date.at(3)));
	int	month (_convertDigit(date[5]) * 10 + _convertDigit(date[6]));
	int day (_convertDigit(date[8]) * 10 + _convertDigit(date[9]));
	int	monthsLength[12] = {31, 28 + !(year % 4), 31, 30, 31, 30, 31, 31, 30, 31 ,30 , 31};
	if (month > 12 || day > monthsLength[month - 1])
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	return (true);
}

static bool	_checkAmountOk(float const f)
{
	if (f < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (f > 1000)
	{
		std::cout << "Error: too large a number" << std::endl;
		return (false);
	}
	return (true);
}

static	int	_convertDigit(char c)
{
	return (c- '0');
}