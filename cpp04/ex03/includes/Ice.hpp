/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:34:04 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 18:34:12 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
	Ice();
	Ice(std::string const type);
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);
	~Ice();

	/* functions */
	AMateria*	clone() const;
	void		use(ICharacter& target) ;
} ;