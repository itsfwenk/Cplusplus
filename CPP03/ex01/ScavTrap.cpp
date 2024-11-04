/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:06:39 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 19:48:16 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("CharlesOignon", 100, 50, 20)
{
	std::cout << "ScavTrap default contructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return(*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name contructor called." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
		if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		this->EnergyPoints--;
		std::cout << "ScavTrap " << this->Name << " attacks ";
		std::cout << target << ", causing " << this->AttackDamage;
		std::cout << " points of damage!";
		std::cout << std::endl;
	}
	else if (this->EnergyPoints <= 0)
		std::cout << "ScavTrap " << this->Name << " is exhausted, can't attack..." << std::endl;
	else
		std::cout << "ScavTrap " << this->Name << " is dead, can't attack..." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode." << std::endl;
}
