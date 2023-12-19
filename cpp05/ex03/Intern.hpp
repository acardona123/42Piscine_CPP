/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:45:56 by acardona          #+#    #+#             */
/*   Updated: 2023/12/18 21:00:52 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern &model);
		~Intern(void);
		Intern& operator=(Intern &model);
		Form	*makeForm(std::string formName, std::string formTarget)const;
	private:
		static Form *_new_shrubbery_creation_new(std::string target);
		static Form *_new_robotomy_request_new(std::string target);
		static Form *_new_presidiential_pardon_new(std::string target);

};

typedef Form *(*formFunction)(std::string formTarget);

#endif