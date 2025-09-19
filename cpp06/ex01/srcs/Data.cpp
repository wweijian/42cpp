/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:08:05 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 20:38:42 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/* constructor1s */

Data::Data()
	:	_DataPointNumberValue(0)
{
	std::cout << "default constructor called" << std::endl;
}

Data::Data(const Data& Data) // copy constructor
{
	std::cout << "copy constructor called" << std::endl;
	_DataPointNumberValue = Data.getRawBits();
}

Data& Data::operator=(const Data &Data) // assignment operator
{
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &Data) {
		_DataPointNumberValue = Data.getRawBits();
	}
	return *this;
}

Data::~Data()
{
	std::cout << "destructor called" << std::endl;
}

/* static constants */
const int	Data::_fractionalBits = 8;

int	Data::getRawBits() const
{
	std::cout << "getRawBits function called" << std::endl;
	return (_DataPointNumberValue);
}

void	Data::setRawBits(int const raw)
{
	std::cout << "setRawBits function called" << std::endl;
	_DataPointNumberValue = raw;
}
