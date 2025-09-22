/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:02:00 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 20:01:26 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materiaSlot[i] = NULL;
	std::cerr << "MateriaSource Constructed" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource& other)
{
	for (int i = 0; i < 4; i++) {
		if (other._materiaSlot[i] == NULL)
			_materiaSlot[i] = NULL;
		else
			_materiaSlot[i] = other._materiaSlot[i]->clone();
	}
	std::cerr << "MateriaSource Copied" << std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource& other)
{
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (other._materiaSlot[i] == NULL)
				_materiaSlot[i] = NULL;
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
		if (_materiaSlot[i] != NULL)
			delete _materiaSlot[i];
	}
	std::cerr << "MateriaSource Destroyed" << std::endl;
}

/* functions */

void 		MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == NULL) {
		std::cout << "materia not learned" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (_materiaSlot[i] == NULL) {
			_materiaSlot[i] = materia;
			std::cout << "materia learned" << std::endl;
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++) {
		if (_materiaSlot[i] && _materiaSlot[i]->getType() == type) {
			std::cout << "materia created" << std::endl;
			return(_materiaSlot[i]->clone());
		}
	}
	std::cout << "materia not created" << std::endl;
	return (0);
}