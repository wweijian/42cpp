/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:34:22 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 19:55:46 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	_type = ICE;
	std::cerr << "Ice created" << std::endl;
}

Ice::Ice(std::string const type)
{
	_type = type;
	std::cerr << "Ice created" << std::endl;
}

Ice::Ice(const Ice& other)
{
	*this = other;
	std::cerr << "Ice copied" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other) {
		_type = other._type;
		std::cerr << "Ice assigned" << std::endl;
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
	std::cout << "materia cloned" << std::endl;
	return new Ice(*this);
}

void	Ice::use(ICharacter &target)
{
	std::cout << " heals " << target.getName() << "'s wounds" << std::endl;
}