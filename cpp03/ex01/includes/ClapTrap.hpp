/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:25:40 by weijian           #+#    #+#             */
/*   Updated: 2025/08/31 15:13:22 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define	MAX_HP 10
#define	MAX_EP 10
#define	DEFAULT_DMG 0

class	ClapTrap
{
	public:
		/* constructor */
		ClapTrap();
		~ClapTrap();
		ClapTrap(const ClapTrap& clapTrap);
		ClapTrap& operator=(const ClapTrap& other);

		/* functions */
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		/* getters */
		std::string		getName() const ;
		unsigned int	getHp() const ;
		unsigned int	getEnergy() const ;
		unsigned int	getAttack() const ;

	private:
		/* variables */
		std::string		_name;
		unsigned int	_hitPts;
		unsigned int	_energyPts;
		unsigned int	_attackDmg;

		/* function */
		void		printEnergy();
} ;