/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:06:32 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 18:26:06 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cerr << "Animal constructed" << std::endl;	
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cerr << "Animal copied" << std::endl;
}

Animal::~Animal()
{
	std::cerr << "Animal destroyed" << std::endl;	
}

/* operators */
Animal& Animal::operator=(const Animal& other)
{
	if (this != &other) {
		type = other.type;
	}
	std::cerr << "Animal assigned" << std::endl;
	return (*this);
}

/* function */
std::string	Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << "[ unknown beast sounds ]" << std::endl;
}

/* print */
std::ostream& operator<<(std::ostream &out, const Animal& animal)
{
	out << animal.getType();
	return (out);
}