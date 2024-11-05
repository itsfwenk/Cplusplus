/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:01:30 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 17:08:05 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap
{
	protected:
		std::string	Name;
		int			HitPoints;
		int			EnergyPoints;
		int			AttackDamage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);

		ClapTrap(std::string name);
		ClapTrap(std::string name, int hp, int ep, int ad);


		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int		getHitPoints();
		int		getEnergyPoints();
		int		getAttackDamage();
		void	setHitPoints(int HP);
		void	setEnergyPoints(int EP);
		void	setAttackDamage(int AD);
};
#endif
