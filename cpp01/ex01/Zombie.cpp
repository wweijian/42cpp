/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:13:29 by weijian           #+#    #+#             */
/*   Updated: 2025/08/21 22:29:44 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* constructors */
Zombie::Zombie()
	:_name(nameZombie()) {}

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

void Zombie::nameZombie()
{
	std::string	name;
	
	std::cout << "give your zombie a name: " << std::endl;
	while (!(std::cin >> name)) {
		if (std::cin.eof())
			std::cout << "give a proper name, dummy: " << std::endl
		else {
			std::cin.clear();
			std::cin.ignore();
		}
	}
}