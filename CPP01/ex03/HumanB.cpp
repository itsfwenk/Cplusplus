/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:43:08 by fli               #+#    #+#             */
/*   Updated: 2024/10/30 12:05:08 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() : name("CharlesOignon"), weapon(NULL)
{
	std::cout << "HumanB default constructor called" << std::endl;
}

HumanB::HumanB(std::string	name) : name(name)
{
	std::cout << "HumanB constructor called" << std::endl;
}


HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}

void	HumanB::attack(void)
{
	if (this->weapon == NULL)
		std::cout << this->name << " attacks by throwing rocks (no weapon)";
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
