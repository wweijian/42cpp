/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:01 by weijian           #+#    #+#             */
/*   Updated: 2025/11/14 15:07:58 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{}

PMergeMe::PMergeMe(std::vector<int> v, std::deque<int> d)
	:	_vec(v),
		_deque(d)
{}

PMergeMe::PMergeMe(const PMergeMe &other)
		:	_vec(other._vec),
			_deque(other._deque)
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
	std::cout << "----- DEQUE  ----\n" << printContainer(_deque) << std::endl;
	std::cout << "----- VECTOR ----\n" << printContainer(_vec) << std::endl;
}
