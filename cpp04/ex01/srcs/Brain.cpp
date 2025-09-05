/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:17:10 by weijian           #+#    #+#             */
/*   Updated: 2025/09/05 10:32:40 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cerr << "Brain constructed" << std::endl;	
}

Brain::Brain(const Brain& other)
{
	*this = other;
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	std::cerr << "Brain copied" << std::endl;
}

Brain::~Brain()
{
	std::cerr << "Brain destroyed" << std::endl;
}

/* operators */
Brain& Brain::operator=(const Brain& other)
{
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

/* function */
std::string	Brain::getIdeas() const
{
	static int	i = 0;

	if (i > 100)
		i = 0;
	return(ideas[i]);
}

std::string	Brain::getIdeas(int i) const
{
	if (i > 100)
		return (NULL);
	return(ideas[i]);
}

/* print */
std::ostream& operator<<(std::ostream &out, const Brain& Brain)
{
	out << Brain.getIdeas();
	return (out);
}