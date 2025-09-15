/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:15:25 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 15:34:33 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Character.hpp"

#define	CURE "cure"
#define	ICE "ice"

class ICharacter;

class AMateria
{
	public:
	/* constructors */
	AMateria();
	AMateria(std::string const type);
	AMateria(AMateria& other);
	AMateria& operator=(AMateria& other);
	virtual ~AMateria();

	/* functions */
	std::string const&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

	protected:
	std::string	_type;
	bool		_equipped;
} ;