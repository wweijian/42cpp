/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 07:41:33 by weijian           #+#    #+#             */
/*   Updated: 2025/11/19 11:21:51 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// container used: map
int main (int ac, char **av)
{
	if (ac != 2) {
		std::cout << "usage: ./btc <filename>" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc;
		btc.evaluatePositions(av[1]);
	} catch (std::exception &err) {
		PRINT(err.what());
		return 1;
	}
}
