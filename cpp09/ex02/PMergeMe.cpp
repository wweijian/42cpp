/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:01 by weijian           #+#    #+#             */
/*   Updated: 2025/11/17 12:09:00 by wjhoe            ###   ########.fr       */
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
	PRINT("\nFUNCTION CALL: find");
	std::cout << "find : " << find << std::endl;
	for (typename C::iterator it = pend.begin(); it != pend.end(); it++) {
		std::cout << (*it)[0] << std::endl;
		if ((*it)[0] == find) {
			std::cout << "found!" << std::endl; 
			return (it);
		}
	}
	PRINT("end returned");
	return (pend.end());
}

template <typename C>
void	PM::insertPend(C& main, C& pend)
{
	typename C::iterator	found; 

	for (size_t i = 0; pend.size() > 0 && (i * 2) < main.size(); i++) {
		found = findNode(pend, main[2 * i][1]);
		if (found != pend.end()) {
			main[2 * i].erase(main[2 * i].begin() + 1);
			main.insert(std::lower_bound(main.begin(), main.begin() + i * 2, *found), *found);
			pend.erase(found);
		}
	}
	if (pend.size() == 1) {
		main.insert(std::lower_bound(main.begin(), main.end(), pend[0]), pend[0]);
		pend.erase(pend.begin());
	}
}

#define FIRST container[i]
#define SECOND container[i + 1]
template <typename C>
void	PM::recurse(C& container)
{
	PRINT("\nFUNCTION CALL: SORT");
	if (container.size() < 2)
		return ;

	C main;
	C pend;

	// main to push back the vector<int>
	// pend takes the other vector<int>
	// main back references the last element added to main
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
