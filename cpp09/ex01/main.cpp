/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:19:32 by weijian           #+#    #+#             */
/*   Updated: 2025/09/21 22:05:24 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// container used: list (adapted to stack)
int main (int ac, char **av)
{
	if (ac != 2) {
		PRINT("usage: ./RPN \"1 2 + [...] \"");
		return (1);
	}
	TRY(PRINT(RPN::solve(av[1])));
}
