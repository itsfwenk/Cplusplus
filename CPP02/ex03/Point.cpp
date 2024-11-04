/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:39:10 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 11:31:36 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
	// std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->x = other.x;
	this->y = other.y;
	return (*this);
}

Point Point::operator-(const Point &other) const
{
	return Point((this->x - other.x).toFloat(), (this->y - other.y).toFloat());
}

Fixed	Point::getX() const
{
	return this->x;
}

Fixed	Point::getY() const
{
	return this->y;
}

// float crossProduct(const Point& v1, const Point& v2)
// {
// 	return ((v1.getX() * v2.getY() - v1.getY() * v2.getX()).toFloat());
// }

// Point vector(const Point& p1, const Point& p2)
// {
// 	Point	tmpPoint = p1 - p2;
// 	return tmpPoint;
// }
