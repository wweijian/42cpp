/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:09:46 by weijian           #+#    #+#             */
/*   Updated: 2025/09/20 21:42:36 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	/* constructors */
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack& operator=(const MutantStack &other);
		~MutantStack();
	
	/* type redefition */
		typedef typename std::stack<T>::container_type::iterator iterator;
	
	/* function */
		iterator	begin(); // stack hides this, so we're implementing this
		iterator	end();
} ;

#include "MutantStack.tpp"