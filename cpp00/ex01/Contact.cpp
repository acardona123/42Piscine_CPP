/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:12:41 by alexcardona       #+#    #+#             */
/*   Updated: 2023/08/30 18:01:25 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "[Contact] Default constructor called" << std::endl;
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_secret = "";
}

Contact::~Contact(void)
{
	std::cout << "[Contact] Default destructor called" << std::endl;
}


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

int	Contact::set_all(void)
{
	if (Contact::set_first_name() || Contact::set_last_name() || Contact::set_nickname() || Contact::set_phone_number() || Contact::set_secret())
		return (1);
	return (0);
}



static int	_set_a_name(std::string *dest, std::string const name_of_name, std::string const special_chars)
{
	std::string	input;
	char		error (0);
	
	std::cout << "- Enter the contact's " << name_of_name << " please : ";
	while (1)
	{
		error = 0;
		getline(std::cin, input);
		if (std::cin.bad() || std::cin.eof())
		{
			std::cout << std::endl << INPUT_ERROR_MSG << std::endl;
			return (1);
		}
		while (!input.empty() && input[0] == ' ')
			input.erase(0, 1);
		if (input.empty())
		{
			std::cout << "\tThe " << name_of_name << " cannot be empty" << std::endl << "\tPlease retry : ";
			continue ;
		}
		if (!std::isalpha(input[0]))
		{
			std::cout << "\tThe " << name_of_name << " must start with a letter" << std::endl << "\tPlease retry : ";
			continue ;
		}
		for (size_t i = 0;  i < input.size(); i++)
		{
			if (!std::isalpha(input[i])
				&& special_chars.find(input[i]) == std::string::npos)
			{
				std::cout << "\tThe " << name_of_name << " can only contain lettres and the elements of the following string : \"" << special_chars << "\"" << std::endl << "\tPlease retry : ";
				error = 1;
				break ;
			}
			else
				input[i] = static_cast <unsigned char> (std::tolower(input[i]));
		}
		if (!error)
			break;		
	}
	*dest = input;
	return (0);
}

int	Contact::set_first_name(void)
{
	return (_set_a_name(&this->_first_name, "first name", "-"));
}

int	Contact::set_last_name(void)
{
	return (_set_a_name(&this->_last_name, "last name", " -\'"));
}

int	Contact::set_nickname(void)
{
	std::string input;

	std::cout << "- Enter the contact's nickname name please : ";
	while (1)
	{
		getline(std::cin, input);
		if (std::cin.bad() || std::cin.eof())
		{
			std::cout << std::endl << INPUT_ERROR_MSG << std::endl;
			return (1);
		}
		if (input.empty())
		{
			std::cout << "\tThe nickname cannot be empty" << std::endl << " \tPlease retry : ";
			continue ;
		}
		else
			break;
	}
	this->_nickname = input;
	return (0);
}

int	Contact::set_phone_number(void)
{
	std::string input;
	bool		error;
	
	std::cout << "- Enter the contact's phone number please : ";
	while (1)
	{
		error = false;
		getline(std::cin, input);
		if (std::cin.bad() || std::cin.eof())
		{
			std::cout << std::endl << INPUT_ERROR_MSG << std::endl;
			return (1);
		}
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
			std::cout << "\tThe phone number must contain exactly 10 diggits." << std::endl << "\tPlease retry : ";
		else
			break;
	}
	this->_phone_number = input;
	return (0);
}

int	Contact::set_secret(void)
{
	std::string input;
	
	std::cout << "- Enter the contact's darkest secret please : ";
	while (1)
	{
		getline(std::cin, input);
		if (std::cin.bad() || std::cin.eof())
		{
			std::cout << std::endl << INPUT_ERROR_MSG << std::endl;
			return (1);
		}
		if (input.empty())
		{
			std::cout << "\tDon't be shy ! I know everybody have a darkest secret..." << std::endl << "\tI swear I won't tell it to anybody, tell it to me : ";
			continue ;
		}
		else
			break;
	}
	this->_secret = input;
	return (0);
}
