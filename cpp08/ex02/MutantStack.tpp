/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:44:32 by weijian           #+#    #+#             */
/*   Updated: 2025/11/14 09:43:02 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
	: std::stack<T>(other)
{}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other)
{
	std::stack<T>::operator=(this, other);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return (this->c.end());
}
