/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 21:40:22 by weijian           #+#    #+#             */
/*   Updated: 2025/08/18 16:02:36 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructors

Contact::Contact()
	: _firstName(""),
	_lastName(""),
	_nickname(""),
	_number(""),
	_secret("") {}
	
Contact::Contact(int i)
	: _firstName(setField(FIRST_NAME)),
	_lastName(setField(LAST_NAME)),
	_nickname(setField(NICKNAME)),
	_number(setField(NUMBER)),
	_secret(setField(SECRET)) {
		(void) i;
	}
	
Contact::Contact(const Contact &other)
	: _firstName(other._firstName),
	_lastName(other._lastName),
	_nickname(other._nickname),
	_number(other._number),
	_secret(other._secret) {}

Contact&	Contact::operator=(const Contact& other) {
	if (this != &other) {
		this->_firstName = other._firstName;
		this->_lastName = other._lastName;
		this->_nickname = other._nickname;
		this->_number = other._number;
		this->_secret = other._secret;
	}
	return (*this);
}

// Setter Funcitons

bool	Contact::isAllDigits(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

const std::string	Contact::setField(Contact::Field field)
{
	std::string	message;
	std::string	res = "";

	switch (field) {
		case (FIRST_NAME):
			message = "First Name: "; break;
		case (LAST_NAME):
			message = "Last Name: "; break;
		case (NICKNAME):
			message = "Nickname: "; break;
		case (NUMBER):
			message = "Number: "; break;
		case (SECRET):
			message = "Secret: "; break;
	}
	while (res == "")
	{
		std::cout << message;
		std::cin >> res;
		if (res == "")
			std::cout << EMPTY;
		else if (field == NUMBER && !isAllDigits(res))
		{
			std::cout << "Only digits are allowed" << std::endl; 
			res = "";
		}
	}
	return (res);
}

const std::string Contact::getField(Field field)
{
	std::string	res;
	
	switch(field) {
		case (FIRST_NAME): res = this->_firstName; break ;
		case (LAST_NAME): res = this->_lastName; break ;
		case (NICKNAME): res = this->_nickname; break ;
		case (NUMBER): res = this->_number; break ;
		case (SECRET): res = this->_secret; break ;
		default: return ("Error: No such field");
	}
	if (res.size() > 9)
	{
		res[9] = '.';
		res.resize(10);
	}
	return (res);
}
