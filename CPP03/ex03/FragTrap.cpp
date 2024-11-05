/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:06:39 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 17:12:56 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("CharlesOignon", 100, 100, 30)
{
	std::cout << CYAN << "FragTrap default contructor called." << DEFAULT << std::endl;
	// std::cout << "In Frag, HP now is: " << this->HitPoints << std::endl;
	// this->Name = "CharlesOignon";
	// this->HitPoints = 100;
	// this->EnergyPoints = 100;
	// this->AttackDamage = 30;
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << CYAN << "FragTrap " << this->Name << " high fives you !" << DEFAULT << std::endl;
}

std::string	FragTrap::getName()
{
	return(this->Name);
}

int	FragTrap::getHitPoints()
{
	return (this->HitPoints);
}

int	FragTrap::getEnergyPoints()
{
	return (this->EnergyPoints);
}

int	FragTrap::getAttackDamage()
{
	return (this->AttackDamage);
}

void	FragTrap::setHitPoints(int HP)
{
	this->HitPoints = HP;
}

void	FragTrap::setEnergyPoints(int EP)
{
	this->EnergyPoints = EP;
}

void	FragTrap::setAttackDamage(int AD)
{
	this->AttackDamage = AD;
}
