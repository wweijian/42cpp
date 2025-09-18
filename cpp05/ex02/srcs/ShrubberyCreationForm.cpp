/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:12:16 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 21:56:43 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm("ShrubberyCreationForm", SIGN, EXEC, "home")
{
	std::cerr << "Created : " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:	AForm("ShrubberyCreationForm", SIGN, EXEC, target)
{
	std::cerr << "Created : " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& f)
	:	AForm(f.getName(), f.getMinSign(), f.getMinExec(), f.getTarget())
{
	std::cerr << "Copied : " << getName() << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other) {
		this->~ShrubberyCreationForm();
		new (this) ShrubberyCreationForm(other);
		std::cerr << "Assigned : " << getName() << std::endl;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cerr << "Destroyed : " << getName() << std::endl;
}

/* functions */

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > getMinExec())
		throw AForm::GradeTooLowException();
	try {
		ShrubberyCreationForm::makeTree();
	} catch (std::exception &err) {
		throw ;
	}
	std::cout << PURPLE(executor << " executed " << getName()) << std::endl;
}

/* exception */

const char *ShrubberyCreationForm::CannotOpenWriteFile::what() const throw()
{
	return ("cannot open write file");
}

/* make tree */
void	ShrubberyCreationForm::makeTree() const
{
	std::ofstream	outfile;

	outfile.open(getTarget() + "_shrubbery");
	if (!outfile.is_open())
		throw ShrubberyCreationForm::CannotOpenWriteFile();
	outfile << tree;
}

const std::string ShrubberyCreationForm::tree = "   *\n  ***\n *****\n*******\n  |||\n" ;