/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:05:06 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 19:53:39 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal() : type("animal"), sound("meep")
{
	std::cout << YELLOW << "Animal default constructor called" << DEFAULT << std::endl;
}

Animal::~Animal()
{
	std::cout << YELLOW << "Animal default destructor called" << DEFAULT << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type), sound(other.sound)
{
	std::cout << YELLOW << "Animal copy constructor called" << DEFAULT << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout << YELLOW << "Animal copy assignment constructor called" << DEFAULT << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->sound = other.sound;
	}
	return(*this);
}

Animal::Animal(std::string type) : type(type), sound("meep")
{
	std::cout << YELLOW << "Animal name constructor called" << DEFAULT << std::endl;
}

Animal::Animal(std::string type, std::string sound) : type(type), sound(sound)
{
	std::cout << YELLOW << "Animal type and sound constructor called" << DEFAULT << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << this->sound << std::endl;
}

void	Animal::setSound(std::string sound)
{
	this->sound = sound;
}

std::string Animal::getType() const
{
	return (this->type);
}

std::string	Animal::getSound() const
{
	return (this->sound);
}
