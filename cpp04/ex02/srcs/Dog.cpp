/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:43:59 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 18:29:32 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
		: _brain()
{
	type = "dog";
	_brain = new Brain();
	std::cerr << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog& other)
	:	Animal(other)
{
	type = other.getType();
	_brain = new Brain(*(other.getBrain()));
	std::cerr << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cerr << "Dog destroyed" << std::endl;	
}

/* operators */
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other) {
		type = other.getType();
		_brain = new Brain(*(other.getBrain()));
	}
	std::cerr << "Dog assignment operator" << std::endl;
	return (*this);
}

Brain* Dog::getBrain() const
{
	return (_brain);
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
