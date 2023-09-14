/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:57:32 by acardona          #+#    #+#             */
/*   Updated: 2023/09/14 21:44:59 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

#ifndef LOWEST_GRADE
#define	LOWEST_GRADE 150
#endif
#ifndef HIGHEST_GRADE
#define HIGHEST_GRADE 1
#endif

#include "Form.hpp"

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & model);
		~Bureaucrat( void );
		Bureaucrat & operator=( Bureaucrat const & model);

		std::string getName( void ) const;
		int			getGrade( void ) const;
		void		downGrade( void );
		void		upGrade( void );
		void		signForm( Form & form );

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		Bureaucrat( void );
		const std::string	_name;
		int					_grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & elem);

#endif