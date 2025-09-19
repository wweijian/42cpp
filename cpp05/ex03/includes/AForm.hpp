/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:04 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 19:11:14 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#define BRACKET(os)	'[' << os << ']'
#define RED(os)		"\e[31m" << os << "\e[0m"
#define GREEN(os)	"\e[32m" << os << "\e[0m"
#define YELLOW(os)	"\e[33m" << os << "\e[0m"
#define BLUE(os)	"\e[34m" << os << "\e[0m"
#define PURPLE(os)	"\e[35m" << os << "\e[0m"
#define CYAN(os)	"\e[36m" << os << "\e[0m"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, int minSign, int minExec, std::string target);
		virtual AForm& operator=(AForm& f); // can't return an object of AForm in abstract class
		AForm(const AForm& f);
		virtual ~AForm();

	/* exceptions */
		class	FormAlreadySigned : public std::exception
		{
			public:
				const char*	what() const throw();
		} ;

		class	FormNotSigned : public std::exception
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
		virtual void		execute(Bureaucrat const & executor) const = 0;

	/* getters */
		std::string			getName() const;
		std::string			getTarget() const;
		bool				getSigned() const;
		int					getMinSign() const;
		int					getMinExec() const;

	private:
	/* constructor */
	/* variables */
		const std::string	_name;
		bool				_signed;
		const int			_minSign;
		const int			_minExec;
		const std::string	_target;
	
	/* static variables */
		static const int	lowest;
		static const int	highest;
} ;

std::ostream& operator<<(std::ostream& os, const AForm& form);