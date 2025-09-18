/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:19:19 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 17:47:56 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	:	_name("arbtirary Aform"),
		_signed(false),
		_minSign(1),
		_minExec(1),
		_target("home")
{
	std::cerr << "Created : AForm" << std::endl;
}

AForm::AForm(std::string name, int minSign, int minExec, std::string target)
	:	_name(name),
		_signed(false),
		_minSign(minSign),
		_minExec(minExec),
		_target(target)
{
	std::cerr << "Created : AForm" << std::endl;
}

AForm::AForm(const AForm& f)
	:	_name(f._name),
		_signed(f._signed),
		_minSign(f._minSign),
		_minExec(f._minExec),
		_target(f._target)
{
	std::cerr << "Copied : AForm"<< std::endl;
}

AForm& AForm::operator=(AForm& f)
{
	if (this != &f) {
		_signed = f._signed;
		std::cerr << "Assigned : AForm" << std::endl;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cerr << "Destroyed : AForm" << std::endl;
}

/* static variables */

const int AForm::lowest = 150;
const int AForm::highest = 1;

/* functions */
void 	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _minSign) {
		throw AForm::GradeTooLowException();
	}
	if (_signed == true) {
		throw AForm::FormAlreadySigned();
	}
	_signed = true;
	std::cout << GREEN(b.getName() << " signed " << _name) << std::endl;
}

/* getters */
std::string	AForm::getName() const
{
	return(_name);
}

bool	AForm::getSigned() const
{
	return(_signed);
}

int	AForm::getMinSign() const
{
	return(_minSign);
}

int	AForm::getMinExec() const
{
	return(_minExec);
}

std::string	AForm::getTarget() const
{
	return(_target);
}

/* exceptions */
const char*	AForm::FormAlreadySigned::what() const throw()
{
	return ("Form is already signed");
}

const char*	AForm::FormNotSigned::what() const throw()
{
	return ("Form is not signed");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw() 
{
	return ("grade is too low");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
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