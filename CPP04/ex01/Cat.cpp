/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:15:19 by fli               #+#    #+#             */
/*   Updated: 2024/11/11 11:00:58 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << RED << "Cat default constructor called" << DEFAULT << std::endl;

	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << RED << "Cat default destructor called" << DEFAULT << std::endl;

	delete this->brain;
}

Cat::Cat(const Cat &other) : Animal(other.type)
{
	std::cout << RED << "Cat copy constructor called" << DEFAULT << std::endl;

	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdeas(other.brain->getIdeas(i), i);
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << RED << "Cat copy assignment called" << DEFAULT << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->brain = other.brain;
	}
	return(*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
