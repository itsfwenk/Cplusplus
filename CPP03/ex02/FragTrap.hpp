/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:41:36 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 11:29:54 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

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

class FragTrap : public ClapTrap
{
	private:

	public:
	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap& operator=(const FragTrap &other);

	FragTrap(std::string name);

	void	attack(const std::string& target);
	void	highFiveGuys(void);
};

#endif
