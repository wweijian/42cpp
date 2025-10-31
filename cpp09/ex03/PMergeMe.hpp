/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:09:41 by weijian           #+#    #+#             */
/*   Updated: 2025/10/31 15:02:13 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
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

#define MAX_DEPTH 12

class PMergeMe
{
	public:
	/* constructors */
		PMergeMe();
		PMergeMe(int ac, char **av);
		PMergeMe(const PMergeMe &other);
		PMergeMe& operator=(const PMergeMe &other);
		~PMergeMe();

	/* functions */
		void				printLists();
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deque;
		std::multiset<int>	_set;

	/* type redefinition */
		typedef std::string::iterator	iterator;

	/* functions */
/*  		template <template <typename> class C>
		static void	sort(C<int>& list); */
template <template <typename> class C, typename T>
void	sort(C<T>& list);
		template <typename C>
		void						insertLoser(C& winner, C& loser);
		void						validateArgs(int ac, char** av);
} ;
