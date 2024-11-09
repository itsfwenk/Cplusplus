/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:05:06 by fli               #+#    #+#             */
/*   Updated: 2024/11/09 16:55:30 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << YELLOW << "WrongAnimal default constructor called" << DEFAULT << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << YELLOW << "WrongAnimal default destructor called" << DEFAULT << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : sound(other.sound), type(other.type)
{
	std::cout << YELLOW << "WrongAnimal copy constructor called" << DEFAULT << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << YELLOW << "WrongAnimal copy assignment constructor called" << DEFAULT << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->sound = other.sound;
	}
	return(*this);
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << YELLOW << "WrongAnimal type constructor called" << DEFAULT << std::endl;
}

// WrongAnimal::WrongAnimal(std::string type, std::string sound) : type(type), sound(sound)
// {
// 	std::cout << YELLOW << "WrongAnimal type and sound constructor called" << DEFAULT << std::endl;
// }

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Meep" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
