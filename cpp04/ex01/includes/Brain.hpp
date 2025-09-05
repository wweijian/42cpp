/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:04:53 by weijian           #+#    #+#             */
/*   Updated: 2025/09/05 10:28:18 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
	public:
		/* constructor */
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
	
		std::string	getIdeas() const;
		std::string	getIdeas(int i) const;

	private:
		std::string	ideas[100];

} ;