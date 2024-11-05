/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:07:16 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 10:52:46 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap charles;
	ScavTrap oignon("Oignon");

	charles.attack("Bibiche");
	oignon.attack("Bichette");
	charles.attack("Bibiche");

	charles.takeDamage(6);
	oignon.takeDamage(6);
	charles.beRepaired(6);
	oignon.beRepaired(6);
	oignon.guardGate();
}
