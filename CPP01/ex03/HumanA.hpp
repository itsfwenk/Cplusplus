/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:49:09 by fli               #+#    #+#             */
/*   Updated: 2024/10/29 19:50:47 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		HumanA();
		~HumanA();
		HumanA(std::string	name, Weapon &weapon);
		void	attack(void);
};

#endif
