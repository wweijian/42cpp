/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:20:25 by weijian           #+#    #+#             */
/*   Updated: 2025/08/23 12:07:36 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* constructors */
Weapon::Weapon()
	: _type()
{}

Weapon::Weapon(std::string type)
	: _type(type)
{}

Weapon::~Weapon()
{}

/* functions */

std::string	Weapon::getType()
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
