/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:39:27 by mli               #+#    #+#             */
/*   Updated: 2024/11/20 11:26:45 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <string>

template <typename T>
void iter(T* array, size_t length, void (*func)(T))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void iter(T* array, size_t length, void (*func)(const T&))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void	print_var(T var)
{
	std::cout << var << std::endl;
}
