/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:15:51 by weijian           #+#    #+#             */
/*   Updated: 2025/08/22 00:11:21 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].~Zombie();
		new (&horde[i]) Zombie(name);
	}
	return (horde);
}
