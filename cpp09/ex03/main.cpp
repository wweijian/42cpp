/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:27:11 by weijian           #+#    #+#             */
/*   Updated: 2025/10/28 15:22:33 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

// containers used: vector, deque, multiset
int main (int ac, char **av)
{
	if (ac == 1) {
		PRINT("usage: ./PMergeMe n1 ... [positive integers only]");
		return 1;
	}
	TRY(PMergeMe hi(ac, av); hi.printLists());
}

/* int main ()
{
	std::pair<int, int> b(10001, 1000);
	std::pair<int, int> c(10000, 10000);

} */