/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexcardona <alexcardona@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:58:20 by alexcardona       #+#    #+#             */
/*   Updated: 2023/07/30 00:40:26 by alexcardona      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
#include <sstream>

# include "Contact.hpp"

class	PhoneBook
{
	public :
		PhoneBook(void);
		~PhoneBook(void);
		void	phonebook_add(void);
		void	phonebook_search(void) const;
	private :
		int		_index;
		Contact	_repertory[8];
};

#endif