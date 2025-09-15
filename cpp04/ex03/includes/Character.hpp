/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 08:35:55 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 18:51:31 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

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