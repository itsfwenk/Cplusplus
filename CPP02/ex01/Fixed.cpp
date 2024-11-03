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

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : n_value(other.n_value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int nb) : n_value(nb << n_fbits)
{
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(const float nb) : n_value(roundf(nb * (1 << n_fbits)))
{
	std::cout << "Float constructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->n_value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->n_value = raw;
}

int	Fixed::toInt() const
{
	return this->n_value >> n_fbits;
}

float	Fixed::toFloat() const
{
	return (float)this->n_value / (1 << n_fbits);
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->n_value = other.n_value;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &a)
{
	return out << a.toFloat();
}
