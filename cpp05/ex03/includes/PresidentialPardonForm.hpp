/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:11:49 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 21:40:07 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

#include "Bureaucrat.hpp"

/* macros */
#define	PPF_SIGN 25
#define PPF_EXEC 5

/* colors */
#define BRACKET(os)	'[' << os << ']'
#define RED(os)		"\e[31m" << os << "\e[0m"
#define YELLOW(os)	"\e[33m" << os << "\e[0m"
#define GREEN(os)	"\e[32m" << os << "\e[0m"
#define CYAN(os)	"\e[36m" << os << "\e[0m"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& f);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();

	/* functions */
		void	execute(Bureaucrat const & executor) const;

	private:
		void	pardon() const;
} ;
