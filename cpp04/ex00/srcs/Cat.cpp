/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:33:14 by weijian           #+#    #+#             */
/*   Updated: 2025/09/04 14:42:16 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type_ = "cat";
	std::cerr << "Cat constructed" << std::endl;	
}

Cat::Cat(const Cat& other)
	:	Animal(other)
{
	*this = other;
	std::cerr << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	std::cerr << "Cat destroyed" << std::endl;	
}

/* operators */
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other) {
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