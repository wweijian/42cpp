/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:25:40 by weijian           #+#    #+#             */
/*   Updated: 2025/09/12 08:05:25 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define	CLAP_MAX_HP 10
#define	CLAP_MAX_EP 10
#define	CLAP_DEFAULT_DMG 0

class	ClapTrap
{
	public:
		/* constructor */
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& clapTrap);
		ClapTrap& operator=(const ClapTrap& other);
		virtual ~ClapTrap();

		/* functions */
		void 					attack(const std::string& target);
		void 					takeDamage(unsigned int amount);
		void 					beRepaired(unsigned int amount);

		/* getters */
		std::string				getName() const ;
		unsigned int			getHp() const ;
		unsigned int			getEnergy() const ;
		unsigned int			getAttack() const ;

	protected:
		/* variables */
		std::string				_name;
		unsigned int			_hitPts;
		unsigned int			_energyPts;
		unsigned int			_attackDmg;

		/* static const variables */
		virtual unsigned int	getMaxHP() const ;

		/* function */
		void					printEnergy();
} ;