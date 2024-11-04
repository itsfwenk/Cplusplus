/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:17:08 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 18:34:42 by fli              ###   ########.fr       */
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

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return(*this);
	this->Name = other.Name;
	this->HitPoints = other.HitPoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
	return(*this);
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name contructor called." << std::endl;
	this->Name = name;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		this->EnergyPoints--;
		std::cout << "ClapTrap " << this->Name << " attacks ";
		std::cout << target << ", causing " << this->AttackDamage;
		std::cout << " points of damage!";
		std::cout << std::endl;
	}
	else if (this->EnergyPoints <= 0)
		std::cout << "ClapTrap " << this->Name << " is exhausted, can't attack..." << std::endl;
	else
		std::cout << "ClapTrap " << this->Name << " is dead, can't attack..." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints > 0)
	{
		if (amount > 2147483647)
			amount = 2147483647;
		std::cout << "ClapTrap " << this->Name << " loses ";
		std::cout << amount << " hit points, ";
		this->HitPoints -= amount;
		std::cout << "is now at " << this->HitPoints << " HP...";
		std::cout << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->Name << " is dead, can't take more damage..." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		this->EnergyPoints--;
		std::cout << "ClapTrap " << this->Name << " repairs itself of ";
		std::cout << amount << " hit points, ";
		this->HitPoints += amount;
		if (this->HitPoints < 0)
			this->HitPoints = 2147483647;
		std::cout << "is now at " << this->HitPoints << " HP !";
		std::cout << std::endl;
	}
	else if (this->EnergyPoints <= 0)
		std::cout << "ClapTrap " << this->Name << " is exhausted, can't repair itself..." << std::endl;
	else
		std::cout << "ClapTrap " << this->Name << " is dead, can't repair itself..." << std::endl;
}
