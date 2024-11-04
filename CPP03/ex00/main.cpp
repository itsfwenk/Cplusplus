/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:07:16 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 18:34:25 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap charles;
	ClapTrap oignon("Oignon");

	charles.attack("Bibiche");
	oignon.attack("Bichette");
	charles.attack("Bibiche");
	charles.attack("Bibiche");
	charles.attack("Bibiche");
	charles.attack("Bibiche");
	charles.attack("Bibiche");
	charles.attack("Bibiche");
	charles.attack("Bibiche");
	charles.attack("Bibiche");
	charles.attack("Bibiche");
	charles.takeDamage(2147483699);
	oignon.takeDamage(6);
	charles.beRepaired(6);
	oignon.beRepaired(2147483699);
}
