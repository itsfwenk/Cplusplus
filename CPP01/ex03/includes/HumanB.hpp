/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:49:09 by fli               #+#    #+#             */
/*   Updated: 2024/10/29 20:13:35 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	name;
		Weapon		weapon;
	public:
		HumanB();
		HumanB(std::string	name);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon weapon);
};

#endif
