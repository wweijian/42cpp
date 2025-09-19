/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 22:12:08 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 22:33:40 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

typedef struct hello
{
	std::string	word;
	int			number;
} hi;

void	hihi(hi& things)
{
	things.word = "hello";
	things.number++;
}

void	printhi(hi things)
{
	std::cout << "hi " << things.word << " and " << things.number << std::endl;
}

void	printnum(int n)
{
	std::cout << "int " << n << std::endl;
}

void	squares(int& i)
{
	i = i * i;
}

int main ()
{
	int	numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	hi	things[5] = {	{"a", 0},
						{"b", 1},
						{"c", 2},
						{"d", 3},
						{"e", 4},};

	iter(numbers, 10, printnum);
	iter(things, 5, printhi);
	iter(numbers, 10, squares);
	iter(things, 5, hihi);
	iter(numbers, 10, printnum);
	iter(things, 5, printhi);

	const int	number2[10] = {0, 7, 2, 3, 4, 5, 6, 7, 8, 9};
	iter(number2, 10, printnum);
	// iter(number2, 10, squares); // type mismatch
}