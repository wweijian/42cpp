/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:34:59 by weijian           #+#    #+#             */
/*   Updated: 2025/08/22 00:10:14 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(int ac, char **av)
{
	if (ac < 2)
		return ;

	std::string	name;
	std::cin >> name;
	Zombie* horde = zombieHorde(std::atoi(av[1]), name);
	delete[] horde;
}
