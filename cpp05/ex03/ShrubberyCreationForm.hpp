/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:25:52 by acardona          #+#    #+#             */
/*   Updated: 2023/12/17 19:59:15 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "Form.hpp"

#define SHRUBBERYCREATIONFORM_SIGN 145
#define SHRUBBERYCREATIONFORM_EXEC 137


class ShrubberyCreationForm : virtual public Form
{
	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & model );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm & operator=( ShrubberyCreationForm const & model );
		void	execute( Bureaucrat const & executor ) const;
		std::string getTarget( void ) const;

	private:
		ShrubberyCreationForm( void );
		std::string _target;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & elem);

#endif