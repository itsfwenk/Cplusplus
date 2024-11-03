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
#include <iostream>

Fixed	getArea(Point const a, Point const b, Point const c);
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point a(0.0, 0.0);
	Point b(4.0, 0.0);
	Point c(2.0, 3.0);

	Point insidePoint(2.0, 1.0);
	Point outsidePoint(5.0, 5.0);

	std::cout << "[FIRST] SHOULD BE INSIDE: " << bsp(a, b, c, insidePoint) << std::endl;
	std::cout << "[FIRST] SHOULD BE OUTSIDE: " << bsp(a, b, c, outsidePoint) << std::endl;
	std::cout << std::endl;

    Point onVertex(0.0, 0.0);
    Point onEdge(2.0, 0.0);
    Point nearCenter(2.0, 1.0);
    Point outsideCloseToEdge(4.0, 3.0);
    Point farOutside(10.0, 10.0);
    Point centroid((0.0 + 4.0 + 2.0) / 3, (0.0 + 0.0 + 3.0) / 3);
    Point inLine(1.0, 0.0);

    std::cout << "On Vertex: " << bsp(a, b, c, onVertex) << std::endl;
    std::cout << "On Edge: " << bsp(a, b, c, onEdge) << std::endl;
    std::cout << "Near Center: " << bsp(a, b, c, nearCenter) << std::endl;
    std::cout << "Close to Edge: " << bsp(a, b, c, outsideCloseToEdge) << std::endl;
    std::cout << "Far Outside: " << bsp(a, b, c, farOutside) << std::endl;
    std::cout << "Centroid: " << bsp(a, b, c, centroid) << std::endl;
    std::cout << "Degenerate Case (In Line): " << bsp(a, b, c, inLine) << std::endl;
	return 0;
}
