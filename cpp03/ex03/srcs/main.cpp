/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:37:00 by weijian           #+#    #+#             */
/*   Updated: 2025/09/01 09:03:59 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <cstdlib>

void	noHp(DiamondTrap &clapTrap)
{
	clapTrap.takeDamage(10);
	clapTrap.attack("other");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(10);
}

void	noEnergy1(DiamondTrap &clapTrap)
{
	while (clapTrap.getEnergy() > 0 && clapTrap.getHp())
		clapTrap.attack("other");
	clapTrap.attack("other");
	clapTrap.beRepaired(50);
	clapTrap.takeDamage(10);
}

void	noEnergy2(DiamondTrap &clapTrap)
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
		return (1);
		
	DiamondTrap qwerty("qwerty");

	switch(std::atoi(av[1])) {
		case 0:
			qwerty.whoAmI(); break;
		case 1:
			noHp(qwerty); break ;
		case 2:
			noEnergy1(qwerty); break ;
		case 3:
			noEnergy2(qwerty); break ;
		case 4:
			qwerty.highFiveGuys(); break;
		case 5:
			qwerty.guardGate(); break;
		default:
			std::cout << "option unavailable" << std::endl;
	}
}
