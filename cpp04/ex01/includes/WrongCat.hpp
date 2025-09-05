/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:32:55 by weijian           #+#    #+#             */
/*   Updated: 2025/09/04 14:41:58 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		/* constructors */
		WrongCat();
		WrongCat(const WrongCat& other);
		~WrongCat();

		/* operators */
		WrongCat& operator=(const WrongCat& other);

		/* getters */
		void 		makeSound() const;

	protected:

	private:

} ;