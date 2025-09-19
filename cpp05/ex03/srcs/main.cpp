/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:10:37 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 09:38:31 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

void	constructors()
{
	Intern	intern1;
	Intern	intern2(intern1);
	Intern	intern3;
	intern3 = intern2;

	
}

void	forms()
{
	Intern	intern;
	AForm*	forms[3];

	try {
		intern.makeForm("bad form", "zaphod's throne");
	} catch (std::exception &err) {
		std::cerr << RED(err.what()) << std::endl;
	}
	forms[0] = intern.makeForm("ShrubberyCreationForm", "here");
	forms[1] = intern.makeForm("RobotomyRequestForm", "robot");
	forms[2] = intern.makeForm("PresidentialPardonForm", "zaphod");
	for (int i = 2; i >= 0; i--) {
		delete forms[i];
	}
}

void	shrubs()
{
	AForm*		form1;
	Intern		intern;
	Bureaucrat	zaphod("zaphod", 1);
	Bureaucrat	darius("darius", 137);
	Bureaucrat	elsie("elsie", 139);
	
	form1 = intern.makeForm("ShrubberyCreationForm", "here");
	darius.executeForm(*form1); // not signed, can't execute
	darius.executeForm(*form1); // not signed, can't execute
	elsie.signForm(*form1); // can sign the form even though she does not meet exec grade
	darius.executeForm(*form1); // as long as the form is signed, it doesn't matter who
	elsie.executeForm(*form1); // but still need execution grade
	delete form1;
}

void	robotomy()
{
	AForm*		form1;
	Intern		intern;
	Bureaucrat	zaphod("zaphod", 1);
	Bureaucrat	darius("darius", 45);
	Bureaucrat	elsie("elsie", 46);

	form1 = intern.makeForm("RobotomyRequestForm", "here");
	darius.executeForm(*form1); // not signed, can't execute
	elsie.signForm(*form1); // can sign the form even though she does not meet exec grade
	zaphod.executeForm(*form1);
	darius.executeForm(*form1); // as long as the form is signed, it doesn't matter who
	elsie.executeForm(*form1); // but still need execution grade
	delete form1;
}

void	pardon()
{
	AForm*		form1;
	Intern		intern;
	Bureaucrat	zaphod("zaphod", 1);
	Bureaucrat	darius("darius", 5);
	Bureaucrat	elsie("elsie", 25);
	
	form1 = intern.makeForm("PresidentialPardonForm", "here");
	darius.executeForm(*form1); // not signed, can't execute
	elsie.signForm(*form1); // can sign the form even though she does not meet exec grade
	zaphod.executeForm(*form1);
	darius.executeForm(*form1); // as long as the form is signed, it doesn't matter who
	elsie.executeForm(*form1); // but still need execution grade
	delete form1;
}

int	main()
{
	// constructors();
	forms();
	shrubs();
	robotomy();
	pardon();
}
