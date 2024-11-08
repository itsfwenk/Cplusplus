/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:59:45 by fli               #+#    #+#             */
/*   Updated: 2024/11/08 17:03:09 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private :
	public :
		Ice();
		~Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
