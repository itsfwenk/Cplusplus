/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:05:06 by fli               #+#    #+#             */
/*   Updated: 2024/11/09 17:33:34 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << YELLOW << "AAnimal default constructor called" << DEFAULT << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << YELLOW << "AAnimal default destructor called" << DEFAULT << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
	std::cout << YELLOW << "AAnimal copy constructor called" << DEFAULT << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	std::cout << YELLOW << "AAnimal copy assignment constructor called" << DEFAULT << std::endl;
	if (this != &other)
		this->type = other.type;
	return(*this);
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << YELLOW << "AAnimal type constructor called" << DEFAULT << std::endl;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "Meep" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->type);
}
