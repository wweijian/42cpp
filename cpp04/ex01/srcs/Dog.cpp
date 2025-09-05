/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:43:59 by weijian           #+#    #+#             */
/*   Updated: 2025/09/05 10:33:19 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	type_ = "dog";
	brain_ = new Brain();
	std::cerr << "Dog constructed" << std::endl;	
}

Dog::Dog(const Dog& other)
{
	*this = other;
	brain_ = new Brain(*other.brain_);
	std::cerr << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	delete brain_;
	std::cerr << "Dog destroyed" << std::endl;
}

/* operators */
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
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