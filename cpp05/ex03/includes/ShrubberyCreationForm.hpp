/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:11:49 by weijian           #+#    #+#             */
/*   Updated: 2025/09/22 09:44:31 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

#include "Bureaucrat.hpp"

/* macros */
#define	SCF_SIGN 145
#define SCF_EXEC 137

/* colors */
#define BRACKET(os)	'[' << os << ']'
#define RED(os)		"\e[31m" << os << "\e[0m"
#define YELLOW(os)	"\e[33m" << os << "\e[0m"
#define GREEN(os)	"\e[32m" << os << "\e[0m"
#define CYAN(os)	"\e[36m" << os << "\e[0m"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& f);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();

	/* functions */
		void						execute(Bureaucrat const & executor) const;

	private:
		void						makeTree() const;
		static const std::string	tree;
} ;
