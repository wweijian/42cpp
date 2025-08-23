/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:20:32 by weijian           #+#    #+#             */
/*   Updated: 2025/08/23 11:31:32 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Weapon
{
	public:
		/* constructors */
		Weapon();
		Weapon(std::string type);

		~Weapon();

		/* functions */
		std::string	getType();
		void		setType(std::string const type);

	private:
		/* variables */
		std::string	_type;

		/* functions */
} ;
