/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 08:20:10 by weijian           #+#    #+#             */
/*   Updated: 2025/11/13 21:01:10 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename C>
typename C::iterator easyfind(C& container, int searchValue);

template <typename C>
typename C::const_iterator easyfind(const C& container, int searchValue);

#include "easyfind.tpp"