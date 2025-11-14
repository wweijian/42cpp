/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:27:11 by weijian           #+#    #+#             */
/*   Updated: 2025/11/14 14:58:50 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

// containers used: vector, deque, multiset
int	getNumber(char *av)
{
	int					num;
	std::string			arg;
	std::stringstream 	ss;

	arg = std::string(av);
	for (std::string::iterator it = arg.begin(); it != arg.end(); it++) {
		if (!isdigit(*it))
			throw std::invalid_argument("non-digit argument: " + arg);
	}
	ss << arg;
	ss >> num;
	if (ss.fail())
		throw std::invalid_argument("integer arg overflow: " + arg);
	return (num);
}

int main (int ac, char **av)
{
	if (ac == 1) {
		PRINT("usage: ./PMergeMe n1 ... (positive integers only)");
		return 1;
	}
	
	int					num;
	std::vector<int>	v;
	std::deque<int>		d;
	std::multiset<int>	m;

	try {
		for (int i = 1; i < ac; i++) {
			num = getNumber(av[i]);
			v.push_back(num);
			d.push_back(num);
			m.insert(num);
		}
		std::cout << "Before:" << printContainer(v) << std::endl;
		std::cout << "After :" << printContainer(m) << std::endl;
	} catch (std::exception &err) {
			std::cerr << err.what() << std::endl;
	}
}