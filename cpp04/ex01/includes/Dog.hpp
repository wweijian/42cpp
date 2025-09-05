/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:42:32 by weijian           #+#    #+#             */
/*   Updated: 2025/09/05 10:27:51 by weijian          ###   ########.fr       */
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
		void 		makeSound() const;
	
	private:
		/* variables */
		Brain	*brain_;

} ;