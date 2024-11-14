/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:40:40 by fli               #+#    #+#             */
/*   Updated: 2024/11/14 14:44:46 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : i(0)
{
}

Data::~Data()
{
}

Data::Data(Data const &other) : i(other.i)
{
}

Data& Data::operator=(Data const &other)
{
	if (this == &other)
		this->i = other.i;
	return *this;
}
