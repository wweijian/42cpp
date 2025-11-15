/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:09:41 by weijian           #+#    #+#             */
/*   Updated: 2025/11/15 18:19:50 by wjhoe            ###   ########.fr       */
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
#define	TIME(fn)	start = clock(); fn; time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000;

class PMergeMe
{
	public:
	/* constructors */
		PMergeMe();
		PMergeMe(std::vector<std::vector<int> > v, std::deque<std::deque<int> > d);
		PMergeMe(const PMergeMe &other);
		PMergeMe& operator=(const PMergeMe &other);
		~PMergeMe();

	/* functions */
		void		printLists();

	private:
	/* variables */
		std::vector<std::vector<int> >	_vec;
		std::deque<std::deque<int> >	_deque;

	/* type redefinition */
		typedef std::string::iterator	iterator;

	/* functions */
		template<typename C>
		void	sort (C& container);
} ;

/* print container */
template <typename C>
std::string printContainer(C& container, int count)
{
	std::stringstream os;

	for (int i = 0; i < count; i++) {
		if (i != 0)
			os << " ";
		os << container[i][0];
	}
	return (os.str());
}
