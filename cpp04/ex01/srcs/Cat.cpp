/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:33:14 by weijian           #+#    #+#             */
/*   Updated: 2025/09/05 09:21:28 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type_ = "cat";
	brain_ = new Brain();
	std::cerr << "Cat constructed" << std::endl;	
}

Cat::Cat(const Cat& other)
{
	*this = other;
	brain_ = new Brain(*other.brain_);
	std::cerr << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	delete brain_;
	std::cerr << "Cat destroyed" << std::endl;
}

/* operators */
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		type_ = other.type_;
	}
	return (*this);
}

/* function */
void	Cat::makeSound() const
{
	std::cout << "meoW" << std::endl;
}

/* print */
std::ostream& operator<<(std::ostream &out, const Cat& cat)
{
	out << cat.getType();
	return (out);
}