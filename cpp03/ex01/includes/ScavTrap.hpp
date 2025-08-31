/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:54:54 by weijian           #+#    #+#             */
/*   Updated: 2025/08/31 17:02:21 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

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

class	ScavTrap
{
	public:

	private:

	protected:
} ;