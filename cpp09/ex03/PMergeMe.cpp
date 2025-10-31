/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:01 by weijian           #+#    #+#             */
/*   Updated: 2025/10/31 15:02:41 by weijian          ###   ########.fr       */
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
	// TIME(sort(_deque));
	// PRINT("Time to process a range of " << ac - 1 << " elements with std::deque : " << time << "us");
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

template <template <typename> class C>
std::pair<int, int>	getPair(C<std::pair <int, int> >& pairList, int input)
{
	typename C<std::pair <int, int> >::iterator it = pairList.begin();

	while (it != pairList.end()) {
		if (it->first == input) {
			pairList.erase(it);
			return (*it);
		}
		it++;
	}
	return (getPair(pairList, 0));
}

/* template <template <typename> class C>
void	PMergeMe::sort(C<int>& list)
{
	C<std::pair<int, int> >	pairList;
	C<int>					pend;
	C<int>					main;

	if (list.size() < 2)
		return ;
	for (typename C<int>::iterator it = list.begin(); list.size() > 0; it = list.begin()) {
		std::cout << "list size " << list.size() << std::endl;
		std::cout << "compares: " << *it << " " << *(it + 1) << std::endl;
		if (list.size() > 1) {
			if (*it > *(it + 1)) {
				pairList.push_back(std::make_pair(*it, *(it + 1)));
				main.push_back(*it);
			}
			else {
				pairList.push_back(std::make_pair(*(it + 1), *it));
				main.push_back(*(it + 1));
			}
			list.erase(it, it + 2);
		}
		else {
			pairList.push_back(std::make_pair(*it, int()));
			main.push_back(*it);
			list.erase(it);
		}
	}
	sort(main);
	for (size_t i = 0; i < pairList.size(); it++) {
		main.push_back(getPair(pairList, *it).second);
		PRINT(main.size());
		PRINT("hello");
	}
	main.insert(main.end(), list.begin(), list.end());
	list = main;
	PRINT("hi");
}
*/
template <template <typename> class C, typename T>
void	PMergeMe::sort(C<T>& list)
{
	C<std::pair<T, T> >	pairList;
	(void) list;
	sort(pairList);
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
	// can i check for duplicate sargs>? 
}
