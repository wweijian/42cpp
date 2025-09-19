/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:27:39 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 20:33:13 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer& s);
		Serializer& operator=(const Serializer& s);
		~Serializer();

		static uintptr_t	serialize (Data* ptr);
		static Data* 		deserialize(uintptr_t raw);

	/* pure virtual */
	virtual void	dummy() = 0;
} ;