/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:06:39 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 17:19:19 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("CharlesOignon", 100, 50, 20)
{
	std::cout << YELLOW << "ScavTrap default contructor called." << DEFAULT << std::endl;
	// std::cout << "In Scav, HP now is: " << this->HitPoints << std::endl;
	// this->Name = "CharlesOignon";
	// this->HitPoints = 100;
	// this->EnergyPoints = 500;
	// this->AttackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "ScavTrap default destructor called." << DEFAULT << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << YELLOW << "ScavTrap copy constructor called" << DEFAULT << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << YELLOW << "ScavTrap copy assignment operator called" << DEFAULT << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return(*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << YELLOW << "ScavTrap name contructor called." << DEFAULT << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
		if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		this->EnergyPoints--;
		std::cout << YELLOW << "ScavTrap " << this->Name << " attacks ";
		std::cout << target << ", causing " << this->AttackDamage;
		std::cout << " points of damage!";
		std::cout << DEFAULT << std::endl;
	}
	else if (this->EnergyPoints <= 0)
		std::cout << YELLOW << "ScavTrap " << this->Name << " is exhausted, can't attack..." << DEFAULT << std::endl;
	else
		std::cout << YELLOW << "ScavTrap " << this->Name << " is dead, can't attack..." << DEFAULT << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << YELLOW << "ScavTrap " << this->Name << " is now in Gate keeper mode." << DEFAULT << std::endl;
}

int	ScavTrap::getHitPoints()
{
	return (this->HitPoints);
}

int	ScavTrap::getEnergyPoints()
{
	return (this->EnergyPoints);
}

int	ScavTrap::getAttackDamage()
{
	return (this->AttackDamage);
}

void	ScavTrap::setHitPoints(int HP)
{
	this->HitPoints = HP;
}

void	ScavTrap::setEnergyPoints(int EP)
{
	this->EnergyPoints = EP;
}

void	ScavTrap::setAttackDamage(int AD)
{
	this->AttackDamage = AD;
}
