/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:17:08 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 14:49:26 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("CharlesOignon"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Default contructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : Name(other.Name), HitPoints(other.HitPoints), EnergyPoints(other.EnergyPoints), AttackDamage(other.AttackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}
