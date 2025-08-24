/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:09:59 by weijian           #+#    #+#             */
/*   Updated: 2025/08/24 16:15:20 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# define DEBUG "DEBUG"
# define INFO "INFO"
# define WARNING "WARNING"
# define ERROR "ERROR"

/* 
	static
	A static data member belongs to the class itself, not to any particular object.
	There is only one copy of it in memory, shared by all instances of the class.
	You access it with ClassName::member, not through an object 

	const
	A const variable cannot be modified after initialization.
	For class members, it means the value is read-only once set.

	static const:
	a shared variable that cannot be changed by any members of the class
	(like std::endl)
*/

class Harl
{
	public:
	/* constructors */
		Harl();
		~Harl();

	/* functions */
		static void	complain (std::string level);

	private:
	/* functions */
		static void	debug();
		static void	info();
		static void	warning();
		static void	error();
		static void	gibberish();
} ;