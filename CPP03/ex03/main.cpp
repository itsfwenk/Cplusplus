/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:07:16 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 18:38:37 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	FragTrap frag("CharlesFrag");
	frag.highFivesGuys();
	std::cout << "--------------------------------\n";
	DiamondTrap diamond = DiamondTrap();
	std::cout << "--------------------------------\n";
	diamond.attack(frag.getName());
	diamond.takeDamage(6);
	diamond.whoAmI();
	DiamondTrap("luuuul").whoAmI();

	std::cout << "HP: " << diamond.getHitPoints() << std::endl;
	std::cout << "EP: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "AD: " << diamond.getAttackDamage() << std::endl;
}
