/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:31:50 by weijian           #+#    #+#             */
/*   Updated: 2025/08/25 02:19:33 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Fixed.hpp"

class Point
{
	public:
	/* constructors */
	Point();
	Point(Fixed x, Fixed y);
	Point(const Point& point);
	~Point();

	/* operator */
	const Point &operator=(const Point& point);

	/* functions */
	bool			bsp(Point const a,
						Point const b,
						Point const C,
						Point const point);
	Fixed			getX() const;
	Fixed			getY() const;
	void			setX(Fixed const fixed);
	void			setY(Fixed const fixed);
	bool			isOnLine(Point const a, Point const b) const;

	/* static funcitons */
	static Fixed	areaOf(Point const a, Point const b, Point const c);
	
	private:
	/* variables */
	const Fixed		_x;
	const Fixed		_y;

	/* function */

} ;