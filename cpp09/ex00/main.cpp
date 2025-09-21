/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 07:41:33 by weijian           #+#    #+#             */
/*   Updated: 2025/09/21 14:59:37 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// container used: map
int main (int ac, char **av)
{
	if (ac != 2)
		return 1;
	try {
		BitcoinExchange btc;
		btc.evaluatePositions(av[1]);
	} catch (std::exception &err) {
		PRINT(err.what());
		return 1;
	}
}
