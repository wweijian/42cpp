/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:10:37 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 08:14:15 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void	constructors()
{
	ShrubberyCreationForm	form1("copy");
	ShrubberyCreationForm	form2(form1);
		RobotomyRequestForm	form3("copy");
		RobotomyRequestForm	form4(form3);
	PresidentialPardonForm	form5("copy");
	PresidentialPardonForm	form6(form5);

}

void	shrubs()
{
	ShrubberyCreationForm	form1("here");
	Bureaucrat				zaphod("zaphod", 1);
	Bureaucrat				darius("darius", 137);
	Bureaucrat				elsie("elsie", 139);

	darius.executeForm(form1); // not signed, can't execute
	elsie.signForm(form1); // can sign the form even though she does not meet exec grade
	zaphod.executeForm(form1);
	darius.executeForm(form1); // as long as the form is signed, it doesn't matter who
	elsie.executeForm(form1); // but still need execution grade

	// remove permission to test
}

void	robotomy()
{
	RobotomyRequestForm	form1("here");
	Bureaucrat			zaphod("zaphod", 1);
	Bureaucrat			darius("darius", 45);
	Bureaucrat			elsie("elsie", 46);

	darius.executeForm(form1); // not signed, can't execute
	elsie.signForm(form1); // can sign the form even though she does not meet exec grade
	zaphod.executeForm(form1);
	darius.executeForm(form1); // as long as the form is signed, it doesn't matter who
	elsie.executeForm(form1); // but still need execution grade
}

void	pardon()
{
	PresidentialPardonForm	form1("here");
	Bureaucrat				zaphod("zaphod", 1);
	Bureaucrat				darius("darius", 5);
	Bureaucrat				elsie("elsie", 25);

	darius.executeForm(form1); // not signed, can't execute
	elsie.signForm(form1); // can sign the form even though she does not meet exec grade
	zaphod.executeForm(form1);
	darius.executeForm(form1); // as long as the form is signed, it doesn't matter who
	elsie.executeForm(form1); // but still need execution grade
}

void	robotomyRoulette()
{
	Bureaucrat	 		people[10];
	RobotomyRequestForm	forms[10];
	
	for (int i = 0; i < 10; i++) {
		people[i] = Bureaucrat("guy", 1);
		people[i].signForm(forms[i]);
		people[i].executeForm(forms[i]);
	}
}

int	main()
{
	// constructors();
	// shrubs();
	// robotomy();
	// robotomyRoulette();
	// pardon();
}
