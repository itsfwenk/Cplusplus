/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:38:45 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 10:38:47 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : n_value(other.n_value)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int nb) : n_value(nb << n_fbits)
{
	// std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(const float nb) : n_value(roundf(nb * (1 << n_fbits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->n_value);
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
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

std::ostream	&operator<<(std::ostream &out, Fixed const &a)
{
	return out << a.toFloat();
}

Fixed& Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->n_value = other.n_value;
	return (*this);
}

Fixed Fixed::operator+(const Fixed &a) const
{
	// std::cout << "+ operator called" << std::endl;
	return Fixed(this->n_value + a.n_value);
}

Fixed Fixed::operator-(const Fixed &a) const
{
	// std::cout << "- operator called" << std::endl;
	return Fixed(this->n_value - a.n_value);
}

Fixed Fixed::operator*(const Fixed &a) const
{
	// std::cout << "* operator called" << std::endl;
	Fixed	newFixed = *this;
	newFixed.n_value = roundf((float)(newFixed.toFloat() * a.toFloat()) * (1 << n_fbits));

	return newFixed;
}

Fixed Fixed::operator/(const Fixed &a) const
{
	// std::cout << "/ operator called" << std::endl;
	Fixed	newFixed = *this;
	newFixed.n_value = roundf((float)(newFixed.toFloat() / a.toFloat()) * (1 << n_fbits));

	return newFixed;
}

Fixed &Fixed::operator++()
{
	// std::cout << "pre ++ operator called" << std::endl;
	this->n_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;

	// std::cout << "post ++ operator called" << std::endl;
	this->n_value++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	// std::cout << "pre -- operator called" << std::endl;
	this->n_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;

	// std::cout << "post -- operator called" << std::endl;
	this->n_value--;
	return tmp;
}

bool	Fixed::operator>(const Fixed &a) const
{
	// std::cout << "> operator called" << std::endl;
	return (this->n_value > a.n_value);
}

bool	Fixed::operator<(const Fixed &a) const
{
	// std::cout << "< operator called" << std::endl;
	return (this->n_value < a.n_value);
}

bool	Fixed::operator>=(const Fixed &a) const
{
	// std::cout << ">= operator called" << std::endl;
	return (this->n_value >= a.n_value);
}

bool	Fixed::operator<=(const Fixed &a) const
{
	// std::cout << "<= operator called" << std::endl;
	return (this->n_value <= a.n_value);
}

bool	Fixed::operator==(const Fixed &a) const
{
	// std::cout << "== operator called" << std::endl;
	return (this->n_value == a.n_value);
}

bool	Fixed::operator!=(const Fixed &a) const
{
	// std::cout << "!= operator called" << std::endl;
	return (this->n_value != a.n_value);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	// std::cout << "max function called" << std::endl;
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	// std::cout << "max function called" << std::endl;
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	// std::cout << "min function called" << std::endl;
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	// std::cout << "min function called" << std::endl;
	if (a < b)
		return (a);
	else
		return (b);
}
