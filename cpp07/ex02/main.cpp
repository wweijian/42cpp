/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:18:15 by weijian           #+#    #+#             */
/*   Updated: 2025/10/21 20:12:59 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main ()
{
	Array<int>	arr(10);
	arr.printT();
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}
	arr.printT();

/* 	const Array<int>	arr(10);
	arr.printT();
	for (int i = 0; i < 10; i++) {
		(void) arr[i];
	}
	arr.printT(); */
}