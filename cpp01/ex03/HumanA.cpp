/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:43:04 by weijian           #+#    #+#             */
/*   Updated: 2025/08/25 11:11:35 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* constructors */
HumanA::HumanA()
	:	_name(setName()),
		_weapon()
{}

HumanA::HumanA(std::string name, Weapon &weapon)
	:	_name(name),
		_weapon(&weapon)
{}

HumanA::~HumanA()
{}

/* functions */

void	HumanA::attack()
{
	std::cout << _name << " attacks with their ";
	if (_weapon->getType().empty())
		std::cout << " FISTS!?" << std::endl;
	else
		std::cout << _weapon->getType() << std::endl;
}

std::string const	HumanA::setName()
{
	std::string	name;
	
	std::cout << "What is HumanA's Name?   " << std::endl;
	std::cin >> name;
	return (name);
}

std::string const	HumanA::getName()
{
	return (_name);
}