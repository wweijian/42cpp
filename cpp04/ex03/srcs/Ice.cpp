/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:34:22 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 18:57:52 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	_type = ICE;
}

Ice::Ice(std::string const type)
{
	_type = type;
}

Ice::Ice(const Ice& other)
{
	*this = other;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

Ice::~Ice()
{
	std::cerr << "Ice destroyed" << std::endl;
}

/* functions */

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter &target)
{
	std::cout << " shoots an ice bolt at " << target.getName() << std::endl;
}