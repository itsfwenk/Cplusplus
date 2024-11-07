/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:19:11 by fli               #+#    #+#             */
/*   Updated: 2024/11/07 17:37:04 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;

	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = "*no thoughts just vibes*";
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called." << std::endl;

	if (this->ideas)
		delete[] this->ideas;
}

Brain::Brain(const Brain &other) : ideas(other.ideas)
{
	std::cout << "Brain copy constructor called." << std::endl;

	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment constructor called." << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}
