/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:19:19 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 21:53:26 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	:	_name("arbtirary form"),
		_signed(false),
		_minSign(1),
		_minExec(1)
{
	std::cerr << "Created : " << *this << std::endl;
}

Form::Form(std::string name, int minSign, int minExec)
	:	_name(name),
		_signed(false),
		_minSign(minSign),
		_minExec(minExec)
{
	if (_minSign > lowest) {
		std::cerr << "failed to create: " << name << ". ";
		throw Form::GradeTooLowException();
	}
	if (_minSign < highest) {
		std::cerr << "failed to create: " << name << ". ";
		throw Form::GradeTooHighException();
	}
	std::cerr << "Created : " << *this << std::endl;
}

Form::Form(const Form& f)
	:	_name(f._name),
		_signed(f._signed),
		_minSign(f._minSign),
		_minExec(f._minExec)
{
	std::cerr << "Copied : " << getName() << std::endl;
}

Form& Form::operator=(const Form& f)
{
	if (this != &f) {
		this->~Form();
		new (this) Form(f);
		std::cerr << "Assigned : " << getName() << std::endl;
	}
	return (*this);
}

Form::~Form()
{
	std::cerr << "Destroyed : " << getName() << std::endl;
}

/* static variables */

const int Form::lowest = 150;
const int Form::highest = 1;

/* functions */
void 	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _minSign) {
		throw Form::GradeTooLowException();
	}
	if (_signed == true) {
		throw Form::FormAlreadySigned();
	}
	_signed = true;
	std::cout << GREEN(b.getName() << " signed " << _name) << std::endl;
}

/* getters */
std::string	Form::getName() const
{
	return(_name);
}

bool		Form::getSigned() const
{
	return(_signed);
}

int			Form::getMinSign() const
{
	return(_minSign);
}

int			Form::getMinExec() const
{
	return(_minExec);
}

/* exceptions */
const char*	Form::FormAlreadySigned::what() const throw()
{
	return ("form is already signed");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() 
{
	return ("grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	std::string signature("");
	if (form.getMinSign())
		signature = std::string("not signed");
	else
		signature = std::string("signed");

	os	<< form.getName() << "\n"
		<<	"------------------------------\n"
		<< "signed         : " << signature << "\n"
		<< "min sign grade : " << form.getMinSign() << "\n"
		<< "min exec grade : " << form.getMinExec() << "\n"
		<< "------------------------------" << std::endl;
	return (os);
}