/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:42:32 by weijian           #+#    #+#             */
/*   Updated: 2025/09/13 20:34:51 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		/* constructors */
		Dog();
		Dog(const Dog& other);
		~Dog();

		/* operators */
		Dog& operator=(const Dog& other);

		/* getters */
		void 	makeSound() const;
		Brain* getBrain() const;

	protected:

	private:
		Brain *_brain;
} ;
