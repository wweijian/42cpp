/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:02:16 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 21:53:06 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Form.hpp"

#define BRACKET(os)	'[' << os << ']'
#define RED(os)		"\e[31m" << os << "\e[0m"
#define YELLOW(os)	"\e[33m" << os << "\e[0m"
#define GREEN(os)	"\e[32m" << os << "\e[0m"
#define CYAN(os)	"\e[36m" << os << "\e[0m"

class Form;

class Bureaucrat
{
	public:
	/* constructors */
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

	/* increment decrement */
		void				incrementGrade();
		void				decrementGrade();
		void				operator++();
		void				operator--();

		void				signForm(Form& form);

	/* getters */
		std::string			getName() const;
		int					getGrade() const;
	
	/* exceptions */
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

	private:
	/* variables */
		std::string const	_name;
		int					_grade;
	
	/* static variables */
		static const int	lowest;
		static const int	highest;
} ;

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau);

/* notes */
// what does throw do
// should i catch inside or outside the constructors (pros vs cons)