/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:39:10 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 10:39:12 by fli              ###   ########.fr       */
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

Fixed	Point::getX() const
{
	return this->x;
}

Fixed	Point::getY() const
{
	return this->y;
}
