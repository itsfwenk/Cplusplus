/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:45:09 by fli               #+#    #+#             */
/*   Updated: 2024/11/14 15:05:02 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer& Serializer::operator=(Serializer const &other)
{
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t serializedPointer = reinterpret_cast<uintptr_t>(ptr);
	return (serializedPointer);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* deserializedPointer = reinterpret_cast<Data*>(raw);
	return (deserializedPointer);
}
