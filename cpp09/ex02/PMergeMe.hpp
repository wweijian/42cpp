/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:09:41 by weijian           #+#    #+#             */
/*   Updated: 2025/11/14 15:06:23 by wjhoe            ###   ########.fr       */
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
		PMergeMe(std::vector<int>, std::deque<int>);
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

} ;

template <typename C>
std::string printContainer(C container)
{
	std::stringstream os;

	for (typename C::iterator it = container.begin(); it != container.end();
			it++) {
		if (it != container.begin())
			os << " ";
		os << *it;
	}
	return (os.str());
}
