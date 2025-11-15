/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:01 by weijian           #+#    #+#             */
/*   Updated: 2025/11/15 15:11:14 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#define	PM PMergeMe

PMergeMe::PMergeMe()
{}

PMergeMe::PMergeMe(std::vector<void *> v, std::deque<void *> d)
	:	_vec(v),
		_deque(d)
{
	sort(v);
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

/* void	PM::printLists()
{
	std::cout << "----- DEQUE  ----\n" << printContainer(_deque) << std::endl;
	std::cout << "----- VECTOR ----\n" << printContainer(_vec) << std::endl;
}
 */
template <template <typename, typename> class C>
void	PM::sort (C<void *, std::allocator<void *> >& container)
{
	(void) container;
}

