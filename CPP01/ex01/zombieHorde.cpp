/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:31:43 by fli               #+#    #+#             */
/*   Updated: 2024/10/29 16:04:27 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <vector>
#include <algorithm>
#include <functional>

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		std::cout << "Invalid number of zombies" << std::endl;
	Zombie	*zombie_tab = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombie_tab[i].setName(name);
	return (zombie_tab);
}
