/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchanger.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:55:13 by acardona          #+#    #+#             */
/*   Updated: 2024/01/28 18:24:18 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGER_HPP
# define BITCOINEXCHANGER_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchanger
{
	public:
		class ExceptionConstructorFail: public std::exception
		{
		};
		BitcoinExchanger( void );
		BitcoinExchanger(std::string dataFileName) throw (ExceptionConstructorFail);
		BitcoinExchanger(BitcoinExchanger const & model );
		~BitcoinExchanger( void );
		BitcoinExchanger & operator=( BitcoinExchanger const & rhs);

		bool	addChangeRate( std::string & line, char separator );
		bool	getChangeRate( std::string & line ) const;
	private:
		std::map<std::string, float> _changeRatesDB;
};

#endif