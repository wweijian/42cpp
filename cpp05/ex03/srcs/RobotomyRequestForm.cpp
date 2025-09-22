/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:12:16 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 21:56:43 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:	AForm("RobotomyRequestForm", RRF_SIGN, RRF_EXEC, "home")
{
	std::cerr << "Created : " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:	AForm("RobotomyRequestForm", RRF_SIGN, RRF_EXEC, target)
{
	std::cerr << "Created : " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& f)
	:	AForm(f.getName(), f.getMinSign(), f.getMinExec(), f.getTarget())
{
	std::cerr << "Copied : " << getName() << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other) {
		this->~RobotomyRequestForm();
		new (this) RobotomyRequestForm(other);
		std::cerr << "Assigned : " << getName() << std::endl;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cerr << "Destroyed : " << getName() << std::endl;
}

/* functions */

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > getMinExec())
		throw AForm::GradeTooLowException();
	std::cout << PURPLE(executor << " executed " << getName()) << std::endl;
	RobotomyRequestForm::robotomy();
}

/* make tree */
void	RobotomyRequestForm::robotomy() const
{
	std::srand(std::time(0));

	std::cout << "bzzzzt....bzzzzt....bzzzzt....bzzzzt...." << std::endl;
	if (std::rand() % 2) {
		std::cout << getTarget() << " has successfully been robotomized" << std::endl;	}
	else
		std::cout << getTarget() << " has failed to robotomize this time" << std::endl;
}
