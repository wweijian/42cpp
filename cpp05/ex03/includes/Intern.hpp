/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 08:19:34 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 09:13:26 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern;

typedef struct s_forms {
	std::string	name;
	AForm*		(Intern::*createForm)(std::string);
}	t_forms;

class Intern
{
	public:
	/* constructors */
		Intern();
		Intern(const Intern& intern);
		Intern& operator=(const Intern& intern);
		~Intern();

	/* functions */
		AForm* makeForm(std::string formName, std::string target);
	
	/* exceptions */
		class	FormDoesNotExist : public std::exception
		{
			public:
				const char* 		what() const throw();
		} ;

	private:
		static const t_forms	_forms[3];
		AForm*					makePPF(std::string target);
		AForm*					makeRRF(std::string target);
		AForm*					makeSCF(std::string target);
} ;