/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:33:14 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 18:29:32 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
		: _brain()
{
	type = "Cat";
	_brain = new Brain();
	std::cerr << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other)
	:	Animal(other)
{
	type = other.getType();
	_brain = new Brain(*(other.getBrain()));
	std::cerr << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cerr << "Cat destroyed" << std::endl;
}

/* operators */
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other) {
		type = other.getType();
		_brain = new Brain(*(other.getBrain()));
	}
	std::cerr << "Cat assignment operator" << std::endl;
	return (*this);
}

Brain* Cat::getBrain() const
{
	return (_brain);
}

/* function */

void	Cat::makeSound() const
{
	std::cout << "wooF" << std::endl;
}

/* print */
std::ostream& operator<<(std::ostream &out, const Cat& cat)
{
	out << cat.getType();
	return (out);
}
