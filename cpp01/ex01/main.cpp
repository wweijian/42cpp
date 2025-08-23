/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:34:59 by weijian           #+#    #+#             */
/*   Updated: 2025/08/23 09:27:09 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	std::string	name;
	if (ac > 2)
		name = av[2];
	else {
		std::cout << "name please: ";
		std::cin >> name;
	}
	Zombie* horde = zombieHorde(std::atoi(av[1]), name);
	delete[] horde;
}
