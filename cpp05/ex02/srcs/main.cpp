/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:10:37 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 22:02:36 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

void	shrubs()
{
	ShrubberyCreationForm	form1("here");
	ShrubberyCreationForm	form2("there");
	Bureaucrat				colin("colin", 1);
	Bureaucrat				darius("darius", 137);
	Bureaucrat				elsie("elsie", 139);

	colin.signForm(form1);
	colin.executeForm(form1);
	darius.executeForm(form1); // as long as the form is signed, it doesn't matter who
	elsie.executeForm(form1); // but still need execution grade

	/* unsigned form */
	darius.executeForm(form2);
}

int	main()
{
	// constructors();
	shrubs();
}