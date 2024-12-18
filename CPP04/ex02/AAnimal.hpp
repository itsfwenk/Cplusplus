/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:54:05 by fli               #+#    #+#             */
/*   Updated: 2024/11/07 17:37:00 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>
# include "Brain.hpp"

# define DEFAULT "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"

class AAnimal
{
	private:
	protected:
		std::string type;
	public:
		AAnimal();
		virtual ~AAnimal() = 0;
		AAnimal(const AAnimal &other);
		AAnimal& operator=(const AAnimal &other);

		AAnimal(std::string type);

		virtual void makeSound(void) const;
		std::string getType() const;
};

#endif
