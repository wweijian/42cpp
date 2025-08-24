/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:18:23 by weijian           #+#    #+#             */
/*   Updated: 2025/08/25 02:30:31 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a,
			Point const b,
			Point const c,
			Point const x)
{	
	if (x.isOnLine(a, b) || x.isOnLine(b, c) || x.isOnLine(a, c))
		return (false);
	return (Point::areaOf(a, b, c) <= (Point::areaOf(a, b, x)
									  + Point::areaOf(a, x, c)
									  + Point::areaOf(x, b, c))
			);
}

int main( void ) {
	Fixed aX = 0.0f;
	Fixed aY = 0.0f;
	Fixed bX = 10.0f;
	Fixed bY = 10.0f;
	Fixed cX = 0.0f;
	Fixed cY = 10.0f;
	Fixed dX = 2.0f;
	Fixed dY = 8.0f;
	
	Point a(aX, aY);
	Point b(bX, bY);
	Point c(cX, cY);
	Point d(dX, dY);

	if (bsp(a, b, c, d))
		std::cout << "inside triangle!";
	else
		std::cout << "outside triangle";	
}
