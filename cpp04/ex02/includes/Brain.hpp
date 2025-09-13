/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:04:53 by weijian           #+#    #+#             */
/*   Updated: 2025/09/13 20:01:00 by wjhoe            ###   ########.fr       */
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
		void		setIdea(std::string); 

	private:
		/* variables */
		std::string	_ideas[100];
		int			_ideaCount;
} ;