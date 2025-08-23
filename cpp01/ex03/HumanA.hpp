/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:38:45 by weijian           #+#    #+#             */
/*   Updated: 2025/08/23 11:59:13 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	public:
		/* constructors */
		HumanA();
		HumanA(std::string name, Weapon weapon);

		~HumanA();
		
		/* functions */
		void 				attack();
		std::string const	getName();

	private:
		/* variables */
		std::string const	_name;
		Weapon				_weapon;

		/* functions */
		std::string const	setName();
} ;