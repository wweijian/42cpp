/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:13:29 by weijian           #+#    #+#             */
/*   Updated: 2025/08/20 23:53:14 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* constructors */
Zombie::Zombie()
	:_name("Random zombie") {}

Zombie::Zombie(std::string name)
	:_name(name) {
	announce();
}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed" << std::endl;
}

/* functions */
void Zombie::announce()
{
	std::cout << _name << ": " << BRAINS << std::endl;
}