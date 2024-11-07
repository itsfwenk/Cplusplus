/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:15:43 by fli               #+#    #+#             */
/*   Updated: 2024/11/07 14:17:09 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << BLUE << "Dog default constructor called" << DEFAULT << std::endl;

	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << BLUE << "Dog default destructor called" << DEFAULT << std::endl;

	delete this->brain;
}

Dog::Dog(const Dog &other) : AAnimal(other.type)
{
	std::cout << BLUE << "Dog copy constructor called" << DEFAULT << std::endl;

	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain[i] = other.brain[i];
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << BLUE << "Dog copy assignment called" << DEFAULT << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		for (int i = 0; i < 100; i++)
			brain[i] = other.brain[i];
	}
	return(*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}
