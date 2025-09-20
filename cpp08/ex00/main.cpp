/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 08:58:31 by weijian           #+#    #+#             */
/*   Updated: 2025/09/20 13:10:33 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"

int main ()
{
	int		numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	if (easyfind(numbers, 9))
		std::cout << "found!" << std::endl;
	else
		std::cout << "not found!" << std::endl;

	if (easyfind(numbers, 10))
		std::cout << "not found!" << std::endl;

	// std::cout << easyfind(numbers, 9) << std::endl;
	// std::cout << easyfind(numbers, 10) << std::endl;
}
