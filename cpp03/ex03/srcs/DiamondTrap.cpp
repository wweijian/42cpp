/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:54:59 by weijian           #+#    #+#             */
/*   Updated: 2025/09/01 07:19:44 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* constructors */
DiamondTrap::DiamondTrap()
	:	ClapTrap("diamond_clap_trap"),
		_name("diamond")
{
	_hitPts = DIAM_MAX_HP;
	_energyPts = DIAM_MAX_EP;
	_attackDmg = DIAM_DEFAULT_DMG;
	std::cerr << "[DiamondTrap]" << _name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name)
	:	ClapTrap(name + "_clap_name"),
		FragTrap(name),
		ScavTrap(name),
		_name(name)
{
	_hitPts = DIAM_MAX_HP;
	_energyPts = DIAM_MAX_EP;
	_attackDmg = DIAM_DEFAULT_DMG;
	std::cerr << "[DiamondTrap]" << _name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
	:	ClapTrap(other),
		FragTrap(other),
		ScavTrap(other),
		_name(other._name)
{
	*this = other;
	std::cerr << "[DiamondTrap]" << _name << " copied" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cerr << "[DiamondTrap]" << _name << " assigned" << std::endl;
	return *this;
}

/* destructor */
DiamondTrap::~DiamondTrap()
{
	std::cerr << "[DiamondTrap]" << _name << " destroyed" << std::endl;
}

/* getter */
unsigned int		DiamondTrap::getMaxHP() const
{
	return (DIAM_MAX_EP);
}

/* function */
void DiamondTrap::whoAmI()
{
	std::cout	<< "DiamondTrap: " << _name << "\n"
				<< "ClapTrap name: " << ClapTrap::_name
				<< std::endl;
}