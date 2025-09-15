/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:17:19 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 16:55:34 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	_type = CURE;
}

Cure::Cure(std::string const type)
{
	_type = type;
}

Cure::Cure(const Cure& other)
{
	*this = other;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cerr << "Cure destroyed" << std::endl;
}

/* functions */

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout << " heals " << target.getName() << "'s wounds" << std::endl;
}