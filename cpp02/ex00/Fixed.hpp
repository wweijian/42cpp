/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:08:01 by weijian           #+#    #+#             */
/*   Updated: 2025/08/24 18:11:48 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


/* 
	The const after the parentheses applies to the member function itself, 
	meaning that the function does not modify the object it belongs to
	Inside this function, you cannot change any non-mutable member 
	variables of the class.

	[const int function] just means you can't modify the output later
*/
class Fixed 
{
	public:
	/* constructors */
	Fixed();
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed& operator=(const Fixed &fixed);
	
	/* functions */
	int		getRawBits() const;
	void	setRawBits(int const raw);
	
	private:
	/* variables */
	int					_integer;
	static const int	_fractionalBits;
	/* functions */
	
} ;