/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:54:54 by weijian           #+#    #+#             */
/*   Updated: 2025/09/01 07:52:13 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "ClapTrap.hpp"

#define	FRAG_MAX_HP 100
#define	FRAG_MAX_EP 100
#define	FRAG_DEFAULT_DMG 30

class	FragTrap : public ClapTrap
{
	public:
		/* constructor */
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap& FragTrap);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();

		/* functions */
		void 			highFiveGuys();
	private:
		unsigned int	getMaxHP() const;

	protected:
} ;

/* 
	In C++, private members are inherited by derived classes,
	but they cannot be accessed directly by the derived class.
	This means that while the derived class object contains the private members 
	of its base class, you cannot use them by name inside the derived class. 
	To access private members, you must use public or protected getter/setter 
	functions defined in the base class. 
	In contrast, protected members are accessible within derived classes, 
	and public members are accessible both inside derived classes and from outside the class.
*/
