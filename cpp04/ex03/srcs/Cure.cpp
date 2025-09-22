/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:17:19 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 19:54:58 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	_type = CURE;
	std::cerr << "Cure created" << std::endl;
}

Cure::Cure(std::string const type)
{
	_type = type;
	std::cerr << "Cure created" << std::endl;
}

Cure::Cure(const Cure& other)
{
	*this = other;
	std::cerr << "Cure copied" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other) {
		_type = other._type;
		std::cerr << "Cure assigned" << std::endl;
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
	std::cout << "materia cloned" << std::endl;
	return new Cure(*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout << " heals " << target.getName() << "'s wounds" << std::endl;
}