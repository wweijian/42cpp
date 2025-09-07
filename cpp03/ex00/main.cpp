/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:37:00 by weijian           #+#    #+#             */
/*   Updated: 2025/08/31 21:14:27 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
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
	while (clapTrap.getEnergy() > 0 && clapTrap.getHp() > 0)
		clapTrap.attack("other");
	clapTrap.attack("other");
	clapTrap.beRepaired(50);
	clapTrap.takeDamage(10);
}

void	noEnergy2(ClapTrap &clapTrap)
{
	while (clapTrap.getEnergy() > 0 && clapTrap.getHp() > 0)
		clapTrap.beRepaired(50);
	clapTrap.attack("other");
	clapTrap.beRepaired(50);
	clapTrap.takeDamage(10);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
		
	ClapTrap clapTrap;

	switch(std::atoi(av[1])) {
		case 1:
			noHp(clapTrap); break ;
		case 2:
			noEnergy1(clapTrap); break ;
		case 3:
			noEnergy2(clapTrap); break ;
		default:
			std::cout << "option unavailable" << std::endl;
	}
}
