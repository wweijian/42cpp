/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:17:46 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 21:40:08 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate()
{
	srand((unsigned int)time(NULL));

	int	i = rand() % 3;
	switch(i) {
		case (0):
			std::cout << "[A] generated" << std::endl;
			return (new A);
		case (1):
			std::cout << "[B] generated" << std::endl;
			return (new B);
		default:
			std::cout << "[C] generated" << std::endl;
			return (new C);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "this is A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "this is B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "this is C" << std::endl;
}

void identify(Base& p)
{
	try {
		(void) (dynamic_cast<A&>(p));
		std::cout << "this is reference of A" << std::endl;
	} catch (std::exception &err) {
		try {
			(void) (dynamic_cast<B&>(p));
			std::cout << "this is reference of B" << std::endl;
		} catch (std::exception &err) {
			try {
				(void) (dynamic_cast<C&>(p));
				std::cout << "this is reference of C" << std::endl;
			} catch (std::exception &err) {
				std::cerr << "somehow not any of it" << std::endl;
			}	
		}
	}
}

int main()
{
	Base	*p = generate();
	
	identify(p);
	identify(*p);
	delete p;
}