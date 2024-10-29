/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:29:07 by fli               #+#    #+#             */
/*   Updated: 2024/10/29 17:14:40 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <new>
# include <sstream>
# include <limits>

class	Zombie
{
private:
	std::string	name;
public:
	Zombie();
	Zombie( std::string name );
	~Zombie();
	void	announce( void );
	void	setName( std::string name );

};

Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif
