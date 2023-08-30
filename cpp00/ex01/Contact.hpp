/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:03:32 by alexcardona       #+#    #+#             */
/*   Updated: 2023/08/30 18:00:30 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

#ifndef INPUT_ERROR_MSG
# define INPUT_ERROR_MSG "Input eof or faillure : exiting the program."
#endif

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		//get
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone(void) const;
		std::string	get_secret(void) const;
		//set
		int		set_all(void);
		int		set_first_name(void);
		int		set_last_name(void);
		int		set_nickname(void);
		int		set_phone_number(void);
		int		set_secret(void);		
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _secret;
};

#endif