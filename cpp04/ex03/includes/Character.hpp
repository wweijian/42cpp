/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 08:35:55 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 19:38:06 by wjhoe            ###   ########.fr       */
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
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
	AMateria*			getMateria(int i);

	private:
	/* variables */
	std::string			_name;
	AMateria*			_materiaSlot[4];
} ;