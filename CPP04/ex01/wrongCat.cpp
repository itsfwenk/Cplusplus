/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:15:19 by fli               #+#    #+#             */
/*   Updated: 2024/11/06 14:57:42 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongCat.hpp"

wrongCat::wrongCat() : wrongAnimal("wrongCat")
{
	std::cout << YELLOW << "wrongCat default constructor called" << DEFAULT << std::endl;
}

wrongCat::~wrongCat()
{
	std::cout << YELLOW << "wrongCat default destructor called" << DEFAULT << std::endl;
}

wrongCat::wrongCat(const wrongCat &other) : wrongAnimal(other.type)
{
	std::cout << YELLOW << "wrongCat copy constructor called" << DEFAULT << std::endl;
}

wrongCat& wrongCat::operator=(const wrongCat &other)
{
	std::cout << YELLOW << "wrongCat copy assignment constructor called" << DEFAULT << std::endl;
	if (this != &other)
		wrongAnimal::operator=(other);
	return(*this);
}

void	wrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

std::string wrongCat::getType() const
{
	return (this->type);
}
