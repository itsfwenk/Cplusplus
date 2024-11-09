/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:04:05 by fli               #+#    #+#             */
/*   Updated: 2024/11/09 15:34:30 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _equipped(0)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource default destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

MateriaSource::MateriaSource(const MateriaSource &other) : _equipped(other._equipped)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	if (this->_equipped != 0)
	{
		for (int i = 0; i < 4; i++)
			delete this->_inventory[i];
	}
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = other._inventory[i]->clone();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource copy assignment called" << std::endl;
	this->_equipped = other._equipped;
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

void MateriaSource::learnMateria(AMateria* m)
{
	int	i = 0;

	if (this->_equipped == 4)
		return ;
	while (this->_inventory[i] != NULL)
		i++;
	this->_inventory[i] = m->clone();
	this->_equipped++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int	i = 0;
	for (i = 0; i < _equipped; i++)
	{
		if (this->_inventory[i]->getType() == type)
			break ;
	}

	AMateria	*newMateria;
	if (i != 4)
	{
		newMateria = this->_inventory[i]->clone();
		return (newMateria);
	}
	return (NULL);
}
