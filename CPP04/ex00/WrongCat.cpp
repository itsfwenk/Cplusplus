/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:15:19 by fli               #+#    #+#             */
/*   Updated: 2024/11/07 17:27:49 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << YELLOW << "WrongCat default constructor called" << DEFAULT << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << YELLOW << "WrongCat default destructor called" << DEFAULT << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.type)
{
	std::cout << YELLOW << "WrongCat copy constructor called" << DEFAULT << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout << YELLOW << "WrongCat copy assignment constructor called" << DEFAULT << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return(*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

std::string WrongCat::getType() const
{
	return (this->type);
}
