/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:11:49 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 23:05:35 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* macros */
#define	RRF_SIGN 72
#define RRF_EXEC 45

/* colors */
#define BRACKET(os)	'[' << os << ']'
#define RED(os)		"\e[31m" << os << "\e[0m"
#define YELLOW(os)	"\e[33m" << os << "\e[0m"
#define GREEN(os)	"\e[32m" << os << "\e[0m"
#define CYAN(os)	"\e[36m" << os << "\e[0m"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& f);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();

	/* functions */
		void	execute(Bureaucrat const & executor) const;

	private:
		void	robotomy() const;

} ;
