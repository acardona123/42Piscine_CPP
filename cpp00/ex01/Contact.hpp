/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexcardona <alexcardona@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:03:32 by alexcardona       #+#    #+#             */
/*   Updated: 2023/07/29 20:29:22 by alexcardona      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

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
		void		set_all(void);
		void		set_first_name(void);
		void		set_last_name(void);
		void		set_nickname(void);
		void		set_phone_number(void);
		void		set_secret(void);		
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _secret;
};

#endif