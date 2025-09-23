/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:27:39 by weijian           #+#    #+#             */
/*   Updated: 2025/09/23 11:04:12 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <stdint.h> // required for uintptr
#include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t	serialize (Data* ptr);
		static Data* 		deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer& s);
		Serializer& operator=(const Serializer& s);
		~Serializer();

} ;
