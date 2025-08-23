/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:57:33 by weijian           #+#    #+#             */
/*   Updated: 2025/08/23 09:14:19 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

/* macros */
# define BRAINS "BraiiiiiiinnnzzzZ..."

class Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		/* functions */
		void	setName ( std::string );

	private:
		/* variables */
		std::string	_name;
		
		/* functions */
		void	announce ( void );
		
} ;

/* 
	In C++ a static member function inside a class means:
	It belongs to the class itself, not to any particular object.
*/