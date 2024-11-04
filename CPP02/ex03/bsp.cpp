/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:38:26 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 10:38:27 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	getArea(Point const a, Point const b, Point const c)
{
	Fixed	area = (
		(a.getX() * (b.getY() - c.getY()))
		+ (b.getX() * (a.getY() - c.getY()))
		+ c.getX() * (a.getY() - b.getY())) / 2;

	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	A = getArea(a, b, c);

	Fixed	PAB = getArea(point, a, b);
	Fixed	PBC = getArea(point, b, c);
	Fixed	PAC = getArea(point, a, c);

	return PAB + PBC + PAC == A;
}
