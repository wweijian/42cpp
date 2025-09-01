/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:54:54 by weijian           #+#    #+#             */
/*   Updated: 2025/09/01 09:35:57 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

#define	DIAM_MAX_HP FRAG_MAX_HP
#define	DIAM_MAX_EP SCAV_MAX_HP
#define	DIAM_DEFAULT_DMG FRAG_DEFAULT_DMG

class	DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		/* constructor */
		DiamondTrap();
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap& DiamondTrap);
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap();

		/* functions */
		void 					whoAmI();
	private:
		const std::string		_name;
		unsigned int			getMaxHP() const;

	protected:
} ;

/* 
Since ClapTrap is now virtual, the most-derived class (DiamondTrap) is responsible 
for constructing it.
_hitPts, _energyPts, _attackDmg are assigned in the body, not in the initializer list,
 because they belong to the ClapTrap subobject.
*/
