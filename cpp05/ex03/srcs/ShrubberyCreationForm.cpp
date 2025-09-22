/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:12:16 by weijian           #+#    #+#             */
/*   Updated: 2025/09/22 09:46:04 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm("ShrubberyCreationForm", SCF_SIGN, SCF_EXEC, "home")
{
	std::cerr << "Created : " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:	AForm("ShrubberyCreationForm", SCF_SIGN, SCF_EXEC, target)
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
	std::cout << PURPLE(executor << " executed " << getName()) << std::endl;
	ShrubberyCreationForm::makeTree();
}

/* make tree */
void	ShrubberyCreationForm::makeTree() const
{
	std::ofstream	outfile;

	outfile.open((getTarget() + "_shrubbery").c_str());
	if (!outfile.is_open())
	{
		std::cout << "tree cannot be planted because the wife said no" << std::endl;
		return ;
	}
	outfile << tree;
}

const std::string ShrubberyCreationForm::tree = "   *\n  ***\n *****\n*******\n  |||\n" ;