/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:54:59 by weijian           #+#    #+#             */
/*   Updated: 2025/09/01 07:52:36 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* constructors */
ScavTrap::ScavTrap()
	:	ClapTrap()
{
	_name = "scavvy";
	_hitPts = SCAV_MAX_HP;
	_energyPts = SCAV_MAX_EP;
	_attackDmg = SCAV_DEFAULT_DMG;
	std::cerr << "[ScavTrap]" << _name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
	:	ClapTrap(name)
{
	_hitPts = SCAV_MAX_HP;
	_energyPts = SCAV_MAX_EP;
	_attackDmg = SCAV_DEFAULT_DMG;
	std::cerr << "[ScavTrap]" << _name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) 
	:	ClapTrap(other)
{
	*this = other;
	std::cerr << "[ScavTrap]" << _name << " copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cerr << "[ScavTrap]" << _name << " assigned" << std::endl;
	return *this;
}

/* destructor */
ScavTrap::~ScavTrap()
{
	std::cerr << "[ScavTrap]" << _name << " destroyed" << std::endl;
}

/* getter */
unsigned int		ScavTrap::getMaxHP() const
{
	return (SCAV_MAX_EP);
}

/* function */
void ScavTrap::guardGate()
{
	std::cout << _name << " is now in Gate keeper mode!" << std::endl;
}