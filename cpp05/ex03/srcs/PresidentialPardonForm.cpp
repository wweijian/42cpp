/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:12:16 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 21:56:43 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:	AForm("PresidentialPardonForm", PPF_SIGN, PPF_EXEC, "home")
{
	std::cerr << "Created : " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:	AForm("PresidentialPardonForm", PPF_SIGN, PPF_EXEC, target)
{
	std::cerr << "Created : " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& f)
	:	AForm(f.getName(), f.getMinSign(), f.getMinExec(), f.getTarget())
{
	std::cerr << "Copied : " << getName() << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other) {
		this->~PresidentialPardonForm();
		new (this) PresidentialPardonForm(other);
		std::cerr << "Assigned : " << getName() << std::endl;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cerr << "Destroyed : " << getName() << std::endl;
}

/* functions */

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > getMinExec())
		throw AForm::GradeTooLowException();
	std::cout << PURPLE(executor << " executed " << getName()) << std::endl;
	PresidentialPardonForm::pardon();
}

/* make tree */
void	PresidentialPardonForm::pardon() const
{
	std::cout<< getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
