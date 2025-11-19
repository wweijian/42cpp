/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:01 by weijian           #+#    #+#             */
/*   Updated: 2025/11/19 10:20:20 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#define	PM PMergeMe

PMergeMe::PMergeMe()
{}

PMergeMe::PMergeMe(std::vector<int> v, std::deque<int> d)
	:	_vec(sort(v)),
		_deque(sort(d)),
		_size(v.size())
{
	clock_t start = clock();

	_vec = sort(v);
	TIME("std::vector");
	start = clock();
	_deque = sort(d);
	TIME("std::deque")
	// isSorted(_vec);
	// isSorted(_deque);
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
	std::cout << "/// vector ///\n";
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "/// deque ///\n";
	for (size_t i = 0; i < _deque.size(); i++) {
		std::cout << _deque[i] << " ";
	}
	std::cout << std::endl;
}

template <template <typename, typename> class Cont>
Cont<int, std::allocator<int> > PM::sort(const Cont<int, std::allocator<int> >& src)
{
	typedef Cont<int, std::allocator<int> > Inner;
	typedef Cont<Inner, std::allocator<Inner> > Outer;

	Outer	graph;
	Inner	dst;

	for (size_t i = 0; i < src.size(); ++i)
		graph.push_back(Inner(1, src[i]));
	recurse(graph);
	for (size_t i = 0; i < graph.size(); ++i)
		dst.push_back(graph[i][0]);
	return dst;
}

template <typename C>
typename C::iterator	PM::findNode(C& pend, int find)
{
	for (typename C::iterator it = pend.begin(); it != pend.end(); it++) {
		if ((*it)[0] == find) {
			return (it);
		}
	}
	throw std::runtime_error("pend not found");
	return (pend.end());
}

// lower_bound is binary sort
template <typename C>
void	PM::insertPend(C& main, C& pend)
{
	t_jacobsthal			j = {0, -1, -1, static_cast<int>(pend.size() - 1)};
	int						i = j.current;

	C pendCopy;

	for(size_t i = 0; i < main.size(); i++){
		pendCopy.push_back(*findNode(pend, main[i][1]));
		main[i].erase(main[i].begin() + 1);
	}
	if (pend.size() > main.size())
		pendCopy.push_back(*(pend.end() - 1));
	while (j.last < j.max) {
		i = j.current > j.max ? j.max : j.current;
		while (i > j.last) {
			main.insert(std::lower_bound(main.begin(), main.end(), pendCopy[i]), pendCopy[i]);
			i--;
		}
		j.next();
	}
}

#define FIRST container[i]
#define SECOND container[i + 1]
template <typename C>
void	PM::recurse(C& container)
{
	if (container.size() < 2)
		return ;

	C main;
	C pend;

	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		main.push_back(FIRST > SECOND ? FIRST : SECOND); 
		pend.push_back(main.back() == FIRST ? SECOND : FIRST); 
		main.back().insert(main.back().begin() + 1, (main.back() == FIRST ? SECOND[0] : FIRST[0])); 
	}
	
	if (container.size() % 2 == 1)
		pend.push_back(container.back());
	recurse(main);
	insertPend(main, pend);
	container = main;
}
