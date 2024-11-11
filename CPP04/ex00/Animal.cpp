/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:05:06 by fli               #+#    #+#             */
/*   Updated: 2024/11/11 11:19:30 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("animal")
{
	std::cout << YELLOW << "Animal default constructor called" << DEFAULT << std::endl;
}

Animal::~Animal()
{
	std::cout << YELLOW << "Animal default destructor called" << DEFAULT << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << YELLOW << "Animal copy constructor called" << DEFAULT << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout << YELLOW << "Animal copy assignment constructor called" << DEFAULT << std::endl;
	if (this != &other)
		this->type = other.type;
	return(*this);
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << YELLOW << "Animal type constructor called" << DEFAULT << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Meep" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
