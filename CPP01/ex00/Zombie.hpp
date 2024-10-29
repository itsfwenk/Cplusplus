/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:29:07 by fli               #+#    #+#             */
/*   Updated: 2024/10/29 15:14:53 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class	Zombie
{
private:
	std::string	name;
public:
	Zombie( std::string name );
	~Zombie();
	void	announce( void );

};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif
