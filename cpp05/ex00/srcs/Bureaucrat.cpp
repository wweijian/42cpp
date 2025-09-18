#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:	_name("default"),
		_grade(150)
{
	std::cerr << "Created (" << *this << ")" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:	_name(name),
		_grade(grade)
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cerr << "Created (" << *this << ")" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat& other)
	:	_name(other._name),
		_grade(other._grade)
{
	std::cerr << "Copied (" << *this << ")" << std::endl;
}

Bureaucrat Bureaucrat::operator=(Bureaucrat& other)
{
	Bureaucrat res(other._name, other._grade);
	if (this != &other) {
		std::cerr << "Assigned (" << *this << ")" << std::endl;
		return (res);
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cerr << "Destroyed (" << *this << ")" << std::endl;
}

/* increment decrement */
void	Bureaucrat::incrementGrade()
{
	if (++_grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	if (--_grade < 1)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::operator++()
{
	if (++_grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::operator--()
{
	if (--_grade < 1)
		throw Bureaucrat::GradeTooLowException();
}

/* getters */

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("Bureaucrat's grade is too low");
}

/* print */
std::ostream& operator<<(std::ostream& os, Bureaucrat& bureau)
{
	os << bureau.getName() << ", bureacrat grade: " << bureau.getGrade();
	return (os);
}