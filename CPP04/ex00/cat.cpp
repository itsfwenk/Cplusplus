/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:15:19 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 19:54:00 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat() : Animal("Cat", "Meow")
{
	std::cout << YELLOW << "Cat default constructor called" << DEFAULT << std::endl;
}

Cat::~Cat()
{
	std::cout << YELLOW << "Cat default destructor called" << DEFAULT << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other.type)
{
	std::cout << YELLOW << "Cat copy constructor called" << DEFAULT << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << YELLOW << "Cat copy assignment constructor called" << DEFAULT << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return(*this);
}
