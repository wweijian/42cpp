/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:38:53 by weijian           #+#    #+#             */
/*   Updated: 2025/09/05 10:34:25 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define SIZE 10

int main()
{
	const Animal* zoo[SIZE];
	for (int i = 0; i < SIZE; i++) {
		if (i % 2)
			zoo[i] = new Dog();
		if (!(i % 2))
			zoo[i] = new Cat();
	}
	Dog upDog(*(dynamic_cast<const Dog*>(zoo[5])));
	for (int i = 0; i < SIZE; i++) {
		delete zoo[i];
	}
	std::cout << "upDog says"; upDog.makeSound();
	return 0;
}