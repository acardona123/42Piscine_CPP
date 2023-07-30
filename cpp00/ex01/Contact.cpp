/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexcardona <alexcardona@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:12:41 by alexcardona       #+#    #+#             */
/*   Updated: 2023/07/30 00:31:08 by alexcardona      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact(void)
{
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_secret = "";
}

Contact::~Contact(void){}


/*============ GET ============*/

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}
	
std::string Contact::get_phone(void) const
{
	return (this->_phone_number);
}

std::string Contact::get_secret(void) const
{
	return (this->_secret);
}


/*============= SET =============*/

void	Contact::set_all(void)
{
	Contact::set_first_name();
	Contact::set_last_name();
	Contact::set_nickname();
	Contact::set_phone_number();
	Contact::set_secret();
}



std::string	_set_a_name(std::string const name_of_name, std::string const special_chars)
{
	std::string	input;
	char		error (0);
	
	std::cout << "Enter your " << name_of_name << " please : ";
	while (1)
	{
		error = 0;
		getline(std::cin, input);
		if (input.empty())
		{
			std::cout << " The " << name_of_name << " cannot be empty" << std::endl << " Please retry : ";
			continue ;
		}
		for (size_t i = 0;  i < input.size(); i++)
		{
			if (!std::isalpha(input[i])
				&& special_chars.find(input[i]) == std::string::npos)
			{
				std::cout << " The " << name_of_name << " can only contains lettres and those elements of \" " << special_chars << "\"" << std::endl << " Please retry : ";
				error = 1;
			}
			else
				input[i] = static_cast <unsigned char> (std::tolower(input[i]));
		}
		if (!error)
			break;		
	}
	return (input);
}

void	Contact::set_first_name(void)
{
	this->_first_name = _set_a_name("first name", "-");
}

void	Contact::set_last_name(void)
{
	this->_last_name = _set_a_name("last name", " -\'");
}

void	Contact::set_nickname(void)
{
	std::string input;

	std::cout << "Enter your nickname name please : ";
	while (1)
	{
		getline(std::cin, input);
		if (input.empty())
		{
			std::cout << " The nickname cannot be empty" << std::endl << " Please retry : ";
			continue ;
		}
		else
			break;
	}
	this->_nickname = input;
}

void	Contact::set_phone_number(void)
{
	std::string input;
	bool		error;
	
	std::cout << "Enter your phone number please : ";
	while (1)
	{
		error = false;
		getline(std::cin, input);
		if (input.size() != 10)
			error = true;
		else
		{
			for (int i = 0; i < 10; i++)
			{
				if (!std::isdigit(input[i]))
				{
					error = true;
					break;
				}
			}
		}
		if (error)
			std::cout << " The phone number must contain exactly 10 diggits." << std::endl << " Please retry : ";
		else
			break;
	}
	this->_phone_number = input;
}

void	Contact::set_secret(void)
{
	std::string input;
	
	std::cout << "Enter your darkest secret please : ";
	while (1)
	{
		getline(std::cin, input);
		if (input.empty())
		{
			std::cout << " Don't be shy ! I know everybody have a darkest secret..." << std::endl << " I swear I won't tell it to anybody, tell it to me : ";
			continue ;
		}
		else
			break;
	}
	this->_secret = input;
}
