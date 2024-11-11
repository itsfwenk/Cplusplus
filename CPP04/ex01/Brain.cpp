/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:19:11 by fli               #+#    #+#             */
/*   Updated: 2024/11/11 11:04:26 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;

	for (int i = 0; i < 100; i++)
		ideas[i] = "*no thoughts just vibes*";
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called." << std::endl;
}

Brain::Brain(const Brain &other)
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

void	Brain::setIdeas(const std::string &idea, int i)
{
	if (i >= 100 || i < 0)
		return ;
	this->ideas[i] = idea;
}

std::string	Brain::getIdeas(int i)
{
	if (i >= 100 || i < 0)
		return NULL;
	return (this->ideas[i]);
}
