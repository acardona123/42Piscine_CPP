/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:56:35 by acardona          #+#    #+#             */
/*   Updated: 2023/09/18 16:06:39 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTCREATIONFORM_HPP
#define ROBOTOMYREQUESTCREATIONFORM_HPP

#include <fstream>
#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

#define ROBOTOMYREQUESTCREATIONFORM_SIGN 72
#define ROBOTOMYREQUESTCREATIONFORM_EXEC 45


class RobotomyRequestForm : virtual public AForm
{
	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & model );
		~RobotomyRequestForm( void );
		RobotomyRequestForm & operator=( RobotomyRequestForm const & model );
		void	execute( Bureaucrat const & executor ) const;
		std::string getTarget( void ) const;

	private:
		RobotomyRequestForm( void );
		std::string _target;
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & elem);

#endif