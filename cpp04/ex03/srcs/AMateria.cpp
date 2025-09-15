/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:05:14 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 15:31:37 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* constructors */

AMateria::AMateria()
		:	_equipped(false)
{
	std::cerr << "AMateria Constructed" << std::endl;
}

AMateria::AMateria(std::string const type)
		:	_type(type),
			_equipped(false)
{
	std::cerr << "AMateria Constructed" << std::endl;
}

AMateria::AMateria(AMateria& other)
		:	_equipped(false)
{
	_type = other._type;
	std::cerr << "AMateria Copied" << std::endl;
}

AMateria& AMateria::operator=(AMateria& other)
{
	if (this != &other) {
		_type = other._type;
		_equipped = false;
	}
	std::cerr << "AMateria Assigned" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cerr << "AMateria Destroyed" << std::endl;
}

std::string const&	AMateria::getType() const
{
	return(_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "nothing happened to" << target.getName() << std::endl;
}
