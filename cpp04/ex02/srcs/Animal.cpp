/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:06:32 by weijian           #+#    #+#             */
/*   Updated: 2025/09/13 21:29:42 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cerr << "Animal constructed" << std::endl;	
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cerr << "Animal copied" << std::endl;
}

Animal::~Animal()
{
	std::cerr << "Animal destroyed" << std::endl;	
}

/* operators */
Animal& Animal::operator=(const Animal& other)
{
	if (this != &other) {
		type_ = other.type_;
	}
	return (*this);
}

/* function */
std::string	Animal::getType() const
{
	return (type_);
}

/* print */
std::ostream& operator<<(std::ostream &out, const Animal& animal)
{
	out << animal.getType();
	return (out);
}