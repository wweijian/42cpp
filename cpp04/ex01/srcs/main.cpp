/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:38:53 by weijian           #+#    #+#             */
/*   Updated: 2025/09/05 08:14:33 by weijian          ###   ########.fr       */
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
		else
			zoo[i] = new Cat();
	}

	const Dog *temp = static_cast<const Dog*>(zoo[SIZE % 2]);
	temp->getBrain()->setIdea("water is wet");
	Dog upDog = *temp;
	upDog.getBrain()->setIdea("water is not wet");
	std::cout << "updog: " << upDog.getBrain()-> getIdeas(0);
	std::cout << "temp: " << temp->getBrain()-> getIdeas(0);

	for (int i = 0; i < SIZE; i++) {
		delete zoo[i];
	}
	return 0;
}