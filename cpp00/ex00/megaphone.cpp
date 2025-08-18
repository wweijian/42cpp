/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:53:47 by weijian           #+#    #+#             */
/*   Updated: 2025/08/18 20:15:20 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* 
	iostream includes:
		ios, streambuf, istream, ostream, iosfwd
	streambuf, istream, ostream:
		classes 

	The C++ Core Guidelines (and most style guides) recommend avoiding 
	 C-style casts except for very special low‐level situations.
	 static_cast works at compile time, gives more safety, and shows 
	 exactly what’s happening
*/

int main (int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int i = 1; av[i]; i++) {
			for (int j = 0; av[i][j] != 0; j++) {
				std::cout << (char) (toupper(av[i][j]));
			}
		}
	}
	std::cout << std::endl;
}