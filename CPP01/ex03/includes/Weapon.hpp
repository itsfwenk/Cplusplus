/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:49:09 by fli               #+#    #+#             */
/*   Updated: 2024/10/29 20:08:06 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class	Weapon
{
	private:
		std::string	type;
	public:
		Weapon();
		~Weapon();
		Weapon(std::string type);
		const std::string	&getType();
		void				setType( std::string type);
};

#endif
