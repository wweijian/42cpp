/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:09:41 by weijian           #+#    #+#             */
/*   Updated: 2025/11/18 22:18:39 by wjhoe            ###   ########.fr       */
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

	os << "\n";
	for (size_t i = 0; i < container.size(); i++) {
		os << "vector " << i << ": ";
		for (size_t j = 0; j < container[i].size(); j++) {
			// if (j != 0)
				os << " ";
			os << container[i][j];
		}
		os << "\n";
	}
	return (os.str());
}

/* structs */
typedef struct s_jacobsthal {
	int	current;
	int	last;
	int	lastlast;
	int max;
	void next()
	{
		if (current == 0) {
			lastlast = 0;
			last = 0;
			current = 1;
		}
		else if (current == 1) {
			lastlast = 1;
			last = 1;
			current = 3;
		}
		else {
			lastlast = last;
			last = current;
			current = last + 2 * lastlast;
		}
	}
}	t_jacobsthal;

/* misc */
template <typename C>
void isSorted(C& container)
{
	for (size_t i = 1; i < container.size(); i++) {
		if (container[i] < container[i - 1]) {
			std::cout << "container not sorted" << std::endl;
			return;
		}
	}
	std::cout << "congratulation it's sorted" << std::endl;
}