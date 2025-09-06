/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:08:01 by weijian           #+#    #+#             */
/*   Updated: 2025/08/24 23:13:12 by weijian          ###   ########.fr       */
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

	A copy assignment operator is a non-template non-static member function
	with the name operator= that can be called with an argument of the same
	class type and copies the content of the argument without mutating the
	argument.
*/
class Fixed 
{
	public:
	/* constructors */
	Fixed();
	~Fixed();
	Fixed(const int i);
	Fixed(const float f);

	Fixed(const Fixed &fixed);
	Fixed& operator=(const Fixed& fixed);

	/* functions */
	int		getRawBits() const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
	
	private:
	/* variables */
	int					_fixedPointNumberValue;
	static const int	_fractionalBits;
} ;

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);