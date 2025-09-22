/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:10:23 by weijian           #+#    #+#             */
/*   Updated: 2025/09/22 09:06:21 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:	_name("default"),
		_grade(150)
{
	std::cerr << "Created :  " << YELLOW(*this) << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:	_name(name),
		_grade(grade)
{
	if (_grade > lowest) {
		std::cerr << "Failed to create: " << YELLOW(*this) << ". ";
		throw Bureaucrat::GradeTooLowException();
	}
	if (_grade < highest) {
		std::cerr << "Failed to create: " << YELLOW(*this) << ". ";
		throw Bureaucrat::GradeTooHighException();
	}
	std::cerr << "Created :  " << YELLOW(*this) << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:	_name(other._name),
		_grade(other._grade)
{
	std::cerr << "Copied :  " << YELLOW(*this) << std::endl;
}

// i should decide if this is wholly necessary
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other) {
		this->~Bureaucrat();
		new (this) Bureaucrat(other);
		std::cerr << "Assigned :  " << YELLOW(*this) << std::endl;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cerr << "Destroyed :  " << YELLOW(*this) << std::endl;
}


/* static variables */

const int Bureaucrat::lowest = 150;
const int Bureaucrat::highest = 1;

/* increment decrement */
void	Bureaucrat::decrementGrade()
{
	if (_grade == lowest) {
		std::cerr << "Grade cannot be decremented. ";
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == highest) {
		std::cerr << "Grade cannot be incremented. ";
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

/* getters */

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("Bureaucrat's grade is too low");
}

/* print */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau)
{
	os << bureau.getName() << ", bureacrat grade: " << bureau.getGrade();
	return (os);
}

