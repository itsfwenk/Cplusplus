/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:42:07 by fli               #+#    #+#             */
/*   Updated: 2024/10/31 17:44:05 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int			n;
	std::string	input;
	Zombie		*zombie_tab;

	std::cout << "Enter zombie horde size : ";
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::stringstream ss(input);
	ss >> n;
	while (n <= 0)
	{
		std::cout << "Invalid number of zombie.";
		std::cin >> input;
		std::stringstream ss(input);
		ss >> n;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	zombie_tab = zombieHorde(n, "Charles Oignon");
	for(int i = 0; i < n; i++)
		zombie_tab[i].announce();
	delete[] zombie_tab;
}
