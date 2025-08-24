/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:08:05 by weijian           #+#    #+#             */
/*   Updated: 2025/08/24 18:17:38 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* constructors */

Fixed::Fixed()
	:	_integer(0)
{}

Fixed::~Fixed()
{}

Fixed::Fixed(const Fixed &fixed)
{
    _integer = fixed._integer;
    std::cout << "copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "assignment operator called" << std::endl;
    return *this;
}


/* static constants */
const int	Fixed::_fractionalBits = 8;

