/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:09:46 by weijian           #+#    #+#             */
/*   Updated: 2025/11/14 09:43:08 by wjhoe            ###   ########.fr       */
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
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	
	/* function */
		iterator		begin(); // stack hides this, so we're implementing this
		const_iterator	begin() const ;
		iterator		end();
		const_iterator	end() const ;
} ;

#include "MutantStack.tpp"