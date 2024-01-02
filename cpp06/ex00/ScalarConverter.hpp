/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:09:53 by acardona          #+#    #+#             */
/*   Updated: 2024/01/02 23:13:47 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip> //std::setprecision, std::fixed
# include <sstream>
# include <stdexcept>//std::invalid_argument
# include <limits>
# include <cmath> //nan, nanf
# include <cstdlib> //strtof, strtod

# define CHAR_MIN	std::numeric_limits<char>::min()
# define CHAR_MAX	std::numeric_limits<char>::max()
# define INT_MIN	std::numeric_limits<int>::min()
# define INT_MAX	std::numeric_limits<int>::max()
# define FLOAT_MIN	std::numeric_limits<float>::min()
# define FLOAT_MAX	std::numeric_limits<float>::max()
# define FLOAT_INF	std::numeric_limits<float>::infinity()
# define FLOAT_NANF	std::numeric_limits<float>::nanf()
# define DOUBLE_MIN	std::numeric_limits<double>::min()
# define DOUBLE_MAX	std::numeric_limits<double>::max()
# define DOUBLE_INF	std::numeric_limits<double>::infinity()
# define DOUBLE_NAN	std::numeric_limits<double>::nan()



class ScalarConverter
{
	public:
		static void convert(std::string input);
	private:
		ScalarConverter();
		
};

typedef enum e_input_type
{
	IS_CHAR,
	IS_INT,
	IS_FLOAT,
	IS_DOUBLE,
	IS_INVALID
}	t_input_type;

#endif