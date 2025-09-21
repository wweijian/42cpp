/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:01 by weijian           #+#    #+#             */
/*   Updated: 2025/09/21 18:06:44 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{}

PMergeMe::PMergeMe(int ac, char **av)
{
	validateArgs(ac, av);
	std::cout << "Before:";
	int n;
	for (int i = 1; i < ac; i++) {
		n = std::stoi(av[i]);
		_vec.push_back(n);
		_deque.push_back(n);
		_set.insert(n); 
		std::cout << " " << av[i];
	}
	std::cout << "\nAfter :";
	for (std::set<int>::iterator it = _set.begin(); it != _set.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	clock_t	start;
	double	time;
	TIME(sort(_deque));
	PRINT("Time to process a range of " << ac - 1 << " elements with std::deque : " << time << "us");
	TIME(sort(_vec));
	PRINT("Time to process a range of " << ac - 1 << " elements with std::vector : " << time << "us");
}

PMergeMe::PMergeMe(const PMergeMe &other)
		:	_vec(other._vec),
			_deque(other._deque),
			_set(other._set)
{}

PMergeMe& PMergeMe::operator=(const PMergeMe &other)
{
	if (this == &other) {
		delete this;
		new (this) PMergeMe(other);
	}
	return (*this);
}

PMergeMe::~PMergeMe()
{}

void	PMergeMe::printLists()
{
	PRINT("----- DEQUE  ----");
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	PRINT("----- VECTOR ----");
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

template <typename C> void	PMergeMe::insertLoser(C& winner, C& loser)
{
	for (typename C::iterator itLoser = loser.begin(); itLoser != loser.end(); itLoser++) {
		for (typename C::iterator itWinner = winner.begin(); itWinner != winner.end(); itWinner++) {
			if (*itWinner >= *itLoser) {
				winner.insert(itWinner, *itLoser);
				break ;
			}
			else if (itWinner + 1 == winner.end())
				winner.push_back(*itLoser);
		}
	}
}

template <typename C> void	PMergeMe::sort(C& list)
{
	C	winner;
	C	loser;
	
	if (list.size() < 2)
		return ;
	typename C::iterator	it = list.begin();
	if (list.size() % 2 == 1) {
		loser.push_back(*it);
		it++;
	}
	while (it != list.end()) {
		loser.push_back(*it <= *(it + 1) ? *it : *(it + 1));
		winner.push_back(*it <= *(it + 1) ? *(it + 1) : *it);
		it += 2;
	}
	sort(winner);
	insertLoser(winner, loser);
}

void	PMergeMe::validateArgs(int ac, char** av)
{
	std::string	arg;
	for (int i = 1; i < ac; i++) {
		arg = av[i];
		for (iterator it = arg.begin(); it != arg.end(); it++) {
			if (!isdigit(*it))
				throw std::invalid_argument(arg);
		}
	}
}
