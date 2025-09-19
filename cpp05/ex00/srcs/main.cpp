/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:10:19 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 09:21:16 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// we won't try/catch for things we know will definitely succeed
void	basic()
{
	Bureaucrat	sally;
	Bureaucrat	bob("bob", 1);
	Bureaucrat	bobby(bob);
	Bureaucrat	dude("dude", 150);
	dude = bob;

	std::cout << "default constructor : " << sally << std::endl;
	std::cout << "overload constructor: " << bob << std::endl;
	std::cout << "copy constructor    : " << bobby << std::endl;
	std::cout << "assignment operator : " << dude << std::endl;
}

void	invalid()
{
	try {
		Bureaucrat	guy("guy", 151);
	} catch (const std::exception &err) {
		std::cerr << RED(BRACKET(err.what())) << std::endl;
	}
	try {
		Bureaucrat	guy("guy", 0);
	} catch (const std::exception &err) {
		std::cerr << RED(BRACKET(err.what())) << std::endl;
	}
	try {
		Bureaucrat	guy("guy",-10);
	} catch (const std::exception &err) {
		std::cerr << RED(BRACKET(err.what())) << std::endl;
	}
	// std::cout << guy << std::endl; will not compile 
	// should not to create these object without try catch
}

void	decrement()
{
	Bureaucrat	guy("guy", 149);
	
	std::cout	<< "decrement\n"
				<< "starting grade: " << guy.getGrade() << std::endl;
	try {
		guy.decrementGrade();
	} catch (const std::exception &err) {
		std::cerr << "reducing grade..." << "\n";
		std::cerr << RED(err.what()) << std::endl;
	}
	std::cout << "new_grade: " << guy.getGrade() << std::endl;
	try {
		std::cerr << "reducing grade..." << "\n";
		guy.decrementGrade();
	} catch (const std::exception &err) {
		std::cerr << RED(err.what()) << std::endl;
	}
	std::cout << "new_grade: " << guy.getGrade() << std::endl;
}

void	increment()

{
	Bureaucrat	guy("guy", 2);
	std::cout	<< "increment\n"
				<< "starting grade: " << guy.getGrade() << std::endl;
	try {
		guy.incrementGrade();
	} catch (const std::exception &err) {
		std::cerr << "improving grade..." << "\n";
		std::cerr << RED(err.what()) << std::endl;
	}
	std::cout << "new_grade: " << guy.getGrade() << std::endl;
	try {
		std::cerr << "improving grade..." << "\n";
		guy.incrementGrade();
	} catch (const std::exception &err) {
		std::cerr << RED(err.what()) << std::endl;
	}
	std::cout << "new_grade: " << guy.getGrade() << std::endl;
}

int main()
{
	basic();
	invalid();
	increment();
	decrement();
}