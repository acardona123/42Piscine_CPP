/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:58:20 by alexcardona       #+#    #+#             */
/*   Updated: 2023/08/30 18:00:30 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
#include <sstream>

# include "Contact.hpp"

#ifndef INPUT_ERROR_MSG
# define INPUT_ERROR_MSG "Input eof or faillure : exiting the program."
#endif

class	PhoneBook
{
	public :
		PhoneBook(void);
		~PhoneBook(void);
		int	phonebook_add(void);
		int	phonebook_search(void) const;
	private :
		int		_index;
		Contact	_repertory[8];
};

#endif