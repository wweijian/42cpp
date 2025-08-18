/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:49:51 by weijian           #+#    #+#             */
/*   Updated: 2025/08/18 12:09:09 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook	(void); 

		void		addContact();
		void		searchContact();
		void		printContact();
		std::string	displayMenu();
		void		clearScreen();
	
	private:
		Contact		*_contact[8];
		int			_count;
} ;

#endif