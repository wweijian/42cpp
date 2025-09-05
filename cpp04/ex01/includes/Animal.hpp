/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:57:16 by weijian           #+#    #+#             */
/*   Updated: 2025/09/04 13:48:42 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
	public:
		/* constructors */
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();

		/* operators */
		Animal& operator=(const Animal& other);

		/* getters */
		std::string			getType() const ;
		virtual void 		makeSound() const;

	protected:
		/* variables */
		std::string	type_;

	private:

} ;