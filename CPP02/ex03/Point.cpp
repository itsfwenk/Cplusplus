/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:42:07 by fli               #+#    #+#             */
/*   Updated: 2024/10/31 17:40:27 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Destructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
	std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
	std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->x = other.x;
	this->y = other.y;
	return (*this);
}

Fixed	Point::getX() const
{
	return this->x;
}

Fixed	Point::getY() const
{
	return this->y;
}

bool	Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	std::cout << "bsp function called" << std::endl;
	Fixed	ab = b.x - a.x;
	Fixed	bc = c.x - b.x;
	Fixed	ca = a.x - c.x;
	Fixed	ap = point.x - a.x;
	Fixed	bp = point.x - b.x;
	Fixed	cp = point.x - c.x;

	Fixed	d = ab * bc - ca * ca;
	Fixed	e = ab * bp - ap * bc;
	Fixed	f = ab * cp - ap * ca;
	Fixed	g = bp * cp - ap * bp;

	if (d == 0)
		return (false);
	if (e == 0)
		return (false);
	if (f == 0)
		return (false);
	if (g == 0)
		return (false);
	return (true);
}
