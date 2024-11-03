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

#include "Fixed.hpp"

#include <iostream>

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
