/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:32:55 by weijian           #+#    #+#             */
/*   Updated: 2025/09/13 21:22:57 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

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
		Brain* 		getBrain() const;


	protected:

	private:
		Brain *_brain;
} ;