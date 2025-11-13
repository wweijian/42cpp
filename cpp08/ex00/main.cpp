/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 08:58:31 by weijian           #+#    #+#             */
/*   Updated: 2025/11/13 21:02:17 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main ()
{
	int		numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	const std::vector<int> v(numbers, numbers + 10);
	std::vector<int> v2(numbers, numbers + 10);
	
	if (easyfind(v, 9) != v.end())
		std::cout << "found!" << std::endl;
	else
		std::cout << "not found!" << std::endl;
	if (easyfind(v, 10) == v.end())
		std::cout << "not found!" << std::endl;
	if (easyfind(v2, 9) != v2.end())
		std::cout << "found!" << std::endl;
	else
		std::cout << "not found!" << std::endl;
	if (easyfind(v2, 10) == v2.end())
		std::cout << "not found!" << std::endl;
}
