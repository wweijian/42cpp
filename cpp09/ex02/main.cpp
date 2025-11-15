/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:27:11 by weijian           #+#    #+#             */
/*   Updated: 2025/11/15 13:38:25 by wjhoe            ###   ########.fr       */
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

std::string printSorted(std::multiset<int> ms)
{
	std::stringstream os;
	
	for (std::multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
		os << *it << " " << std::endl;
	return (os.str());
}

int main (int ac, char **av)
{
	if (ac == 1 || ac > 3001) {
		PRINT("usage: ./PMergeMe n1 ... (up to 3000 positive integers only)");
		return 1;
	}

	int					num;
	std::vector<int>		v[ac];
	std::deque<int>			d[ac];
	std::multiset<int>		m;

	try {
		for (int i = 1; i < ac; i++) {
			num = getNumber(av[i]);
			v[i - 1] = std::vector<int>(1, num);
			d[i - 1] = std::deque<int>(1, num);
			m.insert(num);
		}
		std::cout << "Before:" << printContainer(v, ac - 1) << std::endl;
		std::cout << "After :" << printSorted(m) << std::endl;
	} catch (std::exception &err) {
			std::cerr << err.what() << std::endl;
	}
}