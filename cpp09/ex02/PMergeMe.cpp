/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:01 by weijian           #+#    #+#             */
/*   Updated: 2025/11/15 18:29:18 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#define	PM PMergeMe

PMergeMe::PMergeMe()
{}

PMergeMe::PMergeMe(std::vector<std::vector<int> > v, std::deque<std::deque<int> > d)
	:	_vec(v),
		_deque(d)
{
	sort(_vec);
}

PM::PM(const PM &other)
		:	_vec(other._vec),
			_deque(other._deque)
{}

PM& PM::operator=(const PM &other)
{
	if (this == &other) {
		delete this;
		new (this) PM(other);
	}
	return (*this);
}

PM::~PM()
{}

void	PM::printLists()
{
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec[i][0] << " ";
	};
	std::cout << std::endl;
}

template <typename C>
void	PM::sort(C& container)
{
	std::cout << "sort " << std::endl;
	if (container.size() < 2)
		return ;

	C main;

	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		main.push_back(container[i] > container [i + 1] ? container[i] : container [i + 1]);
		main.back().push_back(main.back() == container[i] ? container[i + 1][0] : container [i][0]);
		std::cout << main.back()[0] << " && " << main.back()[1] << std::endl;
	}
	// todo: missing dangling elements
	sort(main);
	container = main;
}
