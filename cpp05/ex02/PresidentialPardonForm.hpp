/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:56:35 by acardona          #+#    #+#             */
/*   Updated: 2023/09/18 16:07:01 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENCIALPARDONFORM_HPP
#define PRESIDENCIALPARDONFORM_HPP

#include <fstream>

#include "AForm.hpp"

#define PRESIDENCIALPARDONFORM_SIGN 25
#define PRESIDENCIALPARDONFORM_EXEC 5

class PresidentialPardonForm : virtual public AForm
{
	public:
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const & model );
		~PresidentialPardonForm( void );
		PresidentialPardonForm & operator=( PresidentialPardonForm const & model );
		void	execute( Bureaucrat const & executor ) const;
		std::string getTarget( void ) const;

	private:
		PresidentialPardonForm( void );
		std::string _target;
};

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & elem);

#endif