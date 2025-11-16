/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:27:11 by weijian           #+#    #+#             */
/*   Updated: 2025/11/15 22:36:55 by weijian          ###   ########.fr       */
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

template <typename C>
std::string printSorted(C ms)
{
	std::stringstream os;
	
	for (typename C::iterator it = ms.begin(); it != ms.end(); it++)
		os << *it << " ";
	return (os.str());
}

int main (int ac, char **av)
{
	if (ac == 1 || ac > 3001) {
		PRINT("usage: ./PMergeMe n1 ... (up to 3000 positive integers only)");
		return 1;
	}

	int						num;
	std::vector<int>		v;
	std::deque<int>			d;
	std::multiset<int>					m;

	try {
		for (int i = 1; i < ac; i++) {
			num = getNumber(av[i]);
			v.push_back(num);
			d.push_back(num);
			m.insert(num);
		}
		std::cout << "Element Count: " << v.size() << std::endl;
		std::cout << "Before: " << printSorted(v) << std::endl;
		std::cout << "After : " << printSorted(m) << std::endl;
		PMergeMe pm(v, d);
		std::cout << "\n\n\n\n" ;
		pm.printLists();
	} catch (std::exception &err) {
			std::cerr << err.what() << std::endl;
	}
}
