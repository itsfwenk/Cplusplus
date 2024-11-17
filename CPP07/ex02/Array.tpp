/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:52:07 by mli               #+#    #+#             */
/*   Updated: 2024/11/17 18:58:14 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : data(new T[0]), length(0)
{
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->data;
}

template <typename T>
Array<T>::Array(const Array &other) : data(new T[other.length]), length(other.length)
{

	for (size_t i = 0; i < other.length; i++)
	{
		if (i > this->length)
			throw OutOfBoundsException();
		this->data[i] = other.data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	this->length = other.length;
	delete[] this->data;
	this->data = new T[other.length];
	if (this != &other)
	{
		for (size_t i = 0; i < other.length; i++)
		{
			if (i > this->length)
				throw OutOfBoundsException();
			this->data[i] = other.data[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), length(n)
{
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= this->length)
		throw OutOfBoundsException();
	return this->data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= this->length)
		throw OutOfBoundsException();
	return this->data[index];
}

template <typename T>
size_t Array<T>::size() const
{
	return this->length;
}
