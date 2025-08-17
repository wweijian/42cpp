/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 23:02:35 by weijian           #+#    #+#             */
/*   Updated: 2025/08/17 20:58:40 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook(void)
{
	for (int i = 7; i >= 0; i--)
		this->contact[i] = new Contact("", "", "", "", "");
	count = 0;
}

// Functions
std::string	PhoneBook::displayMenu(void)
{
	std::string	command;
	
	std::cout << "MENU\n" << std::endl;
	std::cout << "ADD: save a new contact" << std::endl;
	std::cout << "SEARCH: display a specific contact" << std::endl;
	std::cout << "EXIT: exit" << std::endl;
	std::cout << std::endl;
	std::cin  >> command;
	for (int i = 0; command[i] != 0; i++) {
		command[i] = toupper(command[i]);
	}
	return (command);
}

void	PhoneBook::addContact(void)
{
	clearScreen();
	std::cout << "Adding a new contact...\n" << std::endl;

	for (int i = 7; i > 0; i--)
		this->contact[i] = this->contact[i - 1];
	this->contact[0] = new Contact();
	if (count < 8) count++;
	clearScreen();
	std::cout << this->contact[0]->getField(Contact::NICKNAME) << " has been added to your contacts\n" << std::endl;
}

void	PhoneBook::searchContact()
{
	int	index;
	
	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST_NAME" << "|";
	std::cout << std::setw(10) << "LAST_NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME";
	std::cout << std::endl;
	for (int i = 0; i < this->count; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << this->contact[i]->getField(Contact::FIRST_NAME) << "|";
		std::cout << std::setw(10) << this->contact[i]->getField(Contact::LAST_NAME) << "|";
		std::cout << std::setw(10) << this->contact[i]->getField(Contact::NICKNAME);
		std::cout << std::endl;
	}
	std::cout << "Key the index of the entry to display: ";
	while (!(std::cin >> index) || index >= this->count)
	{
		clearScreen();
		std::cout << "Invalid input. Choose from the available indices." << std::endl;
		std::cin.clear();
		std::cout << std::endl << "Key the index of the entry to display: " << std::endl;
		return (searchContact());
	}
	clearScreen();
	std::cout << "index: " << index << std::endl;
	std::cout << "firstName: " << this->contact[index]->getField(Contact::FIRST_NAME) << std::endl;
	std::cout << "lastName: " << this->contact[index]->getField(Contact::LAST_NAME) << std::endl;
	std::cout << "nickname: " << this->contact[index]->getField(Contact::NICKNAME) << std::endl;
	std::cout << "number: " << this->contact[index]->getField(Contact::NUMBER) << std::endl;
	std::cout << "secret: " << this->contact[index]->getField(Contact::SECRET) << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
}