/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:43:59 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 18:26:35 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "dog";
	std::cerr << "Dog constructed" << std::endl;	
}

Dog::Dog(const Dog& other)
	:	Animal(other)
{
	*this = other;
	std::cerr << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	std::cerr << "Dog destroyed" << std::endl;	
}

/* operators */
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other) {
		type = other.type;
	}
	return (*this);
}

/* function */

void	Dog::makeSound() const
{
	std::cout << "wooF" << std::endl;
}

/* print */
std::ostream& operator<<(std::ostream &out, const Dog& dog)
{
	out << dog.getType();
	return (out);
}