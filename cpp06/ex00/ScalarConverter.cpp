/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:18:12 by acardona          #+#    #+#             */
/*   Updated: 2024/01/02 23:31:08 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{}


//================ display_functions ================
//display the values based on the argument type

static void	_display(char c);
static void	_display(int n);
static void	_display(float f, int precision);
static void	_display(double d, int precision);
static void _display_impossible(std::string type);

static void	_display(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void	_display(int n)
{
	std::cout << "int: " << n << std::endl;
}

static void	_display(float f, int precision)
{
	if (precision == 0)
		++precision;
	std::cout << "float: " << std::setprecision(precision) << std::fixed << f << "f" << std::endl;
}

static void	_display(double d, int precision)
{
	if (precision == 0)
		++precision;
	std::cout << "double: " << std::setprecision(precision) << std::fixed << d << std::endl;
}

static void _display_impossible(std::string type)
{
	std::cout << type << ": impossible" << std::endl;
}

//================ infinity detection ================

static bool	_is_infinity(std::string str)
{
	return (str == "inf" || str == "+inf" || str == "-inf"
		|| str == "inff" || str == "+inff" || str == "-inff");
}


//================ fractonal_precision ================
//calculates the presicion (number of fractional diggits) required to display a float or a double

static int _fractional_precision(t_input_type type, std::string str)
{
	if (_is_infinity(str) || str == "nan" || str == "nanf")
		return (1);
	if (type == IS_FLOAT)
		return (str.substr(str.find(".") + 1, str.length() - str.find(".") - 1).length() - 1);
	else
	return (str.substr(str.find(".") + 1, str.length() - str.find(".") - 1).length());
}



/**
 * @brief returns the likely type of the number represented by the string (based
 *	on the structure of it). Throws a exception in case of syntax error
 * 
 * @param input 
 * @return t_input_type 
 */
static t_input_type _get_input_likely_type(std::string input) throw(std::invalid_argument)
{
	if (input.empty())
		throw (std::invalid_argument("empty string"));
	if (input.at(0) == '\'')
		return (IS_CHAR);
	if (input == "-inff" || input == "+inff" || input == "inff" || input == "nanf"
		|| (!_is_infinity(input) && input.find('f') != std::string::npos))
		return (IS_FLOAT);
	if (input == "-inf" || input == "+inf" || input == "inf" || input == "nan" || input.find(".") != std::string::npos)
		return (IS_DOUBLE);
	return (IS_INT);
}


// === convert from char ===

static char _check_format_and_exctract_char(std::string input) throw(std::invalid_argument)
{
	if (input.size() != 3 || input.at(2) != '\'')
		throw(std::invalid_argument("wrong char format"));
	return (input.at(1));
}

static void	_convert_char(std::string str) throw(std::invalid_argument)
{
	char	c;

	c = _check_format_and_exctract_char(str);
	_display(str.at(1));
	_display(static_cast<int>(c));
	_display(static_cast<float>(c), 1);
	_display(static_cast<double>(c), 1);
}


// === convert from int ===

static int _check_format_and_exctract_int(std::string input) throw(std::invalid_argument)
{
	if (input.find_first_not_of("-0123456789") != std::string::npos)
		throw (std::invalid_argument("wrong format"));

	int			n (std::atoi(input.c_str()));
	std::string	str_conv  (static_cast<std::ostringstream&>((std::ostringstream() << std::dec << n)).str());

	if (str_conv != input)
		throw (std::invalid_argument("wrong format"));
	return (n);
}

static void	_convert_int(std::string input) throw(std::invalid_argument)
{
	int	n;

	n = _check_format_and_exctract_int(input);
	if (n < 0 || n > 255)
		_display_impossible("char");
	else
		_display(static_cast<char>(n));
	_display(n);
	_display(static_cast<float>(n), 0);
	_display(static_cast<double>(n), 0);
	
}



// === convert from float ===

static float _check_format_and_exctract_float(std::string input) throw(std::invalid_argument)
{
	float	f;
	char	*nextChar;

	f = std::strtof(input.c_str(), &nextChar);
	if (*nextChar != 'f' || *(nextChar + 1) || input.at(0) == '.' || input.at(input.size() - 2) == '.')
		throw (std::invalid_argument("wrong format"));
	return (f);
}

static void	_convert_float(std::string str) throw(std::invalid_argument)
{
	float	f (_check_format_and_exctract_float(str));
	int		precision;

	std::cout << "FLOAT: " << f << std::endl;
	std::cout << "INT_MIN: " << INT_MIN << std::endl;
	if (f < CHAR_MIN || f > CHAR_MAX || str == "nanf")
		_display_impossible("char");
	else
		_display(static_cast<char>(f));
	std::cout << std::endl <<  "FLOAT: " << f << std::endl;//==============
	std::cout << "INT_MIN: " << INT_MIN << std::endl;//====================
	std::cout << "INF: " << (f < INT_MIN) << std::endl;//====================
	if (f < INT_MIN || f > INT_MAX || str == "nanf")
		_display_impossible("int");
	else
		_display(static_cast<int>(f));
	precision = _fractional_precision(IS_FLOAT, str);
	_display(f, precision);
	_display(static_cast<double>(f), precision);
}


// === convert from double ===

static float _check_format_and_exctract_double(std::string input) throw(std::invalid_argument)
{
	double	d;
	char	*nextChar;

	d = std::strtod(input.c_str(), &nextChar);
	if (*nextChar || input.at(0) == '.' || input.at(input.size() - 1) == '.')
		throw (std::invalid_argument("wrong format"));
	return (d);
}
static void	_convert_double(std::string str) throw(std::invalid_argument)
{
	double	d (_check_format_and_exctract_double(str));
	int		precision;


	if (d < CHAR_MIN || d > CHAR_MAX || str == "nan")
		_display_impossible("char");
	else
		_display(static_cast<char>(d));
	if (d < INT_MIN || d > INT_MAX || str == "nan")
		_display_impossible("int");
	else
		_display(static_cast<int>(d));
	precision = _fractional_precision(IS_FLOAT, str);
	if (d == DOUBLE_INF)
		_display(FLOAT_INF, 1);
	else if (d == -DOUBLE_INF)
		_display(-FLOAT_INF, 1);
	else if (d < FLOAT_MIN || d > FLOAT_MAX)
		_display_impossible("float");
	else
		_display(static_cast<float>(d), precision);
	_display(d, precision);
}

void ScalarConverter::convert(std::string input)
{
	t_input_type	type;

	try
	{
		type = _get_input_likely_type(input);
		switch (type)
		{
		case IS_CHAR:
			_convert_char(input);
			break;
		case IS_INT:
			_convert_int(input);
			break;
		case IS_FLOAT:
			_convert_float(input);
			break;
		default:
			_convert_double(input);
			break;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Error:" << std::endl << e.what() << std::endl;
		return;
	}
	
}
