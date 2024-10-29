/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:33:37 by fli               #+#    #+#             */
/*   Updated: 2024/10/29 17:18:16 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie constructor " << this->name << std::endl;
}

Zombie::Zombie( std::string name )
{
	this->name = name;
	std::cout << "Zombie constructor " << this->name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destructor " << this->name << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->name = name;
}
