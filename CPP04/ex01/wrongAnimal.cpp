/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:05:06 by fli               #+#    #+#             */
/*   Updated: 2024/11/06 15:06:41 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongAnimal.hpp"

wrongAnimal::wrongAnimal() : type("wrongAnimal")
{
	std::cout << YELLOW << "wrongAnimal default constructor called" << DEFAULT << std::endl;
}

wrongAnimal::~wrongAnimal()
{
	std::cout << YELLOW << "wrongAnimal default destructor called" << DEFAULT << std::endl;
}

wrongAnimal::wrongAnimal(const wrongAnimal &other) : type(other.type), sound(other.sound)
{
	std::cout << YELLOW << "wrongAnimal copy constructor called" << DEFAULT << std::endl;
}

wrongAnimal& wrongAnimal::operator=(const wrongAnimal &other)
{
	std::cout << YELLOW << "wrongAnimal copy assignment constructor called" << DEFAULT << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->sound = other.sound;
	}
	return(*this);
}

wrongAnimal::wrongAnimal(std::string type) : type(type)
{
	std::cout << YELLOW << "wrongAnimal type constructor called" << DEFAULT << std::endl;
}

// wrongAnimal::wrongAnimal(std::string type, std::string sound) : type(type), sound(sound)
// {
// 	std::cout << YELLOW << "wrongAnimal type and sound constructor called" << DEFAULT << std::endl;
// }

void	wrongAnimal::makeSound(void) const
{
	std::cout << "Meep" << std::endl;
}

std::string wrongAnimal::getType() const
{
	return (this->type);
}
