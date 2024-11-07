/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:15:19 by fli               #+#    #+#             */
/*   Updated: 2024/11/07 17:37:17 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << RED << "Cat default constructor called" << DEFAULT << std::endl;

	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << RED << "Cat default destructor called" << DEFAULT << std::endl;

	delete this->brain;
}

Cat::Cat(const Cat &other) : AAnimal(other.type)
{
	std::cout << RED << "Cat copy constructor called" << DEFAULT << std::endl;

	this->brain = new Brain();
		brain = other.brain;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << RED << "Cat copy assignment called" << DEFAULT << std::endl;
	if (this != &other)
	{
		std::cout << "meep\n";
		this->type = other.type;
		this->brain = other.brain;
	}
	return(*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
