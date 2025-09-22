/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:27:39 by weijian           #+#    #+#             */
/*   Updated: 2025/09/22 12:50:27 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <stdint.h> // required for uintptr
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