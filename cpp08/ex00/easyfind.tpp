/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 08:55:24 by weijian           #+#    #+#             */
/*   Updated: 2025/11/13 20:53:45 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template <typename C>
typename C::iterator easyfind(C& container, int searchValue)
{
	return (std::find(container.begin(), container.end(), searchValue));
}

template <typename C>
typename C::const_iterator easyfind(const C& container, int searchValue)
{
	return (std::find(container.begin(), container.end(), searchValue));
}
