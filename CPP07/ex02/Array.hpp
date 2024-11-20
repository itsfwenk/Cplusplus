/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:11:17 by mli               #+#    #+#             */
/*   Updated: 2024/11/20 11:28:00 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>
# include <iostream>

template <typename T>
class Array
{
	private:
	T*	data;
	unsigned int	length;
	public:
	Array();
	~Array();
	Array(const Array &other);
	Array& operator=(const Array &other);

	Array(unsigned int n);

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	size_t size() const;

	class OutOfBoundsException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return "error : out of bounds";
		}
	};
};

template <typename T>
std::ostream	&operator<<(std::ostream &stream, const Array<T> &arr)
{
	stream << "[";
	for (size_t i = 0; i < arr.size(); i++)
		stream << arr[i] << (i == arr.size() - 1 ? "" : ", ");
	stream << "]";
	return stream;
}

# include "Array.tpp"

#endif
