/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 22:48:29 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 23:38:11 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> 
Array<T>::Array() 
		: 	size()
{
	array = new T[0];
	std::cout << "Array is constructed" << std::endl;
}

template <typename T> 
Array<T>::Array(const Array<T>& arr)
		:	array(arr.copyArray()),
			size(arr.getSize())
{
	std::cout << "Array is copied" << std::endl;	
}

template <typename T> 
Array<T>::Array(unsigned int n)
		:	size(n)
{
	array = new T[n];
	std::cout << "Array is constructed" << std::endl;
}

template <typename T> 
Array<T>& Array<T>::operator=(const Array& arr)
{
	if (this != &arr) {
		delete array;
		array = arr.copyArray();
		size = arr.getSize();
	}
	return (*this);
}

template <typename T> 
T& Array<T>::operator[](unsigned int n)
{
	if (n >= size)
		throw OutOfBounds();
	return (array[n]);
}

template <typename T> 
Array<T>::~Array()
{
	delete this->array;
	std::cout << "Array is destroyed" << std::endl;	
}

/* exceptions */
template <typename T> 
const char*	Array<T>::OutOfBounds::what () const throw ()
{
	return ("Array<T>::operator[]: index is out of bounds");
}

/* getter */
template <typename T>
T*	Array<T>::copyArray() const
{
	T*	arr[size] = new T[size];
	for (int i = 0; i < size; i++) {
		arr[i] = array[i];
	}
	return (arr);
}

template <typename T>
unsigned int	Array<T>::getSize() const
{
	return (size);
}

template <typename T>
void	Array<T>::printT() const
{
	for (unsigned int i = 0; i < size; i++) {
		std::cout << i << " : " << array[i] << std::endl;
	}
}
