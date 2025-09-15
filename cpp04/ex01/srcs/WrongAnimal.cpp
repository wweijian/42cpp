/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:06:32 by weijian           #+#    #+#             */
/*   Updated: 2025/09/04 14:34:24 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cerr << "WrongAnimal constructed" << std::endl;	
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
	std::cerr << "WrongAnimal copied" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cerr << "WrongAnimal destroyed" << std::endl;	
}

/* operators */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other) {
		type = other.type;
	}
	return (*this);
}

/* function */
std::string	WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "[ unknown beast sounds ]" << std::endl;
}

/* print */
std::ostream& operator<<(std::ostream &out, const WrongAnimal& wrongAnimal)
{
	out << wrongAnimal.getType();
	return (out);
}