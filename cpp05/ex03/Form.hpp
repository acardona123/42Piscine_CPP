/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:14:33 by acardona          #+#    #+#             */
/*   Updated: 2023/12/17 18:50:15 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#ifndef LOWEST_GRADE
#define	LOWEST_GRADE 150
#endif
#ifndef HIGHEST_GRADE
#define HIGHEST_GRADE 1
#endif

class	Bureaucrat;

class Form
{
	public:
		Form( std::string name, int grade_signature, int grade_execution, bool is_signed = false );
		Form( Form const & model );
		virtual ~Form( void );
		Form & operator=( Form const & model);

		std::string		getName( void ) const;
		bool			getSigned( void ) const;
		int				getGradeSignature( void ) const;
		int				getGradeExecution( void ) const;

		void			beSigned( Bureaucrat const & Bob);
		virtual	void	execute( Bureaucrat const & executor ) const;

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	

	protected:
		bool			checkExecGrade( Bureaucrat const & executor ) const;
	
	
	private:
		Form( void );
		std::string const	_name;
		int const			_grade_signature;
		int const			_grade_execution;
		bool				_signed;
};

std::ostream & operator<<(std::ostream & o, Form const & elem);


#endif