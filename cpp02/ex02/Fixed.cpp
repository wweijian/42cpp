/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:08:05 by weijian           #+#    #+#             */
/*   Updated: 2025/09/18 08:51:41 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/* constructors */

Fixed::Fixed()
	:	_fixedPointNumberValue(0)
{}

Fixed::Fixed(const Fixed &fixed) // copy constructor
{
	_fixedPointNumberValue = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &fixed) // assignment operator
{
	if (this != &fixed) {
		_fixedPointNumberValue = fixed.getRawBits();
	}
	return *this;
}

Fixed::Fixed(const int i)
	:	_fixedPointNumberValue( i << _fractionalBits )
{}

Fixed::Fixed(const float f)
	:	_fixedPointNumberValue( roundf(f * (1 << _fractionalBits)) )
{}

Fixed::~Fixed()
{}

/* static constants */
const int	Fixed::_fractionalBits = 8;

/* function */
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

/* comparisons */
bool Fixed::operator>(const Fixed& other) const
{
	return (_fixedPointNumberValue > other._fixedPointNumberValue);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (_fixedPointNumberValue < other._fixedPointNumberValue);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (_fixedPointNumberValue >= other._fixedPointNumberValue);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (_fixedPointNumberValue <= other._fixedPointNumberValue);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (_fixedPointNumberValue == other._fixedPointNumberValue);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (_fixedPointNumberValue != other._fixedPointNumberValue);
}

/* arithmetic */
Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(toFloat() + other.toFloat());¡
}
Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(toFloat() / other.toFloat());
}

/* increment decrement */

Fixed&	Fixed::operator++()
{
	_fixedPointNumberValue++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed&	Fixed::operator--()
{
	_fixedPointNumberValue--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed& temp(*this);
	--(*this);
	return (temp);
}

/* minmax */
const Fixed	Fixed::min(const Fixed& x, const Fixed& y)
{
	return (x.toFloat() < y.toFloat() ? x : y);
}

const Fixed	Fixed::max(const Fixed& x, const Fixed& y)
{
	return (x.toFloat() > y.toFloat() ? x : y);
}

Fixed	Fixed::min(Fixed& x, Fixed& y)
{
	return (x.toFloat() < y.toFloat() ? x : y);
}

Fixed	Fixed::max(Fixed& x, Fixed& y)
{
	return (x.toFloat() > y.toFloat() ? x : y);
}

/* << operator */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}