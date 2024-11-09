/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:29:49 by fli               #+#    #+#             */
/*   Updated: 2024/11/09 16:16:03 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure default destructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other.type)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure	&Cure::operator=(const Cure &other)
{
	std::cout << "Cure copy assignment constructor called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria *newCure = new Cure(*this);
	return (newCure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *";
}
