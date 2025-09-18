/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:02:16 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 12:22:52 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat
{
	public:
	/* constructors */
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat& other);
		Bureaucrat operator=(Bureaucrat& other);
		~Bureaucrat();

	/* increment decrement */
		void				incrementGrade();
		void				decrementGrade();
		void				operator++();
		void				operator--();

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
		
} ;

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureau);

/* notes */
// what does throw do
// should i catch inside or outside the constructors (pros vs cons)