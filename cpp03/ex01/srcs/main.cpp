/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:37:00 by weijian           #+#    #+#             */
/*   Updated: 2025/09/08 10:26:35 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <cstdlib>

void	noHp(ClapTrap &clapTrap)
{
	clapTrap.takeDamage(10);
	clapTrap.attack("other");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(10);
}

void	noEnergy1(ClapTrap &clapTrap)
{
	while (clapTrap.getEnergy() > 0 && clapTrap.getHp())
		clapTrap.attack("other");
	clapTrap.attack("other");
	clapTrap.beRepaired(50);
	clapTrap.takeDamage(10);
}

void	noEnergy2(ClapTrap &clapTrap)
{
	while (clapTrap.getEnergy() > 0 && clapTrap.getHp())
		clapTrap.beRepaired(50);
	clapTrap.attack("other");
	clapTrap.beRepaired(50);
	clapTrap.takeDamage(10);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "usage: ./ex01 [n]" << std::endl;
		return (1);
	}

	ScavTrap scavTrap("scavvy");

	switch(std::atoi(av[1])) {
		case 0:
			scavTrap.guardGate(); break;
		case 1:
			noHp(scavTrap); break ;
		case 2:
			noEnergy1(scavTrap); break ;
		case 3:
			noEnergy2(scavTrap); break ;
		default:
			std::cout << "option unavailable" << std::endl;
	}
}
