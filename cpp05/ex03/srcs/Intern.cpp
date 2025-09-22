/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 08:21:38 by weijian           #+#    #+#             */
/*   Updated: 2025/09/22 09:54:48 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* constructors */
Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& intern)
{
	(void) intern;
	std::cout << "Intern copied" << std::endl;
}

Intern& Intern::operator=(const Intern& intern)
{
	(void) intern;
	std::cout << "Intern assigned" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

/* static variable */
const t_forms	Intern::_forms[3] = { 	{"PresidentialPardonForm", &Intern::makePPF},
										{"RobotomyRequestForm", &Intern::makeRRF},
										{"ShrubberyCreationForm", &Intern::makeSCF} } ;

/* functions */

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	for (int i = 0; i < 3; i++)
	{
		if(formName == _forms[i].name) {
			AForm* form = (this->*(_forms[i].createForm))(target);
			return (form);
		}
	}
	std::cerr << "form was not created because " << std::flush;
	throw Intern::FormDoesNotExist();
}

AForm*	Intern::makePPF(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeRRF(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makeSCF(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

/* exceptions */
const char* Intern::FormDoesNotExist::what() const throw() 
{
	return ("form does not exist");
}
