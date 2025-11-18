/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:01 by weijian           #+#    #+#             */
/*   Updated: 2025/11/18 22:24:42 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#define	PM PMergeMe

PMergeMe::PMergeMe()
{}

PMergeMe::PMergeMe(std::vector<int> v, std::deque<int> d)
	:	_vec(sort(v)),
		_deque()
{
	std::cout << "\n\n\n\n" ;
	PRINT("vector size: " << _vec.size());
	// isSorted(_vec);
	(void) d;
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
		std::cout << _vec[i] << " ";
	};
	std::cout << std::endl;
}

template <template <typename, typename> class Cont>
Cont<int, std::allocator<int> > PM::sort(const Cont<int, std::allocator<int> >& src)
{
	typedef Cont<int, std::allocator<int> > Inner;
	typedef Cont<Inner, std::allocator<Inner> > Outer;

	Outer graph;
	Inner dst;

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
	PRINT("FUNCTION CALL: find");
	std::cout << "find : " << find << std::endl;
	for (typename C::iterator it = pend.begin(); it != pend.end(); it++) {
		PRINT((*it)[0]);
		if ((*it)[0] == find) {
			std::cout << "found!" << std::endl; 
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
	t_jacobsthal			j = {0, -1, -1, static_cast<int>(main.size() - 1)};
	int						i = j.current;

	for(size_t i = 0; i < main.size(); i++){
		pend[i][0] = main[i][1];
	}
	main.insert(main.begin(), pend[0]);
	// if (pend.size() > 1)
	// 	main.insert(std::lower_bound(main.begin(), main.begin() + 1, pend[1]), pend[1]);
	while (j.last < static_cast<int>(pend.size())) {
		i = j.current > j.max ? j.max : j.current;
		while (i > j.last) {
			main.insert(std::lower_bound(main.begin(), main.end(), pend[i]), pend[i]);
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
