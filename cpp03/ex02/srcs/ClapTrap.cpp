/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:44:26 by weijian           #+#    #+#             */
/*   Updated: 2025/09/01 07:52:27 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* constructors */
ClapTrap::ClapTrap()
	:	_name("Clappy"),
		_hitPts(CLAP_MAX_HP),
		_energyPts(CLAP_MAX_EP),
		_attackDmg(CLAP_DEFAULT_DMG)
{
	std::cerr << "[ClapTrap]" << _name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
	:	_name(name),
		_hitPts(CLAP_MAX_HP),
		_energyPts(CLAP_MAX_EP),
		_attackDmg(CLAP_DEFAULT_DMG)
{
	std::cerr << "[ClapTrap]" << _name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	:	_name(other._name),
		_hitPts(other._hitPts),
		_energyPts(other._energyPts),
		_attackDmg(other._attackDmg)
{
	std::cerr << "[ClapTrap]" << _name << " copied" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other) {
		_name = other._name;
		_hitPts = other._hitPts;
		_energyPts = other._energyPts;
		_attackDmg = other._attackDmg;
	}
	std::cerr << "[ClapTrap]" << _name << " assigned" << std::endl;
	return *this;
}

/* destructor */
ClapTrap::~ClapTrap()
{
	std::cerr << "[ClapTrap]" << _name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPts && _hitPts) {
		std::cout	<< _name << " attacks " << target << ", "
					<< "causing " << _attackDmg
					<< " points of damage!";
		_energyPts--;
	}
	else if (!_energyPts && !_hitPts)
		std::cout << _name << " has no hp and energy left to attack!";
	else if (!_energyPts)
		std::cout << _name << " has no energy left to attack!";
	else if (!_hitPts)
		std::cout << _name << " has no hp left to attack!";
	printEnergy();
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPts == 0)
		std::cout << _name << " has no more hp!";
	else if (_hitPts <= amount)
	{
		std::cout	<< _name << " took "
					<< _hitPts << " damage "
					<< "and is now dead ):";
		_hitPts = 0;
	}
	else
	{
		_hitPts -= amount;
		std::cout	<< _name << " took "
					<< amount << " damage "
					<< "and has " 
					<< _hitPts << " left!";
	}
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPts == 0)
	{
		std::cout << _name << " can't heal because its dead" << std::endl;
		return ;
	}
	if (_energyPts == 0)
	{
		std::cout << _name << " can't heal because it has no energy" << std::endl;
		return ;
	}
	if (_hitPts == getMaxHP())
		std::cout << _name << " is at full hp!";
	else if (_hitPts + amount >= getMaxHP())
		std::cout	<< _name << " has healed "
					<< _hitPts + amount - getMaxHP() << " to the full HP";
	else
		std::cout	<< _name << " has healed "
					<< _hitPts << " HP";
	printEnergy();
	std::cout << std::endl;
	_energyPts--;
}

/* getters */
std::string	ClapTrap::getName() const
{
	return (_name);
}

unsigned int	ClapTrap::getHp() const
{
	return(_hitPts);
}

unsigned int	ClapTrap::getEnergy() const
{
	return(_energyPts);
}

unsigned int	ClapTrap::getAttack() const
{
	return(_attackDmg);
}

unsigned int	ClapTrap::getMaxHP() const
{
	return (CLAP_MAX_HP);
}

/* print */
std::ostream&	operator<<(std::ostream& out, const ClapTrap& clapTrap)
{
	out << clapTrap.getName();
	return (out);
}

void	ClapTrap::printEnergy()
{
	std::cout	<< "    (ENERGY LEFT: " << _energyPts << ")";
}