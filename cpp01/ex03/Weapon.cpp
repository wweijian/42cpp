/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:20:25 by weijian           #+#    #+#             */
/*   Updated: 2025/08/25 13:50:51 by wjhoe            ###   ########.fr       */
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

const std::string	&Weapon::getType()
{
	return (_type);
}

void	Weapon::setType(std::string const type)
{
	_type = type;
}
