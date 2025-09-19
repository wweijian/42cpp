/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:42:19 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 13:04:16 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "usage: ./convert <string>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
}