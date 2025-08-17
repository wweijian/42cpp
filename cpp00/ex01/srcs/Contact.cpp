/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 21:40:22 by weijian           #+#    #+#             */
/*   Updated: 2025/08/17 20:47:48 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* 
Contact::Contact(void)	:	_FIRSTNAME();
							_LASTNAME;
							_NICKNAME;
							_NUMBER;
							_SECRET; */

// Constructors
Contact::Contact()
	: _firstName(setField(FIRST_NAME)), 
	_lastName(setField(LAST_NAME)),
	_nickname(setField(NICKNAME)),
	_number(setField(NUMBER)),
	_secret(setField(SECRET)) {}

Contact::Contact(std::string firstName,
					std::string lastName,
					std::string nickname,
					std::string number,
					std::string secret)
	: _firstName(firstName), 
	_lastName(lastName),
	_nickname(nickname),
	_number(number),
	_secret(secret) {}
	
Contact::Contact(const Contact &other)
	: _firstName(other._firstName), 
	_lastName(other._lastName),
	_nickname(other._nickname),
	_number(other._number),
	_secret(other._secret) {}

Contact&	Contact::operator=(const Contact& other) {
	if (this != &other) {
		*this = Contact(other);
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
