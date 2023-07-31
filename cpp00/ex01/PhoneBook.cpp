/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexcardona <alexcardona@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:20:14 by alexcardona       #+#    #+#             */
/*   Updated: 2023/08/01 01:28:05 by alexcardona      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _index(0)
{
	std::cout << "Empty new phonebook generatedm use ADD, SEARCH and EXIT commands to interact with it." << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Phonebook destroyed" << std::endl;
}


/* ============= _phonebook_add ================*/

void	PhoneBook::phonebook_add(void)
{
	this->_repertory[this->_index].set_all();
	std::cout << "Contact added." << std::endl;
	this->_index++;
	this->_index %= 8;
}

/* ============= _phonebook_add end================*/


/* ============= _phonebook_search ================*/

static void	_search_print_formate_string(std::string str)
{
	if (str.length() <= 10)
		std::cout << std::setw(10) << std::right << str;
	else
		std::cout << str.substr(0, 9) << '.';
}

static void	_search_print_contact_list_element(std::string str0, std::string str1,
	std::string str2, std::string str3)
{
	_search_print_formate_string(str0);
	std::cout << '|';
	_search_print_formate_string(str1);
	std::cout << '|';
	_search_print_formate_string(str2);
	std::cout << '|';
	_search_print_formate_string(str3);
	std::cout << std::endl;
}

static int	_search_print_contact_list(const Contact list[8])
{
	if (list[0].get_first_name().empty())
	{
		std::cout << "There isn't any contact saved in this phonebook." << std::endl;
		return 0;
	}
	_search_print_contact_list_element("index", "first name", "last name", "nickname");
	int			nb_contacts (-1);
	std::string	tmp ("");
	while (++nb_contacts < 8)
	{
		tmp += '0' + nb_contacts;
		if (!list[nb_contacts].get_first_name().empty())
			_search_print_contact_list_element(tmp,
				list[nb_contacts].get_first_name(),
				list[nb_contacts].get_last_name(),
				list[nb_contacts].get_nickname());
		else
			break ;
		tmp.clear();
	}
	return (nb_contacts);
}

int	_search_get_input_index(int nb_contacts)
{
	std::cout << "- Please enter the index of the contact you would like to display (in [0; " << nb_contacts - 1 << "]): ";
	std::string	input;
	while (1)
	{
		getline(std::cin, input);
		if (input.size() != 1 || !std::isdigit(input[0]) || input[0] - '0' >= nb_contacts)
			std::cout << "\tIncorrect index, please enter an index in [0;" << nb_contacts - 1 << "] :" << std::endl;
		else
		 	return (input[0] - '0');
	}
}

void	PhoneBook::phonebook_search(void) const
{

	int	nb_contacts = _search_print_contact_list(this->_repertory);
	if (!nb_contacts)
		return ;
	int	index_input = _search_get_input_index(nb_contacts);
	std::cout << "-> Your contact data is :" << std::endl;
	std::cout << "  - first name : " << this->_repertory[index_input].get_first_name() << std::endl;
	std::cout << "  - last name : " << this->_repertory[index_input].get_last_name() << std::endl;
	std::cout << "  - nickname : " << this->_repertory[index_input].get_nickname() << std::endl;
	std::cout << "  - phone number : " << this->_repertory[index_input].get_phone() << std::endl;
	std::cout << "  - darkest secret : " << this->_repertory[index_input].get_secret() << std::endl;
	std::cout << "End of the research." << std::endl;
}

/* ============= _phonebook_search end================*/
