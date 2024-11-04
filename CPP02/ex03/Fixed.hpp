/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:38:50 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 10:38:53 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int	n_value;
		static const int	n_fbits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed(const int nb);
		Fixed(const float nb);

		Fixed& operator=(const Fixed &other);
		Fixed	operator+(const Fixed &a) const;
		Fixed	operator-(const Fixed &a) const;
		Fixed	operator*(const Fixed &a) const;
		Fixed	operator/(const Fixed &a) const;
		Fixed	operator++(int);
		Fixed	&operator++();
		Fixed	operator--(int);
		Fixed	&operator--();
		bool	operator>(const Fixed &a) const;
		bool	operator<(const Fixed &a) const;
		bool	operator>=(const Fixed &a) const;
		bool	operator<=(const Fixed &a) const;
		bool	operator==(const Fixed &a) const;
		bool	operator!=(const Fixed &a) const;

		static	Fixed &max(Fixed &a, Fixed &b);
		static	const Fixed &max(const Fixed &a, const Fixed &b);
		static	Fixed &min(Fixed &a, Fixed &b);
		static	const Fixed &min(const Fixed &a, const Fixed &b);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &out, Fixed const &a);

#endif
