/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:35:06 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 20:49:07 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main ()
{
	Data		fixed;
	uintptr_t	u = Serializer::serialize(&fixed);

	std::cout	<< "fixed address: " << &fixed << "\n"
				<< "uintptr      : " << u << "\n"
				<< "fixed address: " << Serializer::deserialize(u) << "\n"
				<< std::endl;

	Data*		fixedptr = NULL;
	u = Serializer::serialize(fixedptr);

	std::cout	<< "fixed address: " << fixedptr << "\n"
				<< "uintptr      : " << u << "\n"
				<< "fixed address: " << Serializer::deserialize(u) << "\n"
				<< std::endl;

	fixedptr = new Data;
	u = Serializer::serialize(fixedptr);

	std::cout	<< "fixed address: " << fixedptr << "\n"
				<< "uintptr      : " << u << "\n"
				<< "fixed address: " << Serializer::deserialize(u) << "\n"
				<< std::endl;
	
	delete fixedptr;
}