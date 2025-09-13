/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:17:10 by weijian           #+#    #+#             */
/*   Updated: 2025/09/13 08:40:24 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
		: _ideaCount(0)
{
	std::cerr << "Brain constructed" << std::endl;	
}

Brain::Brain(const Brain& other)
{
	*this = other;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
		_ideaCount = other._ideaCount;
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
			_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

/* function */

void	Brain::setIdea(std::string idea)
{
	if (_ideaCount >= 100) {
		std::cout << "brain full, idea not added" << std::endl;
		return ; 
	}
	_ideas[_ideaCount++] = idea;
}

std::string	Brain::getIdeas(int i) const
{
	if (i > 100)
		return (NULL);
	return(_ideas[i]);
}

std::string	Brain::getIdeas() const
{
	static int	i = 0;

	if (i++ > 100)
		i = 0;
	return(_ideas[i]);
}

/* print */
std::ostream& operator<<(std::ostream &out, const Brain& Brain)
{
	out << Brain.getIdeas();
	return (out);
}