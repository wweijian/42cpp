/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:04 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 21:53:18 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
#define BRACKET(os)	'[' << os << ']'
#define RED(os)		"\e[31m" << os << "\e[0m"
#define YELLOW(os)	"\e[33m" << os << "\e[0m"
#define GREEN(os)	"\e[32m" << os << "\e[0m"
#define CYAN(os)	"\e[36m" << os << "\e[0m"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, int minSign, int minExec);
		Form(const Form& f);
		Form& operator=(const Form& f);
		~Form();

	/* exceptions */
		class	FormAlreadySigned : public std::exception
		{
			public:
				const char*	what() const throw();
		} ;
		class	GradeTooHighException : public std::exception
		{
			public:
				const char* 		what() const throw();
		} ;

		class	GradeTooLowException : public std::exception
		{
			public:
				const char*			what() const throw();
		} ;

	/* functions */
		void				beSigned(Bureaucrat& b);

	/* getters */
		std::string			getName() const;
		bool				getSigned() const;
		int					getMinSign() const;
		int					getMinExec() const;

	private:
	/* variables */
		const std::string	_name;
		bool				_signed;
		const int			_minSign;
		const int			_minExec;

	/* static variables */
		static const int	lowest;
		static const int	highest;
} ;

std::ostream& operator<<(std::ostream& os, const Form& form);