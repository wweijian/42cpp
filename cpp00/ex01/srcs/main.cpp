/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:27:42 by weijian           #+#    #+#             */
/*   Updated: 2025/08/17 20:59:01 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


int	main(void)
{
	std::string	input;
	PhoneBook	phoneBook;

	phoneBook.clearScreen();
	std::cout << "[Your terrible PhoneBook]\n" << std::endl;
	while ((input = phoneBook.displayMenu()) != "EXIT") {
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else if (input == "EXIT")
			break ;
		else
		{
			phoneBook.clearScreen();
			std::cout << "Input not recognized. Try again.\n" << std::endl;
			continue ;
		}
	}
	std::cout << "The program quits and the contacts are lost forever!" << std::endl;
}