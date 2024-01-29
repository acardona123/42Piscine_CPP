/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:11:07 by acardona          #+#    #+#             */
/*   Updated: 2024/01/25 21:11:16 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool _isDiggit(char c);
static bool _isOperand(char c);
static int	_doOperation(std::stack<int> & buffer, char operand);
static int	_errorFormat(void);
static int	_errorOverflow( void );
static int	_errorNullDivision( void );

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "This program requires a unique argument: an inverted Polish mathematical expression" << std::endl;
		return (1);
	}

	std::string		input(av[1]);
	std::stack<int>	buffer;
	for (unsigned int i = 0; i < input.size(); ++i)
	{
		if (i % 2)
		{
			if (input.at(i) != ' ')
				return (_errorFormat());
		}
		else {
		
			if (_isDiggit(input.at(i)))
				buffer.push(input.at(i) - '0');
			else if (_isOperand(input.at(i)))
			{
				if (buffer.size() < 2)
					return (_errorFormat());
				if (_doOperation(buffer, input.at(i)))
					return (1);
			}
			else
				return (_errorFormat());
			
		}
	}
	if (buffer.size() != 1)
		return (_errorFormat());
	std::cout << buffer.top() << std::endl;
	return (0);
}

static bool	_isDiggit(char c)
{
	static std::string digits = "0123456789";

	return (digits.find(c) != std::string::npos);
}

static bool	_isOperand(char c)
{
	static std::string digits = "+-/*";

	return (digits.find(c) != std::string::npos);
}

static int	_doOperation(std::stack<int> & buffer, char operand)
{
	int leftMember;
	int	rightMember;

	rightMember = buffer.top();
	buffer.pop();
	leftMember = buffer.top();
	buffer.pop();
	switch (operand)
	{
		case '+' :
			if (INT_MAX - leftMember < rightMember)
				return (_errorOverflow());
			buffer.push(leftMember + rightMember);
			return (0);
		case '-' :
			if (INT_MIN + rightMember > leftMember)
				return (_errorOverflow());
			buffer.push(leftMember - rightMember);
			return (0);
		case '*' :
			if (leftMember > INT_MAX / rightMember)
				return (_errorOverflow());
			buffer.push(leftMember * rightMember);
			return (0);
		case '/' :
			if (leftMember == 0)
				return (_errorNullDivision());
			buffer.push(leftMember / rightMember);
			return (0);
	}
	return (1);
}


static int	_errorFormat(void)
{
	std::cout << "Error:\nWrong format" << std::endl;
	return (1);	
}

static int	_errorNullDivision( void )
{
	std::cout << "Error:\nDivision by 0" << std::endl;
	return (1);	
}

static int	_errorOverflow( void )
{
	std::cout << "Error:\nOverflow" << std::endl;
	return (1);
}