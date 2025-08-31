/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:20:32 by weijian           #+#    #+#             */
/*   Updated: 2025/08/25 13:52:38 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Weapon
{
	public:
		/* constructors */
		Weapon(std::string type);

		~Weapon();

		/* functions */
		const std::string	&getType();
		void				setType(std::string const type);

	private:
		/* constructor */
		Weapon();

		/* variables */
		std::string	_type;
} ;
