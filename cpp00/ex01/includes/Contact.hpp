/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:49:53 by weijian           #+#    #+#             */
/*   Updated: 2025/08/17 20:47:56 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

# define EMPTY "Field cannot be empty\n"

/*
	The contact fields are: first name, last name, nickname, phone number, and
	darkest secret. A saved contact can’t have empty fields.
*/

class Contact {
	public:
		Contact	(void);
		Contact(std::string firstName,
				std::string lastName,
				std::string nickname,
				std::string number,
				std::string secret);
		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
		
		/* Constants */
		enum Field {FIRST_NAME, LAST_NAME, NICKNAME, NUMBER, SECRET};
		
		/* Functions */
		const std::string getField(Field field);
	
	private:

		/* Setter functions */
		const std::string setField(Field field);

		/* Variables */
		const std::string	_firstName;
		const std::string	_lastName;
		const std::string	_nickname;
		const std::string	_number;
		const std::string	_secret;

		/* Utilities */
		bool	isAllDigits(std::string str);
	} ; 

#endif