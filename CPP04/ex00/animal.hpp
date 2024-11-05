/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:54:05 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 19:52:57 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

# define DEFAULT "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"

class Animal
{
	private:
		std::string sound;
	protected:
		std::string type;
	public:
		Animal();
		~Animal();
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);

		Animal(std::string type);
		Animal(std::string type, std::string sound);

		void makeSound(void) const;
		void setSound(std::string sound);
		std::string getType() const;
		std::string getSound() const;
};

#endif
