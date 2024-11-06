/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:54:05 by fli               #+#    #+#             */
/*   Updated: 2024/11/06 15:11:01 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

# define DEFAULT "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"

class wrongAnimal
{
	private:
		std::string sound;
	protected:
		std::string type;
	public:
		wrongAnimal();
		virtual ~wrongAnimal();
		wrongAnimal(const wrongAnimal &other);
		wrongAnimal& operator=(const wrongAnimal &other);

		wrongAnimal(std::string type);

		void makeSound(void) const;
		std::string getType() const;
};

#endif