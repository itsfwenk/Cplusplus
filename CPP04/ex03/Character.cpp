/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:59:02 by fli               #+#    #+#             */
/*   Updated: 2024/11/08 17:59:30 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
	: _name("Brigitte"), _equipped(0), _inventory{nullptr, nullptr, nullptr, nullptr}
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character default destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

Character::Character(const Character &other) : _equipped(other._equipped)
{
	std::cout << "Character copy constructor called" << std::endl;
	if (this->_equipped != 0)
		delete [] this->_inventory;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = other._inventory[i]->clone();
}

Character&	Character::operator=(const Character &other)
{
	std::cout << "Character copy assignment called" << std::endl;
	if (this != &other)
	{
		if (this->_equipped != 0)
		{
			for (int i = 0; i < this->_equipped; i++)
				delete _inventory[i];
		}
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

Character::Character(std::string name)
	: _name(name), _equipped(0), _inventory{nullptr, nullptr, nullptr, nullptr}
{
	std::cout << "Character name constructor called" << std::endl;
}

std::string const &Character::getName()
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	int	i = 0;

	while (this->_inventory[i] != nullptr)
		i++;
	if (i == 4)
		return ;
	this->_inventory[i] = m;
	this->_equipped++;
}

void	Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0)
		return ;
	this->_inventory[idx] = nullptr;
	this->_equipped--;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 4 || idx < 0 || idx >= this->_equipped)
		return ;
	this->_inventory[idx]->use(target);
}
