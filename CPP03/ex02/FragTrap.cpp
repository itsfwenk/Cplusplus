/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:06:39 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 11:37:08 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("CharlesOignon", 100, 100, 30)
{
	std::cout << CYAN << "FragTrap default contructor called." << DEFAULT << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << CYAN << "FragTrap default destructor called." << DEFAULT << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << CYAN << "FragTrap copy constructor called" << DEFAULT << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << CYAN << "FragTrap copy assignment operator called" << DEFAULT << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return(*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << CYAN << "FragTrap name contructor called." << DEFAULT << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
		if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		this->EnergyPoints--;
		std::cout << CYAN << "FragTrap " << this->Name << " attacks ";
		std::cout << target << ", causing " << this->AttackDamage;
		std::cout << " points of damage!";
		std::cout << DEFAULT << std::endl;
	}
	else if (this->EnergyPoints <= 0)
		std::cout << CYAN << "FragTrap " << this->Name << " is exhausted, can't attack..." << DEFAULT << std::endl;
	else
		std::cout << CYAN << "FragTrap " << this->Name << " is dead, can't attack..." << DEFAULT << std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << CYAN << "FragTrap " << this->Name << " high fives you !" << DEFAULT << std::endl;
}
