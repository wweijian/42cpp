/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:54:59 by weijian           #+#    #+#             */
/*   Updated: 2025/09/01 07:19:44 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* constructors */
FragTrap::FragTrap()
	:	ClapTrap()
{
	_name = "fraggy";
	_hitPts = FRAG_MAX_HP;
	_energyPts = FRAG_MAX_EP;
	_attackDmg = FRAG_DEFAULT_DMG;
	std::cerr << "[FragTrap]" << _name << " constructed" << std::endl;
}

FragTrap::FragTrap(std::string name)
	:	ClapTrap(name)
{
	_hitPts = FRAG_MAX_HP;
	_energyPts = FRAG_MAX_EP;
	_attackDmg = FRAG_DEFAULT_DMG;
	std::cerr << "[FragTrap]" << _name << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) 
	:	ClapTrap(other)
{
	*this = other;
	std::cerr << "[FragTrap]" << _name << " copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cerr << "[FragTrap]" << _name << " assigned" << std::endl;
	return *this;
}

/* destructor */
FragTrap::~FragTrap()
{
	std::cerr << "[FragTrap]" << _name << " destroyed" << std::endl;
}

/* getter */
unsigned int		FragTrap::getMaxHP() const
{
	return (FRAG_MAX_EP);
}

/* function */
void FragTrap::highFiveGuys()
{
	std::cout << _name << " requests for the highest of fives!" << std::endl;
}