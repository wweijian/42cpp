/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:02:00 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 18:54:25 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materiaSlot[i] = nullptr;
	std::cerr << "MateriaSource Constructed" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource& other)
{
	for (int i = 0; i < 4; i++) {
		if (other._materiaSlot[i] == nullptr)
			_materiaSlot[i] = nullptr;
		else
			_materiaSlot[i] = other._materiaSlot[i]->clone();
	}
	std::cerr << "MateriaSource Copied" << std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource& other)
{
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (other._materiaSlot[i] == nullptr)
				_materiaSlot[i] = nullptr;
			else
				_materiaSlot[i] = other._materiaSlot[i]->clone();
		}
	}
	std::cerr << "MateriaSource Assigned" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++) {
		if (_materiaSlot[i] != nullptr)
			delete _materiaSlot[i];
	}
	std::cerr << "MateriaSource Destroyed" << std::endl;
}

/* functions */

void 		MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++) {
		if (_materiaSlot[i] == nullptr) {
			_materiaSlot[i] = materia->clone();
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++) {
		if (_materiaSlot[i] && _materiaSlot[i]->getType() == type) {
			return(_materiaSlot[i]->clone());
		}
	}
	return (0);
}