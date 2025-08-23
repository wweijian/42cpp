/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:50:37 by weijian           #+#    #+#             */
/*   Updated: 2025/08/23 12:29:15 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* constructors */
HumanB::HumanB()
	:	_name(),
		_weapon()
{}

HumanB::HumanB(std::string name, Weapon& weapon)
	:	_name(name),
		_weapon(&weapon)
{}

HumanB::HumanB(std::string name)
	:	_name(name),
		_weapon(NULL)
{}

HumanB::~HumanB()
{}

/* functions */

void	HumanB::attack()
{
	std::cout << _name << " attacks with their ";
	if ((*_weapon).getType().empty())
		std::cout << " FISTS!?" << std::endl;
	else
		std::cout << (*_weapon).getType() << std::endl;
}

std::string const	HumanB::getName()
{
	return (_name);
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}