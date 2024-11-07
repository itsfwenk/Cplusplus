/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:15:43 by fli               #+#    #+#             */
/*   Updated: 2024/11/07 17:25:56 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << YELLOW << "Dog default constructor called" << DEFAULT << std::endl;
}

Dog::~Dog()
{
	std::cout << YELLOW << "Dog default destructor called" << DEFAULT << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other.type)
{
	std::cout << YELLOW << "Dog copy constructor called" << DEFAULT << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << YELLOW << "Dog copy assignment constructor called" << DEFAULT << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return(*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}
