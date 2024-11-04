/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:38:26 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 11:57:10 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Fixed	getArea(Point const a, Point const b, Point const c)
// {
// 	Fixed	area = (
// 		(a.getX() * (b.getY() - c.getY()))
// 		+ (b.getX() * (a.getY() - c.getY()))
// 		+ c.getX() * (a.getY() - b.getY())) / 2;

// 	return area;
// }

// bool bsp( Point const a, Point const b, Point const c, Point const point)
// {
// 	Fixed	A = getArea(a, b, c);

// 	Fixed	PAB = getArea(point, a, b);
// 	Fixed	PBC = getArea(point, b, c);
// 	Fixed	PAC = getArea(point, a, c);

// 	return PAB + PBC + PAC == A;
// }

float crossProduct(const Point& v1, const Point& v2)
{
	return (v1.getX().toFloat() * v2.getY().toFloat() - v1.getY().toFloat() * v2.getX().toFloat());
}

Point vector(const Point& p1, const Point& p2)
{
	Point	tmpPoint = p1 - p2;
	return tmpPoint;
}

bool bsp(const Point& A, const Point& B, const Point& C, const Point& P)
{
	Point AB = vector(A, B);
	Point BC = vector(B, C);
	Point CA = vector(C, A);

	Point AP = vector(A, P);
	Point BP = vector(B, P);
	Point CP = vector(C, P);

	float crossAB_AP = crossProduct(AB, AP);
	float crossBC_BP = crossProduct(BC, BP);
	float crossCA_CP = crossProduct(CA, CP);

	return (crossAB_AP > 0 && crossBC_BP > 0 && crossCA_CP > 0) ||
			(crossAB_AP < 0 && crossBC_BP < 0 && crossCA_CP < 0);
}
