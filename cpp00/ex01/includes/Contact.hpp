/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:49:53 by weijian           #+#    #+#             */
/*   Updated: 2025/08/18 16:10:24 by wjhoe            ###   ########.fr       */
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
		Contact(int i);
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
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;

		/* Utilities */
		bool	isAllDigits(std::string str);
	} ; 

#endif