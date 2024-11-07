/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:51:15 by fli               #+#    #+#             */
/*   Updated: 2024/11/07 19:24:01 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <string>
# include <iostream>

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		~AMateria();
		AMateria(const AMateria &other);
		AMateria& operator=(const AMateria &other);

		AMateria(std::string const & type);
		std::string const& getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
