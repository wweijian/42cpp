/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 08:20:10 by weijian           #+#    #+#             */
/*   Updated: 2025/09/20 13:06:45 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T, unsigned int N>
T* easyfind(T(&arr)[N] , int searchValue);

#include "easyfind.tpp"