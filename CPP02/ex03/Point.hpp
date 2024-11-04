/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:42:07 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 10:39:20 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		Point();
		~Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point& operator=(const Point &other);
		bool	bsp(Point const a, Point const b, Point const c, Point const point);

		Fixed	getX() const;
		Fixed	getY() const;
};

#endif
