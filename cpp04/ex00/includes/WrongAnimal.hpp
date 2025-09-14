/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:57:16 by weijian           #+#    #+#             */
/*   Updated: 2025/09/04 13:48:42 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
	public:
		/* constructors */
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal();

		/* operators */
		WrongAnimal& operator=(const WrongAnimal& other);

		/* getters */
		std::string	getType() const ;
		void 		makeSound() const;

	protected:
		/* variables */
		std::string	type_;

	private:

} ;