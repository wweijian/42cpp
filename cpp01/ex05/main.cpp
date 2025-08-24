/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:40:09 by weijian           #+#    #+#             */
/*   Updated: 2025/08/24 13:30:50 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl 		harl;
	std::string	level;

	while(true)
	{
		std::cout << "what is your complaint?: " << std::flush;
		if (!(std::cin >> level))
			return (0);
		harl.complain(level);
	}
}
