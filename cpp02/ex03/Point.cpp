/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:32:25 by weijian           #+#    #+#             */
/*   Updated: 2025/08/25 02:28:24 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
		:	_x(0),
			_y(0)
{}

Point::Point(Fixed x, Fixed y)
		:	_x(x),
			_y(y)
{}

Point::Point(const Point& point)
{	
	_x = point.getX();
	_y = point.getY();
}

Point::~Point()
{}

/* operator */
Point& Point::operator=(const Point& point)
{
	if (this != &point) {
		_x = point.getX();
		_y = point.getY();
	}
	return *this;
}

/* functions */

Fixed	Point::getX() const
{
	return (_x);
}
Fixed	Point::getY() const
{
	return (_y);
}
void	Point::setX(Fixed const fixed)
{
	_x = fixed;
}
void	Point::setY(Fixed const fixed)
{
	_y = fixed;
}

/* static functions */

Fixed	Point::areaOf(Point const a, Point const b, Point const c)
{
	return ((	a.getX() * (b.getY() - c.getY())
				+ b.getX() * (c.getY() - a.getY())
				+ c.getX() * (a.getY() - b.getY())	)
				/ 2)
			;
}

bool	Point::isOnLine(Point const a, Point const b) const
{
	Fixed cross = ((getX() - a.getX()) * (b.getY() - a.getY()))
				- (getY() - a.getY()) * (b.getX() - a.getX());
	if (cross != Fixed(0))
		return (false);
	return (	getX() >= Fixed::min(a.getX(), b.getX())
				&& getX() <= Fixed::max(a.getX(), b.getX())
				&& getY() >= Fixed::min(a.getY(), b.getY())
				&& getY() <= Fixed::max(a.getY(), b.getY())	)
			 ;
}