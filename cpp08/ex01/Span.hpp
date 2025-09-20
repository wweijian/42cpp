/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:57:48 by weijian           #+#    #+#             */
/*   Updated: 2025/09/20 19:40:12 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	public:
	/* constructors */
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		int& operator[](unsigned int i);
		~Span();
	
	/* type redefinition */
	typedef std::vector<int>	vector;
	typedef vector::iterator	iterator;
	
	/* functions */
		void				addNumber(int n);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();
		void				fillSpan(iterator start, int nElements, int n);

	/* getters */
		std::vector<int>	getVec() const ;
		iterator			getStart();
		iterator			getEnd();
		unsigned int		getMaxElements() const ;

	/* exceptions */
		class SpanFull : public std::exception
		{
			const char * what() const throw();
		} ;

	private:
	/* macro */
	#define VEC_FN(fn) fn(_vec.begin(), _vec.end())
	
	/* variables */
	const unsigned int	_maxElements;
	std::vector<int>	_vec;
} ;

std::ostream& operator<<(std::ostream& os, Span span);