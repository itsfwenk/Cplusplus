/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:06:39 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 18:37:46 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
 : name("CharlesOignon"), ClapTrap("CharlesOignon_clap_name", FragTrap().getHitPoints(), ScavTrap().getEnergyPoints(), FragTrap().getAttackDamage())
{
	std::cout << BLUE << "DiamondTrap default contructor called." << DEFAULT << std::endl;
	// ClapTrap::Name = this->name + "_clap_name";
	// FragTrap::setHitPoints(FragTrap().getHitPoints());
	// ScavTrap::setEnergyPoints(ScavTrap().getEnergyPoints());
	// FragTrap::setAttackDamage(FragTrap().getAttackDamage());
	// std::cout << this->name << std::endl;
	// std::cout << ClapTrap::Name << std::endl;
	// std::cout << RED << "HP = " << this->HitPoints << " EP = " << this->EnergyPoints << " AD = " << this->AttackDamage << DEFAULT << std::endl;
}


DiamondTrap::~DiamondTrap()
{
	std::cout << BLUE << "DiamondTrap default destructor called." << DEFAULT << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), name(other.Name)
{
	std::cout << BLUE << "DiamondTrap copy constructor called" << DEFAULT << std::endl;
	ClapTrap::Name = other.name + "_clap_name";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << BLUE << "DiamondTrap copy assignment operator called" << DEFAULT << std::endl;
	if (this != &other)
	{
		ClapTrap::Name = other.name + "_clap_name";
		this->Name = other.Name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	return(*this);
}

DiamondTrap::DiamondTrap(std::string name)
 : name(name), ClapTrap(name + "_clap_name", FragTrap().getHitPoints(), ScavTrap().getEnergyPoints(), FragTrap().getAttackDamage())
{
	std::cout << BLUE << "DiamondTrap name contructor called." << DEFAULT << std::endl;
	// ClapTrap::Name = this->name + "_clap_name";
	// FragTrap::setHitPoints(FragTrap().getHitPoints());
	// ScavTrap::setEnergyPoints(ScavTrap().getEnergyPoints());
	// FragTrap::setAttackDamage(FragTrap().getAttackDamage());
	// std::cout << this->name << std::endl;
	// std::cout << ClapTrap::Name << std::endl;
	// std::cout << RED << "HP = " << this->HitPoints << " EP = " << this->EnergyPoints << " AD = " << this->AttackDamage << DEFAULT << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << BLUE << "I am " << this->name << " birthed from " << ClapTrap::Name << DEFAULT << std::endl;
}

int	DiamondTrap::getHitPoints()
{
	return (this->HitPoints);
}

int	DiamondTrap::getEnergyPoints()
{
	return (this->EnergyPoints);
}

int	DiamondTrap::getAttackDamage()
{
	return (this->AttackDamage);
}
