/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:49:29 by weijian           #+#    #+#             */
/*   Updated: 2025/08/23 12:40:33 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	public:
		/* constructors */
		HumanB();
		/* pass a reference instead of making a copy of the club
		so that when that value changes, it'll reflect in this as well
		refer to ex02 
		if you store _weapon = &weapon; you’re actually storing the address 
		of the real club, not some temporary.
		*/
		HumanB(std::string name, Weapon& weapon);
		HumanB(std::string name);

		~HumanB();
		
		/* functions */
		void 				attack();
		std::string const	getName();
		void				setWeapon(Weapon &weapon);

	private:
		/* variables */
		std::string const	_name;
		Weapon				*_weapon;

} ;