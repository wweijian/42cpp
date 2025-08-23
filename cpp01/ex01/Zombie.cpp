/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:13:29 by weijian           #+#    #+#             */
/*   Updated: 2025/08/23 09:24:51 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* constructors */
Zombie::Zombie()
	:_name("")
{}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed" << std::endl;
}

/* functions */
void Zombie::announce()
{
	std::cout << _name << ": " << BRAINS << std::endl;
	
}
void Zombie::setName(std::string name)
{
	_name = name;
	announce();
}