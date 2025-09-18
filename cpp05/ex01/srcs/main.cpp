/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:10:15 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 19:10:16 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	construction()
{
	Form formA;
	Form formB("form B", 1, 1);
	Form formB2(formB);
	Form formC("form C", 150, 150);
	formC = formB;

	std::cout << "default constructor : " << formA << std::endl;
	std::cout << "overload constructor: " << formB << std::endl;
	std::cout << "copy constructor    : " << formB2 << std::endl;
	std::cout << "assignment operator : " << formC << std::endl;
}

void	invalid()
{
	try {
		Form formX1("unimportant form", 151, 151);
	} catch (const std::exception &err) {
		std::cerr << RED(BRACKET("the form " << err.what())) << std::endl;
	}
	try {
		Form formX2("fake form", 0, 0);
	} catch (const std::exception &err) {
		std::cerr << RED(BRACKET("the form " << err.what())) << std::endl;
	}
}

void	signing()
{
	Bureaucrat	noob("noob", 150);
	Bureaucrat	mid("mid", 75);
	Bureaucrat	pro("pro", 1);
	Form		form("random form", 75, 75);

	noob.signForm(form);
	mid.signForm(form);
	pro.signForm(form);
}

int	main()
{
	construction();
	invalid();
	signing();
}