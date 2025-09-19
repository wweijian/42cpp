/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:31:19 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 20:44:02 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* useless constructors */
Serializer::Serializer()
{}

Serializer::Serializer(const Serializer& s)
{(void) s;}

Serializer& Serializer::operator=(const Serializer& s)
{(void) s; return (*this);}

Serializer::~Serializer()
{}

/* functions */

uintptr_t	Serializer::serialize (Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* 		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
