/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 22:39:55 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 23:38:07 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>

template <typename T>
class Array
{
	public:
	/* constructors */
		Array();
		Array(const Array<T>& arr);
		Array(unsigned int n);
		Array& operator=(const Array& arr);
		T& operator[](unsigned int n);
		~Array();
	
	/* getters */
		T*				copyArray() const ;
		unsigned int	getSize() const ;
		void			printT() const ;

	/* exception */
		class OutOfBounds : public std::exception
		{
			public:
				const char*	what () const throw ();
		} ;
	private:
		T*				array;
		unsigned int	size;
} ;

#include "Array.tpp"