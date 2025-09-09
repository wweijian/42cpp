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

		/* functions */
		std::string	getIdeas() const;
		std::string	getIdeas(int i) const;
		int			getIdeaCount() const;
		void		setIdea(std::string); 

	private:
		/* variables */
		std::string	_ideas[100];
		int			_ideaCount;
} ;