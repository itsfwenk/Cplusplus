/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:36:16 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 10:36:28 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int	n_value;
		static const int	n_fbits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
