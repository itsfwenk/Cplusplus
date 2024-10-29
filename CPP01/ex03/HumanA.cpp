/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:43:08 by fli               #+#    #+#             */
/*   Updated: 2024/10/29 20:11:47 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

static Weapon defaultWeapon("Stick");

HumanA::HumanA() : name("CharlesOignon"), weapon(defaultWeapon)
{
	std::cout << "HumanA default constructor called" << std::endl;
}

HumanA::HumanA(std::string	name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << "HumanA constructor called" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destructor called" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType();
	std::cout << std::endl;
}

