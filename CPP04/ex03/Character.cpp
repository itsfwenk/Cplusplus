/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:59:02 by fli               #+#    #+#             */
/*   Updated: 2024/11/09 16:50:35 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

Character::Character() : _name("Fatima"), _equipped(0)
{
	std::cout << "Character default constructor called" << std::endl;
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
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
	{
		for (int i = 0; i < 4; i++)
			delete this->_inventory[i];
	}
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

Character::Character(std::string name) : _name(name), _equipped(0)
{
	std::cout << "Character name constructor called" << std::endl;
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	int	i = 0;

	while (this->_inventory[i] != NULL)
		i++;
	if (i == 4 || m == NULL)
		return ;
	this->_inventory[i] = m;
	this->_equipped++;
}

void	Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0)
		return ;
	this->_inventory[idx] = NULL;
	this->_equipped--;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 4 || idx < 0 || idx >= this->_equipped)
		return ;
	this->_inventory[idx]->use(target);
}
