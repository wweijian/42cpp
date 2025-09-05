/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:32:55 by weijian           #+#    #+#             */
/*   Updated: 2025/09/04 14:48:00 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		/* constructors */
		Cat();
		Cat(const Cat& other);
		~Cat();

		/* operators */
		Cat& operator=(const Cat& other);

		/* getters */
		void 		makeSound() const;

	protected:

	private:

} ;