/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:41:36 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 17:19:39 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

# define DEFAULT "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"

class ScavTrap : public virtual ClapTrap
{
	protected:

	public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(const ScavTrap &other);
	ScavTrap& operator=(const ScavTrap &other);

	ScavTrap(std::string name);

	void	attack(const std::string& target);
	void	guardGate();

	int		getHitPoints();
	int		getEnergyPoints();
	int		getAttackDamage();
	void	setHitPoints(int HP);
	void	setEnergyPoints(int EP);
	void	setAttackDamage(int AD);
};

#endif
