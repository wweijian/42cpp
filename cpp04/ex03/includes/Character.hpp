/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 08:35:55 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 16:41:44 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
	virtual ~ICharacter();
	
	virtual std::string const& getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
} ;

class Character : public ICharacter
{
	public:
	/* constructors */
	Character();
	Character(std::string const name);
	Character(Character& other);
	Character& operator=(Character& other);
	~Character();

	/* functions */
	std::string const&	getName() const;
	virtual void		equip(AMateria* m);
	virtual void		unequip(int idx);
	virtual void		use(int idx, ICharacter& target);

	private:
	/* variables */
	std::string			_name;
	AMateria*			_materiaSlot[4];
	AMateria*			_unequipped[];
} ;