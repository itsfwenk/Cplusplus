/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:42:07 by fli               #+#    #+#             */
/*   Updated: 2024/10/31 17:39:05 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl constructor called" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl destructor called" << std::endl;
}

void Harl::complain( std::string level )
{
	int	i = 0;

	while (level[i])
	{
		if (level[i] >= 'A' && level[i] <= 'Z')
			level[i] = level[i] + ('a' - 'A');
		i++;
	}
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	void (Harl::*harlFunc[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*harlFunc[i])();
			return;
		}
	}
	std::cout << "*Harl keeps yapping*" << std::endl;
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special ";
	std::cout << "ketchup burger. I really do!";
	std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << " I’ve been coming for years ";
	std::cout << "whereas you started working here since last month.";
	std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}
