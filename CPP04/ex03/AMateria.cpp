/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:59:02 by fli               #+#    #+#             */
/*   Updated: 2024/11/07 19:24:14 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria default destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria copy assignment called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "AMateria type constructor called" << std::endl;
}

std::string const& AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{

}
