/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:08:05 by weijian           #+#    #+#             */
/*   Updated: 2025/08/24 23:30:34 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* constructors */

Fixed::Fixed()
	:	_fixedPointNumberValue(0)
{
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) // copy constructor
{
	std::cout << "copy constructor called" << std::endl;
	_fixedPointNumberValue = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &fixed) // assignment operator
{
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &fixed) {
		_fixedPointNumberValue = fixed.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "destructor called" << std::endl;
}

/* static constants */
const int	Fixed::_fractionalBits = 8;

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits function called" << std::endl;
	return (_fixedPointNumberValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits function called" << std::endl;
	_fixedPointNumberValue = raw;
}
