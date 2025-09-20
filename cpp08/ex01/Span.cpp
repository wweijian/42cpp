/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:12:01 by weijian           #+#    #+#             */
/*   Updated: 2025/09/20 19:55:11 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* constructors */

Span::Span()
	:	_maxElements(0)
{}

Span::Span(unsigned int N)
	:	_maxElements(N)
{}

Span::Span(const Span& other)
	:	_maxElements(other._maxElements),
		_vec(other._vec)
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other) {
		this->~Span();
		new (this) Span(other);
	}
	return (*this);
}

int& Span::operator[](unsigned int i)
{
	if (i >= _vec.size() || _maxElements == 0)
		throw std::invalid_argument("Span: indexing unavailable index");
	return (_vec[i]);
}

Span::~Span()
{}

/* functions */

void	Span::addNumber(int n)
{	
	if (_vec.size() == _maxElements)
		throw SpanFull();
	_vec.push_back(n);
}

unsigned int	Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw std::invalid_argument("Span::shortestSpan less than 2 arguments");

	int	min = longestSpan();
	int	temp = 0;
	
	vector tempVec(_vec);
	std::sort(tempVec.begin(), tempVec.end());

	for (iterator it = tempVec.begin(); it + 1 !=tempVec.end(); it++) {
		temp = *(it + 1) - *it;
		if (temp < min)
			min = temp;
	}
	return (min);
}

unsigned int	Span::longestSpan()
{
	if (_vec.size() < 2)
		throw std::invalid_argument("Span::longestSpan less than 2 arguments");
	return (*(VEC_FN(std::max_element)) - *(VEC_FN(std::min_element)));
}

void	Span::fillSpan(iterator start, int nElements, int n)
{
	if (nElements + _vec.size() > _maxElements)
		throw std::invalid_argument("fillSpan : too many elements for this span");
	_vec.insert(start++, nElements, n);
}

/* getters */

Span::vector	Span::getVec() const
{
	return (_vec);
}

Span::iterator	Span::getStart()
{
	return (_vec.begin());
}

Span::iterator	Span::getEnd()
{
	return (_vec.end());
}

unsigned int	Span::getMaxElements() const
{
	return (_maxElements);
}

/* exceptions */
const char * Span::SpanFull::what() const throw()
{
	return ("Span: span is already filled");
}

/* printer */
std::ostream& operator<<(std::ostream& os, Span span)
{
	for (unsigned int i = 0; i < span.getVec().size(); i++) {
		os << "index [" << i << "] : " << span[i] << "\n";
	}
	os << "end of Span";
	return (os);
}
