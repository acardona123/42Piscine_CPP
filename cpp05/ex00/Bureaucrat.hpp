/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:57:32 by acardona          #+#    #+#             */
/*   Updated: 2023/09/14 21:02:33 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

#define	LOWEST_GRADE 150
#define HIGHEST_GRADE 1

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

		class GradeTooHighException : public std::exception
		{
			public:
				// GradeTooHighException() throw();
				// ~GradeTooHighException() throw();
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				// GradeTooLowException() throw();
				// ~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};
	private:
		Bureaucrat( void );
		const std::string	_name;
		int					_grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & elem);

#endif