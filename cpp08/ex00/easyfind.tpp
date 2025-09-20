/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 08:55:24 by weijian           #+#    #+#             */
/*   Updated: 2025/09/20 13:12:51 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template <typename T, unsigned int N>
T* easyfind(T(&arr)[N] , int searchValue)
{
	T*	search = std::find(arr, arr + N, searchValue);
	
	if (search == arr + N + 1)
		return (NULL);
	return (search);
}
