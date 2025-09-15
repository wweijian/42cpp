/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:16:36 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 18:44:18 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* constructors */

Character::Character()
{
	for (int i = 0; i < 4; i++)
		_materiaSlot[i] = nullptr;
	std::cerr << "Character Constructed" << std::endl;
}

Character::Character(std::string const name)
			:	_name(name)
{
	for (int i = 0; i < 4; i++)
		_materiaSlot[i] = nullptr;
	std::cerr << "Character Constructed" << std::endl;
}

Character::Character(Character& other)
{
	this->_name = other._name;
	for (int i = 0; i < 4; i++) {
		if (other._materiaSlot[i] == nullptr)
			_materiaSlot[i] = nullptr;
		else
			_materiaSlot[i] = other._materiaSlot[i]->clone();
	}
	std::cerr << "Character Copied" << std::endl;
}

Character& Character::operator=(Character& other)
{
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (other._materiaSlot[i] == nullptr)
				_materiaSlot[i] = nullptr;
			else
				_materiaSlot[i] = other._materiaSlot[i]->clone();
		}
	}
	std::cerr << "Character Assigned" << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++) {
		if (_materiaSlot[i] != nullptr)
			delete _materiaSlot[i];
	}
	std::cerr << "Character Destroyed" << std::endl;
}

/* functions */
std::string const&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (!m) {
		std::cout << "materia does not exist" << std::endl;
		return ;
	}
	
	for (int i = 0; i < 4; i++) {
		if (_materiaSlot[i] == m) {
			std::cout << "materia is already equipped" << std::endl;
			return ;
		}
		if (_materiaSlot[i] == nullptr) {
			_materiaSlot[i] = m;
			break ;
		}
		if (i == 3)
			std::cout << "inventory full" << std::endl;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_materiaSlot[idx])
	{
		for (int i = 0; true; i++) {
			if (_unequipped[i] == nullptr) {
				_unequipped[i] = this->_materiaSlot[idx];
				break;
			}
		}
		_materiaSlot[idx] = nullptr;
	}
	else
		std::cout << "materia does not exist" << std::endl;
	
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || _materiaSlot[idx] == nullptr) {
		std::cout << "materia does not exist" << std::endl;
		return ;
	}
	std::cout << _name;
	_materiaSlot[idx]->use(target);
}
