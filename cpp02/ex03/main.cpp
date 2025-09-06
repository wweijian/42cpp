/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:18:23 by weijian           #+#    #+#             */
/*   Updated: 2025/08/25 09:28:26 by weijian          ###   ########.fr       */
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
	
	Fixed	totalArea = Point::areaOf(a, b, c);
	Fixed	summedArea  = (Point::areaOf(a, b, x)
						+ Point::areaOf(a, x, c)
						+ Point::areaOf(x, b, c));
	Fixed	epsilon = Fixed(0.001f);
	Fixed	diff = (summedArea > totalArea) ? (summedArea - totalArea) : (totalArea - summedArea);
	return (diff <= epsilon);
}

int main( void ) {
	Fixed aX = 0.0f;
	Fixed aY = 0.0f;
	Fixed bX = 10.0f;
	Fixed bY = 10.0f;
	Fixed cX = 0.0f;
	Fixed cY = 10.0f;
	Fixed dX = 2.0f;
	Fixed dY = 5.0f;
	
	Point a(aX, aY);
	Point b(bX, bY);
	Point c(cX, cY);
	Point d(dX, dY);

	if (bsp(a, b, c, d))
		std::cout << "inside triangle!";
	else
		std::cout << "outside triangle";	
}
