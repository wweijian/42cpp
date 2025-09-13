/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:38:53 by weijian           #+#    #+#             */
/*   Updated: 2025/09/13 21:11:39 by wjhoe            ###   ########.fr       */
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
	
	static_cast<const Dog*>(zoo[1])->getBrain()->setIdea("water is wet");
	std::cout << static_cast<const Dog*>(zoo[1])->getBrain()->getIdeas(0) << std::endl;
	const Dog* upDog = new Dog(*(static_cast<const Dog*> (zoo[1])));
	upDog->getBrain()->setIdea("water is not wet");
	std::cout << static_cast<const Dog*>(zoo[1])->getBrain()->getIdeas(0) << std::endl;
	std::cout << upDog->getBrain()->getIdeas(0) << std::endl;
	static_cast<const Dog*>(zoo[1])->getBrain()->setIdea("syau handsome");
	upDog->getBrain()->setIdea("syau ugly");
	std::cout << static_cast<const Dog*>(zoo[1])->getBrain()->getIdeas(1) << std::endl;
	std::cout << upDog->getBrain()->getIdeas(1) << std::endl;
	
	upDog->makeSound();

	for (int i = 0; i < SIZE; i++) {
		delete zoo[i];
	}
	return 0;
}