/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:33:14 by weijian           #+#    #+#             */
/*   Updated: 2025/09/04 14:42:16 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type_ = "Wrongcat";
	std::cerr << "WrongCat constructed" << std::endl;	
}

WrongCat::WrongCat(const WrongCat& other)
	:	WrongAnimal(other)
{
	*this = other;
	std::cerr << "WrongCat copied" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cerr << "WrongCat destroyed" << std::endl;	
}

/* operators */
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		type_ = other.type_;
	}
	return (*this);
}

/* function */
void	WrongCat::makeSound() const
{
	std::cout << "wrong meoW" << std::endl;
}

/* print */
std::ostream& operator<<(std::ostream &out, const WrongCat& wrongCat)
{
	out << wrongCat.getType();
	return (out);
}