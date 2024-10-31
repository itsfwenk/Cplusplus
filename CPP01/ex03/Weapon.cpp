/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:53:02 by fli               #+#    #+#             */
/*   Updated: 2024/10/31 17:45:55 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("defaultWeapon")
{
	std::cout << "Weapon default constructor called" << std::endl;
}

Weapon::Weapon(std::string type)
{
	this->setType(type);
	std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called" << std::endl;
}

const std::string	&Weapon::getType()
{
	std::string	&typeREF = this->type;
	return (typeREF);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
