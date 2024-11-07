/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:59:02 by fli               #+#    #+#             */
/*   Updated: 2024/11/07 20:00:07 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
	: _equipped(0), _inventory{nullptr, nullptr, nullptr, nullptr}
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
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = other._inventory[i]->clone();
}

Character&	Character::operator=(const Character &other)
{
	std::cout << "Character copy assignment called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

