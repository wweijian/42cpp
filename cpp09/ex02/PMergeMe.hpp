/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:09:41 by weijian           #+#    #+#             */
/*   Updated: 2025/11/16 11:19:06 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>

#include <vector>
#include <deque>
#include <set>
#include <exception>
#include <cctype>
#include <ctime>
#include <iomanip>

#define	PRINT(os)	std::cout << os << std::endl;
#define	TRY(fn)		try {fn;} catch (std::exception &e) {PRINT(e.what());}
#define	TIME(fn)	clock_t start = clock(); fn; time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000;

class PMergeMe
{
	public:
	/* constructors */
		PMergeMe();
		PMergeMe(std::vector<int> v, std::deque<int> d);
		PMergeMe(const PMergeMe &other);
		PMergeMe& operator=(const PMergeMe &other);
		~PMergeMe();

	/* functions */
		void		printLists();

	private:
	/* variables */
		std::vector<int>	_vec;
		std::deque<int>		_deque;

	/* type redefinition */
		typedef std::string::iterator	iterator;

	/* functions */
		template <template <typename, typename> class Cont>
		static Cont<int, std::allocator<int> > sort(const Cont<int, std::allocator<int> >& src);
		
		template<typename C>
		static void	recurse(C& container);

		template <typename C>
		static void	insertPend(C& main, C& pend);

		template <typename C>
		static typename C::iterator	findNode(C& pend, int find);
} ;

/* print container */
template <typename C>
std::string printContainer(C& container)
{
	std::stringstream os;

	for (size_t i = 0; i < container.size(); i++) {
		if (i != 0)
			os << "\t";
		os << container[i][0];
	}
	return (os.str());
}

/*
	./PMergeMe 134 150 281 5712 481 190 482 2149 1038 88199 77

	134		150
	5712	281
	481		190
	2149	482
	88199	1038
			77
	
	5712	134
	2149	481
			88199

	5712	2149
*/