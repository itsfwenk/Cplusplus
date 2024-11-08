/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:59:45 by fli               #+#    #+#             */
/*   Updated: 2024/11/08 17:09:06 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	private :
	public :
		Cure();
		~Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
