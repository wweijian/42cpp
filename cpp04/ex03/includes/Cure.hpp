/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:19:27 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 15:39:20 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
	Cure();
	Cure(std::string const type);
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	~Cure();

	/* functions */
	AMateria*	clone() const;
	void		use(ICharacter& target) ;
} ;