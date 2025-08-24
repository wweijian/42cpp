/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:08:05 by weijian           #+#    #+#             */
/*   Updated: 2025/08/24 23:00:49 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/* constructors */

Fixed::Fixed()
	:	_fixedPointNumberValue(0)
{
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) // copy constructor
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

Fixed::Fixed(int i)
	:	_fixedPointNumberValue( i << _fractionalBits )
{
	std::cout << "integer constructor called" << std::endl;
}

Fixed::Fixed(float f)
	:	_fixedPointNumberValue( roundf(f * (1 << _fractionalBits)) )
{
	std::cout << "float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "destructor called" << std::endl;
}

/* static constants */
const int	Fixed::_fractionalBits = 8;

/* funcitions */

int	Fixed::getRawBits() const
{
	return (_fixedPointNumberValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointNumberValue = raw;
}

int	Fixed::toInt(void) const
{
	return (_fixedPointNumberValue >> _fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(getRawBits()) / (1 << _fractionalBits);
}

/* << operator */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
