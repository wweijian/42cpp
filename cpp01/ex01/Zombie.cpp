/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:13:29 by weijian           #+#    #+#             */
/*   Updated: 2025/08/22 00:00:39 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* constructors */
Zombie::Zombie()
	:_name("")
{}

Zombie::Zombie(std::string name)
	:_name(name)
{
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

/* while (getline(cin, str)) {

}

if (cin.bad()) {
    // IO error
} else if (!cin.eof()) {
    // format error (not possible with getline but possible with operator>>)
} else {
    // format error (not possible with getline but possible with operator>>)
    // or end of file (can't make the difference)
} */