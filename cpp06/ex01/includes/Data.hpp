/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:08:01 by weijian           #+#    #+#             */
/*   Updated: 2025/09/04 09:01:07 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Data 
{
	public:
	/* constructors */
	Data();
	~Data();
	Data(const Data& Data);
	Data& operator=(const Data& Data);
	
	/* functions */
	int		getRawBits() const;
	void	setRawBits(int const raw);
	
	private:
	/* variables */
	int					_DataPointNumberValue;
	static const int	_fractionalBits;
} ;
